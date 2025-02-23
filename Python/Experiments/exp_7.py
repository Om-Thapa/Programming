c=50 
h=30
d=input("Enter values : ").split(',')

q = ( int((2*c*int(i) // h )** 0.5) for i in d )
for i in q:
    print(i,end=" ")