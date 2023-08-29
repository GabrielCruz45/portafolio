phrase = 'This is CS50'
print(f"{phrase}")

letter_only = True if input("Gimme: ").isalpha() else False
print(f"{letter_only}")

# only 2 loops in python; ++ does not exist in python ;( +=

for x in range(0, 420, 69):
    print(f"{x}")

# Arrays; in python they are called lists and are not fixed in size; also its easy to splice things in and out
# Declaring it its pretty straight foward
nums = [] # empty list
nums1 = list() # also empty list
nums2 = [1, 2, 3, 4] # explicitly declared list
nums3 = [x for x in range(500)] #
for i in range(500):
    print(f"{nums3[i]}")
# CHEQUEA ESTO^^^^^^^^^^^
# print(nums3)
nums4 = [1, 2, 3, 4]
nums4.append(5) # Puts 5 at the end of the array
nums4.insert(5, 6) # Inserts 6 into the 5th position
nums4[len(nums4):] = [7] # This is how you would attach a list at the end of another list
print(nums4)


# Tuples = ordered immutable set of data
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809),
    ("garieL Super Saiyan 4", 6969)
]
# Tuples are iterable as well
for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))

# Dictionaries
# key: value, key : value, etc
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetables": 11,
    "buffalo chicken": 12,
}

pizzas["cheese"] = 8 # cheese is now associated with 8 instead of 9
# boolean expressions are possible
# if pizzas["vegetables"] < 12:
#     # do something
pizzas["bacon"] = 14 # add new key:value pair
pizzas["garieL"] = 69
for pie, price in pizzas.items(): # You need to add items in order to iterate w/ the values as well
    print(f"A whole {pie} pizza costs ${price}")

def square(x):
    return x**2

print(square(69))

# object.method()

class Student():
    def __init__(self, name, id): # the self paramater is to indicate which object you are using inside that method!!
        self.name = name
        slef.id = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))

jane = Student("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()