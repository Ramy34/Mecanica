int potPin = A0;
float valPot = 0;
int digPot = 0;

int led=3;

int tiempo=100;


 
void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  
}
 
void loop(){
  valPot = analogRead(potPin);
  digPot= digitalRead(potPin);
  Serial.print("Pot: ");Serial.println(valPot);
  delay(tiempo);
  
  if (digPot == 1)
  {
    digitalWrite(led, HIGH);
    
  }

  if (digPot == 0)
  {
    digitalWrite(led, LOW);
  }

}
