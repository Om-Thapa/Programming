#This is a Car Simulator Game

#Cars Details
Porshe = { 1 : {'Name' : '911 GT3 RS', 'Engine' : '4L Inline', 'Top_Speed(in mph)' : 180, 'Power(in bph)' : 518},
           2 : {'Name' : '918 Spyder', 'Engine' : '4.6L V8', 'Top_Speed(in mph)' : 211, 'Power(in bph)' : 887},
           3 : {'Name' : 'Panamera', 'Engine' : '2.9L V6', 'Top_Speed(in mph)' : 168, 'Power(in bph)' : 348}}

Lamborgini = { 1 : {'Name' : 'Aventador SVJ', 'Engine' : '6.5L V12', 'Top_Speed(in mph)' :217 , 'Power(in bph)' : 770},
               2 : {'Name' : 'Revuelto', 'Engine' : '6.5L V12', 'Top_Speed(in mph)' : 210, 'Power(in bph)' : 1015},
               3 : {'Name' : 'Huracan', 'Engine' : '5.2L V10', 'Top_Speed(in mph)' : 201, 'Power(in bph)' : 610}}

Bugatti = { 1 : {'Name' : 'Chiron', 'Engine' : '8.0L W16', 'Top_Speed(in mph)' : 261, 'Power(in bph)' : 1479},
            2 : {'Name' : 'Tourbillon', 'Engine' : '8.3L V16', 'Top_Speed(in mph)' : 236, 'Power(in bph)' : 1800},
            3 : {'Name' : 'Veyron', 'Engine' : '8.0L W16', 'Top_Speed(in mph)' : 267, 'Power(in bph)' : 987}}

Koenigsegg = { 1 : {'Name' : 'Jesko', 'Engine' : '5.0L V8', 'Top_Speed(in mph)' : 310, 'Power(in bph)' : 1600},
               2 : {'Name' : 'Regera', 'Engine' : '5.0L V8', 'Top_Speed(in mph)' : 251, 'Power(in bph)' : 1500},
               3 : {'Name' : 'Agera RS', 'Engine' : '5.0L V8', 'Top_Speed(in mph)' : 278, 'Power(in bph)' : 1160}}

l = { 'Bugatti' : Bugatti, 'Porshe' : Porshe, 'Lamborgini' : Lamborgini, 'Koenigsegg' : Koenigsegg}

gear = ('Neutral', 'First', 'Second', 'Third', 'Fourth', 'Fifth')

#Function to print all Cars along with details
def print_Car():
    for k,v in l.items():
        print("Brand : ",k)
        for j in v.values():
            print(j)
        print()

#Function to calculate max speed at each gears
def gear_Ratio( speed ):
    gears = [ 0, int(0.4*speed), int((0.4+.24)*speed), int((.4+.24+.144)*speed), int((.4+.24+.144+.0864)*speed), speed]
    return gears

#Function to find the desired car
def car_Model():

    brand = input("Choice a car Brand : ")
    model = input("Choice a car Model : ")
    
    f = False
    for k,v in l.items():
        if brand == k:
            brand = v
            f = True
    if f == False:
        print("! Car Not Found !")
        print("Choose Again")
        return 0
    
    for i in brand.values():
        if model == i['Name']:
            return i
    print("! Car Not Found !")
    print("Choose Again")
    return 0

ch = input("Press any key ( except E ) to start the game : ").lower()
print(ch)

while ch != 'e':
    
    print_Car()
    car = 0
    while car == 0:
        car = car_Model()
    
    print("Top speed : ",car['Top_Speed(in mph)'])
    gearSpeed = gear_Ratio(car['Top_Speed(in mph)'])
    print("Max Speed in each Gears : ")
    print(gearSpeed)

    inCar = input("Press Y to drive the car : ").lower()
    
    print("Controls : ")
    print("Press W to Accelerate")
    print("Press S to Deccelerate")
    print("Press E to Upshift")
    print("Press Q to Downshift")
    state = input("Press the control button : ").lower()
    speed = 0
    curGear = 0

    while inCar == 'y':
        incSpeed = 0
        decSpeed = 0

        if curGear != 0:
            incSpeed = (gearSpeed[curGear] - gearSpeed[curGear - 1]) //3
            decSpeed = incSpeed
        else :
            decSpeed = 5

        if speed >= gearSpeed[5] and state != 's':
            speed = gearSpeed[5]
            print("!! Reached Top Speed !!")
        elif curGear != 0 and speed >= gearSpeed[curGear] and state == 'w':
            print("!! Touching Rev Limit !!\nChange gears")
        elif state == 'w' :
            speed += incSpeed
        elif state == 's' :
            speed -= decSpeed
        elif state == 'e' and curGear == 5:
            print("Driving at Max Gear")
        elif state == 'e' :
            curGear += 1
        elif state == 'q' and curGear == 0:
            print("Already at neutral")
        elif state == 'q' :
            curGear -= 1
        
        if speed <= 0:
            speed=0

        if speed == 0 and curGear == 0 and state != 'w':
            speed = 0
            print("Press Y to continue ")
            print("Press F to exit car ")
            inCar = input("Press Choice : ").lower()
            if inCar == 'f':
                break
        
        print("Current Speed : ",speed,end='\t\t')
        print("Gear : ",gear[curGear])
        state = input("Press control button : ").lower()
        
    print("Press any key to choice a car again, or")
    print("Press E to exit game")
    ch = input("Press choice : ").lower()