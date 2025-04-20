// TODO LOOKS BAD LOL
#include <iostream>
#include <vector>

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
    int multicand = 1;
    int multipler = 1;
    
    return 0;
}