# -*- coding: utf-8 -*-
from sympy import Symbol
from sympy import lambdify
"""
Created on Mon May 31 16:54:07 2021
Calculates the derivative of x(x-1) at a user-given x value.
Can also calculate functional values.
@author: Jacob Landerer
"""
print("Given the function f(x) = x(x-1), you can evaluate values of it or its derivative.")
print("For functional values, type f(#).\nFor derivatives, type fPrime(#)")
x = Symbol('x')
f = x*(x-1)
fPrime = f.diff(x)
f = lambdify(x,f)
fPrime = lambdify(x,fPrime)
"""
x must be made into a symbol if we are to define and manipulate a function
that uses it. The Lambdify command allows the computer to easily, quickly,
and efficiently do some math with the function f and its variable x,
namely differentiation.
We can evaluate values of the function and its derivative at any x value.
"""