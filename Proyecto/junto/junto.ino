int signal = 7;
int onoff;
int botonPin = 4;
int botonEstado;
long distancia;
long tiempo;

void setup() {
  Serial.begin(9600);
  pinMode(botonPin,INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);

}

void loop() {
  botonEstado = digitalRead(botonPin);
     while (botonEstado == 1 ){
       digitalWrite(2, HIGH);
       digitalWrite(3, LOW);
       analogWrite(5, 120);
       onoff = digitalRead(signal);
       if (onoff == 0){  //cambiar a 1
         botonEstado = 0;
         digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
         delayMicroseconds(5);
         digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
         delayMicroseconds(10);
         tiempo=pulseIn(8, HIGH);
         distancia= int(0.017*tiempo);
         distancia = distancia * 10;
         //Serial.println("Distancia ");
         //Serial.println(distancia);
         //Serial.println(" mm");
         
         delay(1000);
       }
       else{
        botonEstado = (digitalRead(botonPin) + 1); 
       }
     }
   digitalWrite(2, HIGH);
   digitalWrite(3, LOW);
   analogWrite(5, 0);
}
