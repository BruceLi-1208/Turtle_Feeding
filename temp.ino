#include <dht.h>

dht myDHT_5;
int dht_5_gettemperature() {
  int chk = myDHT_5.read11(5);
  int value = myDHT_5.temperature;
  return value;
}

void setup(){
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop(){
  if (dht_5_gettemperature() < 28) {
    digitalWrite(10,HIGH);
    Serial.println("temperature<28");
    delay(1000);

  }
  if (dht_5_gettemperature() > 26) {
    digitalWrite(10,LOW);
    Serial.println("temperature>26");
    delay(1000);

  }
  if (analogRead(A0) > 600) {
    digitalWrite(9,HIGH);
    Serial.println("out of water");
    delay(1000);

  }
  if (analogRead(A0) < 300) {
    digitalWrite(9,LOW);
    Serial.println("water enough");
    delay(1000);

  }

}
