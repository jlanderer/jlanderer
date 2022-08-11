# -*- coding: utf-8 -*-
"""
Created on Mon Aug  8 16:11:41 2022

@author: Jacob Landerer
"""
from vpython import *
import numpy as np
Bulb = sphere(radius = 1.25,color = color.white,opacity = .3)
Cyl = cylinder(radius = .65,color = color.white, opacity = .3,length = 6)
Mercury = sphere(radius = 1, color = color.red)
MercuryColumn = cylinder(radius = .45, length = 6, color = color.red)

while True:
    for myTemp in np.linspace(1,6,100):
        rate(25)
        MercuryColumn.length = myTemp
    for myTemp in np.linspace(6,1,100):
        rate(25)
        MercuryColumn.length = myTemp