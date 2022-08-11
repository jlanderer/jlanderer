# -*- coding: utf-8 -*-
"""
Created on Thu Jul 28 14:13:19 2022

@author: Jacob Landerer
"""

import serial
import numpy as np
from drawnow import *
SerialComm = serial.Serial('COM10',115200)
plt.close('all')
plt.figure();
plt.ion(); # Tells python you want to plot live data
plt.show(); 
DataArray = np.array([])
