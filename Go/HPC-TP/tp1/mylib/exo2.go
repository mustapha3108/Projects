package mylib

import (
	"fmt"
	"strconv"
	"math/rand"
)


func Exo2() {
	fmt.Println("-----exo 2 start-----")
	/*
	Ecrire une fonction qui génère les n premiers nombres de la séquence de Fibonacci et les stocke
	dans un slice. Utilisez cette fonction dans une fonction principale pour imprimer les 10 premiers
	nombres de Fibonacci
	*/
	n := rand.Intn(10) + 10
	s := []int{0,1}
	for i := 0; i < n; i++ {
		lastindex := len(s) - 1
		s = append(s, s[lastindex] + s[lastindex - 1])
	}
	fmt.Println("the fibanoci sequence for " +strconv.Itoa(n) + " elements")
	fmt.Println(s)	
	fmt.Println("-----exo 2 finished-----")
}