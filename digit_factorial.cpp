#include <iostream>
#include <string>
#include <vector>

#define N 100
std::vector<unsigned long long> fac;

void precomputeFactorials() {
    fac.resize(N + 1, 1);
    for (int i = 2; i <= N; ++i) {
        fac[i] = fac[i - 1] * i;
    }
}

unsigned long long factorial(int n) {
    return fac[n];
}


int main(void) {
    precomputeFactorials();
    int x = 0;
    unsigned long long result = 0;
    while (x < 1e6) {
        std::string numStr = std::to_string(x);
        unsigned long long sum = 0;
        for (char c : numStr) {
            sum += factorial(c - '0');
        }
        if (sum > 2 && sum == x) {
            result += sum;
            std::cout << x << ": " << sum << std::endl;
        }
        x++;
    }
    std::cout << "result: " << result << std::endl; // correct solution was 40730 = 145 + 40585
    return 0;
}