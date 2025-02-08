#1
n=int(input("Enter n : "))
i=1
f=1
for i in range(n):
    f=f*i
print("Factorial of ",n," = ",f)

#2
n=int(input("Enter n : "))
s=0
len=len(str(n))
num=n
for i in range(len):
    d=num%10
    s=s+d**3
    num=num//10
if s==n:
    print(n ," is an armstrong no")
else :
    print(n ," is not an armstrong no")

#3
a=1
b=0
i=1
c=0
n=int(input("Enter n : "))
for i in range(n):
    print(c)
    c=a+b
    a=b
    b=c

#4
n=int(input("Enter n : "))
f=True
i=2
while i in range(2,n):
    if n%i==0:
        f=False
        break
if f==False:
    print(n," is not a Prime No")
else:
    print(n," is a Prime No")

#5
n=int(input("Enter n : "))
r=0
num=n
len=len(str(n))
for i in range(len):
    print(i)
    d=num%10
    r=r*10+d
    num=num//10
if r==n:
    print(n," is Pallindrome")
else:
    print(n," is not Pallindrome")

#6
n=int(input("Enter n : "))
num=n
s=0
i=0
len=len(str(n))
for i in range(len):
    d=num%10
    s=s+d
    num=num//10
print("Sum = ",s)

#7
c=0
i=1
n=int(input("Enter n : "))
for i in range(n):
    if i%5==0 and i%7:
        print(i)
        c=c+1
print("Total number divisible by 5 and 7 = ",c)

#8
s=input("Enter a string : ")
new=s.lower()
print(new)

#9
i=2
j=2
f=0
for i in range(2,100):
    for j in range(2,i):
        if i%j==0:
            f=1
    if f==0:         
        print(i)
    j=2
    f=0

#10
n=int(input("Enter n : "))
for i in range(1,10):
    p=n*i
    print(n," x ",i," = ",p)