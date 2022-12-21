const int buttonPin1 = 2;  //pushbutton
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

const int ledPin1 = 10; 
const int ledPin2 = 11;
const int ledPin3 = 12;
const int ledPin4 = 13;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;


void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  if (buttonState1 == LOW) {
    // turn LED on:
    digitalWrite(ledPin1, HIGH);
  } 
  else if (buttonState1 == HIGH){
    // turn LED off:
    digitalWrite(ledPin1, LOW);
  }

  if (buttonState2 == LOW) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
  } 
  else if (buttonState2 == HIGH) {
    // turn LED off:
    digitalWrite(ledPin2, LOW);
  }
  
  if (buttonState3 == LOW) {
    // turn LED on:
    digitalWrite(ledPin3, HIGH);
  } 
  else if (buttonState3 == HIGH){
    // turn LED off
    digitalWrite(ledPin3, LOW);
  }
  
  if (buttonState4 == LOW) {
    // turn LED on:
    digitalWrite(ledPin4, HIGH);
  } 
  else if (buttonState4 == HIGH){
    // turn LED off:
    digitalWrite(ledPin4, LOW);
  }
  
}
