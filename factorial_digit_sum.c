#include <stdio.h>
#include <gmp.h>
#include <string.h>

void factorial(mpz_t n, mpz_t result) {
    // Base case: if n == 0 or n == 1, set result = 1 and return
    if (mpz_cmp_ui(n, 0) == 0 || mpz_cmp_ui(n, 1) == 0) {
        mpz_set_ui(result, 1);
        return;
    }

    // Store n in a temporary variable to prevent modifying the original input
    mpz_t temp;
    mpz_init(temp);
    mpz_sub_ui(temp, n, 1); // temp = n - 1

    // Recursive call
    factorial(temp, result);

    // result = n * result
    mpz_mul(result, n, result);

    // Free temp
    mpz_clear(temp);
}

int main(void) {
    mpz_t total, n;
    mpz_init(total);
    mpz_init_set_ui(n, 100);

    factorial(n, total);
    gmp_printf("total: %Zd\n", total);
    char num[200];
    mpz_get_str(num, 10, total);
    int res = 0;
    for (int i = 0; i < strlen(num); i++) {
        res += num[i] - '0';
    }
    printf("%d\n", res);
    return 0;
}