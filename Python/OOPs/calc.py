class Calculator:
    def __init__(self, x, y):
        print("Welcome to calculator")
        self.a = x
        self.b = y
    
    def add(self):
        c = self.a + self.b
        print(f"{self.a} + {self.b} = {c}")

    def sub(self):
        c = self.a - self.b
        print(f"{self.a} - {self.b} = {c}")

    def mul(self):
        c = self.a * self.b
        print(f"{self.a} x {self.b} = {c}")

    def div(self):
        try:
            c = self.a // self.b
            print(f"{self.a} / {self.b} = {c}")
        except Exception as e:
            print(e)
    
x=int(input("Enter first number: "))
y=int(input("Enter second number: "))
Obj1 = Calculator(x, y)

Obj1.add()
Obj1.sub()
Obj1.mul()
Obj1.div()