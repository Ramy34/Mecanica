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
  while (botonEstado == 1 ){
    if (botonEstado == 1 ){
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
      analogWrite(5, 100);
      botonEstado = 1;
    }
    //botonEstado = digitalRead(botonPin);
    if (botonEstado == 0){
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
      analogWrite(5, 0);
      botonEstado = 0;
    }
  }
}
