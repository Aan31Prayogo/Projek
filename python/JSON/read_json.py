import json

file_json=open("student1.json")

data=json.loads(file_json.read())
data_=data["students"]
for Data in data_:
    print(Data["firstName"],end = " ")