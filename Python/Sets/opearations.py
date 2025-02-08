S1={1,2,3,4,5}

#Add
S1.add("Name")

#Update
S1.update([56,'One'])

#remove() and discard()
S1.remove(4)
S1.discard(4) #Doesn't throw error even if element is not present
print(S1)

A={1,2,3,4,5}
B={5,6,7,8,9,10}
C={8,11,12,13,14}

#Union()
Un=A.union(B).union(C)
print(Un)

#Intersection
InU=A.intersection_update(B)
In=A.intersection(B)
print(In)
print(InU)

#Subset, Disjoint, Superset
Val=A.issubset(B)
disVal=A.isdisjoint(C)
print(Val)
print(disVal)

#Converting a list of odd numbers into a set using list comprehension

odd_Set=set([i for i in range(1,30,2)])

print(odd_Set)

even_Tuple=tuple([i for i in range(0,50,2)])
print(even_Tuple)

for i,val in enumerate(odd_Set):
    print(i)