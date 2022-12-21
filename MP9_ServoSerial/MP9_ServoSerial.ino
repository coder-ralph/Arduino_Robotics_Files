#include <Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo
int angle = 0;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
 
void setup() 
{ 
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
  Serial.begin(9600);
} 
  
void loop() 
{ 
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(100);
  
  angle = sensorValue;
  servo_test.write(angle);                 //command to rotate the servo to the specified angle
  
  
}
