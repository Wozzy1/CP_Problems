#include <iostream>

bool is_prime(long long n);
int main() {

    int count {0};
    long long n {1LL};
    while (count < 10001) {
        if (is_prime(n)) {
            count++;
        }
        n++;
    }

    std::cout << n-1 << std::endl;
    return 0;
}


bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;  // 2 is the only even prime
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
