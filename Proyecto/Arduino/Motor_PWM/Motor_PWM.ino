/*

* Brushed_H_Bridge sketch

*comandos desde puero serie para control de direccion y velocidad

*’0′ a ‘9’ para la velocidad tomando a ‘0’ apagado, ‘9’ maxima velocidad

* + y – para asignar la direccion

*/

const int enPin = 5; // PWM se conecta al pin 1 del puente-H
const int in1Pin = 6; // Entrada 2 del puente-H
const int in2Pin = 4; // Entrada 7 del puente-H

//puertos para sensor QRD
int sensorQRD = A0;
//int ledPin = 10;
int umbral = 512;

void setup() //Inicializa y prepara los valores

{

Serial.begin(9600); //Abre el puerto serie a 9600 bps

pinMode(in1Pin, OUTPUT); //Configura in1Pin como salida

pinMode(in2Pin, OUTPUT); //Configura in2Pin como salida

Serial.println("Speed (0-9) or + – to set direction"); //Imprime en la consola puerto serie

}

void loop() //La funcion loop se ejecuta consecutivamente

{ //permitiendole al programa variar y responder

int valorQRD = analogRead(sensorQRD);

 //Serial.print("QRD: "); Serial.println(valorQRD);

 boolean digQRD = (valorQRD > umbral);
   
if ( Serial.available()) { //Si el puerto serie esta disponible?

char ch = Serial.read(); //variable tipo char desde puerto serial

if(ch >= '0' && ch <= '9') //Si ch es un numero?

{

int speed = map(ch, '0', '9', 0, 255); //Re-mapea un numero desde un rango a otro

analogWrite(enPin, speed); //’0′ a 0 ‘9’ a 255

Serial.println(speed); //Escribe el valor analogico PWM enPin

}

else if (ch == '+') //Si el caracter es ‘+’

{ //el motor avanza Clockwise
  if(valorQRD > umbral){
    //sensorQRD = HIGH;
    Serial.println("CW");
    
    digitalWrite(in1Pin,LOW);
    
    //digitalWrite(in2Pin,HIGH);
  }
  if(valorQRD < umbral){
    //sensorQRD = LOW;
    digitalWrite(in1Pin,HIGH);
  }
}



else //Cualquier otro caracter es omitido

{

Serial.print("Unexpected character ");

Serial.println(ch);

}

}

}
