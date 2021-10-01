# Write a finction that takes in an array of integers and returns a sorted version of that array. Use Bubble sort algorithm to sort the array.
#  Best case Runs in O(n) Becasue, this code stops when it sees that there were no swaps made | Worst case, still runs in O(n^2)
    
def bubbleSort(array):
    count = 0
    for i in range(len(array)):
        for j in range(len(array)-i-1):
            if array[j] >= array[j+1]:
                array[j], array[j+1] = array[j+1],array[j]
                count += 1
        if count == 0:
            return array
        count = 0
    return array