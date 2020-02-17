
import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *

class window(QDialog):
   def __init__(self, parent=None):
      super(window, self).__init__(parent)
      
      self.originalPalette = QApplication.palette()
      
      styleComboBox = QComboBox()
      styleComboBox.addItems(QStyleFactory.keys())
      
      styleLabel = QLabel("&Style:")
      styleLabel.setBuddy(styleComboBox)
      
      self.use
      
      layout = QHBoxLayout()
      self.b1 = QCheckBox("Activar Ultrasonidos")
      self.b1.setChecked(False)
      self.b1.stateChanged.connect(lambda:self.btnstate(self.b1))
      layout.addWidget(self.b1)
		
      self.b2 = QCheckBox("Activar Infrarrojos")
      self.b2.toggled.connect(lambda:self.btnstate(self.b2))
      layout.addWidget(self.b2)
      
      self.b3 = QCheckBox("Activar motores")
      self.b3.toggled.connect(lambda:self.btnstate(self.b3))
      layout.addWidget(self.b3)
      
   def changeValue(self,value):
	   print(value)
	
   def btnstate(self,b):
      if b.text() == "Activar Ultrasonidos":
         if b.isChecked() == True:
				US = 1
				print "Ultrasonidos activado" 
				print US
         else:
				US = 0
				print "Ultrasonidos desactivado"
				print US
            		 
      if b.text() == "Activar Infrarrojos":
         if b.isChecked() == True:
				IR = 1
				print "Infrarrojos activado"
				print IR
         
         else:
				IR = 0
				print "Infrarrojos desactivado"
				print IR
		
      if b.text() == "Activar motores":
		  if b.isChecked() == True:
				MOT = 1
				print "Motores activados"
				print MOT
		  else: 
				MOT = 0
				print "Motores desactivados"
				print MOT
          
   
if __name__ =='__main__':
	import sys 
	app = QApplication(sys.argv)
	gallery = WidgetGallery()
	gallery.show()
	sys.exit(app.exec_())
