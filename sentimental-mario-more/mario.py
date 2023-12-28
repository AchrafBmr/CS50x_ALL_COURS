# TODO
def main():
    n = 0
    while n < 1 or n > 8:
        n = int(input("height: "))

    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end="")

        for j in range(i + 1):
            print("#", end="")

        print("  ", end="")

        for j in range(i + 1):
            print("#", end="")

        print()

if __name__ == "__main__":
    main()