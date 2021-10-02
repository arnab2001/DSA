# Write a function that takes in a sorted array of distinct integers as well as a target Integer. The caveat is that the integers in the array have been shifted by some amount; In other words, they've been moved to the left or to the right by one or more positions. For example, [1, 2, 3, 4] might have turned into [3, 4, 1, 2].

# The function should use a variation of the Binary Search algorithm to determine if the target Integer is contained in the array and should return its index if it is, otherwise -1.

# If you're unfamiliar with Binary Search, we recommend watching the Conceptual Overview section of the Binary Search question's video explanation before starting to code.

# <------------ Runs in O(logn) ---------------->

def shiftedBinarySearch(array, target):

    left,right = 0, len(array)-1
    
    while left <= right:
        mid = (left + right )// 2
        
        if array[mid] == target:
            return mid
        
        if array[mid] <= array[right]:
            if target > array[mid] and target <= array[right]:
                left = mid + 1
            else:
                right = mid - 1
        elif array[mid] > array[left]:
            if target >= array[left] and target < array[mid]:
                right = mid - 1
            else:
                left = mid + 1
        
    return -1
        
        

print(shiftedBinarySearch([45, 61, 71, 72, 73, 0, 1, 21, 33, 37],33))