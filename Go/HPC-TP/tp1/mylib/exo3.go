package mylib

import (
	"fmt"
	"math/rand"
	"sync"
	"strconv"
)

func calcsum(s []int, ch chan int, wg *sync.WaitGroup){
	defer wg.Done()
	sum:=0
	for _,v:= range(s){
		sum = sum + v
	}
	ch <- sum
}

func Exo3(){
	fmt.Println("-----exo 3 start-----")
	/*
	Etant donne un tableau de n elements (n de votre choix), initialiser ce tableau a partir du clavier puis
	diviser ce tableau en deux parties et utiliser deux goroutines pour calculer la somme des elements de
	chaque partie du tableau. Chaque goroutine va ecrire le resulat obtenue dans un channel (le meme)
	et le programme principal (main) lis les resultats et calcul la somme total puis l'affiche. Remarque:
	le main doit attendre la fin des deux goroutines avec sync.WaitGroup (exp de declaration:
	*/
	n:= rand.Intn(10) + 5
	s:= make([]int, n)
	for i := 0; i < n; i++ {
		s[i] = rand.Intn(10)
	}

	middle := len(s)/2
	first:= s[:middle]
	second:= s[middle:]

	ch:= make(chan int, 2)
	var wg sync.WaitGroup
	wg.Add(2)

	go calcsum(first, ch, &wg)
	go calcsum(second, ch, &wg)

	//just a quick note, waitgroups are really not necessary, channels already block
	wg.Wait()
	sum:= <-ch + <-ch
	
	fmt.Println(s)
	fmt.Println("the sum is: " + strconv.Itoa(sum))





	fmt.Println("-----exo 3 end-----")
}