import serial #Import Serial Library
from visual import * #Import all the vPython library
 
arduinoSerialData = serial.Serial('com6', 9600) #Create an object for the Serial port. Adjust 'com6' to whatever port your arduino is sending to.
measuringRod = cylinder( radius= .1, length=6, color=color.yellow, pos=(-3,-2,0))
lengthLabel = label(pos=(0,5,0), text='Target Distance is: ', box=false, height=30)
target=box(pos=(0,-.5,0), length=.2, width=3, height=3, color=color.green)
while (1==1):  #Create a loop that continues to read and display the data
    rate(20)#Tell vpython to run this loop 20 times a second
    if (arduinoSerialData.inWaiting()>0):  #Check to see if a data point is available on the serial port
        myData = arduinoSerialData.readline() #Read the distance measure as a string
        print myData #Print the measurement to confirm things are working
        distance = float(myData) #convert reading to a floating point number
        measuringRod.length=distance #Change the length of your measuring rod to your last measurement
        target.pos=(-3+distance,-.5,0)
        myLabel= 'Target Distance is: ' + myData #Create label by appending string myData to string
        lengthLabel.text = myLabel #display updated myLabel on your graphic
