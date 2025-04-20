# even fibonacci numbers sum

def fibo(num):
    if num <= 1:
        return num
    else:
        return fibo(num-1) + fibo(num-2)


value = 0
index = 0
total = 0
while value <= 4000000:
    value = fibo(index)
    index += 1
    if value % 2 == 0:
        total += value
print(total)

# 14930351

# index = 0
# total = 0
# currValue = 0
# while currValue < 4000000:
#     currValue = fibo(index)
#     if currValue % 2 == 0:
#         total += currValue
#     index +=1
# print(total)