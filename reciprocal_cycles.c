#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>
#define D 1000
#define MAX_LENGTH 200

int l(char* out, mp_exp_t* e, int d_) {
    mpf_t d, a;
    mpf_init(d);
    mpf_init_set_ui(a, 1);

    mpf_div_ui(d, a, d_);
    // gmp_printf("%.25Ff\n", d);
    
    mpf_get_str(out, e, 10, 50, d);
    
    mpf_clear(d);
    mpf_clear(a);
    return 0;
}

void printDigits(int* arr) {
    printf("[");
    for (int i = 0; i < 9; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[9]);
}

void getStr(char* full, char* str, mp_exp_t e) {
    if (e <= 0) {
        // If exponent is negative or zero, we need to pad with zeros
        for (int j = 0; j < -e; j++) {
            sprintf(full + j, "%c", '0');
        }
        sprintf(full -e, "%s", str);
    } // there is no e > 0
    // printf("%s\n", full);
}

// returns length of matching substring or -1 if not repeating
int compareHalves(char* str, int len) {
    char str1[len/2];
    char str2[len/2+1];
    strncpy(str1, str, len/2);
    str1[len/2+1] = '\0';
    strcpy(str2, str+(len/2));
    // printf("given: %s\n", str);
    // printf("str1 : %s\n", str1);
    // printf("str2 : %s\n", str2);
    return strcmp(str1, str2);
}

int allEven(int* digits) {
    for (int j = 0; j < 10; j++) {      // iterate over all digits
        if (digits[j] == 0) continue;   // skip nonpresent digits

        if (digits[j] % 2 == 1) {       // if any odd, return false
            return 0;
        }
    }
    return 1;                           // if no odd, return true
}

// digits - int[10]
// returns result of compare halves if we find a repeating substring
int buildSet(char* str, int* digits) {
    int l = strlen(str);
    if (l < 1) {
        printf("empty string\n");
        return -1;
    }
    for (int i = 0; i < l; i++) {   // iterate over each character until 
                                    // index where all digit count are even
        digits[str[i]-'0']++;   
        // printf("%d\n", str[i]-'0');
        int isAllEven = allEven(digits);

        if (isAllEven) {  // initiate check of string and its two halves
            char newStr[MAX_LENGTH];
            strncpy(newStr, str, i+1);  // note: THIS DOESNT NULL TERMINATE
            newStr[i+1] = '\0';
            // printf("newStr: %s\n", newStr);
            // printDigits(digits);
            // printf("index found: %d\n", i); // 142857142857142857143
            if (compareHalves(newStr, (int)strlen(newStr)) == 0) {
                return i/2+1;   // len of full string / 2 + 1
            }
        }
    }
    return -1;
}

int main(void) {
    // convert decimal to string
    // find longest recurring substring
    mpf_set_default_prec(128);
    int longest = 0;
    int res = -1;
    for (int i = 2; i <= D; i++) {
        // if (i != 3) continue;
        char str[MAX_LENGTH];
        char full[MAX_LENGTH];
        // sprintf(full, "%s", "0.");
        mp_exp_t e;
        l(str, &e, i);
        getStr(full, str, e);
        int digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        printf("%s\n", full);
        int x = buildSet(full, digits);
        if (x > 0) {
            printf("i : %d : length = %d\n", i, x);
            if (x > longest) {
                longest = x;
                res = i;
            }
        }
    }
    printf("res: %d\n", res);
    return 0;
}