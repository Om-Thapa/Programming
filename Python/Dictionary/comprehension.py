#zip() to combine two dictionary
l1=[1,2,3,4,5]
l2=["A","B","C","D","E"]
D1={k:v for (k,v) in zip(l1,l2)}
print(D1)

my_str="welcometodictionary"
D2={k:v.upper() for (k,v) in enumerate(my_str)}
print(D2)