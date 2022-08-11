from vpython import *
import numpy as np
import serial
Num = 98
DataAcq = serial.Serial('COM10', 115200)
tempBulb = sphere(radius=1.25, color=color.white, opacity=0, pos=vector(-3, 0, 0))
tempCyl = cylinder(radius=.65, color=color.white, opacity=.3, length=6, axis=vector(0, 1, 0), pos=vector(-3, 0, 0))
Mercury = sphere(radius=1, color=color.red, axis=vector(0, 1, 0), pos=vector(-3, 0, 0))
MercuryColumn = cylinder(radius=.45, length=5, color=color.red, axis=vector(0, 1, 0), pos=vector(-3, 0, 0))
TempTitle = text(text='Temperature in *C', align='center', pos=vector(-6, 8, 0))
Barometer = cylinder(radius=3, color=color.blue, axis=vector(0, 0, 1), pos=vector(5, 2, -.5), length=1)
BarometerTitle = text(text='Pressure in kPa', align='center', pos=vector(5, 8, 0))
TickL = Barometer.radius/5
TickT = 2*np.pi*Barometer.radius/250
TickW = Barometer.length*1.2
for theta in np.linspace(5*np.pi/4, -np.pi/4, 21):
    Tick = box(align='center', pos=vector((Barometer.radius-TickL/2)*np.cos(theta)+5, (Barometer.radius-(TickL/2))*np.sin(theta)+2, 0), axis=vector(Barometer.radius*np.cos(theta), Barometer.radius*np.sin(theta), 0), length=TickL, width=TickW, height=TickT, color=color.white)
for i in np.linspace(5*np.pi/4, -np.pi/4, 4):
        Numlabel = text(height=Barometer.radius/5, align='center', text=str(Num), pos=vector(Barometer.radius*1.25*np.cos(i)+5, Barometer.radius*1.25*np.sin(i)+2, 0), color=color.green)
        Num = Num + 1
presHub = cylinder(radius=Barometer.radius/10, color=color.red, length=.5, pos=vector(5, 2, .5), axis=vector(0, 0, 1))
pressArrow = arrow(axis=vector(0, 0, 0), color=color.red, shaftwidth=.25, length=2.7, pos=vector(5, 2, .5))
while True:
    rate(5000)
    if DataAcq.inWaiting() == 0:
        pass
    Data = DataAcq.readline()
    Data = str(Data, 'utf-8')
    Data = Data.strip('\r\n')  # Get data
    DataArr = Data.split(",")

    Temp = float(DataArr[0])  # *C
    AdjustedTemp = Temp-23
    LiveTemp = label(text=str(Temp), align='center', pos=vector(-3, 7, 0))

    Press = float(DataArr[1])  # ~101325 Pa
    kPa = round(Press / 1000, 1)     # adjust data for scaling w/ graphics
    MercuryColumn.length = AdjustedTemp
    LivePres = label(text=str(kPa), align='center', pos=vector(5, 7, 0))
    kPa = (kPa-98)/3  # Puts pressure on a 0-1 scale such that cos and sin don't complain abt their args
    #pressArrow.axis = vector(2.7*np.cos(kPa)+5*np.pi/4, 2.7*np.sin(kPa)+5*np.pi/4, 0)
