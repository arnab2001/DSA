# Write a function that takes in an array of integers and returns a sorted version of that array. Use the insertion Sort algorithm to sort the array.

def insertionSort(array):
    for i in range(1, len(array)):
        for j in reversed(range(i)):
            if array[j+1] >= array[j]:
                pass
            else:
                array[j+1], array[j] = array[j], array[j+1]

    return array