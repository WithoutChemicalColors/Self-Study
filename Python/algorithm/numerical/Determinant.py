# -*- coding: utf-8 -*-
"""
Created on Mon Nov 12 23:14:30 2018

@author: melissa
"""
A = np.array([ [ 1, 0, 4, 1],
               [-2, 1,-3, 2],
               [ 0, 0, 0, 2], 
               [ 3, 2, 1,-1] ])

B = np.array([ [ 1, 2],
               [ 3, 4]  ])

def det(matrix):
    """
    determinant of a matrix recursively
    """
    SUM = 0
    if matrix.shape[0] > 1:
        for i, col in enumerate(matrix[0]):
            sub_matrix = np.delete(matrix, 0, axis=0)
            sub_matrix = np.delete(sub_matrix, i, axis=1)
            SUM += (-1)**i * col * det(sub_matrix)
        return SUM
    else:
        return matrix[0,0]
    
ans = det(A)
ans2 = det(B)
print(ans, ans2)