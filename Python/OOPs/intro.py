class Person:
    name = 'Om'
    occupation = "Student"
    Salary = 0

    def info(self):
        print(f"{self.name} is a {self.occupation}")

P1 = Person()

print(P1.name,P1.occupation)

P1.info()

P1.name = "Om Thapa"
print(P1.name,P1.occupation)