import sys
import serial

from PyQt5.QtCore import pyqtSlot, pyqtSignal, QUrl, QObject
from PyQt5.QtQuick import QQuickView
from PyQt5.QtWidgets import QApplication

class GUI(QQuickView):
    #signal handling
    serialchange = pyqtSignal(str)

    def __init__(self):
        super().__init__()
        self.setSource(QUrl("main.qml"))
        self.rootContext().setContextProperty("GUI",self)
        self.show()
        vista = self.rootObject()
        self.read_serial("COM8")

        #Data transfer
        self.serialchange.connect(vista.say)

    def read_serial(self,port):
        try:
            self.ser= serial.Serial(port,9600)
            line=self.ser.readline()
            line=line.rstrip()
            line=line.decode("utf-8")
            print(line)
            self.serialchange.emit(str(line))
            print ("after emits")
        except Exception as e:
            print("Serial Error", str(e))

    @pyqtSlot()
    def say(self):
        print("hai")
    
if __name__ == '__main__':
    app=QApplication(sys.argv)
    gui=GUI()
    sys.exit(app.exec_())