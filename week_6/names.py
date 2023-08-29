import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]
name = input("Name: ")

if name in names: # in syntax searches for what precedes it in what comes after
        print("Found!")
        sys.exit(0)

print("Not found!")
sys.exit(1)