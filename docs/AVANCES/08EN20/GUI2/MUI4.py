#PyQT CheckBox

from PyQt5.QtWidgets import *
import sys

class Window(QWidget):
    def __init__(self):
        QWidget.__init__(self)
        layout = QGridLayout()
        self.setLayout(layout)

		nameLabel = QLabel("Name:")
		layout.addWidget(nameLabel, 0, 1)
		
		nameEdit = QLineEdit()
		layout.addWidget(nameEdit, 0, 2)
		
		adressLabel=QLabel("Address:")
		layout.addWidget(addressLabel, 1, 1)
		
		addressEdit = QTextEdit()
		layout.addWidget(addressEdit, 1, 2)
		
        radiobutton = QCheckBox("Activar Ultrasonidos")
        radiobutton.setChecked(False)
        radiobutton.animal = "Activar Ultrasonidos"
        radiobutton.toggled.connect(self.onClicked)
        layout.addWidget(radiobutton, 0, 0)

        radiobutton1 = QCheckBox("Activar Infrarrojos")
        radiobutton1.setChecked(False)
        radiobutton1.animal = "Activar Infrarrojos"
        radiobutton1.toggled.connect(self.onClicked1)
        layout.addWidget(radiobutton1, 1,0)

        radiobutton2 = QCheckBox("Activar Motores")
        radiobutton2.setChecked(False)
        radiobutton2.animal = "Activar Motores"
        radiobutton2.toggled.connect(self.onClicked1)
        layout.addWidget(radiobutton2, 2,0)

    def onClicked(self):
        radioButton = self.sender()
        print((radioButton.animal) + " is " + str(radioButton.isChecked()))

    def onClicked1(self):
        radioButton1 = self.sender()
        print((radioButton1.animal) + " is " + str(radioButton1.isChecked()))

    def onClicked2(self):
        radioButton2 = self.sender()
        print((radioButton2.animal) + " is " + str(radioButton2.isChecked()))

app = QApplication(sys.argv)
screen = Window()
screen.show()
sys.exit(app.exec_())
