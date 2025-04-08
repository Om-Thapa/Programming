# Note : Pass keyword is useful as a placeholder when a statement is required syntactically,
# but no code needs to be executed

# Use double underscore( __ ) to make a function private
# Use single underscore( _ ) to make a function protected

class Employee:
    def __init__(self, name, emp_id):
        self.n = name
        self.i = emp_id

    def __display(self):  # Private method
        print(f"The name of the employee: {self.n} has id: {self.i}")

# Accessing the private method using name mangling
emp = Employee("Alice", 101)
emp._Employee__display()  # Directly accessing the private method

class Manager(Employee):
    def __init__(self):
        super().__init__("Om", 17338)
        # or Employee.__init__("May", 17339)