int signal = 7;
int onoff;
int botonPin=4;
int botonEstado;
long distancia;
long tiempo;
float mu;
float as;
float h = 36;
float b1 = (88.1 * 9.81);
float b2 = (113.8 * 9.81);
float dis;

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
         distancia= float(0.017*tiempo);
         distancia = distancia * 10;
         dis = distancia;
         as = (dis * dis) + (h * h);
         mu = (b1*dis)/(b2*sqrt(as)-(b1*h));
         Serial.println(dis);
         Serial.println("El coeficiente de friccion es: ");
         Serial.println(mu);
       }
       else{
        botonEstado = (digitalRead(botonPin) + 1); 
       }
     }
   digitalWrite(2, HIGH);
   digitalWrite(3, LOW);
   analogWrite(5, 0);
}
