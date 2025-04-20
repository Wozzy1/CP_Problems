// #include <stdio.h>
// #include <math.h>
// int findDivisors(int n)
// {   
//     int count = 0;
//     int iters = ((int) pow(n, 0.5)) + 1;
//     for (int i = 1; i < iters; i++) {
//         if (n % i == 0) {
//             // printf("%d ",i);
//             count += 2;  // i and (n / i)
//             if (i * i == n) count--;  // If i is a perfect square, don't double count
//         }
//     }
//     return count;
// }

// int main(void) {
//     int result = 0, num = 1;

//     while (result < 500) {
//         result = findDivisors(num);
//         num += num+1;
//     }
//     printf("%d\n", num);
// }

#include <stdio.h>
#include <math.h>

int findDivisors(int n) {   
    int count = 0;
    int iters = ((int) sqrt(n)) + 1;
    for (int i = 1; i < iters; i++) {
        if (n % i == 0) {
            count += 2;  // i and (n / i)
            if (i * i == n) count--;  // If perfect square, adjust count
        }
    }
    return count;
}

int main(void) {
    int result = 0, n = 1, triangle = 0;

    while (result < 500) {
        triangle += n;  // Compute triangle number
        result = findDivisors(triangle);
        n++;  // Move to the next natural number
    }
    printf("%d\n", triangle);
}
