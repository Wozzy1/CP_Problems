# sum of squares difference

def sumSqures(i):
    if i <= 0:
        return 0
    return i * i + sumSqures(i-1)

def squareSum(i):
    sum = 0
    for j in range(i+1):
        sum += j
    return sum * sum


print(squareSum(100)-sumSqures(100))