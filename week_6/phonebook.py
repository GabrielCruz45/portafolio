import csv

with open("phonebook.csv", "a") as file:

    name = input("Name: ")
    number = input("Number: ")

    #based on the first line in the csv,
    # the DictWriter is going to figue=re out where to put that data
    writer = csv.DictWriter(file, fieldnames = ["name", "number"])
    writer.writerow({"name" : name, "number" : number})