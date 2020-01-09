#Programa para obtener datos:

import sys
from random import *
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *

import serial
import time
import threading
import Queue as queue


ser = serial.Serial()
usbport = '/dev/ttyACM0'
ser = serial.Serial(usbport,38400, timeout=1)


from MUI2 import Ui_MainWindow 

class Form(QMainWindow):
	def __init_(self):
		super(Form,self).__init__()

		self.ui = Ui_MainWindow()
		self.ui.setupUi(self)
		

		
def check_serial_event(self):
        self.timeout += 1
        # print (self.timeout)
        serial_thread = threading.Timer(1, self.check_serial_event)
        if ser.is_open == True:
      while True: 	
	time.sleep(2)
	
	print("Hola, soy arduino.\n")
	print("Activacion: 1) activar motores 2)activar ultrasonidos 3)activar infrarrojos 4)desactivar motores 5) desactivar ultrasonidos 6) desactivar infrarrojos\n") 
	print("Instrucciones ordenes: U) ultrasonidos I) Infrarrojos F) Delante B) Detras L) Izquierda R) Derecha S) Parar\n")
	
	var = raw_input()
		if(var == '1'):
			ser.write(b'1')
			data = ser.read(100)
			print(data.decode('ascii', errors='replace'))

		if(var == '2'):
			ser.write(b'2')
			data = ser.read(100)
			print(data.decode('ascii', errors='replace'))		
	
	elif(var =='3'):		
		ser.write(b'3')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='4'):
		ser.write(b'4')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='5'):
		ser.write(b'5')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='6'):
		ser.write(b'6')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='I'):
		ser.write(b'I')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))	
	
	elif(var =='U'):
		ser.write(b'U')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))	
	
	elif(var =='S'):
		ser.write(b'S')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='F'):
		ser.write(b'F')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='B'):
		ser.write(b'B')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='L'):
		ser.write(b'L')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='R'):
		ser.write(b'R')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
	
	elif(var =='S'):
		ser.write(b'S')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
		
ser.close()
      
      
      
      
      

        if self.timeout >= 10:
            ser.close()	
