#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array.h"

int isPrime(int n) {
    if (n < 2) return 0;
    if (n <= 3) return 1;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// checks if left to right truncated variations of the number are prime
// as well as right to left
// Returns 1 if all are prime, otherwise returns 0
int checkVariations(int num) {
    char str[25];
    sprintf(str, "%d", num);
    int len = strlen(str);

    // check if string of number with offset is prime
    // doesn't modify the string
    for (int i = 0; i < len; i++) {     // had an off by one error here smh
        int truncatedNum = atoi(str + i);
        // if (num == 29)
        // printf("%d | %s\n", truncatedNum, str);
        if (isPrime(truncatedNum) == 0) {
            // printf("Failed in first loop\n");
            return 0;   // one variation is not prime, so exit
        }
    }
    if (num == 29)
    printf("%s\n", str);

    // repeatedly move the end of string one index closer to beginning
    // then check if prime
    // this does modify the (local) char array 
    for (int i = len-1; i > 0; i--) {
        (str + i)[0] = '\0';
        int truncatedNum = atoi(str);
        // if (num == 29)
        // printf("%d | %s\n", truncatedNum, str);
        if (isPrime(truncatedNum) == 0) {
            // printf("Failed in second loop\n");
            return 0;   // one variation is not prime, so exit
        }
    }
    // if we made it through both forloops, all variations are prime
    return 1;
}

int main(void) {
    Array arr;
    initArray(&arr, 11);
    int sum = 0;
    int count = 0;
    int curr = 8;

    while (count < 11 & curr < 1e6) {
        if (isPrime(curr) == 1) {
            // printf("Checking %d\n", curr);
            int res = checkVariations(curr);
            if (res) {
                count++;
                sum += curr;
                printf("found %d\n", curr);
                insertArray(&arr, curr);
            }
        }
        curr++;
        if (curr % 1000000 == 0) printf("--> %d\n", curr);
    }
    printf("%d and %d\n", count, curr);
    printf("%d\n", sum);
    printArray(&arr);
    freeArray(&arr);
    return 0;
}