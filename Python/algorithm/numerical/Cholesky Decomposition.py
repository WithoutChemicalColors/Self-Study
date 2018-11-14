# -*- coding: utf-8 -*-
"""
Created on Tue Nov 13 05:05:22 2018

Cholesky Decomposition

@author: melissa
"""
A = np.array([ [ 4, 2,-1],
               [ 2, 4, 1],
               [-1, 1, 4] ], dtype=np.float)

B = np.array([ [ 16,-28,  0],
               [-28, 53, 10],
               [  0, 10, 29] ], dtype=np.float)

C = np.array([ [9/4,  3,3/2],
               [  3,25/4,7/2],
               [3/2,7/2,17/4]], dtype=np.float)

def cholesky_decomposition(matrix):
    if matrix.dtype != np.float:
        matrix = matrix.astype(np.float)
    nrows, ncols = matrix.shape
    L = np.zeros((nrows, ncols), dtype=np.float)
    # first element
    L[0,0] = np.sqrt(matrix[0,0])
    # first column (other elements)
    for r in range(1, nrows):
        L[r,0] = matrix[r,0] / L[0,0]
    
    for step in range(1, ncols):
        # L[step,step]
        SUM = 0
        for c in range(step):
            SUM += L[step,c] * L[step,c]
            
        L[step,step] = np.sqrt(matrix[step,step] - SUM)
        
        for r in range(step+1, nrows):
            SUM = 0
            for c in range(step):
                SUM += L[r,c] * L[step,c]
        L[r,step] = (matrix[r,step] - SUM)/L[step,step]
        
    return L

L = cholesky_decomposition(A)
print("L:\n", L)

L = cholesky_decomposition(B)
print("L:\n", L)
                
L = cholesky_decomposition(C)
print("L:\n", L)