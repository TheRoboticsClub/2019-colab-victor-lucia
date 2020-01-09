# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MOTORESULTRASONIDOSINFRARROJOS.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets

import serial
import time
import threading
import Queue as queue

global ser
ser = serial.Serial('/dev/ttyACM0', baudrate=9600, timeout=10,
                    parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE,
                    bytesize=serial.EIGHTBITS
                    )

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        
        self.DIRECCIONHORIZONTAL = QtWidgets.QSlider(self.centralwidget)
        self.DIRECCIONHORIZONTAL.setGeometry(QtCore.QRect(270, 490, 160, 16))
        self.DIRECCIONHORIZONTAL.setOrientation(QtCore.Qt.Horizontal)
        self.DIRECCIONHORIZONTAL.setObjectName("DIRECCIONHORIZONTAL")
        self.label = QtWidgets.QLabel(self.centralwidget)
   
        self.label.setGeometry(QtCore.QRect(30, 340, 91, 17))
        self.label.setObjectName("label")
        self.IR1 = QtWidgets.QLineEdit(self.centralwidget)
        self.IR1.setGeometry(QtCore.QRect(80, 70, 113, 25))
        self.IR1.setObjectName("IR1")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(70, 110, 131, 17))
        self.label_2.setObjectName("label_2")
        self.IR2 = QtWidgets.QLineEdit(self.centralwidget)
        self.IR2.setGeometry(QtCore.QRect(270, 70, 113, 25))
        self.IR2.setObjectName("IR2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(280, 110, 111, 20))
        self.label_3.setObjectName("label_3")
        self.VELOCIDAD_2 = QtWidgets.QSlider(self.centralwidget)
        self.VELOCIDAD_2.setGeometry(QtCore.QRect(70, 360, 16, 160))
        self.VELOCIDAD_2.setOrientation(QtCore.Qt.Vertical)
        self.VELOCIDAD_2.setObjectName("VELOCIDAD_2")
        self.US1 = QtWidgets.QLineEdit(self.centralwidget)
        self.US1.setGeometry(QtCore.QRect(80, 170, 113, 25))
        self.US1.setObjectName("US1")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(80, 210, 111, 20))
        self.label_4.setObjectName("label_4")
        self.US2 = QtWidgets.QLineEdit(self.centralwidget)
        self.US2.setGeometry(QtCore.QRect(270, 170, 113, 25))
        self.US2.setObjectName("US2")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(270, 210, 111, 17))
        self.label_5.setObjectName("label_5")
        self.ACTIR = QtWidgets.QCheckBox(self.centralwidget)
        self.ACTIR.setGeometry(QtCore.QRect(500, 70, 191, 23))
        self.ACTIR.setObjectName("ACTIR")
        self.ACTUS = QtWidgets.QCheckBox(self.centralwidget)
        self.ACTUS.setGeometry(QtCore.QRect(500, 170, 161, 23))
        self.ACTUS.setObjectName("ACTUS")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(250, 510, 71, 20))
        self.label_6.setObjectName("label_6")
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setGeometry(QtCore.QRect(403, 510, 61, 20))
        self.label_7.setObjectName("label_7")
        self.label_8 = QtWidgets.QLabel(self.centralwidget)
        self.label_8.setGeometry(QtCore.QRect(280, 450, 151, 20))
        self.label_8.setObjectName("label_8")
        self.label_9 = QtWidgets.QLabel(self.centralwidget)
        self.label_9.setGeometry(QtCore.QRect(100, 360, 54, 17))
        self.label_9.setObjectName("label_9")
        self.label_10 = QtWidgets.QLabel(self.centralwidget)
        self.label_10.setGeometry(QtCore.QRect(100, 510, 54, 17))
        self.label_10.setObjectName("label_10")
        self.DIRECCIONVERTICAL = QtWidgets.QSlider(self.centralwidget)
        self.DIRECCIONVERTICAL.setGeometry(QtCore.QRect(610, 360, 16, 160))
        self.DIRECCIONVERTICAL.setOrientation(QtCore.Qt.Vertical)
        self.DIRECCIONVERTICAL.setObjectName("DIRECCIONVERTICAL")
        self.label_11 = QtWidgets.QLabel(self.centralwidget)
        self.label_11.setGeometry(QtCore.QRect(560, 330, 121, 20))
        self.label_11.setObjectName("label_11")
        self.label_12 = QtWidgets.QLabel(self.centralwidget)
        self.label_12.setGeometry(QtCore.QRect(630, 350, 81, 17))
        self.label_12.setObjectName("label_12")
        self.label_13 = QtWidgets.QLabel(self.centralwidget)
        self.label_13.setGeometry(QtCore.QRect(640, 510, 54, 17))
        self.label_13.setObjectName("label_13")
        self.ACTMOT = QtWidgets.QCheckBox(self.centralwidget)
        self.ACTMOT.setGeometry(QtCore.QRect(500, 290, 161, 23))
        self.ACTMOT.setObjectName("ACTMOT")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        self.menuLJB = QtWidgets.QMenu(self.menubar)
        self.menuLJB.setObjectName("menuLJB")
        MainWindow.setMenuBar(self.menubar)
        self.menubar.addAction(self.menuLJB.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "   VELOCIDAD"))
        self.label_2.setText(_translate("MainWindow", "     INFRARROJOS 1"))
        self.label_3.setText(_translate("MainWindow", "INFRARROJOS 2"))
        self.label_4.setText(_translate("MainWindow", "ULTRASONIDOS 1"))
        self.label_5.setText(_translate("MainWindow", "ULTRASONIDOS 2"))
        self.ACTIR.setText(_translate("MainWindow", "ACTIVAR INFRARROJOS"))
        self.ACTUS.setText(_translate("MainWindow", "ACTIVAR ULTRASONIDOS"))
        self.label_6.setText(_translate("MainWindow", "IZQUIERDA"))
        self.label_7.setText(_translate("MainWindow", "DERECHA"))
        self.label_8.setText(_translate("MainWindow", "DIRECCIÓN HORIZONTAL"))
        self.label_9.setText(_translate("MainWindow", "MÁXIMO"))
        self.label_10.setText(_translate("MainWindow", "MÍNIMO"))
        self.label_11.setText(_translate("MainWindow", "DIRECCIÓN VERTICAL"))
        self.label_12.setText(_translate("MainWindow", "DELANTE"))
        self.label_13.setText(_translate("MainWindow", "DETRÁS"))
        self.ACTMOT.setText(_translate("MainWindow", "ACTIVAR MOTORES"))
        self.menuLJB.setTitle(_translate("MainWindow", "LJB"))

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

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
   

