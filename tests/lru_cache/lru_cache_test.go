package lrucache_test

import (
	. "ds/cmd/lru_cache"
	"testing"
)

func TestLRU(t *testing.T) {
    l := NewLRU(5)

    l.Put(1, 10)
    l.Put(2, 20)
    l.Put(3, 30)
    l.Put(4, 40)
    l.Put(5, 50)

    if l.Get(3) != 30 {
        t.Fatalf("Get return expected %d, got %d", 30, l.Get(3))
    }

    l.Put(6, 60)

    if l.Get(1) != -1 {
        t.Fatalf("Get return expected %d, got %d", -1, l.Get(1))
    }
}
