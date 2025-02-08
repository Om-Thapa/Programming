#If statement
x=10
if x>0 :
    print("Hello")
    x=x+1
print("Done")

#Else-If statement
temp=int(input("Enter temperature : "))
if temp > 10 :
    print("It is bit cold outside")
elif temp > 20 :
    print("It is a good day")
elif temp > 30 :
    print("It is a hot day")
    print("Drink plenty water")
else :
    print("Enjoy")

# Weigth-convertion
w=float(input("Enter weigth : "))
u=input("Enter unit(kg/lbs) : ")
if u == "kg" :
    w=w*2.2
    print("Weigth = "+str(w)+" lbs")
else :
    w=w/2.2
    print("Weigth = "+str(w)+" kg")
