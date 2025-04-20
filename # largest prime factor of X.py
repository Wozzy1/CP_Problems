# largest prime factor of X
# 600851475143
import math

def largestPrimeFactor(num):

    return

def allPrimeFactors(num):

    while num % 2 == 0:
        num /= 2
        print(2)

    for i in range(3, int(math.sqrt(num))+1, 2):
        while num % i == 0:
            print(str(i) + " ")
            num /= i

allPrimeFactors(600851475143)