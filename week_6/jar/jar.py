def main():
    jar = Jar(12)

    jar.deposit(12)
    print(str(jar))


    jar.withdraw(11)
    print(str(jar))








































class Jar:
    def __init__(self, capacity):
        self._capacity = capacity
        if isinstance(self._capacity, int) != True:
            raise ValueError("Capacity needs to be an integer.")
        if self._capacity > 12:
            raise ValueError("A cookie jar with that capacity is not available!")
        self._cookiesInJar = 0

    def __str__(self):
        cookiez = ""

        for cookies in range(self._cookiesInJar):
            cookiez += "🍪"
        return cookiez

    def deposit(self, n):
        self._cookiesInJar += n
        if self._cookiesInJar > self._capacity:
            raise ValueError("Too many cookies! Cookie jar overflows! ;(")

    def withdraw(self, n):
        if n >= 5 and n < 8:
            print("Your cookie cravings are great!")
        elif n >= 8 and n < 10:
            print("Your cookie cravings are off the charts")
        elif n >= 10 and n < 12:
            print("You should get your cookie cravings checked with a health professional.")
        else:
            if self._cookiesInJar < 0:
                raise ValueError("Your cookie cravings are worse than cookie monsters'. If you want more than available, MAKE MOAR")
            else:
                print("Om nom nom")
        self._cookiesInJar -= n


    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._cookiesInJar



main()