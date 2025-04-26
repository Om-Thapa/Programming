import carDetails

# Load car brand details
Porshe = carDetails.Porshe
Lamborgini = carDetails.Lamborgini
Bugatti = carDetails.Bugatti
Koenigsegg = carDetails.Koenigsegg

l = carDetails.list_Of_Brands

class Print_Cars:
    def __init__(self, carsList):
        self.l = carsList

    #Function to print all Cars along with details
    def print_Car(self):
        for k,v in self.l.items():
            print("Brand : ",k)
            for j in v.values():
                print(j)
            print()

carObject = Print_Cars(l)

gear = ('Neutral', 'First', 'Second', 'Third', 'Fourth', 'Fifth')

ch = input("Press any key ( except E ) to start the game : ").lower()
print(ch)

while ch != 'e':
    # Print car details
    carObject.print_Car()
    
    car = None
    while not car:
        car = carDetails.car_Model(**l)
    
    print("Selected Car Details:")
    print(f"Name: {car['Name']}")
    print(f"Engine: {car['Engine']}")
    print(f"Top Speed: {car['Top_Speed(in mph)']} mph")
    print(f"Power: {car['Power(in bph)']} bph")
    
    # Calculate gear speeds
    gearSpeed = carDetails.gear_Ratio(car['Top_Speed(in mph)'])
    print("Max Speed in Each Gear:")
    for i, speed in enumerate(gearSpeed):
        print(f"{gear[i]}: {speed} mph")
    
    inCar = input("Press Y to drive the car : ").lower()
    
    print("Controls:")
    print("Press W to Accelerate")
    print("Press S to Decelerate")
    print("Press E to Upshift")
    print("Press Q to Downshift")
    print("Press F to Exit Car")
    
    speed = 0
    curGear = 0
    state = input("Press the control button: ").lower()
    
    while inCar == 'y':
        incSpeed = 0
        decSpeed = 0
        
        if curGear != 0:
            incSpeed = (gearSpeed[curGear] - gearSpeed[curGear - 1]) // 3
            decSpeed = incSpeed
        else:
            decSpeed = 5
        
        if speed >= gearSpeed[5] and state != 's':
            speed = gearSpeed[5]
            print("!! Reached Top Speed !!")
        elif curGear != 0 and speed >= gearSpeed[curGear] and state == 'w':
            print("!! Touching Rev Limit !!\nChange gears")
        elif state == 'w':
            speed += incSpeed
        elif state == 's':
            speed -= decSpeed
        elif state == 'e' and curGear < 5:
            curGear += 1
        elif state == 'q' and curGear > 0:
            curGear -= 1
        elif state == 'f':
            print("Exiting the car...")
            break
        
        if speed < 0:
            speed = 0
        
        print(f"Current Speed: {speed} mph\tGear: {gear[curGear]}")
        state = input("Press control button: ").lower()
    
    print("Press any key to choose a car again, or")
    print("Press E to exit the game.")
    ch = input("Press choice: ").lower()