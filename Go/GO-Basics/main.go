package main

import(
	"fmt"
	"math"
	"math/rand"
	"strconv"
	"sync"
	//must learn file handling/reader/writers
	"nest/backmeup"
)
//declaring stuff
var x, y int = 100, 200
const pi = 3.14
//desclaring different types at once omitting types
var xy, yx = 100, false
//also can do this 
/*
type IntSlice []int
type StringMap map[string]string
type JobQueue chan int
type Grid [3][3]int
*/


func add(x int, y int) string{
	//var works inside funcs and main func
	var z int = 20
	return strconv.Itoa(x+y+z)
}
func swap(x, y int) (int, int){
	return y,x
}
//just to be clear, i would not write code like this
func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

//this is apperantly function closures or as i like to call em, compound functions
//useful because the functon remembers the variables, see better in executions
func ads(start int) func(int) int {
	var count int = start
	return func( step int) int {
		count = count + step
		return count
	}
}

//structs
type nest struct{
	si int
	sf float32
	ss string
}

//this is a method, basically a function with extra steps for structs
func (n nest) exmeth() string {
	return " " + strconv.Itoa(n.si) + " " + n.ss
}
//this is a pointer method, can change the values of a struct directly, cuz normal methods/functions only work with a copy of the values
//you call them like you call normal methods, however if you want them in func format you gotta call with &st
//also, go says don't mix pointers and values in method calls
func (n *nest) exmethp() {
	n.si = 100
	n.ss = "batman beats superman"
}
//THE MIGHTY INTERFACES
//heads up they are pretty ....... unusual
type exinter interface {
	intermeth() int
}
type interstruct struct {
	crow int
}
func (s *interstruct) intermeth() int {
	return s.crow
}
func (s *interstruct) nointermeth() int {
	return s.crow * 10
}
//and congrats interstruct is now a part of exinter, basically if they have the required methods than it's a part of it automatically
//now for interface FUNCTION, methods don't work on interfaces
func interfunc(i *exinter) int {
	return 5
}
//note that the use of pointers is not necessary, but often recommended, also methods don't care wheather you call them with pointer or value
//an empty interface implements everything

	//aight now for the new tool, generics, which are rather pretty simple
	//only two keywords to remember + you can make your own with interfaces and the |, okay so comparable and any

//comparable for when using == or !=
func eq[T comparable](x, y T) bool {
	if x==y {
		return true
	}
	return false
}
//any
//that is a linked list, i hate them but that's how you make them
type List[T any] struct {
	next *List[T]
	val  T
}

func gen[T any] (t T) string { 
	var i interface{} //chat gpt says any(t) can replace these two lines
	i = t
	switch i.(type){
	case int:
		return "an int"
	case float32:
		return "a float 32"
	case string:
		return "a string"
	default:
		return "must be a bool or something else"
	}
}


func multiboy(x int, ch chan int, cl *sync.WaitGroup) {
	for i:= 0; i<5; i++ {
		ch <- x*i
	}
	cl.Done()
}
func addboy(x int, ch chan int, cl *sync.WaitGroup) {
	for i:=100; i<=500; i = i+100 {
		ch <- x + i
	}
	cl.Done()
}

var shared int = 0
var sharedbox sync.Mutex
func addshared(cl *sync.WaitGroup){
	sharedbox.Lock()
	shared++
	sharedbox.Unlock()
	cl.Done()
}
func subshared(cl *sync.WaitGroup){
	sharedbox.Lock()
	shared--
	sharedbox.Unlock()
	cl.Done()
}




