# Write a function that takes in a sorted array of integers as well as a target Integer. The function should use a variation of the Binary Search algorithm to find a range of indices in between which the target number is contained in the array and should return this range in the form of an array.

# The first number in the output array should represent the first index at which the target number is located, while the second number should represent the last index at which the target number is located. The function should return [-1, -1] if the Integer isn't contained in the array.

# If you're unfamiliar with Binary Search, we recommend watching the Conceptual Overview section of the Binary Search question's video explanation before starting to code.

def searchForRange(array, target):
	leftIdx = binarySearch(array, target, True)
	rightIdx = binarySearch(array, target, False)
	return [leftIdx, rightIdx] if leftIdx != -1 else [-1, -1]

def binarySearch(array, target, left):
	start, end = 0, len(array) - 1
	while start <= end:
		mid = (start + end) // 2
		if array[mid] == target:
			if left:
				if mid == 0 or array[mid - 1] != target:
					return mid
				else:
					end = mid - 1
			else:
				if mid == len(array) - 1 or array[mid + 1] != target:
					return mid
				else:
					start = mid + 1
					
		elif array[mid] < target:
			start = mid + 1
		else:
			end = mid - 1
			
	return -1
print(searchForRange([0, 1, 21, 33, 45, 45, 45, 45, 45, 45, 61, 71, 73],45))