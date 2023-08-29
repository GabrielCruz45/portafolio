import sys, random
from pyfiglet import Figlet

def main():
    print("Greetings, you have come to the cool ascii fonts bazaar.")

    if len(sys.argv) == 1:
        print("You have selected random font.")
        userText = input("Input text to be converted: ")
        availableFonts = figlet.getFonts()
        enumerate = 0
        for font in availableFonts:
            enumerate += 1
        randomFont = availableFonts[random.randint(0, enumerate)]
        figlet.setFont(font = randomFont)
        print(figlet.renderText(userText))
        print("Thanks for coming to the cool ascii text bazaar.\nDon't tell your friends")


    elif (sys.argv[1] == '-f' or sys.argv[1] == '-font') and type(sys.argv[2] is str):
        print("You have selected specific font.")
        userText = input("Input text to be converted: ")
        userFont = sys.argv[2]
        figlet.setFont(font = userFont)
        print(figlet.renderText(userText))
        print("Thanks for coming to the cool ascii text bazaar.\nDon't tell your friends.")

    else:
        print("\nWe have rules here.\nUsage: python script.py if you want a random font\n\n")
        print("For font of your choosing\nUsage: python script.py [-f (or --font)] [cool ascii font of choice]\n\n")
        print("Customers are giving you evil eye. It's better if you are on your way. Farewell.")
        sys.exit(1)



    sys.exit(0)




figlet = Figlet()
main()