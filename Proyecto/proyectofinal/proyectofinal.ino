int signal = 4;
int botonPin = 12;
int onoff;
int botonEstado;
long distancia;
long tiempo;
float mu;
float hip;
float h = 285;
float b1 = (0.0681 * 9.81);
float b2 = (((0.1138 + .0881) * 9.81))+ (0.5);
float x;

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
       digitalWrite(3, HIGH);
       digitalWrite(2, LOW);
       analogWrite(5, 155);
       onoff = digitalRead(signal);
       if (onoff == 0){
         digitalWrite(2, HIGH);
         digitalWrite(3, LOW);
         analogWrite(5, 0);
         delay(100);
         digitalWrite(9,LOW); /*Por cuestión de estabilización del sensor*/
         delayMicroseconds(5);
         digitalWrite(9, HIGH); /*Envío del pulso ultrasónico*/
         delayMicroseconds(10);
         tiempo = pulseIn(8, HIGH);
         distancia = float(0.017 * tiempo);
         distancia = distancia * 10; /*Convierte a milimetros*/
         x = distancia + 80;
         hip = sqrt(x * x + h * h);
         mu = b1*x/hip/(b2 - b1*(h/hip));
         Serial.print(x);
         Serial.println(" mm");
         Serial.print("El coeficiente de friccion es: ");
         Serial.println(mu);
         botonEstado = 0;
       }
     }
   digitalWrite(2, HIGH);
   digitalWrite(3, LOW);
   analogWrite(5, 0);
}
