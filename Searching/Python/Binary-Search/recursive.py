# Write a function that takes in a sorted array of integers as well as a target Integer. The function should use the Binary Search algorithm to determine if the target integer is contained in the array and should return its index if it is, otherwise -1
# If you're unfamiliar with Binary Search, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

def binarySearch(array, target):
    print(array)
    left,right = 0,len(array) - 1
    mid = (left+right)//2
    print(mid)
    if array[mid] == target:
        return mid
    elif array[mid] < target:
        binarySearch((array[mid+1:]),target)
    elif array[mid] > target:
        binarySearch((array[:mid]),target)
    return -1

print(binarySearch([0, 1, 21, 33, 45, 45, 61, 71, 72, 73],33))