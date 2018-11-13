# -*- coding: utf-8 -*-
"""
Created on Tue Nov 13 03:06:52 2018

Direct Factorization (Crout) method

<note>
Dolittle :  L[i,i] = 1
Crout    :  U[i,i] = 1

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


def direct_factorize(matrix):
    nrows, ncols = matrix.shape
    L = np.zeros((nrows,ncols), dtype=np.float)
    U = np.diag([1. for _ in range(nrows)])
    # first column of L
    L[:,0] = matrix[:,0]
    # first row of U
    U[0,1:] = matrix[0,1:] / L[0,0]


    for step in range(1, ncols):
        # solve L
        for r in range(step, nrows):
            SUM = 0
            for _ in range(r):
                SUM += L[r,_] * U[_,step]
            L[r,step] = matrix[r,step] - SUM
        # solve U
        for c in range(step+1, ncols):
            SUM = 0
            for _ in range(step):
                SUM += L[step,_] * U[_,c]
            U[step,c] = ( matrix[step,c] - SUM ) / L[step,step]
            
    return L, U
    
L, U = direct_factorize(A)
print("L:\n", L, "\n\nU:\n", U, '\n')
print("L * U :\n", L @ U )
