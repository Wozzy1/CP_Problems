#include <stdio.h>
#define MAXDEPTH 15
#define MAXDEPTH2 5

int nums[] = {
    75,
    95, 64,
    17, 47, 82, // index 4, depth 3 | left = 7, right = 8
    18, 35, 87, 10,
    20,  4, 82, 47, 65, // index 10, depth 5 | left = 15, right = 16
    19,  1, 23, 75,  3, 34,
    88,  2, 77, 73,  7, 63, 67,
    99, 65,  4, 28,  6, 16, 70, 92,
    41, 41, 26, 56, 83, 40, 80, 70, 33,
    41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
    53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
    70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
    91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
    63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
     4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23
};

int test[] = {
    3, 7, 4, 2, 4, 6, 8, 5, 9, 3
};

int traverse(int pos, int pathScore, int depth, int* max) {
    if (depth > MAXDEPTH) return pathScore;
    pathScore += nums[pos];
    if (pathScore > *max) *max = pathScore;
    printf("%d\n", pathScore);
    
    int leftScore  = traverse(pos + depth, pathScore, depth + 1, max); // left
    int rightScore = traverse(pos + depth + 1, pathScore, depth + 1, max); // right
    
    // pathScore += (leftScore < rightScore) ? rightScore : leftScore;
    
    return pathScore;
}

int main (void) {
    int max = -1;
    int x = traverse(0, 0, 1, &max);
    // for (int i = 0; i < SIZE; i++) {
    //     printf("%d ", nums[i]);
    // }
    printf("final: %d\n", max);
    return 0;
}