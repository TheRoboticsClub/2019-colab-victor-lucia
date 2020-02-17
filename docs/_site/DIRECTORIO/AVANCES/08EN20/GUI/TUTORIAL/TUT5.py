#PyQT imagen

import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QGridLayout, QWidget
from PyQt5.QtGui import QPixmap

class Example(QWidget):
	
	def __init__(self):
		super(Example,self).__init__()
		
		self.im = QPixmap("./example.jpg")
		self.label = QLabel()
		self.label.setPixmap(self.im)
		
		self.grid = QGridLayout()
		self.grid.addWidget(self.label,1,1)
		self.setLayout(self.grid)
		
		self.setGeometry(50,50,600,600)
		self.setWindowTitle("PyQT muestra imagen")
		self.show()

if __name__ == '__main__':
	app = QApplication(sys.argv)
	ex = Example()
	sys.exit(app.exec_())
	
	
