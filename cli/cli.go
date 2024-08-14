package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"strconv"
	"flag"
)

func main() {
	flag.Parse()

	if flag.NArg() == 0 {
		fmt.Println("Usage: cli [command] [options]")
		return
	}

	cmd := flag.Arg(0)
	switch cmd {
	case "init":
		initCmd()
	case "run":
		runCmd()
	case "stop":
		stopCmd()
	case "status":
		statusCmd()
	default:
		fmt.Println("Unknown command:", cmd)
	}
}

func initCmd() {
	fmt.Println("Initializing...")
	// initialization code here
}

func runCmd() {
	fmt.Println("Running...")
	// running code here
}

func stopCmd() {
	fmt.Println("Stopping...")
	// stopping code here
}

func statusCmd() {
	fmt.Println("Status:")
	// status code here
}

func readLine(prompt string) string {
	fmt.Print(prompt)
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func readInt(prompt string) int {
	line := readLine(prompt)
	num, _ := strconv.Atoi(line)
	return num
}

func readFloat(prompt string) float64 {
	line := readLine(prompt)
	num, _ := strconv.ParseFloat(line, 64)
	return num
}
