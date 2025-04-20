#include <stdio.h>

int is_perfect(int a, int b, int c) {
    if ((a < b && b < c) && ((a*a + b*b) == c*c) && (a + b + c == 1000)) return 1; 
    else return 0;
}

int main() {
    for (int i = 0; i < 1000; i++) {
        for (int j = i+1; j < 1000; j++) {
            for (int k = j+1; k < 1000; k++) {
                if (is_perfect(i, j, k)) printf("%d * %d * %d = %d\n", i, j, k, i * j * k);
            }
        }
    }
    return 0;
}


