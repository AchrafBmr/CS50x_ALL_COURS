# TODO
def get_credit_card_number():
    while True:
        try:
            credit_card_number = input("Enter a credit card number: ")
            return int(credit_card_number)
        except ValueError:
            print("Invalid input. Please enter a valid credit card number.")

def is_credit_card_valid(credit_card_number):
    digits = [int(digit) for digit in str(credit_card_number)]
    digits.reverse()

    total = 0
    for i in range(len(digits)):
        if i % 2 == 1:
            doubled = digits[i] * 2
            if doubled > 9:
                doubled = doubled // 10 + doubled % 10
            total += doubled
        else:
            total += digits[i]

    if total % 10 == 0:
        return True
    else:
        return False

def get_credit_card_type(credit_card_number):
    credit_card_prefixes = {
        "AMEX": [34, 37],
        "MASTERCARD": [51, 52, 53, 54, 55],
        "VISA": [4]
    }

    prefix = int(str(credit_card_number)[:2])

    for card_type, prefixes in credit_card_prefixes.items():
        if prefix in prefixes:
            if card_type == "VISA" and len(str(credit_card_number)) in [13, 16]:
                return card_type
            elif card_type != "VISA":
                return card_type

    return "INVALID"

def main():
    credit_card_number = get_credit_card_number()

    if is_credit_card_valid(credit_card_number):
        credit_card_type = get_credit_card_type(credit_card_number)
        print(credit_card_type)
    else:
        print("INVALID")

if __name__ == "__main__":
    main()