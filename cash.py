from cs50 import get_float

while True:
    dollar = get_float("Change: ")
    if dollar > 0:
        break

change = int(dollar * 100)

number = 0
holder = 0

if change // 25 != 0:
    number = change // 25
    change = change - (25 * number)

if change != 0 and change // 10 != 0:
    number = number + (change // 10)
    holder = change // 10
    change = change - (10 * holder)
    holder = 0

if change != 0 and change // 5 != 0:
    number = number + (change // 5)
    holder = change // 5
    change = change - (5 * holder)
    holder = 0

if change != 0:
    number = number + change

print(number)
