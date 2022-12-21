#define COL_1 2
#define COL_2 3
#define COL_3 4
#define COL_4 5
#define COL_5 6
#define COL_6 7
#define COL_7 8
#define COL_8 9

#define ROW_1 10
#define ROW_2 11
#define ROW_3 12
#define ROW_4 13
#define ROW_5 A0
#define ROW_6 A1
#define ROW_7 A2
#define ROW_8 A3

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

byte right[] = {B00011000,B00110001,B01100011,B11000110,B11000110,B01100011,B00110001,B00011000};
byte left[] = {B00011000,B10001100,B11000110,B01100011,B01100011,B11000110,B10001100,B00011000};
byte ontrack[] = {B00011000,B00111100,B01100110,B11000011,B10000001,B00011000,B00111100,B01100110};

float timeCount = 0;

void setup() {
    Serial.begin(9600);
    
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
        
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        char serialListener = Serial.read();
        
        if (serialListener == 'R') {
           drawScreen(right);
        }
        else if (serialListener == 'O') {
            drawScreen(ontrack);
        }
        else if (serialListener == 'L') {
            drawScreen(left);
        }
    }
    delay(5);
}

void drawScreen(byte buffer2[]){
    for (byte i = 0; i < 8; i++) {
      setColumns(buffer2[i]);
      digitalWrite(rows[i], HIGH);
      delay(2);
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
