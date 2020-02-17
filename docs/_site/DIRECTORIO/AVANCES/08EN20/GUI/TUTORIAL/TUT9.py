# groupbox

from PyQt5.QtWidgets import *
import sys

class GroupBox(QWidget):
	
	def __init__(self):
		QWidget.__init__(self)
	
		self.setWindowTitle("GroupBox")
		layout = QGridLayout()
		self.setLayout(layout)
	
		groupbox = QGroupBox("GroupBox Example")
		groupbox.setCheckable(True)
		layout.addWidget(groupbox)
	
		vbox = QVBoxLayout()
		groupbox.setLayout(vbox)
		
		radiobutton = QRadioButton("RadioButton 1")
		radiobutton.country = "1"
		radiobutton.toggled.connect(self.onClicked)
		vbox.addWidget(radiobutton)
	
		radiobutton = QRadioButton("RadioButton 2")
		radiobutton.country = "2"
		radiobutton.toggled.connect(self.onClicked)
		vbox.addWidget(radiobutton)
	
		radiobutton = QRadioButton("RadioButton 3")
		radiobutton.country = "3"
		radiobutton.toggled.connect(self.onClicked)
		vbox.addWidget(radiobutton)
	
		radiobutton = QRadioButton("RadioButton 4")
		radiobutton.country = "4"
		radiobutton.toggled.connect(self.onClicked)
		vbox.addWidget(radiobutton)

	def onClicked(self):
		radioButton = self.sender()
		if radioButton.isChecked():
			print("Radio button is %s" % (radioButton.country))
	
app = QApplication(sys.argv)
screen = GroupBox()
screen.show()
sys.exit(app.exec_())
	
