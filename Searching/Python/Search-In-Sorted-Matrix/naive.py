# You're given a two-dimensional array (a matrix) of distinct integers and a target Integer. Each row in the matrix is sorted, and each column is also sorted; the matrix doesn't necessarily have the same height and width.
# Write a function that returns an array of the row and column Indices of the target Integer if it's contained in the matrix,
# otherwise [-1, -1]

def searchInSortedMatrix(matrix, target):
    for i in range(len(matrix)):
        if target in matrix[i]:
            for j in range(len(matrix[i])):
                if matrix[i][j] == target:
                    return [i,j]
    return [-1,-1]