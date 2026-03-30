package help

import (
	"database/sql"
	"errors"
	"fmt"
	"infinitvoid/frontend/mark/comp"
	"mime/multipart"
	"path/filepath"
	"strings"

	"github.com/a-h/templ"
	"github.com/go-playground/validator/v10"
	"github.com/gofiber/fiber/v3"
	"github.com/google/uuid"
	"github.com/jackc/pgx/v5/pgconn"
	"golang.org/x/crypto/bcrypt"
)

//rendering
func Render(c fiber.Ctx, component templ.Component) error {
	c.Set("Content-Type", "text/html")
	return component.Render(c.Context(), c.Response().BodyWriter())
}

func Hrender(c fiber.Ctx, component templ.Component) error {
	if c.Get("HX-Request") == "true" {
		return Render(c, component)
	}
	return Render(c, comp.Layout(component))
}

func Redirect(c fiber.Ctx, path string) error {
    if c.Get("HX-Request") == "true" {
        c.Set("HX-Redirect", path)
        return c.SendStatus(200)
    }
    return c.Redirect().To(path)
}

func SaveImage(c fiber.Ctx, image *multipart.FileHeader) (string, error) {
	if !IsImage(image) {
		return "", errors.New("not supported image type")
	}
	ext:= filepath.Ext(image.Filename)
	name:= uuid.New().String() + ext
	path:= fmt.Sprintf("frontend/glitter/media/dynamic/%s", name)
	if err:= c.SaveFile(image, path); err!=nil {
		return "", err
	}
	return "media/dynamic/" + name, nil
}

//checking stuff and manual security 
const MaxImageSize = 5 * 1024 * 1024

func IsImage(file *multipart.FileHeader) bool {

	// ─── Size check ──────────────────────────────────────────────────────────
	if file.Size > MaxImageSize {
		return false
	}

	f, err := file.Open()
	if err != nil {
		return false
	}
	defer f.Close()

	// ─── Read enough bytes for all format checks ──────────────────────────────
	// 261 bytes covers all magic byte signatures including ZIP-based polyglots
	buf := make([]byte, 261)
	n, err := f.Read(buf)
	if err != nil || n < 8 {
		return false
	}
	buf = buf[:n]

	// ─── Magic byte checks ────────────────────────────────────────────────────
	allowed := []func([]byte) bool{
		func(b []byte) bool { // PNG
			return len(b) >= 8 &&
				b[0] == 0x89 && b[1] == 0x50 && b[2] == 0x4E && b[3] == 0x47 &&
				b[4] == 0x0D && b[5] == 0x0A && b[6] == 0x1A && b[7] == 0x0A
		},
		func(b []byte) bool { // JPEG / JPG
			return len(b) >= 3 &&
				b[0] == 0xFF && b[1] == 0xD8 && b[2] == 0xFF
		},
		func(b []byte) bool { // GIF
			return len(b) >= 6 &&
				b[0] == 0x47 && b[1] == 0x49 && b[2] == 0x46 &&
				b[3] == 0x38 && (b[4] == 0x37 || b[4] == 0x39) && b[5] == 0x61
		},
		func(b []byte) bool { // WEBP
			return len(b) >= 12 &&
				b[0] == 0x52 && b[1] == 0x49 && b[2] == 0x46 && b[3] == 0x46 &&
				b[8] == 0x57 && b[9] == 0x45 && b[10] == 0x42 && b[11] == 0x50
		},
		// func(b []byte) bool { // BMP
		// 	return len(b) >= 2 && b[0] == 0x42 && b[1] == 0x4D
		// },
		// func(b []byte) bool { // TIFF
		// 	return len(b) >= 4 &&
		// 		((b[0] == 0x49 && b[1] == 0x49 && b[2] == 0x2A && b[3] == 0x00) ||
		// 		 (b[0] == 0x4D && b[1] == 0x4D && b[2] == 0x00 && b[3] == 0x2A))
		// },
		// func(b []byte) bool { // SVG — disabled, can contain JS
		// 	return len(b) >= 5 &&
		// 		(string(b[:4]) == "<svg" || string(b[:5]) == "<?xml")
		// },
	}

	matched := false
	for _, check := range allowed {
		if check(buf) {
			matched = true
			break
		}
	}
	if !matched {
		return false
	}

	// ─── Polyglot checks ──────────────────────────────────────────────────────
	// reject ZIP-based polyglots (ZIP, JAR, DOCX etc embedded in image)
	if len(buf) >= 4 && buf[0] == 0x50 && buf[1] == 0x4B && buf[2] == 0x03 && buf[3] == 0x04 {
		return false
	}

	// reject PDF polyglots
	if len(buf) >= 4 && string(buf[:4]) == "%PDF" {
		return false
	}

	// reject PHP/script injection in the first bytes
	dangerousPatterns := []string{
		"<?php", "<?=", "<script", "<%", "#!/",
	}
	header := strings.ToLower(string(buf))
	for _, pattern := range dangerousPatterns {
		if strings.Contains(header, pattern) {
			return false
		}
	}

	// reject files with null bytes in unexpected places (common in exploit payloads)
	nullCount := 0
	for _, b := range buf[8:] {
		if b == 0x00 {
			nullCount++
		}
	}
	// allow some nulls (binary formats have them) but not suspiciously many in the header
	if nullCount > 128 {
		return false
	}

	return true
}


