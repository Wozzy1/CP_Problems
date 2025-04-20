#include <stdio.h>
#include <gmp.h>

int findLengthOfCollatzChain(long long num) {
    // mpz_t currentNumber, tempNumber;
    // mpz_init(currentNumber);
    // mpz_set_ui(currentNumber, num);
    // mpz_init(tempNumber);
    // int length = 0;

    // while (mpz_cmp_ui(currentNumber, 1) != 0) {
    //     if (mpz_mod_ui(NULL, currentNumber, 2) == 0) {      // if curr % 2 == 0
    //         mpz_cdiv_q_ui(tempNumber, currentNumber, 2);    //   temp = curr / 2
    //     } else {                                            // else if odd
    //         mpz_mul_ui(tempNumber, currentNumber, 3);       //   temp = 3 * curr
    //         mpz_add_ui(tempNumber, tempNumber, 1);          //   temp += 1
    //     }
    //     mpz_set(currentNumber, tempNumber);                 // curr = temp
    //     length++;
    // }

    int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = (3 * num) + 1;
        }
        length++;
        // printf("%lld\n", num);
    }
    return length;                                          // return length     
}

int main(void) {
    // mpz_t num;
    // mpz_init_set_str(num, "13", 10);
    int maxLength = -1;
    int maxNum = -1;
    for (int i = 1; i < 1e6; i++) {
        int x = findLengthOfCollatzChain(i);
        // printf("%d\n", x);
        if (maxLength < x) {
            maxNum = i;
            maxLength = x;
        }
    }
    printf("Number: %d\nLength: %d\n", maxNum, maxLength);

    return 0;
}