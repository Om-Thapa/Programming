a=10+\
10\
+20
print(a)
b=input("Enter a number ")
c=float(input("Enter a number "))
#Note that input function takes input as string
print(b)
print(c)

#Multi line string (use ''' or """")
a='''hello this is multi
line statement and 
it is a test statemnet'''
print(a)

#Escape Sequence
b="Welcome \nto \npython"
print(b)

c="Hello "
print(c*5)

#Length of string
print(len(b))

print(b[0])
#Printing first 5 characters of b
print(b[0:5])
#Printing last characters of b
print(b[-1])
print(b[-6:])
print(b[-8:10])