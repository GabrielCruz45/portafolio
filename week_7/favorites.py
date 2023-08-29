from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite) # in the world of SQL, '?' functions as a placeholder.
#                                                                                      just like printf("", variable)

print(rows[0]["n"])