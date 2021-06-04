/* Prueba del Puente H (L293D) 

ARDUINO   L293D(Puente H)   CIRCUITO 
*Motor izq
  10         1                PWM MOTOR1  
  11         2                INPUT1
  12         7                INPUT2
             3                OUTPUT1  TERMINAL1 MOTOR1
             6                OUTPUT2  TERMINAL2 MOTOR1

*Motor der
   9         9                PWM MOTOR2  
   8        10                INPUT3
   7        15                INPUT4
            11                OUTPUT3  TERMINAL1 MOTOR2
            14                OUTPUT4  TERMINAL2 MOTOR2  

  Bateria    8               Voltaje externo para alimentar al motor
  5V        16               (1Y9 SI VEL=255 CTE)
  GND        4, 5, 12, 13 y la terminal negativa de la bateria
  
*/

int MotIzqVel = 10;
int MotIzqA = 11; 
int MotIzqB = 12;

int MotDerVel = 9;
int MotDerA = 8; 
int MotDerB = 7; 

int VelIzq = 127; // Velocidad de los motores (0-255)
int VelDer = 127; // Velocidad de los motores (0-255)

void setup()  { 
  //Iniciar comunicacin serial
  Serial.begin(9600);
  
  //Configurar pines como salidas
  pinMode(MotIzqVel, OUTPUT);
  pinMode(MotIzqA, OUTPUT);
  pinMode(MotIzqB, OUTPUT);
  pinMode(MotDerVel, OUTPUT);  
  pinMode(MotDerA, OUTPUT);
  pinMode(MotDerB, OUTPUT);    

  //Asegurar que los motores estan detenidos al inicio
  digitalWrite(MotIzqA,LOW);
  digitalWrite(MotIzqB,LOW);
  digitalWrite(MotDerA,LOW);
  digitalWrite(MotDerB,LOW);
 } 
 
void loop()  { 
  //Motores detenidos
  digitalWrite(MotIzqA,LOW);
  digitalWrite(MotIzqB,LOW);
  digitalWrite(MotDerA,LOW);
  digitalWrite(MotDerB,LOW);
  Serial.println("Detenido");
  //analogWrite(MotIzqVel, 0);
  //analogWrite(MotDerVel, 0);
  delay(1000);

  analogWrite(MotIzqVel, VelIzq);
  analogWrite(MotDerVel, VelDer);

  //Adelante (Mover rueda izquierda y derecha mismo sentido)
  digitalWrite(MotIzqA,HIGH);
  digitalWrite(MotIzqB,LOW);
  digitalWrite(MotDerA,HIGH);
  digitalWrite(MotDerB,LOW);
  Serial.println("Adelante");
  delay(1000);
  
  //Reversa (Mover rueda izquierda y derecha sentido contrario)
  digitalWrite(MotIzqA,LOW);
  digitalWrite(MotIzqB,HIGH);
  digitalWrite(MotDerA,LOW);
  digitalWrite(MotDerB,HIGH);
  Serial.println("Reversa");
  delay(1000);

  //Giro a la derecha (Solo mover rueda izquierda)
  digitalWrite(MotIzqA,HIGH);
  digitalWrite(MotIzqB,LOW);
  digitalWrite(MotDerA,LOW);
  digitalWrite(MotDerB,LOW);
  Serial.println("Derecha");
  delay(1000);

  //Giro a la izquierda (Mover rueda derecha)
  digitalWrite(MotIzqA,LOW);
  digitalWrite(MotIzqB,LOW);
  digitalWrite(MotDerA,HIGH);
  digitalWrite(MotDerB,LOW);
  Serial.println("Izquierda");
  delay(1000);             
}
