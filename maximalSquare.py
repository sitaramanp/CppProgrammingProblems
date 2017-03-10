# Leetcode 221
# Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


def maximalSquare(self, matrix):
    """
    :type matrix: List[List[str]]
    :rtype: int
    """
    if not matrix or not matrix[0]:
        return 0
            
    intMatrix = [ [1 if char == '1' else 0 for char in row] for row in matrix]    
        
    for row in range(1, len(intMatrix)):
        for col in range(1, len(intMatrix[0])):
            if intMatrix[row][col] == 1 :
                intMatrix[row][col] = 1 + min(intMatrix[row-1][col-1], min(intMatrix[row-1][col], intMatrix[row][col-1]))
                    
    return max(max(row) for row in intMatrix) ** 2  
    
    

        