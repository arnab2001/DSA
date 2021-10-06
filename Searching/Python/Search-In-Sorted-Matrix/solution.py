# You're given a two-dimensional array (a matrix) of distinct integers and a target Integer. Each row in the matrix is sorted, and each column is also sorted; the matrix doesn't necessarily have the same height and width.
# Write a function that returns an array of the row and column Indices of the target Integer if it's contained in the matrix,
# otherwise [-1, -1]

def searchInSortedMatrix(matrix, target):
    row = 0
    col = len(matrix[0]) - 1
    while row < len(matrix) and col >= 0:
        if matrix[row][col] > target:
            col -= 1
        elif matrix[row][col] < target:
            row += 1
        else:
            return [row,col]
    return [-1,-1]