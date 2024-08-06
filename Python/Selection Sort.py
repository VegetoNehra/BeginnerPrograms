# Initializing the list
array = list()
array.append(54)
array.append(47)
array.append(2)
array.append(10)
array.append(60)
array.append(48)
print("Original array:", array)

# Defining the selection sort function
def selectionsort(array):
    count = len(array)
    for i in range(count):
        # Find the minimum element in remaining unsorted array
        min_index = i
        for j in range(i + 1, count):
            if array[j] < array[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        array[i], array[min_index] = array[min_index], array[i]

# Sorting the array using selection sort
selectionsort(array)
print("Sorted array:", array)
