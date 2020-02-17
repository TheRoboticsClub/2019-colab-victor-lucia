#PyQT slider

import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QSlider
from PyQt5.QtCore import Qt

class Example(QMainWindow):
	
	def __init__(self):
		super(Example, self).__init__()
		
		mySlider = QSlider(Qt.Vertical, self)
		mySlider.setGeometry(40, 30, 200, 100)
		mySlider.valueChanged[int].connect(self.changeValue)
		
		self.setGeometry(50,50,320,200)
		self.setWindowTitle("Checkbox Example")
		self.show()
	
		mySlider2 = QSlider(Qt.Vertical, self)
		mySlider2.setGeometry(60, 40, 200, 30)
		mySlider2.valueChanged[int].connect(self.changeValue)
		
		self.setGeometry(100,100,320,200)
		self.setWindowTitle("Checkbox Example")
		self.show()	
	
	def changeValue(self, value):
		print(value)
		
		
if __name__ == '__main__':
	app = QApplication(sys.argv)
	ex = Example()
	sys.exit(app.exec_())