func ShowError(err error) string {
	if err == nil {
		return ""
	}

	if err.Error()== "not supported image type" {
		return "not supported image type"
	}

	if err.Error() == "wrong credentials" {
		return "invalid login"
	}

	// ─── Database ────────────────────────────────────────────────────────────
	if errors.Is(err, sql.ErrNoRows) {
		return "not found"
	}

	var pgErr *pgconn.PgError
	if errors.As(err, &pgErr) {
		switch pgErr.Code {
		case "23505": // unique violation
			return "already exists"
		case "23503": // foreign key violation
			return "referenced record does not exist"
		case "23502": // not null violation
			return "missing required field"
		case "22001": // string too long
			return "value is too long"
		case "28P01": // wrong password
			return "invalid credentials"
		case "3D000": // database does not exist
			return "database not found"
		case "08006": // connection failure
			return "could not connect to database"
		}
	}

	// ─── Bcrypt ──────────────────────────────────────────────────────────────
	if errors.Is(err, bcrypt.ErrMismatchedHashAndPassword) {
		return "invalid credentials"
	}
	if errors.Is(err, bcrypt.ErrHashTooShort) {
		return "invalid credentials"
	}
	if errors.Is(err, bcrypt.ErrPasswordTooLong) {
		return "password is too long"
	}

	// ─── Validation (go-playground/validator) ────────────────────────────────
	var validationErrs validator.ValidationErrors
	if errors.As(err, &validationErrs) {
		var msgs []string
		for _, e := range validationErrs {
			field := strings.ToLower(e.Field())
			switch e.Tag() {
			case "required":
				msgs = append(msgs, field+" is required")
			case "email":
				msgs = append(msgs, field+" must be a valid email")
			case "min":
				msgs = append(msgs, field+" is too short")
			case "max":
				msgs = append(msgs, field+" is too long")
			case "len":
				msgs = append(msgs, field+" has invalid length")
			case "numeric":
				msgs = append(msgs, field+" must be a number")
			case "alpha":
				msgs = append(msgs, field+" must contain only letters")
			case "alphanum":
				msgs = append(msgs, field+" must contain only letters and numbers")
			case "url":
				msgs = append(msgs, field+" must be a valid URL")
			case "uuid":
				msgs = append(msgs, field+" must be a valid UUID")
			case "oneof":
				msgs = append(msgs, field+" has an invalid value")
			case "eqfield":
				msgs = append(msgs, field+" does not match")
			case "gtefield":
				msgs = append(msgs, field+" is out of range")
			case "lt":
				msgs = append(msgs, field+" is too large")
			case "gt":
				msgs = append(msgs, field+" is too small")
			case "lte":
				msgs = append(msgs, field+" is too large")
			case "gte":
				msgs = append(msgs, field+" is too small")
			default:
				msgs = append(msgs, field+" is invalid")
			}
		}
		return strings.Join(msgs, ", ")
	}

	// ─── Fiber binding ───────────────────────────────────────────────────────
	if errors.Is(err, fiber.ErrUnprocessableEntity) {
		return "invalid form data"
	}
	if errors.Is(err, fiber.ErrBadRequest) {
		return "bad request"
	}

	// ─── File upload ─────────────────────────────────────────────────────────
	if errors.Is(err, fiber.ErrRequestEntityTooLarge) {
		return "file is too large"
	}
	if strings.Contains(err.Error(), "no such file") {
		return "file not found"
	}
	if strings.Contains(err.Error(), "multipart") {
		return "invalid file upload"
	}

	// ─── Session ─────────────────────────────────────────────────────────────
	if strings.Contains(err.Error(), "session") {
		return "session error, please log in again"
	}

	// ─── Redis ───────────────────────────────────────────────────────────────
	if strings.Contains(err.Error(), "redis") || strings.Contains(err.Error(), "EOF") {
		return "cache unavailable, please try again"
	}

	// ─── Fallback ────────────────────────────────────────────────────────────
	return "something went wrong"
}