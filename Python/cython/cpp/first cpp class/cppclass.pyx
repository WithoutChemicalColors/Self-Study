# distutils: language = c++
import numpy as np
cimport numpy as np

cdef class FirstClass():
    cdef int self.x0, self.y0
    cdef np.ndarray self.matrix = np.zeros([10,10], dtype=int)
    
    
    def __cinit__(self, int x0, int y0):
        self.x0 = x0
        self.y0 = y0
        
    def show(self):
        print("CALLing show function")
        print(self.matrix)
        return self.x0 + self.y0