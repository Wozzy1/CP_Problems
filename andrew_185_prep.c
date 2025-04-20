#include <stdio.h>


void changeNumber(int** arr, int* size, int newValue, int pos) {

    // Handle if pos is in bounds
    if (pos < *size) {
        arr[pos] = newValue;
    }

}

int main() {
    int** myNums = {1, 2, 3, 4, 5};
    int* size = 5;
    int newValue = 8;
    int pos = 0;

    for (int i = 0; i < *size; i++) {
        printf("%d ", myNums[i]);
    }
    printf('\n');
    
    changeNumber(myNums, &size, newValue, pos);

    for (int i = 0; i < *size; i++) {
        printf("%d ", myNums[i]);
    }
    printf('\n');
    return 0;
}

void mergeArrays(int* arr1, int* arr2, int* outputArr, int outputSize) {
    for (int i = 0; i < outputSize; i++) {
        // line 1
        outputArr[i] = arr1[i];
        // line 2
        outputArr[i+1] = arr2[i]
    }
}