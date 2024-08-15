package main

import (
	"fmt"
	"log"
	"net/http"
	"strconv"
	"sync"

	"github.com/gorilla/mux"
)

type PiPrimeServer struct {
	mu    sync.Mutex
	pi    float64
	prime bool
}

func (s *PiPrimeServer) calculatePi(n int) float64 {
	s.mu.Lock()
	defer s.mu.Unlock()
	s.pi = 0.0
	for k := 0; k < n; k++ {
		s.pi += 1 / math.Pow(16, k) * (
			4 / (8 * k + 1) -
			2 / (8 * k + 4) -
			1 / (8 * k + 5) -
			1 / (8 * k + 6)
		)
	}
	return s.pi
}

func (s *PiPrimeServer) isPrime(num string) bool {
	s.mu.Lock()
	defer s.mu.Unlock()
	n, err := strconv.Atoi(num)
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

func main() {
	s := &PiPrimeServer{}
	r := mux.NewRouter()
	r.HandleFunc("/pi", func(w http.ResponseWriter, r *http.Request) {
		n, err := strconv.Atoi(r.URL.Query().Get("n"))
		if err != nil {
			http.Error(w, "Invalid n", http.StatusBadRequest)
			return
		}
		pi := s.calculatePi(n)
		fmt.Fprintf(w, "%f", pi)
	})
	r.HandleFunc("/prime", func(w http.ResponseWriter, r *http.Request) {
		num := r.URL.Query().Get("num")
		prime := s.isPrime(num)
		fmt.Fprintf(w, "%t", prime)
	})
	log.Fatal(http.ListenAndServe(":8080", r))
}
