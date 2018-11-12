# -*- coding: utf-8 -*-
"""
Created on Mon Nov 12 22:41:43 2018

@author: melissa
"""

"""
Secant Method
Use central difference ( numerical difference )
to replace differentiation
"""
func = lambda x: x**3 + 2*x**2 - 3*x - 1
func2 = lambda x: x**2

def _central_difference(func, x, delta=1e-5):
    half = delta/2
    return ( func(x+half) - func(x-half) ) / delta

def Secant_Method(func, x_now, x_old, tolerance=1e-5):
    judge = 1
    stopper = 0
    while judge > tolerance:
        stopper += 1
        if stopper >= 1e10:
            print("stopper")
            break;
        x_new = x_now - func(x_now) * (x_now - x_old) \
                         / ( func(x_now) - func(x_old) )
        judge = abs( x_new - x_now )
        x_now, x_old = x_new, x_now
    return x_now
        
ans = Secant_Method(func, 2, 1)
ans2 = Secant_Method(func2, 2, 1)
print(ans)
print(ans2)

X = np.linspace(-2, 2)
Y = func(X)

plt.plot(X, Y)
