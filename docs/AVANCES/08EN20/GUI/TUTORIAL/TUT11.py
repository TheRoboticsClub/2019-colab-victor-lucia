#PyQt Toolbar

from PyQt5.QtWidgets import *
import sys

class Window(QWidget):
	
	def __init__(self):
		QWidget.__init__(self)
		layout = QGridLayout()
		self.setLayout(layout)
		
		#Create PyQt toolbar
		toolBar = QToolBar()
		layout.addWidget(toolBar)
		
		#Add buttos to toolbar
		toolButton = QToolButton()
		toolButton.setText("Apple")
		toolButton.setCheckable(True)
		toolButton.setAutoExclusive(True)
		toolBar.addWidget(toolButton)
		toolButton = QToolButton()
		toolButton.setText("Orange")
		toolButton.setCheckable(True)
		toolButton.setAutoExclusive(True)
		toolBar.addWidget(toolButton)
		
		#Add textfield to window
		tbox = QPlainTextEdit()
		layout.addWidget(tbox)
		
app = QApplication(sys.argv)
screen = Window()
screen.show()
sys.exit(app.exec_())
	
