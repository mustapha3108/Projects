package main

import (
	"infinitvoid/frontend/mark/comp"
	"infinitvoid/frontend/mark/pages"
	"infinitvoid/help"
	"strconv"
	"time"

	"github.com/gofiber/fiber/v3"
	"github.com/gofiber/fiber/v3/middleware/session"
	"github.com/joho/godotenv"
)


func main() {


	//todo:="make an app where multiple users can create accounts and upload posts with pictures, dashboard + global + posts filtering, if have time add animation"

	godotenv.Load()

	//body limit man, body limit
	app:= fiber.New(fiber.Config{
	    // Default is 4MB. For a SaaS, you might want 10MB or 20MB.
	    BodyLimit: 10 * 1024 * 1024, 
	})

	db:= help.BasicDb()

	help.BasicStart(app)


	//Gets
	app.Get("/", func(c fiber.Ctx) error {
		return help.Hrender(c, pages.Welcome(help.Logcheck(c)))
	})

	app.Get("/posts", func(c fiber.Ctx) error {
		var posts []help.Post
		if err:= db.Select(&posts, "select * from posts"); err!= nil {
			return c.SendString(help.ShowError(err))
		}
		return help.Hrender(c, pages.Posts(posts))
	})

	app.Get("/account", help.Authmid, func(c fiber.Ctx) error {
		user := c.Locals("user").(*help.User)
		return help.Hrender(c, pages.Account(user))
	})

	app.Get("/sign", help.Authmidr, func(c fiber.Ctx) error {
		return help.Hrender(c, pages.Sign())
	})
	

	//Posts
	app.Post("/signup", func(c fiber.Ctx) error {
		err:= help.Signup(c, db)
		if err!=nil {
			return c.SendString(help.ShowError(err))
		}
		return help.Redirect(c, "/account")
	})

	app.Post("/login", help.Authmidr, func(c fiber.Ctx) error {
		if  err:=help.Login(c, db); err!=nil {
			return c.SendString(help.ShowError(err))
		}
		return help.Redirect(c, "/account")

	})

	app.Post("/logout", help.Authmid, func(c fiber.Ctx) error {
		if err:=help.Logout(c); err!=nil {
			return c.SendString(help.ShowError(err))
		}
		return help.Redirect(c, "/")
	})

	app.Post("/alpinetest", func(c fiber.Ctx) error {
		return help.Render(c, comp.Alpinetest())
	})

	app.Post("/uploadPoste", func(c fiber.Ctx) error {
		poste:= new(help.Post)
		if err:= c.Bind().Form(poste); err!= nil {
			return c.SendString(help.ShowError(err))
		}
		if imagepath, err :=  help.SaveImage(c, poste.Image); err!= nil{
			return c.SendString(help.ShowError(err))
		} else {
			poste.ImagePath = imagepath
		}

		user:= session.FromContext(c).Get("user").(*help.User)

		if _, err:= db.Exec("insert into posts(userid, postname, description, imagepath) VALUES($1, $2, $3, $4)",
		user.UserID, poste.PostName, poste.Description, poste.ImagePath);
		err!= nil {
			return c.SendString(help.ShowError(err))
		 }

		return help.Redirect(c, "/posts")
	})

	app.Post("/colab1", func(c fiber.Ctx) error {
		
		x, _ := strconv.Atoi(c.FormValue("message"))
		x++
		return c.SendString(strconv.Itoa(x))
	})

	app.Post("/colab2", func(c fiber.Ctx) error {
		x, _ := strconv.Atoi(c.FormValue("message"))
		x++
		return c.SendString(strconv.Itoa(x))
	})

	app.Post("/apitest", func(c fiber.Ctx) error {

		time.Sleep(2 * time.Second )

		var mess struct {
			Message int `json:"message"`
		}
		if err:= c.Bind().JSON(&mess); err!= nil {
			return c.SendString("error binding")
		}
		return c.JSON(mess.Message + 1)
	})

	app.Listen(":3000")
}