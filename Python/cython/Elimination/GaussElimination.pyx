def GaussElimination(M, int nrows, int ncols):
    cdef float pivot
    cdef float ratio
    cdef int row
    cdef int col
    cdef int step
    # 變數宣告要分開 不然會掛掉...
    for step in range(0, ncols-1):    
        pivot = M[step][step]
        
        for row in range(step+1, nrows):
            ratio = M[row][step]/pivot
            M[row][step] = 0

            for col in range(step+1, ncols):
                M[row][col] = M[row][col] - ratio*M[step][col]
                       
    return M