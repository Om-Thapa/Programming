#Anonymous Functions
Addition = lambda a,b:a+b
print("5 + 10 = ",Addition(5,10))

#Passing list as parameter
Summation = lambda *args : sum(*args)
l1=[1,2,3,4,5,6,7,8]
print(Summation(l1))

#Passing Dictionary as parameter
ADD_1 = lambda **kwarg : kwarg.values()
D1 = { 'Name' : 'Om', 'Age' : 20 }
print(ADD_1( Name = 'Om', Age = 20 ))
print(ADD_1(**D1))

#Map, Filter, Reduce
