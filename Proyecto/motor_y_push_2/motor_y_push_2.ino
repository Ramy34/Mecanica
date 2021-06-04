int botonPin=7;
int botonEstado;

void setup() {
  Serial.begin(9600);
  pinMode(botonPin,INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  botonEstado = digitalRead(botonPin);
  if (botonEstado == 1){
    while (botonEstado == 1 ){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      analogWrite(5, 120);
      botonEstado = (digitalRead(botonPin) + 1);
    }
  }
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  analogWrite(5, 0);
 }
