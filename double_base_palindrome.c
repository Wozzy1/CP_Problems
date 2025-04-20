#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Two pointer approach to check if palindrome. 
// Returns 1 if palindrome, otherwise returns 0
int isPalindrome(char *digits, int len) {
    int l = 0, r = len-1;
    // 1001
    while (l <= r) {
        if (digits[l] != digits[r]) {
            return 0;
        }
        l++; r--;
    }
    return 1;
}

void reverse(char *bin, int left, int right) {
    
    while (left < right) {
        char temp = bin[left];
        bin[left] = bin[right];
        bin[right] = temp;
        left++;
        right--;
    }
}

void getBinaryStr(char* str, unsigned int num) {
    int i = 0;
    while (num) {
        str[i++] = (num & 0b1) + '0';
        num >>= 1;
    }
    str[i] = '\0';      // BRUH THIS WAS THE ONLY MISSING THING. NULL TERMINATED STRINGS WOOOO
    reverse(str, 0, i-1);
}


int main(void) {
    int sum = 0;
    int curr = 0;
    while (curr <= 1e6) {
        char buf[20];
        sprintf(buf, "%d", curr);
        if (isPalindrome(buf, strlen(buf))) {
            char bin[25];
            getBinaryStr(bin, curr);
            if (isPalindrome(bin, strlen(bin))) {
                printf("%-10s | %-30s\n", buf, bin);
                sum += curr;
                // sum++;
            }
        }
        curr++;
    }
    printf("%d\n", sum);
    return 0;
}