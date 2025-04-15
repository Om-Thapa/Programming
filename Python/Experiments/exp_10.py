import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Create a Pandas Series
calories = {"day1": 420, "day2": 380, "day3": 390}
myvar = pd.Series(calories)
print(myvar)

# Create a DataFrame
data = {
  "calories": [420, 380, 390],
  "duration": [50, 40, 45]
}
df = pd.DataFrame(data)
print(df)

# Use a list of indexes
print(df.loc[[0, 1]])

# Add a list of names to give each row a name
df = pd.DataFrame(data, index=["day1", "day2", "day3"])
print(df)

# Load a CSV file into a DataFrame
try:
    df = pd.read_csv(r"C:\Users\ASUS\Desktop\Programming\Python\Experiments\data.csv")
    print(df)
except FileNotFoundError:
    print("Error: 'data.csv' file not found. Please ensure the file exists.")

#Numpy and Matplotlib
# Draw a line in a diagram from position (0,0) to position (6,250)
xpoints = np.array([0, 6])
ypoints = np.array([0, 250])
plt.plot(xpoints, ypoints)
plt.show()

# Draw a line in a diagram from position (1, 3) to position (8, 10)
xpoints = np.array([1, 8])
ypoints = np.array([3, 10])
plt.plot(xpoints, ypoints)
plt.show()

# Draw two points in the diagram, one at position (1, 3) and one at position (8, 10)
xpoints = np.array([1, 8])
ypoints = np.array([3, 10])
plt.plot(xpoints, ypoints, 'o')
plt.show()

# Create a NumPy array
arr = np.array([1, 2, 3, 4, 5])
print(arr)
print(type(arr))

a = np.array(42)
b = np.array([1, 2, 3, 4, 5])
c = np.array([[1, 2, 3], [4, 5, 6]])
d = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])

#Print the array
print(a.ndim)
print(b.ndim)
print(c.ndim)
print(d.ndim)

# Access the third element of the second array of the first array
arr = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
print(arr[0, 1, 2])

# Print the last element from the 2nd dim
arr = np.array([[1,2,3,4,5], [6,7,8,9,10]])
print('Last element from 2nd dim: ', arr[1, -1])

# Slice elements from index 1 to index 5 from the following array
arr = np.array([1, 2, 3, 4, 5, 6, 7])
print(arr[1:5])