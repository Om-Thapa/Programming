#Making a Dictionary
Dict = {'Roll_No':'16/001',
        'Name':'Arav',
        'Age':21,
        'Course':'BTech'}

print("Name : ",Dict['Name'])

#Modify or Add an item
Dict['Uni']='UPES'
Dict['Dept']='CSE'
print(Dict)

#Deleting an item
print(Dict.pop('Dept')) #Deletes Dept item
print(Dict.popitem()) #Deletes a random item
print(Dict.pop('Aggr',10)) #Return default value 10 but doesn't add it
#print(Dict.pop('Aggr')) Generates error