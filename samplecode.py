person = {
    "name" : "Bhawish",
    "id": 12345,
    "age"  : 21, 
    "occupation":"student"
}

person["age"]  = 22 
print(person["age"])

person["Fav Football Team"] = "Georgia"
print(person)
del person["age"]
print(person)

for x in person:
    print(person[x])