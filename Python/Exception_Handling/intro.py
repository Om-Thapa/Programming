#Exception is the top hierarchy class that contains all the types of errors, eg ValueError, OverflowError, etc
#Else block executes if no error occurs, Finally block executes irrespective of the error
#raise is use to create own exception
try:
    a = int(input("Enter no."))
    for i in range(1, 11):
        print(f'{a} x {i} = {a*i}')
except OverflowError:
    print("OverFlow Error")
except ValueError:
    print("Check your input")
except Exception:
    print("Check your input")

print("Welcome to Uttarakhand")


print("Enter two no. :")
x = int(input())
y = int(input())
try:
    print(x//y)
except ValueError as e:
    print(e)
    print("Value Error")
except ZeroDivisionError as e:
    print(e)

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

x = int(input("Enter no. b/w 10 to 30 : "))
if x<10 or x>30:
    raise ValueError("please check the range of input")