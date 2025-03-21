import os

# os.mkdir("Data")

# for i in range(0,100):
#     os.mkdir(f"Data/Day{i+1}")

if (not os.path.exists("Data")):
    os.mkdir("Data")
for i in range(0,100):
    os.mkdir(f"Data/Day{i+1}")

# Rename

for i in range(0, 100):
    os.rename((f"Data/Day{i+1}"), (f"Data/Tutorial {i+1}"))