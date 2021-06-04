int sensorQRD = A0;

// leds indicadores
int led = 13;

// umbral para el QRD
int umbral = 512;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*int digQRD = digitalRead(sensorQRD);
  Serial.print("QRD: "); Serial.println(digQRD);
  
  digitalWrite(led, digQRD);

  */
  int valQRD = analogRead(sensorQRD);
  Serial.print("QRD: "); Serial.println(valQRD);
  
  if(valQRD > umbral)
  {
  digitalWrite(led, HIGH);
  Serial.println("Encendido");
  delay(1000);
  }

  if(valQRD < umbral)
  {
  digitalWrite(led, LOW);
  Serial.println("Apagado");
  delay(1000);
  }
  
}

