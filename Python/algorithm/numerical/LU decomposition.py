# -*- coding: utf-8 -*-
"""
Created on Sun Nov 11 15:35:08 2018

@author: melissa
"""

A = np.array([ [ 1, 4, 3],
               [ 2, 7, 9],
               [ 5, 8,-2] ], dtype=np.float)

B = np.array([ [2, 7, 5],
               [6,20,10],
               [4, 3, 0] ], dtype=np.float)
    
C = np.array([ [ 1, 1, 2],
               [-1, 0, 2],
               [ 3, 2,-1] ], dtype=np.float)
    
D = np.array([ [ 2, 2,-1],
               [ 6, 8, 1],
               [ 4, 2, 7]], dtype=np.float)

def LU( mat ):
    matrix = mat.copy()
    # Basic parameters
    nrows, ncols = matrix.shape
    # initialize scale vector
    sv = np.max(abs(matrix), axis=1)
    # initialize row vector
    rv = np.array([ i for i in range(nrows) ])
    
    for step in range(nrows-1):
        # decide use which row as pivot
        pivot_id = np.argmax( abs(matrix[rv[step:],step])/sv[step:] ) + step
        rv[[step,pivot_id]] = rv[[pivot_id,step]]
        # pivot
        pivot = matrix[rv[step], step]
        print(matrix)
        print(rv)
        for row in range(step+1, nrows):
            ratio = matrix[rv[row], step] / pivot
            matrix[rv[row], step] = ratio
            
            for col in range(step+1, ncols):
                matrix[rv[row], col] = matrix[rv[row], col] - matrix[rv[step], col] * ratio
        
    
    # print(matrix)
    # L ?
    # U <- matrix with some point set as 0
    L = np.diag([ 1. for i in range(nrows)])
    for row in range(nrows):
        for col in range(row):
            L[row, col] = matrix[rv[row], col];
            matrix[rv[row], col] = 0.;  
    # U ?
    U = matrix.copy()
    for row in range(nrows):
        U[row,:] = matrix[rv[row],:]
    # rearrange l and U
                
    return L, U

        
L, U = LU(A)