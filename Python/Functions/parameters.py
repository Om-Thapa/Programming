#*args : To take list, tuple, set as parameters , **kwargs : To take Dictionary as parameter

def data(*args):
    for i in args:
        print(i)
data(12,'Om',20)
l=['May', 17339, 19]
data(*l)

def bio_data(**kwargs):
    for key,val in kwargs.items():
        print(key,val)
bio_data(Name='Om',Sap=17338,Age=20)
d={'Name':'OM','SAP':17338,'Age':20}
bio_data(**d)

def func1(a, *l1, **d1):
    j=0
    for i in d1.keys():
        d1[i]=l1[j]
        j+=1
    for i in d1.items():
        print(i)
    print(a)
func1( *l, 3, **d)