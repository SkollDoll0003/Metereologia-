#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int analogValue;
int EvaluarAnalog;
float veloc1 = 0;
int tiem = 0;
float v1 = 0;

void setup() {
Serial.begin(9600);

Serial.println(F("DHTxx test!"));
dht.begin();
pinMode(35,INPUT);
pinMode (buzzer, OUTPUT);

}

void loop() {
  
delay(2000); //Es un sensor lento, por lo que hay que darle tiempo.
float h = dht.readHumidity();
float t = dht.readTemperature();

if (isnan(h) || isnan(t)) {
Serial.println(F("Failed to read from DHT sensor!"));
return;
}

analogValue = analogRead(35);
  if(analogValue <= 4095 && analogValue >= 3000){
    Serial.println("SECO");
  }
  else if(analogValue < 3000 && analogValue >= 2500){
    Serial.println("LIGERA");
  }

  else if(analogValue < 2500 && analogValue >= 1500){
    Serial.println("MODERADA");
  }

   else if(analogValue < 1500 && analogValue >= 900){
    Serial.println("INTENSA");
  }

Serial.print(F("Humedad: "));
Serial.print(h);
Serial.print(F("% Temperatura: "));
Serial.print(t);
Serial.println(F("°C "));

EvaluarAnalog = analogRead(34);
  v1 = (analogRead(34));
  veloc1= (v1*0.019);
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
