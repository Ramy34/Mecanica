int ledPin = 3;
int potPin = 0;
int value, pwm;
 
void setup(){
Serial.begin(9600);
}
 
void loop(){
  value = analogRead(potPin);
  //pwm = value*255/1023;
  pwm = map(value,0,1023,0,255);
  Serial.println(value);  
  analogWrite(ledPin, pwm);
}
