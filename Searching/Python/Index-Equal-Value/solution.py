# Write a fuction that takes in a sorted attay of distinct integers and returns hte first index in the array that is equal to the value at that index. In other words, your function should return the minimum incex where index == array[index]
# If there is no such index, your function should return -1

# Approach : Run Normal Binary Search, Even after finding the value which is equal to the index, update right to mid -1 and continue searching to the left, this will ensure that you get the minimum possible value


def indexEqualsValue(array):
    answer = -1
    left, right = 0, len(array) - 1
    while left <= right:
        mid = (left + right)//2
        if array[mid] == mid:
            answer = mid
            right = mid - 1

        elif array[mid] < mid:
            left = mid + 1
        else:
            right = mid - 1
    return answer 
    


print(indexEqualsValue([-5, -3, 0, 3, 4, 5, 9]))
