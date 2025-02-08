sec_num=14
guess_count=3
counter=0
while counter<guess_count:
    num=int(input("Enter the guess number : "))
    if num==sec_num:
        print("Success")
        break
    else :
        counter=counter+1
        print("Try Again")
