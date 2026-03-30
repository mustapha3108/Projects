package mylib

import (
	"bufio"
    "fmt"
    "os"
    "strings"
	"strconv"
	"sync"
)

type message struct {
	sender *process
	receiver *process
	content string
}

type process struct {
	id int
	ch chan *message
	pred *process
	succ *process
}

func send(proc *process, wg *sync.WaitGroup) {
	mess := <-proc.ch
	if mess.receiver != proc {
		proc.succ.ch <- mess
		wg.Add(1)
		go send(proc.succ, wg)
		wg.Done()
	}else {
		fmt.Println("server says message recieved in server from client: " + strconv.Itoa(mess.receiver.id) + " " + strconv.Itoa(mess.sender.id) + " " + mess.content)
		ack := message{
			sender: mess.receiver,
			receiver: mess.sender,
			content: "server ack",
		}
		proc.succ.ch <- &ack
		wg.Add(1)
		go receive(proc.succ, wg)
		wg.Done()
	}
}

func receive(proc *process, wg *sync.WaitGroup) {
	mess := <-proc.ch
	if mess.receiver != proc {
		proc.succ.ch <- mess
		wg.Add(1)
		go receive(proc.succ, wg)
		wg.Done()
	} else {
		fmt.Println("client says ack received from server : " + strconv.Itoa(mess.receiver.id) + " " + strconv.Itoa(mess.sender.id) + " " + mess.content)
		wg.Done()
	}
}

func Exo5() {
	fmt.Println("-----exo 5 start-----")

	/*
	Ecrire un algorithme distribue compose de n processus diriges evenement connecte avec
	une topologie anneau chacun connais son successeur et predecesseur, le but de
	l'algorithme est d'implementer un client serveur sur l'anneau, il y a un seul processus qui
	joue le role du serveur et les autres clients. quand un client souhaite un service il envoie
	un message a son successeur qui le relai sur l'anneau jusqu'au serveur la reponse du
	serveur aussi suivre le chemin de l'anneau. utiliser les goroutines, les channels et
	waitGroups.
	*/
	
	machines := [10]process{}
	for i := 0; i < 10; i++ {
		p:= i-1
		s:= i+1
		if p == -1 {p=9}
		if s == 10 {s=0}
		machines[i] = process{
			id: i,
			ch : make(chan *message, 5),
			pred : &machines[p],
			succ: &machines[s],
		}
	}

	reader := bufio.NewReader(os.Stdin)

		fmt.Println("type info: machine-id, message don't forget the ',' . machine id from 1 to 9")
		input, _ := reader.ReadString('\n')
        input = strings.TrimSpace(input)

		params := strings.Split(input, ",")
		mess:= params[1]
		id, err := strconv.Atoi(params[0])
		if err!= nil || id<1 || id>9 {fmt.Println("kill me")}

		var wg sync.WaitGroup
		wg.Add(1)
        newMessage := message{
			sender: &machines[id],
			receiver: &machines[0],
			content: mess,
		}

		machines[id].succ.ch <- &newMessage
		go send(machines[id].succ, &wg)

	wg.Wait()
	fmt.Println("-----exo 5 finished-----")
}