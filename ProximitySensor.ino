
#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A1
#define COL_6 A2
#define COL_7 A3
#define COL_8 A4

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

byte one[] = { B00011000,B00111000,B01111000,B00011000,B00011000,B00011000,B00011000,B00011000};
byte two[] = { B00111100,B01111110,B01100110,B00001100,B00011000,B00110000,B01111110,B01111110};
byte three[] = { B01111110,B01111110,B00000110,B00111110,B00111110,B00000110,B01111110,B01111110};
byte four[] = { B01100110,B01100110,B01100110,B01111110,B01111110,B00000110,B00000110,B00000110};
byte five[] = { B01111110,B01111110,B01100000,B01111110,B01111110,B00000110,B01111110,B01111110};
byte six[] = { B01111110,B01111110,B01100000,B01111110,B01111110,B01100110,B01111110,B01111110};

// Declare the used sensor pin <br>int sensorPin = A0;

void setup(){
  // Start the Serial connection
  Serial.begin(9600);

  for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
}

void loop(){
  // Read the analog value of the sensor
  int val = analogRead(A0);
  Serial.println(val);
  if(val < 200){
    drawScreen(one);
  }
  else if(val < 300 && val > 200){
    drawScreen(two);
  }
  else if(val < 400 && val > 300){
    drawScreen(three);
  }
  else if(val < 500 && val > 400){
    drawScreen(four);
  }
  else if(val < 600 && val > 500){
    drawScreen(five);
  }
  else if(val > 600){
    drawScreen(six);
  }
  delay(1);
}

void  drawScreen(byte buffer2[]){
   // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
      setColumns(buffer2[i]); // Set columns for this specific row
      digitalWrite(rows[i], HIGH);
      delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
      digitalWrite(rows[i], LOW);
    }
}


void setColumns(byte b) {
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
    
    // If the polarity of your matrix is the opposite of mine
    // remove all the '~' above.
}
