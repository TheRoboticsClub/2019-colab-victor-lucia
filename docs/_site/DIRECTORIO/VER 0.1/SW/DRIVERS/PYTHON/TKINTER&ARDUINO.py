import serial, time 

from Tkinter import *
import tkMessageBox

ser = serial.Serial()
usbport = '/dev/ttyUSB0'
ser = serial.Serial(usbport,9600, timeout=1)





#arduino = serial.Serial(port, 9600)
#time.sleep(2)
#rawString = arduino.readline()
#print(rawString)
#arduino.close()

#def delante():
	
	
#def detras():
	
	
#def izquierda():
	
	
#def derecha():

#def parar():

ventana =Tk() 	

var1 = IntVar()
var2 = IntVar()
var3 = IntVar()
var4 = IntVar()
var5 = IntVar()

a= Checkbutton(ventana, text="Delante", variable=var1)
a.pack()
if var1== 1: print("var1 on")
b= Checkbutton(ventana, text="Detras", variable=var2)
b.pack()
if var2== 1: print("var2 on")
c= Checkbutton(ventana, text="Izquierda", variable=var3)
c.pack()
d= Checkbutton(ventana, text="Derecha", variable=var4)
d.pack()
e= Checkbutton(ventana, text="Parar", variable= var5)
e.pack()

mainloop()

