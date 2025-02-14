#Looping over Item in Dictionary
Dict = {'Roll_No':'16/001',
        'Name':'Arav',
        'Age':21,
        'Course':'BTech'}

#Adding
Dict['Year']=2028

#Using membership operator
for key in Dict:
    print(key,end=' ')
print()
for val in Dict.values():
    print(val,end=' ')
print()
for key,val in Dict.items():
    print("Key : ",key,"\nValue : ",val)

#1
l3=[]
for i in range(5):
    l3.append(l[i]*l2[i])
print(l3)

#2
d={input("Enter key : "):int(input("Enter value : ")) for i in range(5)}
s=set({d.values()})
print(s)    