import serial

## Boolean variable that will represent 
## whether or not the arduino is connected
connected = False

## open the serial port that your ardiono 
## is connected to.
ser = serial.Serial("dev/ttyUSB0", 9600)

## loop until the arduino tells us it is ready
while not connected:
    serin = ser.read()
    connected = True

## Tell the arduino to blink!
ser.write("1")

## Wait until the arduino tells us it 
## is finished blinking
while ser.read() == '1':
    ser.read()

## close the port and end the program
ser.close()

