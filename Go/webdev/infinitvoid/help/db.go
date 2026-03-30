package help

import (
	"log"
	"mime/multipart"
	_ "github.com/jackc/pgx/v5/stdlib"
	"github.com/jmoiron/sqlx"
	"os"
)


//structs
type User struct {
	UserID   int    `db:"userid"`
	UserName string `db:"username" form:"UserName" validate:"required"`
	Password string `db:"password" form:"Password" validate:"required"`
}

type Post struct {
	PostID      int                   ` db:"postid"`
	UserID      int                   ` db:"userid"`
	PostName    string                ` db:"postname" validate:"required"`
	Description string                ` db:"description" validate:"required"`
	ImagePath   string                ` db:"imagepath"`
	Image       *multipart.FileHeader `form:"Image" db:"-"`
}

//database
func BasicDb() *sqlx.DB {
	dsn := os.Getenv("db_url")

	db, err := sqlx.Connect("pgx", dsn)
	if err != nil {
		log.Fatal("database connection error:", err)
	}

	db.SetMaxOpenConns(2)
	db.SetMaxIdleConns(2)

	tables := []string{
		`CREATE TABLE IF NOT EXISTS users (
			userid SERIAL PRIMARY KEY,
			username VARCHAR(50) NOT NULL UNIQUE,
			password TEXT NOT NULL
		);`,
		`CREATE TABLE IF NOT EXISTS posts (
		 	postid SERIAL PRIMARY KEY,
			userid INT NOT NULL REFERENCES users(userid) ON DELETE CASCADE,
			postname VARCHAR(50) NOT NULL,
			description TEXT NOT NULL,
			imagepath TEXT NOT NULL
		 );`,
	}

	for _, v := range tables {
		if _, err := db.Exec(v); err!=nil {
			log.Fatal("error creating:", v, "	", err)
		}
	}

    return db
}