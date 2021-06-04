        /* HC-SR04 del sensor

https://www.dealextreme.com/p/hc-sr04-ultrasonic-sensor-distance-measuring-module-133696

   Este bosquejo lee un telemetro ultrasonico HC-SR04 y devuelve el
   distancia al objeto mas cercano en el rango. Para ello, envia un pulso
   para el sensor para iniciar una lectura, luego capta un pulso 
   para volver. La longitud del impulso de retorno es proporcional a
   la distancia del objeto desde el sensor.
     
   El circuito:
  * La conexion de VCC del sensor conectado a +5 V
  * Conexion GND del sensor conectado a tierra
  * Conexion TRIG del sensor conectado al pin digital 2
  * Conexion ECHO del sensor conectado al pin digital 4
 
 
   Codigo original para Ping))) ejemplo fue creado por David A. Mellis
   Adaptado para HC-SR04 por Tautvidas Sipavicius
 
   Este codigo de ejemplo se encuentra en el dominio publico.
 */
 
 
const int trigPin = 1;
const int echoPin = 2;
int pinpwm=3;
int pin2=4;   //Entrada 2 del L293D
int pin7=5;  //Entrada 7 del L293D
int pote=A0;   //Potenciómetro1
int pote1=A2;

 
int valorpote;  //Variable que recoge el valor del potenciómetro
int valorpote1;
int pwm1;          //Variable del PWM 1
int pwm2;          //Variable del PWM 2

void setup() {
  pinMode(pin2,OUTPUT);
  pinMode(pin7, OUTPUT);
  // Inicializa la comunicacion en serie:
  Serial.begin(9600);
}
 
void loop()
{
  //Almacenamos el valor del potenciómetro en la variable
  valorpote=analogRead(pote);  
  valorpote1=analogRead(pote1);
  //valorpote=analogRead(pote);
  //Como la entrada analógica del Arduino es de 10 bits, el rango va de 0 a 1023.
  //En cambio, la salidas del Arduio son de 8 bits, quiere decir, rango entre 0 a 255.
  //Por esta razón tenemos que mapear el número de un rango a otro usando este código.
  pwm1 = map(valorpote, 0, 1023, 0, 280);
  pwm2 = map(valorpote1, 0, 1023, 280, 0); //El PWM 2 esta invertido respecto al PWM 1
 
 /*Serial.print(valorpote );
 Serial.print("  valor pote 1, ");
 Serial.print(valorpote1 );
 Serial.print("  valor pote 2, ");*/
 
  //Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)
  analogWrite(pin2,pwm1);
  analogWrite(pin7,pwm2);
  
  // Establecer las variables de duracion del ping, 
  // Y el resultado la distancia en pulgadas y centimetros:
  long duration, inches, mm;
 
  // El sensor se activa por un alto pulso de 10 microsegundos o mas.
  // Dale un pulso BAJO corta de antemano para asegurar un pulso ALTO limpia:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
 
  // Leer la senial del sensor: un pulso ALTO cuya
  // Duracion es el tiempo (en microsegundos) por el envio
  // Del ping para la recepcion de su eco fuera de un objeto.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convertir el tiempo en una distancia
  inches = microsecondsToInches(duration);
  mm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(mm);
  Serial.print(" mm");
  Serial.println();
  
  delay(500);
}
 
long microsecondsToInches(long microseconds)
{
  // Segun la hoja de datos del paralaje para el PING))), hay
  // 73,746 microsegundos por pulgada (es decir, el sonido viaja a 1130 pies por
  // Segundo). Esto le da a la distancia recorrida por el ping, saliente
  // Y el regreso, asi que dividimos por 2 para obtener la distancia del obstaculo.
  // Ver: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
  // La velocidad del sonido es de 340 m / s o 29 microsegundos por centimetro.
  // La mesa de ping viaja de ida y vuelta, por lo que para encontrar la distancia del
  // Object tomamos la mitad de la distancia recorrida.
  return microseconds / 2.9 / 2;
}
