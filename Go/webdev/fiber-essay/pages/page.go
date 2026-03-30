package pages

import (
	//"fmt"
	//"fiber-essay/main"
	"github.com/gofiber/fiber/v3"
	//"github.com/gofiber/fiber/v3/middleware/static"
)


func Page2(app *fiber.App){
    app.Get("/:crow", func(c fiber.Ctx) error {

        return c.SendString("Hello, World!, " + c.Params("crow"))
		//return static.New("./public/home.html")
    })
}