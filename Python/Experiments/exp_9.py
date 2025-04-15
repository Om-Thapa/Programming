#1
class Student:
    def __init__(self, name, sap_id, marks):
        self.n = name
        self.id = sap_id
        self.marks = marks
    
    def Display(self):
        print(f"Name : {self.n}")
        print(f"Sap ID : {self.id}")
        print(f"Marks in :")
        print(f"Physics : {self.marks[0]} \t Mathematics : {self.marks[1]} \t Computer : {self.marks[2]}")
    
    def Marks_percentage(self):
        sum = self.marks[0] + self.marks[1] + self.marks[2]
        print(f"Percentage : {sum // 3}")
    
    def result(self):
        f = False

        for i in self.marks:
            if i < 40:
                f = True
        
        if f :
            print("Fail")
        else:
            print("Pass")
    
    def classAvg(self):
        sum = self.marks[0] + self.marks[1] + self.marks[2]
        avg = sum // 3
        print(f"Average : {avg}")

S1 = Student("Om", 17388, [80, 90, 95])
S2 = Student("May", 17389, [80, 90, 80])
S3 = Student("Par", 17387, [80, 90, 70])

S1.Display()
S2.Display()
S3.Display()

#2

#Multiple Inheritance
class Person:
    def __init__(self, name):
        self.name = name
        print(self.name)

    def property(self):
        print("My Property is worth 1Cr")

class Employee(Person):
    def property(self, Id=None):
        print("I Don't Care")

class Manager(Person, Employee):
    def __init__(self, name):
        super().__init__(name)

M1 = Manager("Om")
M1.property()

#Multi-Level Inheritance
class Person:
    def __init__(self, name):
        self.name = name
        print(self.name)

    def property(self):
        print("My Property is worth 1Cr")

class Employee(Person):
    def property(self, Id):
        print("I Don't Care")

class HR(Employee):
    def __init__(self, name):
        super().__init__(name)

H1 = HR("Om")
H1.property(10)

#3
class OverRide:
    def print(self):
        print("This is function in parent class")

class ChildOverRide(OverRide):
    def print(self):
        print("This is function in child class")

C = ChildOverRide()
C.print()

#5
class Operator:
    def __init__(self, p1, p2):
        self.Point1 = p1
        self.Point2 = p2
    
    def addPoints(self):
        print(self.Point1)
        print(self.Point2)
        p1Sum = self.Point1[0] + self.Point2[0]
        p2Sum = self.Point1[1] + self.Point2[1]
        print(f"Sum = (x = {p1Sum}, y = {p2Sum})")

O = Operator([10,20], [12, 15])
O.addPoints()