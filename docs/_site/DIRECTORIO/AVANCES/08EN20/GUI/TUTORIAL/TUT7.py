#PyQT CheckBox

from PyQt5.QtWidgets import *
import sys

class Window(QWidget):
    def __init__(self):
        QWidget.__init__(self)
        layout = QGridLayout()
        self.setLayout(layout)

        radiobutton = QCheckBox("I have a Cat")
        radiobutton.setChecked(True)
        radiobutton.animal = "Cat"
        radiobutton.toggled.connect(self.onClicked)
        layout.addWidget(radiobutton, 0, 0)

    def onClicked(self):
        radioButton = self.sender()
        print("Animal " + (radioButton.animal) + " is " + str(radioButton.isChecked()))

app = QApplication(sys.argv)
screen = Window()
screen.show()
sys.exit(app.exec_())

