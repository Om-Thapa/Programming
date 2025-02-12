#Looping over Item in Dictionary
Dict = {'Roll_No':'16/001',
        'Name':'Arav',
        'Age':21,
        'Course':'BTech'}

#Using membership operator
for key in Dict:
    print(key,end=' ')
print()
for val in Dict.values():
    print(val,end=' ')
print()
for key,val in Dict.items():
    print("Key : ",key,"\nValue : ",val)