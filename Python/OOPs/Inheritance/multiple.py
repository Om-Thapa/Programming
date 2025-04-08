class Person:
    def __init__(self, name):
        self.name = name
        print(self.name)

    def property(self):
        print("My Property is worth 1Cr")

class Employee(Person):
    def property(self, Id=None):  # Added default value for Id to avoid errors
        print("I Don't Care")

class Manager(Person, Employee):
    def __init__(self, name):
        super().__init__(name)  # Corrected the initialization

M1 = Manager("Om")
M1.property()  # Calls the `property` method based on MRO