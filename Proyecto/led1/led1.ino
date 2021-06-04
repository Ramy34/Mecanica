/*
  Programa de prueba para el control de la intensidad de un LED por medio de señales PWM.
  Se hace parpadear el LED cambiando su intensidad de forma oscilatoria.
 
  Autor: Arduino UTFSM
  Fecha: 20 de Mayo 2014
 
  Materiales utilizados:
    1 Arduino UNO Rev3
    1 LED de color azul conectado a salida PWM 9
    1 Resistencia de 220[ohm]
    2 Cables de conexión
*/
 
/*------Declaración de variables-----*/
int led = 13; //Se escoje la variable donde se conectará el LED
int i;//Variable auxiliar para condicionales
 
void setup() {                
  pinMode(led, OUTPUT);//Se inicializa como OUTPUT el pin a usar. Debe ser PWM
}
 
void loop() {
//Se recorren los valores desde el 0 al 255 para enviar una señal PWM con ciclo de trabajo de 0% a 100%
//aumentando en 2.55% el ciclo de trabajo cada 10 mili segundos.  
  for(i=0; i<256; i++){ 
    analogWrite(led,i);
    delay(10);
  }
//Se recorren los valores del 255 al 0 de mayor a menor igual que el for anterior.
  for(i=255; i>-1; i--){
    analogWrite(led,i);
    delay(10);
  }
}
