def BackwordElimination( M, int nrows, int ncols):
    cdef float pivot
    cdef float ratio
    cdef int step
    cdef int row
    cdef int col
    
    for step in range(ncols-1, 0, -1):
        pivot = M[step][step]
        
        for row in range(step-1, -1, -1):
            ratio = M[row][step] / pivot
            M[row][step] = 0
            
            for col in range(step-1, -1, -1):
                M[row][col] = M[row][col] - ratio*M[step][col]
    
    return M