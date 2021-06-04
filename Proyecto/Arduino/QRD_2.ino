int sensorQRD = A1;
int ledPin = 13;
int umbral = 512;

void setup() {
 pinMode(ledPin,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  
 int valorQRD = analogRead(sensorQRD);

 //Serial.print("QRD: "); Serial.println(valorQRD);

 boolean digQRD = (valorQRD > umbral);
 if(valorQRD > umbral){
  sensorQRD = HIGH;
  Serial.println("LED Apagado");
 }
 if(valorQRD < umbral){
  sensorQRD = LOW;
  Serial.println("LED Encendido");
 }

 digitalWrite(ledPin, digQRD);
 //delay (1000);
}
