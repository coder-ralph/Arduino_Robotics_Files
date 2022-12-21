#include <Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo
int angle = 0;
String inString = "";

void setup() {
    servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
    servo_test.write(90);
    Serial.begin(9600);
}

void loop() {
    /*if (Serial.available()) {
        char serialListener = Serial.read();

        int len = Serial.readBytes();
        int x = 0;
        while(x <= len){
          output =output + serialListener;
          x+=1;
        }
        

        
        servo_test.write(output.toInt());
        
    }*/

    while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    else
    {
       servo_test.write(inString.toInt());
       inString = "";
    }
    
  }
   
}
