# Write a function that takes in an array of at least three Integers and, without sorting the input array, returns a sorted array of the three largest integers in the input array.
# The function should return duplicate Integers if necessary; for example, it should return [10, 10, 12] for an input array of
# [10, 5, 9, 10, 12]

def findThreeLargestNumbers(array):
    res = [0,0,0]
    
    for i in reversed(range(3)):
        maximum = min(array)
        for j in range(len(array)):
            maximum = max(array[j],maximum)
        res[i] = maximum
        array.pop(array.index(maximum))
    return (res)       
