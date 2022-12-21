
// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int buttonPin2 = 3;
const int ledPin = 7;       // the pin that the LED is attached to

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  static bool ledState = false;
  if ((digitalRead(buttonPin) == LOW) && !ledState) {
    digitalWrite(ledPin, HIGH);
    ledState = true;
  }
  if((digitalRead(buttonPin2) == LOW) && ledState) {
    digitalWrite(ledPin, LOW);
    ledState = false;
  }
}
