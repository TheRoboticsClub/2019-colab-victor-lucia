# PyQT Boton
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot 

def window():
	app = QApplication(sys.argv)
	widget = QWidget()
	
	button1= QPushButton(widget)
	button1.setText("Boton1")
	button1.move(64,32)
	button1.clicked.connect(button1_clicked)
	
	button2= QPushButton(widget)
	button2.setText("Boton2")
	button2.move(64,64)
	button2.clicked.connect(button2_clicked)
	
	widget.setGeometry(50,50,320,200)
	widget.setWindowTitle("Ejemplo Boton click")
	widget.show()
	sys.exit(app.exec_())

def button1_clicked():
	print("Boton 1 presionado")
	
def button2_clicked():
	print("Boton 2 presionado")

if __name__ == '__main__':
	window()
