int pwmPin = 3; // Utilizamos un pin PWM, el 3
int pwm = 30;   // Este va a ser un valor entre 0 y 255
 
void setup(){
  // analogWrite pone el pinMode como OUTPUT por si solo
}
 
void loop(){
  // Si pwm se “pasa” de 255 pasaran cosas inesperadas
  analogWrite(pwmPin, pwm);
}