func main(){
	//short declaration thing
	k:="hello there shawty"
	a,b,c := 10, 15.6, false
	//prints
	fmt.Println(k,a,b,c, "\nalso the default values are 0, '', and false")
	fmt.Println("Blazing fast Nigger", rand.Intn(10))
	fmt.Print("print statement \n")
	fmt.Printf("yo yo nigger this is a printf shit with an f %g of the type %T \n", math.Sqrt(36), pi)

	//functions calls
	fmt.Println(add(5,6))
	xx, yy := swap(1 ,2)
	fmt.Println(xx," ", yy)
	fmt.Println(split(17))
	/*
		also you can declare functions inline
		hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	*/

	//loops and cons and stuff like that
	//for
	sum:=0
	for i:=1; i<10; i++{
		sum = sum +i
	}
	fmt.Println(sum)
	//while
	sum2:=0
	i:=0
	for i<10 {
		sum2=sum2+i
		i++
	}
	fmt.Println(sum2)
	//if
	if sum2 == sum {
		fmt.Println("equal sums")
	} else {
		fmt.Println("not equal sums")
	}
	if sum3:=sum + sum2; sum3 >80 {
		fmt.Println("special if go statement thing, very memory efficient")
	}

	//switch statements
	state:="oran"
	switch state {
	case "alger":
		fmt.Println("algerwa nigger")
	case "oran":
		fmt.Println("you like drinking")
	default:
		fmt.Println("lost nigger")
	}
	//switch based on which case is true FIRST, also known as the diagonally empty door nob
	switch {
	case sum<10:
		fmt.Println("yo sum is less than 3")
	case sum>10:
		fmt.Println("yo sum is big yo")
	}

	//the mighty pointers, i actually like these
	var so  = new(int)
	*so = 20
	fmt.Println(*so)
	fmt.Println(&so)
	fmt.Println(&sum)

	fmt.Println(sum)
	sumad := &sum
	*sumad = 69
	fmt.Println(sum)
	fmt.Println(sumad, "and the & is: ", &sumad)

	var po *int
	po = &sum
	*po = 699
	fmt.Println(*po, " ", sum)

	//structs
	st:=nest{10,25.6,"jhon cena"}
	st.si = 50
	fmt.Println(st)
	sp:=&st
	sp.ss="hikigaya"
	fmt.Println(st)
	st2:=nest{si:10} //basically we can ommit other and they go to default values
	st3:=nest{}
	fmt.Println(st2, st3)
	/*
	lots of them at once
		s := []struct {
		i int
		b bool
	}{
		{2, true},
		{3, false},
		{5, true},
		{7, true},
		{11, false},
		{13, true},
	}
	*/

	//arrays and slices
	ar:= [5]int{1,2,3,4,5} //that is an array
	//var ar [5]int = [5]int{1,2,3,4,5}
	//var as []int //that is a slice
	//be careful, slices represent parts of an arrays, so they do effect each other if you put them in the same base array
	as:= ar[1:3] //this is putting a slice with the base of ar also can [:4] or some shit also q := []int{2, 3, 5, 7, 11, 13}
	as2:=ar[2:4] //this is another also the four is not included var s []int = primes[1:4]
	as[0]=69
	fmt.Println(ar, " and the slice is ", as)
	as2[0]=96
	fmt.Println(ar, " and the slice is ", as, " and the second slice is ", as2)
	fmt.Println(len(as), cap(as), len(ar))
	// as==nil if cap and len = 0 and no underlying array
	aaa:= make([]int, 5) //var aaa []int = make([]int, 5)
	aab:= make([]int, 0, 5)
	fmt.Println(aaa, aab)
	//matrix, or slices of slices basically
	/*
		board := [][]string{
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
	}
	*/
	as = append(as,2,58,69,325)
	as = append([]int{55}, append([]int{1,2,3}, as...)...)
	//as = append([]int{1, 2, 3}, append(as, 55)...)
	fmt.Println(as)
	for i ,v := range as {
		v=v+1 //this does not change the values, v is just a copy
		fmt.Println(i, v)
	}
	for i:=0; i<len(as); i++ {
		as[i]= as[i]+1
	}
	fmt.Println(as)

	//MAPS
	/*	var m map[string]int and then again you have to make it inside the function, weird i know m = make(map [string] int) no ':' though
		var m = map [string] int {
		"deer slayer" : 10,
		"rabbit killer" : 20,
		}
	*/
	m:= make(map [string] int)
	m["deer slayer"] = 10 //making an entry
	m["pigeon rapist"] = 20
	m["deer slayer"] = 20 //updating an entry
	mapvalue, mapexists := m["deer slayer"] //checking if it exists, mapexists is true or false
	delete(m, "pigeon rapist") //deleting an entry
	fmt.Println(m, mapexists, mapvalue) //if element does not exist the value is going to be 0

	//calling function closures
	fc := ads(100) //100 is the argument passed to the "parent" function
	fmt.Println(fc(5))
	fmt.Println(fc(50))
	fmt.Println(fc(500))

	//methods
	fmt.Println(st.exmeth())
	st.exmethp()
	fmt.Println(st.exmeth())

	//interfaces
	var ic exinter = &interstruct{10}
	fmt.Println(ic.intermeth())
	fmt.Println(interfunc(&ic))

	//type assertion, only works with interfaces, part of the reason empty interfaces are helpful
	tt, okk := ic.(*interstruct) //if not pointer than just ic.(interstruct)
	fmt.Println(tt, okk)
	fmt.Println(tt.nointermeth())
	fmt.Println(ic.(*interstruct).nointermeth()) //very useful for executing methods unique to structs, since they can't be executed with the interface
	/*
	switch cases + interface = type determination
	func do(i interface{}) {
	switch v := i.(type) {
	case int:
		fmt.Printf("Twice %v is %v\n", v, v*2)
	case string:
		fmt.Printf("%q is %v bytes long\n", v, len(v))
	default:
		fmt.Printf("I don't know about type %T!\n", v)
	}
	}

	func main() {
		do(21)
		do("hello")
		do(true)
	}
	*/

	//ERROR HANDLING, the way i understand it, you gotta put error as a result of a function, like func crow() int, error
	//also recieve it like x, err := crow()
	//if err != nil {do your stuff}
	//some build in function already have error results built into them so you jsut need to receive
	//if you need to set it, they tend to do this fmt.Errorf("error message thiing")

	//calling generics
	fmt.Println(eq(5,6))
	fmt.Println(eq(5,5))
	fmt.Println(eq(5.6,6.0))
	fmt.Println(eq(5.6,6))
	fmt.Println(eq(5.6,5.6))
	fmt.Println(eq(true,false))
	fmt.Println(eq(true,true))
	fmt.Println(eq("jhon", "cena"))
	fmt.Println(eq("batman", "batman"))

	fmt.Println(gen("batman"))
	fmt.Println(gen(5))
	fmt.Println(gen(15.6))
	fmt.Println(gen(true))

	//goroutines
	//linked lists i guess and maybe some other data structure

	ch:= make(chan int) //ch := make(chan int, 100) that 100 is a buffer, like max 100 values
	var cl sync.WaitGroup
	cl.Add(2)
	go multiboy(10, ch, &cl) //they also work on methods....duh
	go addboy(20, ch, &cl)
	go func(){
		cl.Wait()
		close(ch)
	}()
	for chv := range ch {
		fmt.Println("the shit is awesome ", chv)
	}
	//alternatively value = <-ch, remember first in first out

	//as for the shared box thing sync.Mutex
	var cll sync.WaitGroup
	for i:=0; i<100; i++ {
		cll.Add(1)
		go addshared(&cll)
	}
	for i:=0; i<50; i++ {
		cll.Add(1)
		go subshared(&cll)
	}
	cll.Wait()
	fmt.Println(shared)

	//selects, basically checks if any operation of case is possible, and if it it IT EXECUTES IT like if it can do x<-trick it will do it
	//also a very cool use of the infinite for function, notice it ends on the return cuz this was supposed to be a function not a main
	/*
	for {
		select {
		case x<-tick:
			fmt.Printf("[%6s] tick.\n", elapsed())
		case y<-boom:
			fmt.Printf("[%6s] BOOM!\n", elapsed())
			return
		default:
			fmt.Printf("[%6s]     .\n", elapsed())
			time.Sleep(50 * time.Millisecond)
		}
	}
	*/

	//next up packages, mods and data structurs, also fiber+htmx, have fun with it man
	backmeup.Pbmu()
	fmt.Println(backmeup.AAA)
	if jj, err:=fmt.Println(backmeup.AAA); err!=nil {
		fmt.Println("yeah man works", jj)
	}








}