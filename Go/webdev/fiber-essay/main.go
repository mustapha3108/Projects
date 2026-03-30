package main

import (
	"fmt"
	"fiber-essay/pages"
	"github.com/gofiber/fiber/v3"
	"github.com/gofiber/fiber/v3/middleware/static"
)





func main()  {

	fmt.Println("hello go")

    app := fiber.New()

	

	app.Get("/crow", func(c fiber.Ctx) error {

        return c.SendString("Hello, World!, and we're in baby")
		//return static.New("./public/home.html")
    })

	pages.Page2(app)

    app.Listen(":3000")

	
}