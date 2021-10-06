# Write a function that takes in a sorted array of integers as well as a target Integer. The function should use the Binary Search algorithm to determine if the target integer is contained in the array and should return its index if it is, otherwise -1
# If you're unfamiliar with Binary Search, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

def binarySearch(array, target):

    left,right = 0,len(array) - 1

    while left <= right:
        mid = (left+right)//2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            left = mid + 1
        elif array[mid] > target:
            right = mid - 1
            
    return -1

        
        