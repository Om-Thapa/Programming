#1
x=9
y=7
add=x+y
sub=x-y
mul=x*y
div=x/y
print('Add = {}, Sub = {}, Mul = {}, Div = {}'.format(add,sub,mul,div))

#2
r=int(input("Enter radius of Circle : "))
a=r*r*3.14
print("Area = {}".format(a))

#3
x=4
y=3
z=(x+y)*(x+y)
print(z)

#4
b=float(input("Enter Base of Triangle : "))
p=float(input("Enter Perpendicular of Triangle : "))
h=(b*b + p*p) ** 0.5
print("Hypotenuse = {}".format(h))

#5
p=int(input("Enter principal : "))
r=float(input("Enter rate : "))
t=int(input("Enter time : "))
print("S.I = {}".format(p*r*t/100))

#6
S1=int(input("Enter first side : "))
S2=int(input("Enter second side : "))
S3=int(input("Enter third side : "))
sem=(S1+S2+S3)/2
area=(sem(sem-S1)(sem-S2)(sem-S3)) ** 0.5
print("Area of triangle = ",area)

#7
s=int(input('Enter total seconds : '))
hour=s//(60*60)
rs=s%(60*60)
min=rs//60
rs=rs%60
print("Hour : {}, Minutes : {}, Second : {}".format(hour,min,rs))

#8
x=3
y=5
print("Before Swap : x={} y={}".format(x,y))
x=x+y
y=x-y
x=x-y
print("After Swap : x={} y={}".format(x,y))

#9
n=int(input("Enter n : "))
sum=n*(n+1)/2
print("Sum = ",sum)

#10
print("A\tB\tA & B\tA | B\tA ^ B")
for A in [0, 1]:
    for B in [0, 1]:
        print(f"{A}\t{B}\t{A & B}\t{A | B}\t{A ^ B}")

#11
num = int(input("Enter a number: "))
shift = int(input("Enter number of shifts: "))
left_shift = num << shift
right_shift = num >> shift
print(f"Number after {shift} left shifts: {left_shift}")
print(f"Number after {shift} right shifts: {right_shift}")

#12
sequence = (10, 20, 56, 78, 89)
num = int(input("Enter a number: "))
if num in sequence:
    print(f"{num} is in the sequence {sequence}")
else:
    print(f"{num} is not in the sequence {sequence}")

#13
string = input("Enter a string: ")
char = input("Enter a character to check: ")
if char in string:
    print(f"'{char}' is in the string '{string}'")
else:
    print(f"'{char}' is not in the string '{string}'")