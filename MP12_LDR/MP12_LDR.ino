int LDR=A0;
int led=13;  
int ldrreading=0;  

void setup()  
{  
  pinMode(led,OUTPUT);
  Serial.begin(9600);  
}  

void loop()  
{  
  ldrreading=analogRead(LDR);
  if(ldrreading < 800)
  {
    digitalWrite(led,HIGH); 
  }
  else
  {
    digitalWrite(led,LOW);
  }
  Serial.println(ldrreading);  
  delay(200);  
}  
