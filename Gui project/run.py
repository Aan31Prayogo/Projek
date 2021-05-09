from PyQt5.QtQml import QQmlApplicationEngine
from PyQt5.QtCore import pyqtSignal, pyqtSlot,QObject
#from PyQt5.QtWidgets import QApplication
from PyQt5.QtGui import QGuiApplication
import sys
import serial
import threading
#import multiprocessing 

class SetFunction(QObject):
    __qualname__ = "SetFunction"
    
    serialChange= pyqtSignal(str)

    @pyqtSlot()
    def say(self):
        print("hai")

    #@pyqtSlot()
    def serial_read(self,COM,baudrate):
        global ser
        global stop_thread
        try:
            stop_thread=False
            ser=serial.Serial(COM,baudrate)
            while 1:
                line=ser.readline()
                line=line.rstrip()
                line=line.decode("utf-8")
                print("Serial read =",line)
                self.serialChange.emit(str(line))
                if stop_thread:
                    stop_thread=False
                    ser.close()
                    break
        except Exception as e:
            print(" SERIAL ERROR OCCURED : " + str(e))
            return False

    @pyqtSlot(str,str)
    def start_serial(self):
        global t1
        t1=threading.Thread(target=self.serial_read,args=(str,str,))
        t1.start()
        #t1.join()
    
    @pyqtSlot()
    def stop_serial(self):
        global t1
        #global ser
        global stop_thread
        stop_thread=True
      

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
    
    