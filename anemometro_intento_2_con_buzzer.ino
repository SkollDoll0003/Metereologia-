int analogValue;
int buzzer = 8;
float veloc1 = 0;
int tiem = 0;
float v1 = 0;
void setup(){
  pinMode (buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  analogValue = analogRead(36);
  v1 = (analogRead(36));
  veloc1= (v1*5.1990);
  Serial.println(veloc1);
  Serial.println("Km/H");

  if (veloc1 > 120){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
  delay (1000);
}
