#1
n=int(input("Enter n : "))
i=1
f=1
while i<=n :
    f=f*i
    i=i+1
print("Factorial of ",n," = ",f)

#2
n=int(input("Enter n : "))
s=0
num=n
while num>0 :
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
while i<=n :
    print(c)
    c=a+b
    a=b
    b=c
    i=i+1

#4
n=int(input("Enter n : "))
f=0
i=2
while i<n:
    if n%i==0:
        f=1
        break
    i=i+1
if f==1:
    print(n," is not a Prime No")
else:
    print(n," is a Prime No")

#5
n=int(input("Enter n : "))
r=0
num=n
while num>0:
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
while num>0:
    d=num%10
    s=s+d
    num=num//10
print("Sum = ",s)

#7
c=0
i=1
while i<=10:
    if i%5==0 and i%7:
        print(i)
        c=c+1
print("Total number = ",c)

#8
s=input("Enter a string : ")
new=s.lower()
print(new)

#9
i=2
j=2
f=0
while i<=100:
    while j<i:
        if i%j==0:
            f=1
        j=j+1
    if f==0:         
        print(i)
    i=i+1
    j=2
    f=0

#10
n=int(input("Enter n : "))
i=1
while i<=10:
    p=n*i
    print(n," x ",i," = ",p)
