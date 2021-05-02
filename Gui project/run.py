from PyQt5.QtQml import QQmlApplicationEngine
from PyQt5.QtCore import pyqtSignal, pyqtSlot,QObject
#from PyQt5.QtWidgets import QApplication
from PyQt5.QtGui import QGuiApplication
import sys
import serial
import threading


class SetFunction(QObject):
    __qualname__ = "SetFunction"
    
    serialChange= pyqtSignal(str)

    @pyqtSlot()
    def say(self):
        print("hai")

    #@pyqtSlot()
    def serial_read(self):
        global ser
        ser=serial.Serial("COM6",9600)
        try:
            while 1:
                line=ser.readline()
                #print(line)
                line=line.rstrip()
                #line=line.decode("utf-8")
                print("Serial read =",line)
                self.serialChange.emit(str(line))
        except Exception as e:
            print("ERROR OCCURED",str(e))
            return False
        finally:
            ser.close()
    

    @pyqtSlot()
    def start_serial(self):
        t1=threading.Thread(target=self.serial_read)
        t1.start()
        #t1.join()
    
    @pyqtSlot()
    def stop_serial(self):
        global ser
        ser.close()

if __name__=="__main__":
    try:
        app=QGuiApplication(sys.argv)
        engine=QQmlApplicationEngine()

        setfunction = SetFunction()
        engine.rootContext().setContextProperty("setfunction",setfunction)    
        engine.load("main.qml")
        
        #engine.quit.connect(app.quit)
        sys.exit(app.exec_())

    except Exception as e:
        print("qml Error : ", str(e))
    
    