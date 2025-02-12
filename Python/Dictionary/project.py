#Emojis Generator

emojis={'happy':"😀",
        'sad':"😔",
        "angry":"😡",
        'surprise':'🫨'}

message=input("Enter message \n").lower()

print(emojis[message.split(' ')[2]])