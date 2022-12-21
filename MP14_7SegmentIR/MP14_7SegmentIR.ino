#include <IRremote.h>      //must copy IRremote library to arduino libraries
#define zero 0xC101E57B
#define one 0x9716BE3F
#define two 0x3D9AE3F7
#define three 0x6182021B
#define four 0x8C22657B
#define five 0x488F3CBB
#define six 0x449E79F
#define seven 0x32C6FDF7
#define eight 0x1BC0157B
#define nine 0x3EC3FC1B


int RECV_PIN = 11;       //IR receiver pin

IRrecv irrecv(RECV_PIN);

decode_results results;

int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 8;
int pinG = 9;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
}

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    if (results.value == zero)
    {
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }
    
    if (results.value == one)
    {
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }

    if (results.value == two)
    {
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }

    if (results.value == three)
    {
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }

    if (results.value == four)
    {
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }

    if (results.value == five)
    {
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, HIGH);     
      delay(1000);               // wait for a second
    }

    if (results.value == six)
    {
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, HIGH);     
      delay(1000);               // wait for a second
    }

    if (results.value == seven)
    {
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }

    if (results.value == eight)
    {
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }

    if (results.value == nine)
    {
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);     
      delay(1000);               // wait for a second
    }

    delay(20);          //General speed
  }
}
