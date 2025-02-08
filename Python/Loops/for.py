S1="Welcome Back"
for i in S1 :
    print(i)
L1=["Apple",1,'c',2.1]
for i in L1 :
    print(i)

# Continue Statement
for i in S1:
    if i=='l'or i=='b':
        continue
    print(i)

#Range Function
for i in range(10): # 0-10
    print(i)
for i in range(10,20): # 10-19
    print(i)
for i in range(20,40,3): # 20-39 with difference 3
    print(i)