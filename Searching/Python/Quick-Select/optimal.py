# Write a function that takes in an array if distinct integers as well as an integer that returns that kth smallest integer in that array.

# The function should do this in linear time, on average.

def quickselect(array, k):
	return helper(array,0, len(array) -1,k)

def helper(array, start, end,k):
	while True:
		if start > end:
			return
		pivot, left, right = start, start + 1, end 
		while left <= right:
			if array[left] > array[pivot] and array[right] < array[pivot]:
				swap(array,left,right)
			if array[left] <= array[pivot]:
				left += 1
			if array[right] >= array[pivot]:
				right -= 1
		swap(array, pivot, right)
		if right == k-1:
			return array[right]
		elif right < k-1:
			start = right + 1
		else:
			end = right - 1


def swap(array, i, j):
	array[i], array[j] = array[j], array[i]
