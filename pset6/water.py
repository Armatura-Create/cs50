import cs50

print("Minutes: ")
minute = cs50.get_int()

while minute < 0:
    print("Minutes: ", end="")
    minute = cs50.get_int()

result = minute*12

print("Bottle: ", result)