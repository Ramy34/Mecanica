int pwmPin = 3;   //pin de salida analógica 
int IN1 = 4;      //pin de control para IN1 del puente H
int IN2 = 5;      //pin de control para IN2 del puente H
int vel = 180;
int contador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
}

void loop () {
  if (contador==0)
  {
    analogWrite(pwmPin, vel);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    Serial.println("Motor detenido");
  }

  if (contador==1)
  {
    analogWrite(pwmPin, vel);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    Serial.println("Motor levogiro");
  }

  if (contador==2)
  {
    analogWrite(pwmPin, vel);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    Serial.println("Motor dextrogiro");
    
  }

  contador++;
  if (contador==3)
  {
    contador=0;
  }
  
  delay(1000);
  
}

