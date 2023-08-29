from cs50 import get_string

name = get_string("What is your name? ")
print("Hello, " + name) #    + == concatenation
print("Hello,", name)
print(f"Hello, {name}") # f == format string