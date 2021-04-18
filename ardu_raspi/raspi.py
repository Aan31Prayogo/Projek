import serial
import curses

ser=serial.Serial('/dev/ttyUSB0',115200)    #arduino COM port
screen = curses.initscr()
curses.noecho()  
curses.cbreak()
curses.halfdelay(5)
screen.keypad(True)

try:
	while True:
		char=screen.getch()

		if char == ord('q'):
			break
		###################################
		elif char == ord('w'):
			toArduino ='F'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		######################################	
		elif char == ord('s'):
			toArduino = 'B'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		#####################################
		elif char == ord('a'):
			toArduino = 'L'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		###################################
		elif char == ord('d'):
			toArduino = 'R'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		######################################
		elif char == ord('i'):
			toArduino = 'U'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		elif char == ord('k'):
			toArduino = 'D'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		elif char == ord('l'):
			toArduino = 'M'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		elif char == ord('j'):
			toArduino = 'N'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		elif char == ord('f'):
			toArduino ='S'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
			
		else:
			toArduino = 'S'
			toArduinoEncode = toArduino.encode()
			ser.write(toArduinoEncode)
		
		#print("current toArduino = ", toArduino)


finally:
    #Close down curses properly, inc turn echo back on!
    curses.nocbreak(); screen.keypad(0); curses.echo()
    curses.endwin()

