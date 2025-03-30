#__init__ keyword is use to create a contructor

class Employee:
    def __init__(self, n, s):
        print(f"Hey, How you doing {n}....")
        self.name = n
        self.salary = s
    def info(self):
        print(f"{self.name} has a salary {self.salary}")

E1 = Employee("Om", 1000)
E2 = Employee("May", 2000)
E3 = Employee("Par", 3000)

E1.info()
E2.info()
E3.info()