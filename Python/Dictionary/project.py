#Create emojis
mess={"i am happy":"happy",
      "i am sad":"sad",
      "i am angry":"angry",
      "i am surprise":"surprise"}
emojis={'happy':"😀",
        'sad':"😔",
        "angry":"😡",
        'surprise':'🫨'}
message=input("Enter message \n").lower()
print(emojis[mess[message]])