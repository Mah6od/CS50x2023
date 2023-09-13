while True:
    user_input = input("Change Owed: ")
    try:
        change = float(user_input)
        if change > 0:
            break
    except ValueError:
        print("Invalid input. Please enter a positive number.")

cents = round(change * 100)

coins = 0

while cents > 0:
    # initialize a quarter
    if cents >= 25:
        cents -= 25
        coins += 1

    # initialize dimes
    elif cents >= 10:
        cents -= 10
        coins += 1

    # initialize nickels
    elif cents >= 5:
        cents -= 5
        coins += 1

    # initialize pennies
    else:
        cents -= 1
        coins += 1

# print
print(coins)