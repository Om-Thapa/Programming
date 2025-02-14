#1
n=int(input("Enter n : "))
d={}
for i in range(n):
    S=input("Enter Student : ")
    C=input("Enter City : ")
    d[S]=C

city=set(d.values())
print(city)

for i in city:
    count=0
    for v in d.values():
        if v == i:
            count+=1
    print("Number of studnets in ",i," : ",count)


#2
n=int(input("Enter n : "))
d={input("Enter Movie : "):{'Year':int(input("Enter year : ")),
                            'Director':input("Enter Director name : "),
                            'Production_Cost':int(input("Enter Production Cost : ")),
                            'Earnings':int(input("Enter collection made : "))} for i in range(n)}
for k,v in d.items():
    print(k," ",v)
print("Movies before 2015 : ")
for k,v in d.items():
    if v['Year'] < 2015:
        print(k,v)

print("Movie that made profit : ")
for k,v in d.items():
    if v['Earnings']-v['Production_Cost']>0:
        print(k,v)

dir=input("Enter Director whose movie is to be printed : ")
for k,v in d.items():
    if v['Director']==dir:
        print(k,v)  