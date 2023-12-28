def get_cents():
    cents = 0
    while cents < 0:
        cents = int(input("How many cents are you owed? "))
    return cents

def calculate_quarters(cents):
    quarters = cents // 25
    return quarters

def calculate_dimes(cents):
    dimes = cents // 10
    return dimes

def calculate_nickels(cents):
    nickels = cents // 5
    return nickels

def calculate_pennies(cents):
    pennies = cents
    return pennies

def main():
    cents = get_cents()

    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    pennies = calculate_pennies(cents)
    cents -= pennies * 1

    coins = quarters + dimes + nickels + pennies

    print(coins)

if __name__ == "__main__":
    main()