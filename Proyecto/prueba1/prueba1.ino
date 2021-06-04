/*Ejemplo para manejo de servomotor con arduino

2-> Salida a motor 1
3-> Salida a motor 2
4-> Sube PWM
5-> Baja PWM

*/
int valorPWM=0;// Valor de intensidad del pwm, define la velocidad del motor
int est,est2;// Variables para guardar el estado del pulsador.

void izq(int velocidad);//rutina motor hacia la izquierda
void der(int velocidad);//rutina motor hacia la derecha

void setup(){
  pinMode(2,OUTPUT); //Pin 2 Como salida
  pinMode(3,OUTPUT); //Pin 3 Como salida
  pinMode(4,INPUT_PULLUP); //Pin 4 Como entrada -> activa con cero
  pinMode(5,INPUT_PULLUP); //Pin 5 Como entrada -> activa con cero
  digitalWrite(2,LOW);//Apaga el motor
  digitalWrite(3,LOW);//Apaga el motor
}

void loop(){
  est = digitalRead(4);//Guarda el estado del pin 4, depende del pulsador
  est2 = digitalRead(5);//Guarda el estado del pin 5, depende del pulsador
  if(est == 0){//Aumento Pwm
    delay(100);//retardo Antirebote
    valorPWM += 1;
    if(valorPWM > 255){
      valorPWM = 255;
    }
  }
  if(est2 == 0){//Disminuye Pwm
    delay(100);//retardo Antirebote
    valorPWM -= 1;
    if(valorPWM < 0){
      valorPWM = 0;
    }
  }
  //izq(valorPWM);//inicia el giro a izquierda
  der(valorPWM);//inicia el giro a derecha
}

analogWrite(6,100);
void izq(int velocidad){
  digitalWrite(2,LOW);
  analogWrite(3,velocidad);
}

void der(int velocidad){
  digitalWrite(3,LOW);
  analogWrite(2,velocidad);
}
