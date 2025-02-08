#1
num=int(input("Enter a number : "))
if num%5==0 and num%3==0 :
    print("The given no. is multiple of 3 and 5")
else :
    print("Given no. is not a multiple of 3 and 5")

#2
num=int(input("Enter a number : "))
if num%5==0 :
    print("The given no. is multiple of 5")
else :
    print("Given no. is not a multiple of 5")

#3
a=int(input("Enter a number : "))
b=int(input("Enter a number : "))
if a==b :
    print("Both numbers are equal")
elif a>b :
    print(a," id the greatest no")
else :
    print(b," id the greatest no")

#4
a=int(input("Enter a number : "))
b=int(input("Enter a number : "))
c=int(input("Enter a number : "))
if a>b and a>c :
    print(a," is the greatest no.")
elif b>a and b>c :
    print(b," is the greatest no.")
else :
    print(c," is the greatest no.")

#5
x=int(input("Enter coeffient of x\u00b2 : "))
y=int(input("Enter coeffient of x : "))
z=int(input("Enter the constant term : "))
disc=y*y-4*x*z
if disc<0:
    print("Quadratic equation has imaginary roots")
    im1=disc/(2*x)
    im2=-disc/(2*x)
    rm=-y*.5/x
else :
    r1=(-y+disc**0.5)/(2*x)
    r2=(-y-disc**0.5)/(2*x)
    print("Roots of eqaution are : ",r1," and ",r2)

#6
year=int(input("Enter the year : "))
if year%4==0 and year%100!=0 : 
    print(year," is a leap year")
else :
    print(year," is a not leap year")

#7
d=int(input("Enter date : "))
m=int(input("Enter month : "))
y=int(input("Enter year : "))
print("Present Date is : ",d,"-",m,"-",y)
ml=[31,29,31,30,31,30,31,31,30,31,30,31]
if y%4==0 and y%100!=0 : 
    ml[1]=28
if d>31 or d<0 or m>12:
    print("Invalid Date")
if d==ml[m-1] :
    d=1
    if m==12 :
        y=y+1
        m=1
    else :
        m=m+1
else :
    d=d+1
print("Next Date is : ",d,"-",m,"-",y)

#8
# Student Details
name = input("Enter Name: ")
roll_number = input("Enter Roll Number: ")
sap_id = input("Enter SAP ID: ")
sem = input("Enter Semester: ")
course = input("Enter Course: ")

pds=int(input("Enter marks of PDS : "))
py=int(input("Enter marks of Python : "))
chem=int(input("Enter marks of Chemistry : "))
eng=int(input("Enter marks of English : "))
phy=int(input("Enter marks of Physics : "))

# Calculating total, percentage, and CGPA
total_marks = pds+py+chem+eng+phy
percentage = total_marks / 5
cgpa = percentage / 10

# Determining grade
if 0 <= cgpa <= 3.4:
    grade = "F"
elif 3.5 <= cgpa <= 5.0:
    grade = "C+"
elif 5.1 <= cgpa <= 6.0:
    grade = "B"
elif 6.1 <= cgpa <= 7.0:
    grade = "B+"
elif 7.1 <= cgpa <= 8.0:
    grade = "A"
elif 8.1 <= cgpa <= 9.0:
    grade = "A+"
elif 9.1 <= cgpa <= 10.0:
    grade = "O (Outstanding)"
else:
    grade = "Invalid CGPA"

# Printing grade sheet
print("\nGrade Sheet")
print("Name: ", name)
print("Roll Number: ",roll_number)
print("SAP ID: ",sap_id)
print("Semester: ",sem)
print("Course: ",course)
print("\nMarks : ")
print("PDS : ",pds)
print("Python : ",py)
print("Chemistry : ",chem)
print("English : ",eng)
print("Physics : ",phy)
print("Percentage: ",percentage,"%")
print("CGPA: ",cgpa)
print("Grade: ",grade)