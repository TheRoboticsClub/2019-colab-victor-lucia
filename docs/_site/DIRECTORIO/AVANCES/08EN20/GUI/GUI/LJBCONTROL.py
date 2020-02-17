# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'LJBCONTROL.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(350, 60, 80, 25))
        self.pushButton.setObjectName("pushButton")
        self.pushButton_2 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_2.setGeometry(QtCore.QRect(350, 410, 80, 25))
        self.pushButton_2.setObjectName("pushButton_2")
        self.pushButton_3 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_3.setGeometry(QtCore.QRect(100, 240, 80, 25))
        self.pushButton_3.setObjectName("pushButton_3")
        self.pushButton_4 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_4.setGeometry(QtCore.QRect(600, 240, 80, 25))
        self.pushButton_4.setObjectName("pushButton_4")
        self.pushButton_5 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_5.setGeometry(QtCore.QRect(350, 240, 80, 25))
        self.pushButton_5.setObjectName("pushButton_5")
        self.label_distance = QtWidgets.QLabel(self.centralwidget)
        self.label_distance.setGeometry(QtCore.QRect(110, 140, 54, 17))
        self.label_distance.setObjectName("label_distance")
        self.label_cm = QtWidgets.QLabel(self.centralwidget)
        self.label_cm.setGeometry(QtCore.QRect(170, 140, 54, 16))
        self.label_cm.setObjectName("label_cm")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(60, 90, 181, 17))
        self.label.setObjectName("label")
        self.label_distance_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_distance_2.setGeometry(QtCore.QRect(580, 130, 54, 17))
        self.label_distance_2.setObjectName("label_distance_2")
        self.label_cm_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_cm_2.setGeometry(QtCore.QRect(640, 130, 54, 16))
        self.label_cm_2.setObjectName("label_cm_2")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(530, 80, 181, 17))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(70, 340, 151, 17))
        self.label_3.setObjectName("label_3")
        self.label_distance_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_distance_3.setGeometry(QtCore.QRect(110, 370, 54, 17))
        self.label_distance_3.setObjectName("label_distance_3")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(540, 330, 151, 17))
        self.label_4.setObjectName("label_4")
        self.label_distance_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_distance_4.setGeometry(QtCore.QRect(590, 360, 54, 17))
        self.label_distance_4.setObjectName("label_distance_4")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.pushButton.setText(_translate("MainWindow", "DELANTE"))
        self.pushButton_2.setText(_translate("MainWindow", "DETRAS"))
        self.pushButton_3.setText(_translate("MainWindow", "IZQUIERDA"))
        self.pushButton_4.setText(_translate("MainWindow", "DERECHA"))
        self.pushButton_5.setText(_translate("MainWindow", "PARAR"))
        self.label_distance.setText(_translate("MainWindow", "0"))
        self.label_cm.setText(_translate("MainWindow", "cm"))
        self.label.setText(_translate("MainWindow", "SENSOR ULTRASONIDOS 1"))
        self.label_distance_2.setText(_translate("MainWindow", "0"))
        self.label_cm_2.setText(_translate("MainWindow", "cm"))
        self.label_2.setText(_translate("MainWindow", "SENSOR ULTRASONIDOS 2"))
        self.label_3.setText(_translate("MainWindow", "SENSOR INFRARROJOS 1"))
        self.label_distance_3.setText(_translate("MainWindow", "0"))
        self.label_4.setText(_translate("MainWindow", "SENSOR INFRARROJOS 2"))
        self.label_distance_4.setText(_translate("MainWindow", "0"))
