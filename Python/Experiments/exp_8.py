#1
x = int(input())
y = int(input())
try:
    print(x//y)
except ZeroDivisionError as e:
    print(e)

#2
try:
    x = int(input())
    y = int(input())
    print(x//y)
except ValueError as e:
    print(e)
    print("Value Error")
except ZeroDivisionError as e:
    print(e)

#3
def range_check(a):
    if a < 100 or a > 200:
        raise ValueError("Value out of range")
try:
    x = int(input("Enter no. b/w 100 to 200 : "))
    range_check(10)
except ValueError as e:
    print(e)

#4
try:
    a = int(input("Enter no."))
    for i in range(1, 11):
        print(f'{a} x {i} = {a*i}')
except Exception as e:
    print(e)
else:
    print("I'm a software engineer")
finally:
    print("Printing Finally")

#5
def get_input():
    return int(input("Enter No. :"))

l1=[]
i=0
while i<5:
    try:
        l1.append(get_input())
        i+=1
    except ValueError:
        print("Enter a valid no.")

try:
    idx = int(input("Enter index : "))
    print(f"Value at index {idx} = {l1[idx]}")
except Exception as e:
    print(e)

#6
while True:
    try:
        x = int(input("Enter integer no. : "))
        break
    except ValueError:
        print("Enter a valid integer!")