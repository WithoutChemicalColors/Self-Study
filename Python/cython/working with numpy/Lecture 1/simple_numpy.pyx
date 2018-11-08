import numpy as np
cimport numpy as np
import sys

def cFirst(int rows, int cols):
    cdef np.ndarray A = np.zeros((rows,cols), dtype=np.float)
    cdef np.ndarray B = np.ones((rows, cols), dtype=np.float)
    sys.stdout.write("\do something here")
    print( np.where( A==0 )[0] )
    sys.stdout.write("\rThis is Lecture 1 example")
    print("HELLO")
    return A+B