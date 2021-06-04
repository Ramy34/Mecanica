volatile int contador = 0;   // Variable entera volatile (para poder utilizar en todo el programa), se almacena en la RAM
 
void setup() {
  Serial.begin(9600);
  /*  
  
  Tipos de interrupciones
      LOW        pin esta en bajo
      RISING     pin cambia de bajo a alto
      FALLING    pin cambia de alto a bajo
      CHANGE     pin cambia de bajo a alto o de alto a bajo
      
  Sintaxis
    attachInterrupt(digitalPinToInterrupt(PIN DE LA INTERRUPCION), NOMBRE DE LA RUTUNA, TIPO);
    attachInterrupt(NUMERO DE LA INTERRUPCION ASOCIADA A ESE PIN, NOMBRE DE LA RUTUNA, TIPO);
  */
  attachInterrupt(0, cuenta, RISING);
}
 
void loop() {
  Serial.print("Numero de vueltas: ");
  Serial.println(contador/4);       // Al ser 4 interrumpciones por vuelta, se divide entre el valor del contador entre el numero de ranuras para obtener el valor de vueltas


}
 
void cuenta()    // Funcion que se ejecuta durante cada interrupion
{
  contador++;     // Se incrementa en uno el contador
}

