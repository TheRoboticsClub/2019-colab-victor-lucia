# include <NewPing.h>

const int UltrasonicPin1 = 5;
const int MaxDistance1 = 200;

NewPing sonar1(UltrasonicPin1, UltrasonicPin1, MaxDistance1);

const int sensorPin1 = 9;
const int sensorPin2 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);

}

void loop() {
  delay(50);
  int value1 = 0;
  int value2 = 0;
  value1 = digitalRead(sensorPin1);
  value2 = digitalRead(sensorPin2);
  if (value1 == HIGH && value2 == LOW){
    Serial.println("Obstaculo 1");
    }
  else if (value2 == HIGH && value1 == LOW){
    Serial.println("Obstaculo 2");
    }
  else if (value1 == HIGH && value2 == HIGH){
    Serial.println("Obstaculo 12");
    }
  Serial.print(sonar1.ping_cm());
  delay(1000);
}
