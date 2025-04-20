#include <stdio.h>
#include "Array.h"

int main() {
    Array arr;
    initArray(&arr, 10);

    for (int i = 0; i < 2000000; i++) {
        if (is_prime(i)) {
            insertArray(&arr, i);
        }
    }

    long sum = 0;
    for (int i = 0; i < arr.used; i++) {
        sum += arr.array[i];
    }

    printf("%ld\n", sum);
    return 0;
}

int is_prime(long long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;  // 2 is the only even prime
    if (n % 2 == 0) return 0;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}


