package main

import (
	"crypto/ecdsa"
	"crypto/elliptic"
	"crypto/rand"
	"fmt"
	"math/big"
	"time"
)

func main() {
	p256 := elliptic.P256()
	hashed := []byte("testingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtestingtesting")
	priv, _ := ecdsa.GenerateKey(p256, rand.Reader)
	// fmt.Println(priv.PublicKey)

	start := time.Now()

	var arr [25000](*big.Int)
	for i := 0; i < 25000; i++ {
		_, s, _ := ecdsa.Sign(rand.Reader, priv, hashed)
		arr[i] = s
	}
	t := time.Now()
	elapsed := t.Sub(start)

	fmt.Println(len(arr))
	fmt.Println(elapsed)

	return
}
