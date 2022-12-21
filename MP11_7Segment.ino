int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void displayDigit(int digit){
  if(digit!=1 && digit!=4){
    digitalWrite(a,LOW);
  }
  if(digit!=5 && digit!=6){
    digitalWrite(b,LOW);
  }
  if(digit!=2){
    digitalWrite(c,LOW);
  }
  if(digit!=1 && digit!=4 && digit!=7){
    digitalWrite(d,LOW);
  }
  if(digit==2 || digit==6 || digit==8 || digit==0){
    digitalWrite(e,LOW);
  }
  if(digit!=1 && digit!=2 && digit!=3 && digit!=7){
    digitalWrite(f,LOW);
  }
  if(digit!=0 && digit!=1 && digit!=7){
    digitalWrite(g,LOW);
  }
}

void turnOff(){
  digitalWrite(a, HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<10; i++){
    displayDigit(i);
    delay(1000);
    turnOff(); 
  }
}
