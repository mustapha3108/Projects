package mylib

import (
	"fmt"
	"math/rand"
	"sync"
)

func produce(ch chan int, wg *sync.WaitGroup){
	defer wg.Done()
	x:= rand.Intn(100)
	ch <- x
}

func consume(ch chan int, wg *sync.WaitGroup){
	defer wg.Done()
	x:= <-ch
	fmt.Println(x)
}


func Exo4(){
	fmt.Println("-----exo 4 start-----")
	/*
	Ecrire un programme qui démarre plusieurs producteurs et consommateurs travaillant sur une
	ressource commune (un canal de communication). Les producteurs généreront des nombres entiers
	aléatoires et les enverront dans un channel. Les consommateurs liront ces nombres à partir du même
	channel et les imprimeront.
	*/

	ch := make(chan int)
	var wg sync.WaitGroup

	n:= rand.Intn(5) + 2

	wg.Add(n*2)

	for i := 0; i < n; i++ {
		go produce(ch, &wg)
	}

	for i := 0; i < n; i++ {
		go consume(ch, &wg)
	}

	wg.Wait()

	fmt.Println("-----exo 4 finished-----")
}