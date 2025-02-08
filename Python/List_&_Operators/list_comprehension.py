#Insert even no.s in a list
list1=[]
for i in range(0,50,2):
    list1.append(i)
list2=[i for i in range(50) if i%2==0 ]
print(list1)
print(list2)

#Divisible by 6
list3=[i for i in range(80) if i%2==0 and i%3==0]
print(list3)

#iddigit() and isalpha()
st="One 1 Two 2 Three 3 Four 4"
list4=[int(i) for i in st if i.isdigit()]
print(list4)

#Armstrong Number
Arm=[i for i in range(10,10000) if i==sum( int(d) ** len(str(i)) for d in str(i)) ]
print(Arm)

#LCM of list of elements
n=int(input("Enter no of element : "))
nums=[ int(input("Enter no : ")) for i in range(n)]

p=1
m=max(nums[0],nums[1])
for i in range(len(nums)):
    p*=nums[i]
    m=max(m,nums[i])
i=p
lcm=p

while i>=m:
    f=True
    for j in range(len(nums)):
        if i%nums[j]!=0:
            f=False
    if f==True:
        lcm=i
    i-=1

print("LCM : ",lcm)