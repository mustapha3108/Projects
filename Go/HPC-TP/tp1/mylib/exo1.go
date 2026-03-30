package mylib

import (
	"fmt"
	"math/rand"
)

func Exo1() {
	fmt.Println("-----exo 1 start-----")
	/*
	Écrire un programme qui parcourt un tableau d'entiers, vérifie si chaque entier est pair ou impair,
	puis les catégorise dans une map avec les clés "pair" et "impair" pointant vers des tableaux des
	entiers respectifs.
	*/
	m := make(map[string] []int)
	m["pair"] = []int{}
	m["impair"] = []int{}
	n := 10
	v := make([]int, n)
	for i := 0; i<n; i++ {
		v[i] = rand.Intn(9) + 1
	}
	for i, v := range(v) {
		if v%2 == 0 {
			m["pair"] = append(m["pair"], i)
		} else {
			m["impair"] = append(m["impair"], i)
		}
	}

	fmt.Println("even numbers :")

	for _, i := range m["pair"] {
		fmt.Println(v[i])
	}

	fmt.Println("odd numbers:")
	for _, i := range m["impair"] {
		fmt.Println(v[i])
	}

	fmt.Println("-----exo 1 finished-----")
}