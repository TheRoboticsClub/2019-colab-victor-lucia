#Programa para obtener datos:

import serial
import time
import threading
import Queue as queue

ser = serial.Serial()
usbport = '/dev/ttyACM0'
ser = serial.Serial(usbport,9600, timeout=1)


	

while True: 	
	time.sleep(2)
	
	var = raw_input("Hola, soy Arduino. Introduce 1 para leer infrarrojos y 2 para leer ultrasonidos /n")
	
	if (var =='1'):
		
		ser.write(b'1')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
		
	if (var =='2'):	
		ser.write(b'2')
		data = ser.read(100)
		print(data.decode('ascii', errors='replace'))
		
ser.close()
		
	
	
