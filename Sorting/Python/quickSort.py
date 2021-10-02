# Write a function that takes in an array of integers and returns a sorted version of that array. Use Bubble sort algorithm to sort the array.

def quickSort(array):
    helper (array, 0, len(array) -1 )
    return array

def helper(array, start, end):
    if start >= end:
        return
    pivot, left, right = start, start+1, end
    
    while left <= right:
        if array[left] > array[pivot] and array[right] < array[pivot]:
            swap(array, left, right)
        if array[left] <= array[pivot]:
            left += 1
        if array[right] >= array[pivot]:
            right -= 1
    
    swap(array, right, pivot)
    isLeftSmaller = right - 1 - start < end - (right - 1)
    
    if isLeftSmaller:
        helper(array,start,right -1)
        helper(array,right + 1,end)
    else:
        helper(array,right + 1,end)
        helper(array,start,right -1)
        
        
def swap(array, i, j):
	array[i], array[j] = array[j], array[i]