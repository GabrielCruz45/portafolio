s = input("Do you agree? ") # In python there are no chars and " and ' do thhe same thing!!

s = s.lower()

if s in ['y', 'yes']:
    print("Agreed!")
elif s in ['n', 'no']:
    print("Not agreed!")