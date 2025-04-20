# smallest multiple of numbers 1 - 20
import time

def divisible(num, i):

    if i == 0:
        return
    if num % i == 0:
        print("True for " + str(i))
        return True and divisible(num, i-1)
    elif num % i != 0:
        return False


def divisible2(num, i):
    if i <= 0:
        return True
    if num % i != 0:
        return False
    elif num % i == 0:
        return True and divisible2(num, i-1)

number = 2520
result = False
start = time.time()
while result == False:
    result = divisible2(number, 20)
    if result:
        print(number)
    number += 2
print("Compute time: " + str(time.time() - start))