from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules=[
    Extension("GaussElimination", ["GaussElimination.pyx"]),
    Extension("BackwordElimination", ["BackwordElimination.pyx"]),
]

setup(
  name = 'Elimination',
  cmdclass = {'build_ext': build_ext},
  ext_modules = ext_modules,
)