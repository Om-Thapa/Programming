#1
S1=set((input("Enter fruits in Set 1 : ") for i in range(4)))
S2=set((input("Enter fruits in Set 1 : ") for i in range(3)))

S3=S1.intersection(S2)
S4=S1-S2
print("Fruits which are in both sets S1 and S2 : ",S3)
print("Fruits only in S1 but not in S2 : ",S4)
print("Fruits only in S1 but not in S2 : ",S4)

#Counting
count=0
for i in S1:
    count+=1
for i in S2:
    count+=1
print("Total Fruits : ",count)


#2
n=int(input("Enter n : "))
l=[]
for i in range(n):
    l.append(int(input("Enter number from 0-3 : ")))
C0=C1=C2=C3=0
for i in l:
    if i==0:
        C0+=1
    if i==1:
        C1+=1
    if i==2:
        C2+=1
    if i==3:
        C3+=1

print("Number of 0's : ",C0)
print("Number of 1's : ",C1)
print("Number of 2's : ",C2)
print("Number of 3's : ",C3)


#3
n=int(input("Enter n : "))
T=(int(input("Enter a numeric value : ")) for i in range(n))
sum=count=0
for i in T:
    sum+=i
    count+=1
avg=sum//count
print("Average : ",avg)

#4
Arm=[i for i in range(1000) if i==sum( int(d) ** len(str(i)) for d in str(i))]
print(Arm)
Pal=[i for i in range(1000) if str(i)==str(i)[::-1]]
print(Pal)