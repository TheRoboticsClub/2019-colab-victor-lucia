from PyQt5.QtCore import QDateTime, Qt, QTimer
from PyQt5.QtWidgets import (QApplication, QCheckBox, QComboBox, QDateTimeEdit,
        QDial, QDialog, QGridLayout, QGroupBox, QHBoxLayout, QLabel, QLineEdit,
        QProgressBar, QPushButton, QRadioButton, QScrollBar, QSizePolicy,
        QSlider, QSpinBox, QStyleFactory, QTableWidget, QTabWidget, QTextEdit,
        QVBoxLayout, QWidget)

import serial
import time, threading
import Queue as queue

global ser
ser = serial.Serial('/dev/ttyACM0', baudrate=38600, timeout=1)
              
class WidgetGallery(QDialog):
	def __init__(self, parent=None):
		super(WidgetGallery, self).__init__(parent)
					
		self.b1 = QCheckBox("Activar Ultrasonidos")
		self.b1.setChecked(False)
		self.b1.stateChanged.connect(lambda:self.btnstate(self.b1))
		self.labelus1 =QLabel("US1")
		self.us1 = QLineEdit()
		self.us1.setObjectName("US1")
		self.labelus2 =QLabel("US2")
		self.us2 = QLineEdit()
		self.us2.setObjectName("US2")
		
		self.b1.toggled.connect(self.labelus1.setEnabled)
		self.b1.toggled.connect(self.us1.setEnabled)
		self.b1.toggled.connect(self.labelus2.setEnabled)
		self.b1.toggled.connect(self.us2.setEnabled)
		
		self.b2 = QCheckBox("Activar Infrarrojos")
		self.b2.toggled.connect(lambda:self.btnstate(self.b2))
		self.labelir1 =QLabel("IR1")
		self.ir1 = QLineEdit()
		self.ir1.setObjectName("IR1")
		self.labelir2 =QLabel("IR2")
		self.ir2 = QLineEdit()
		self.ir2.setObjectName("IR2")
		
		self.b2.toggled.connect(self.labelir1.setEnabled)
		self.b2.toggled.connect(self.ir1.setEnabled)
		self.b2.toggled.connect(self.labelir2.setEnabled)
		self.b2.toggled.connect(self.ir2.setEnabled)
		
		self.b3 = QCheckBox("Activar motores")
		self.b3.toggled.connect(lambda:self.btnstate(self.b3))
		
		self.slider1 = QSlider(Qt.Vertical)
		self.slider1.setValue(0)
		self.slider1.valueChanged[int].connect(self.changeValue1)
		self.label1=QLabel("velocidad")
		
		self.slider2 = QSlider(Qt.Vertical)
		self.slider2.setValue(50)
		self.slider2.valueChanged[int].connect(self.changeValue2)
		self.label2=QLabel("direccion vertical")
	
		self.slider3 = QSlider(Qt.Horizontal)
		self.slider3.setValue(50)
		self.slider3.valueChanged[int].connect(self.changeValue3)
		self.label3=QLabel("direccion horizontal")
	
		self.b3.toggled.connect(self.slider1.setEnabled)
		self.b3.toggled.connect(self.slider2.setEnabled)
		self.b3.toggled.connect(self.slider3.setEnabled)
		
		layout = QHBoxLayout()
		layout.addWidget(self.b1)
		layout.addWidget(self.labelus1)
		layout.addWidget(self.us1)
		layout.addWidget(self.labelus2)
		layout.addWidget(self.us2)
		
		layout.addWidget(self.b2)
		layout.addWidget(self.labelir1)
		layout.addWidget(self.ir1)
		layout.addWidget(self.labelir2)
		layout.addWidget(self.ir2)
		
		layout.addWidget(self.b3)
		layout.addWidget(self.label1)
		layout.addWidget(self.slider1)
		layout.addWidget(self.label2)
		layout.addWidget(self.slider2)
		layout.addWidget(self.label3)
		layout.addWidget(self.slider3)	
		
		self.setLayout(layout)
		self.setWindowTitle("LJB")		
		
	def changeValue1(self,value):
			print("velocidad")
			print value
			
	def changeValue2(self,value):
			print("direccion vertical")
			print value

	def changeValue3(self,value):
			print("direccion horizontal")
			print value

	def btnstate(self,b):
			  if b.text() == "Activar Ultrasonidos":
				 if b.isChecked() == True:
						US = 1
						print "Ultrasonidos activado" 
						print US
						while ser == True: 
							ser.write(b'2')
							ser.write(b'U')
				 else:
						US = 0
						print"Ultrasonidos desactivado"
						print US
						while ser == True:
							ser.write(b'5')
							 
			  if b.text() == "Activar Infrarrojos":
				 if b.isChecked() == True:
						IR = 1
						print "Infrarrojos activado"
						print IR
						while ser == True:
							ser.write(b'3')
							ser.write(b'I')
				 
				 else:
						IR = 0
						print "Infrarrojos desactivado"
						print IR
						while ser == True:
							ser.write(b'6')
							
				
			  if b.text() == "Activar motores":
				  if b.isChecked() == True:
						MOT = 1
						print "Motores activados"
						print MOT
						while ser == True:
							ser.write(b'1')
							ser.write(b'F')
							
				  else: 
						MOT = 0
						print "Motores desactivados"
						print MOT
						while ser == True: 
							ser.write(b'4')
							
#================================================	
	
	def sendToArduino(sendStr):
		ser.write(sendStr)

#================================================

	def recvFromArduino():
		global startMarker, endMarker
		
		ck = ""
		x = "z"
		byteCount = -1
		
		while ord(x) != startMarker:
			x = ser.read()
			
		while ord(x) != endMarker:
			if ord(x) != startMarker: 
				ck = ck + x
				byteCount += 1
			x = ser.read()
		
		return(ck)

#================================================

	def waitForArduino():
		global startMarker, endMarker
		
		msg = ""
		while msg.find("Arduino is ready") == -1:
			
			while ser.inWaiting() == 0:
				pass
			
			msg = recvFromArduino()
			
			print msg
			print
			
#================================================

if __name__ == '__main__':

    import sys
    app = QApplication(sys.argv)
    gallery = WidgetGallery()
    gallery.show()
    sys.exit(app.exec_()) 
