#include <stdio.h>
#include <stdlib.h> // itoa
#include <string.h> // strlen
#include "Array.h"

// optimized function from gpt
int isPrime(int n) {
    if (n < 2) return 0;
    if (n <= 3) return 1;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// [a, b, c, d, e]
void shift(char* str, int len) {
    int l = len - 1;
    char lastChar = str[l];
    for (int i = l; i > 0; i--) {
        str[i] = str[i-1];
    }
    str[0] = lastChar;
}

/*
for each num,
check if its a prime
then check if all its rotations are prime
if yes, add to the list and inc count correctly
*/

int main(void) {
    Array arr;
    initArray(&arr, 10);

    int current = 2;
    int solution = 0;
    while (current < 1e6) {
        char digits[10];
        sprintf(digits, "%d", current);
        int len = (int)strlen(digits);

        // if prime then check all rotations else dont
        if (isPrime(current) == 0) {
            current++;
            continue;
        }

        // num is prime, now check all the rotations
        Array temp;
        initArray(&temp, 5);
        int isRotationalPrime = 1;
        for (int i = 0; i < len; i++) {
            if (isPrime(atoi(digits)) == 0) {
                isRotationalPrime = 0;
                break;
            } else {
                // printf("%s\n", digits);
                if (arrayContains(&arr, atoi(digits)) == 0) {

                    // filter special case of all same digits
                    if (arrayContains(&temp, atoi(digits)) == 0)
                        insertArray(&temp, atoi(digits));
                }
            }
            shift(digits, len);
        }
        // checking rotations finished
        if (isRotationalPrime) {
            addArrays(&arr, &temp);
            solution += temp.used;
        }
        current++;
        freeArray(&temp);
    }

    printf("%d\n", solution); // was 55 !!!!
    printArray(&arr);
    freeArray(&arr);
    return 0;
}