#include <stdio.h>
#include <string.h>
#include <gmp.h>

int main(void) {
    mpz_t num;
    mpz_init(num);
    mpz_set_ui(num, 2);
    mpz_pow_ui(num, num, 1000);
    char str[500];
    mpz_get_str(str, 10, num);
    int len = strlen(str);
    int res = 0;
    for (int i = 0; i < len; i++) {
        res += str[i] - '0';
    }
    printf("%d\n", res);
    return 0;
}