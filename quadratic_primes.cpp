#include <iostream>
#include <cstdio>
#define N 1e6


int isPrime(long long n) {
    if (n < 2) return 0;
    if (n <= 3) return 1;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

long long quad(int n, int a, int b) {
    return n * n + a * n + b;
}

int main(void) {
    int maxPrimes = 0;
    int x = 0, y = 0;
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b < 1001; b++) {
            int numPrime = 0;
            int n = 0;
            while (isPrime(quad(n, a, b)) == 1) {
                n++;
                numPrime++;
            }
            if (numPrime > 30)
                printf("Got %d for a=%d, b=%d\n", numPrime-1, a, b);
            
            if (maxPrimes < numPrime-1) {
                maxPrimes = numPrime-1;
                x = a; y = b;
            }
        }
    }
    printf("Max primes: %d, a=%d, b=%d, res=%d\n", maxPrimes, x, y, x*y); // res = -59231
    return 0;
}