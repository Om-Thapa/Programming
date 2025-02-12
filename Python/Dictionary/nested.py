#Nested Dictionary
Student={'Shiv':{'CS':93,'DS':89,'CSA':92},
         'Sadhvi':{'CS':90,'DS':85,'CSA':85},
         'Krish':{'CS':95,'DS':90,'CSA':88}}
for key,val in Student.items():
    print(key," ",val)

Credentials={'Name':'Om',
             'Sap_id':590017338,
             'Age':20,
             'University':'UPES',
             'Dept':'B_Tech',
             'Subject':{'DSA':100,'Python':100,'Maths':100,'DE':100,'COA':100}}

print(len(Credentials))
print(str(Credentials))
#print(Credentials.clear())

Cred_Copy=Credentials.copy() #Shares reference to Dictionary
Cred_Copy['Name']="Om Thapa"
print(str(Credentials))