int analogValue;
bool digitalValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(35);
  if (analogValue < 300)
     Serial.println("Lluvia Intensa");
  else if (analogValue < 500)  
   Serial.println ("Lluvia Moderada");
  else if (analogValue < 1000)
     Serial.println ("Lluvia ligera");
  else
     Serial.println("Lluvia no detectada");
  digitalValue = digitalRead(34);
  if (digitalValue == HIGH)
     Serial.println("NO HAY LLUVIA");
  else
     Serial.println("ESTA LLOVIENDO");


  delay (2000);
}
