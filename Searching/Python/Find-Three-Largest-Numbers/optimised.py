# Write a function that takes in an array of at least three Integers and, without sorting the input array, returns a sorted array of the three largest integers in the input array.
# The function should return duplicate Integers if necessary; for example, it should return [10, 10, 12] for an input array of
# [10, 5, 9, 10, 12]

def findThreeLargestNumbers(array):
    inf = float('-inf')
    x, y, z = inf, inf, inf

    for num in array:
        if num > x:
            x, y, z = num, x, y
        elif num > y:
            y,z = num,y
        elif num > z:
            z = num
            
    return [z,y,x]
