from distutils.core import setup
from Cython.Build import cythonize
import numpy

setup(
    ext_modules = cythonize("simple_numpy.pyx"),
    include_dirs=[numpy.get_include()]
)