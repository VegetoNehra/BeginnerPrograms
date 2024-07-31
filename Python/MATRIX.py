# Step 1: Get the number of rows and columns from the user
rows = int(input("Enter the number of rows: "))
cols = int(input("Enter the number of columns: "))

# Step 2: Initialize the matrix
matrix = []

# Step 3: Get matrix elements from the user
print("Enter the matrix elements row by row:")

for i in range(rows):
    row = list(map(int, input().split()))
    # Check if the number of elements in the row is correct
    if len(row) != cols:
        print(f"Error: Expected {cols} elements but got {len(row)} elements. Please enter the row again.")
        row = list(map(int, input().split()))
    matrix.append(row)

# Display the matrix
print("The entered matrix is:")
for row in matrix:
    print(row)
