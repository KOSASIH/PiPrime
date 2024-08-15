package main

import (
	"fmt"
	"math/big"
	"net"
)

type PiPrimeNetwork struct {
	listener net.Listener
}

func NewPiPrimeNetwork(port int) (*PiPrimeNetwork, error) {
	listener, err := net.Listen("tcp", fmt.Sprintf(":%d", port))
	if err != nil {
		return nil, err
	}
	return &PiPrimeNetwork{listener: listener}, nil
}

func (n *PiPrimeNetwork) Listen() error {
	for {
		conn, err := n.listener.Accept()
		if err != nil {
			return err
		}
		go n.handleConnection(conn)
	}
}

func (n *PiPrimeNetwork) handleConnection(conn net.Conn) {
	defer conn.Close()
	var input big.Int
	err := binary.Read(conn, binary.LittleEndian, &input)
	if err != nil {
		fmt.Println(err)
		return
	}
	output, err := isPrime(input)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = binary.Write(conn, binary.LittleEndian, output)
	if err != nil {
		fmt.Println(err)
		return
	}
}

func isPrime(n big.Int) (bool, error) {
	if n.BitLen() < 2 {
		return false, nil
	}
	for i := big.NewInt(2); i.Cmp(n) <= 0; i.Add(i, big.NewInt(1)) {
		if n.Mod(n, i).Cmp(big.NewInt(0)) == 0 {
			return false, nil
		}
	}
	return true, nil
}

func main() {
	network, err := NewPiPrimeNetwork(8080)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = network.Listen()
	if err != nil {
		fmt.Println(err)
		return
	}
}
