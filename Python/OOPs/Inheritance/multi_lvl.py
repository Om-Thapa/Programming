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