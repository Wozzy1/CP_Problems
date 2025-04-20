#include <stdio.h>
#include <gmp.h>
#define N 1000

void computeSeries(mpz_t total) {
    mpz_t num;
    mpz_init(num);
    for (int i = 1; i <= N; i++) {
        mpz_set_ui(num, i);
        mpz_pow_ui(num, num, i);
        mpz_add(total, total, num);
    }
    mpz_clear(num);
}


int main(void) {
    mpz_t total;
    mpz_init(total);
    computeSeries(total);
    gmp_printf("%Zd\n", total);
    mpz_clear(total);
    return 0;
}