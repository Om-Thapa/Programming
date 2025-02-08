#Array
a=[1,2,0.0,'a',"too"]
print(a)

#List Operation
#<list_name>[start:end:step_size]
## -ve step size means reverse order
L1=[1,2,3,4,50]
print(L1[1:4])

#Functions
#append(),insert(),extend()

L2=[1,'Sajid',True,7.5,'Sajid']
L2.append(3)
L2.insert(2,'Om') #means insert at index 2
L2.extend(20,"hello")
print(L2)

#remove(),pop(),del
L3=['Sem_2','Hello',2.5,6,'me',2.5]
L3.remove(2.5)
L3.pop(3)
del L3[0]
print(L3)

#list()
b=list((1,2,3,4,"Abc",'A',7.5))
print(b)

#Cloning
l4=L3[2:6] #from index 2 to (6-1)

#enumerate()
for index , i in enumerate(l4):
    print(i," is at index : ", index)