# Write a function that takes in an array of integers and returns a sorted version of that array. Use the Selecton Sort algorithm to sort the array.

def selectionSort(array):
    for i in range(len(array)):
        minInd = i
        for j in range(i, len(array)):
            if array[j] < array[minInd]:
                minInd = j
        array[minInd],array[i] = array[i], array[minInd]
    return array