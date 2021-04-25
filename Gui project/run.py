from PyQt5.QtQml import QQmlApplicationEngine
from PyQt5.QtCore import QUrl, pyqtSignal, pyqtSlot,QObject,pyqtProperty
#from PyQt5.QtWidgets import QApplication
from PyQt5.QtGui import QGuiApplication
import sys
import serial

class SetFunction(QObject):
    __qualname__ = "SetFunction"
    
    serialChange= pyqtSignal(str)
    def receive_serial(self):
        send_data = self.serial_read()

    @pyqtSlot()
    def say(self):
        print("hai")

    @pyqtSlot()
    def serial_read(self):
        ser=serial.Serial("COM6",9600)
        try:
            line=ser.readline()
            #print(line)
            line=line.rstrip()
            line=line.decode("utf-8")
            print("Serial read =",line)
            self.serialChange.emit(str(line))
        except Exception as e:
            print("ERROR OCCURED",str(e))
            return False

if __name__=="__main__":
    app=QGuiApplication(sys.argv)
    engine=QQmlApplicationEngine()

    setfunction = SetFunction()
    engine.rootContext().setContextProperty("setfunction",setfunction)    
    engine.load("main.qml")
    
    #engine.quit.connect(app.quit)
    sys.exit(app.exec_())
    
    