# Write a function that takes in an array if distinct integers as well as an integer that returns that kth smallest integer in that array.

# The function should do this in linear time, on average.

def quickSelect(array, k):
    minimum = 0
    for _ in range(k):
        minimum = min(array)
        array.pop(array.index(minimum))
    return minimum
