#include <stdio.h>
#include <gmp.h>
#include <string.h>
#define SIZE 10000


mpz_t f[SIZE];  // Global array for memoization

void init_memoization() {
    for (int i = 0; i < SIZE; i++) {
        mpz_init(f[i]);
        mpz_set_si(f[i], -1);  // Mark as uncomputed
    }
    mpz_set_ui(f[0], 0);
    mpz_set_ui(f[1], 1);
}

void clear_memoization() {
    for (int i = 0; i < SIZE; i++) {
        mpz_clear(f[i]);
    }
}

void fib(mpz_t result, unsigned long long n) {
    if (mpz_cmp_si(f[n], -1) != 0) {  // If already computed
        mpz_set(result, f[n]);
        return;
    }

    mpz_t temp1, temp2;
    mpz_init(temp1);
    mpz_init(temp2);

    fib(temp1, n - 1);
    fib(temp2, n - 2);
    mpz_add(f[n], temp1, temp2);
    mpz_set(result, f[n]);

    mpz_clear(temp1);
    mpz_clear(temp2);
}

// unsigned long long fib(unsigned long long n) {
//     if (n <= 1) {
//         return n; 
//     } else {
//         return fib(n-1) + fib(n-2);
//     }
// }


int main (void) {
    
    // mpz_t f[size];
    // mpz_init_set_ui(f[0], 1);
    // mpz_init_set_ui(f[1], 1);
    // for (int i = 2; i < size; i++) {
    //     mpz_init_set_ui(f[i], 0);
    // }
    init_memoization();
    mpz_t num;
    mpz_init_set_ui(num, 0);
    int ok = 0;
    char numStr[1100];
    int x = 1;
    while (!ok) {
        fib(num, x++);
        printf("%d\n", x);

        mpz_get_str(numStr, 10, num);
        if (strlen(numStr) == 1000) {
            ok = !ok;
        }
    }
    gmp_printf("%Zd\n", num);
    printf("%d\n", strlen(numStr));

    clear_memoization();
    return 0;
}