package main

import (
	"context"
	"fmt"
	"log"
	"net/http"
	"os"
	"time"

	"github.com/gorilla/mux"
	"github.com/urfave/negroni"
)

func main() {
	// Create a new router
	r := mux.NewRouter()

	// Define routes
	r.HandleFunc("/pi", piHandler).Methods("GET")
	r.HandleFunc("/prime", primeHandler).Methods("GET")

	// Create a new Negroni instance
	n := negroni.Classic()

	// Use the router as the handler
	n.UseHandler(r)

	// Start the server
	log.Fatal(http.ListenAndServe(":8080", n))
}

func piHandler(w http.ResponseWriter, r *http.Request) {
	// Calculate Pi to 50 decimal places
	pi := calculatePi(50)

	// Return the result as JSON
	json.NewEncoder(w).Encode(struct {
		Pi string `json:"pi"`
	}{
		Pi: pi,
	})
}

func primeHandler(w http.ResponseWriter, r *http.Request) {
	// Get the input number from the query string
	num := r.URL.Query().Get("num")

	// Check if the number is prime
	isPrime := isPrime(num)

	// Return the result as JSON
	json.NewEncoder(w).Encode(struct {
		IsPrime bool `json:"isPrime"`
	}{
		IsPrime: isPrime,
	})
}

func calculatePi(n int) string {
	// Calculate Pi using the Bailey-Borwein-Plouffe formula
	pi := 0.0
	for k := 0; k < n; k++ {
		pi += 1 / math.Pow(16, float64(k)) * (
			4 / (8 * float64(k) + 1) -
				2 / (8 * float64(k) + 4) -
				1 / (8 * float64(k) + 5) -
				1 / (8 * float64(k) + 6))
	}
	return fmt.Sprintf("%.50f", pi)
}

func isPrime(num string) bool {
	// Check if the number is prime using the Miller-Rabin primality test
	n, err := strconv.ParseInt(num, 10, 64)
	if err != nil {
		return false
	}
	if n < 2 {
		return false
	}
	for i := 2; i * i <= n; i++ {
		if n % i == 0 {
			return false
		}
	}
	return true
}
