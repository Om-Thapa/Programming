class Parent:
    def __init__(self, name, salary, age):
        self.n = name
        self.s = salary
        self.a = age
    def disp_Name(self):
        print("Name: ", self.n)
    def _dispAge(self):
        print("Age: ", self.a)
    def __dispSalary(self):
        print("Salary: ", self.s)

class Child(Parent):
    def __init__(self, name, salary, age):
        super().__init__(name, salary, age)
    
P1 = Parent("Dil", 50000, 55)

P1.disp_Name()
P1._dispAge()
P1._Parent__dispSalary()

C1 = Child("Om", 50000, 55)
C1.disp_Name()
C1._dispAge()
C1._Parent__dispSalary()

from inherit import Manager
M = Manager()
M._Employee__display()