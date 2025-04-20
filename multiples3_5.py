print("test")

value = 1000
total = 0
used = []
while value > 0:
    if value % 3 == 0 and value % 5 == 0 and value not in used:
        total += value
        used.append(value)
    elif value % 3 == 0 and value not in used:
        total += value
        used.append(value)
    elif value % 5 == 0 and value not in used:
        total += value
        used.append(value)
    value -= 1
print(total)