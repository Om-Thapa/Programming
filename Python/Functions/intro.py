#Types: 1. predefine, 2. User-Defined, 3. Anonymous Functions

#Checks even or odd
def func1(a):
    '''This Function checks whether a no is even or odd'''
    if a%2==0:
        print(a," is Even")
    else:
        print(a," is Odd")

func1(332)
print(func1.__doc__)

var1=10
def func2():
    var1=5
    return var1
print(func2())
print(var1)

#Recursion
def fibo(n):
    if n==0 or n==1:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)
print('0 ',end='')
for i in range(20):
    print(fibo(i),end=' ')