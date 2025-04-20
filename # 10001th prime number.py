# 10001th prime number

def primeCount():
    count = 0
    n = 1
    while count <= 10001:
        if is_prime(n):
            count += 1
        n+=1

    return n

def is_prime(n):
    if n < 2:
        return False
    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True
print(primeCount())