#include <iostream>

int isPrime(int n) {
    if (n < 2)  return 0;
    if (n <= 3) return 1;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}
// Returns 1 if given number is pandigital
// Otherwise returns 0
int isPandigital(int num) {
    if (num < 0) return 0;

    std::string digits = std::to_string(num);
    int n = digits.length();
    int usedDigits[n];
    for (int i = 0; i < n; i++) {   // usedDigits[n] -> n+1 is present or not
        usedDigits[i] = 0;
    }

    for (char digit : digits) {     // check if each digit in the num is used only once
        int d = digit - '0';        // 2143 - 2
        if (usedDigits[d-1] == 0) { // if not seen yet, mark as seen
            usedDigits[d-1] = 1;
        } else {                    // digit was reused, return false
            return 0;
        }
    }

    return 1;
}

int main(void) {
    int largest = 0;
    int x = 1;
    while (x < 1e8) {   // < 1,000,000,000
        if (isPandigital(x) == 1 && isPrime(x) == 1) {
            largest = largest < x ? x : largest;
            // std::cout << "found new number: " << x << ", largest=" << largest << std::endl;
        }
        if (x % (int)1e5 == 0)
        std::cout << x << std::endl;
        x++;
    }
    std::cout << "largest found: " << largest << std::endl; // result = 7652413
    return 0;
}