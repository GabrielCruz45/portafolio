def main():
    numbers = {3 : "fizz", 5 : "buzz"}
    fizzbuzz(numbers)


def fizzbuzz(numbers):
    check = 0

    for i in range(1, 101):
        for key in numbers.keys():
            if (i % key == 0):
                print(f"{numbers[key]}", end="")
                check += 1

        if check > 0:
            check = 0
            print()
        else:
            print(i)


main()