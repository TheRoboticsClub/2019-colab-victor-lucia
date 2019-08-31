#include <Ultrasonic.h>

Ultrasonic ultraleft(6,5);  // (Trig PIN, Echo PIN)
Ultrasonic ultraright(4,3); // (Trig PIN, Echo PIN)

const int sensorPin1 = 9;
const int sensorPin2 = 8;

void setup(){
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
  
  Serial.print("Left: ");
  Serial.print(ultraleft.read(CM)); //CM or INC
  Serial.print("cm      ");
  delay(50);
  Serial.print("Right: ");
  Serial.print(ultraright.read(CM)); //CM or INC
  Serial.print("cm      ");
  delay(50);
  Serial.print("Ir1: ");
  Serial.print(value1);
  Serial.print("         ");
  delay(50);
  Serial.print("Ir2: ");
  Serial.print(value2);
  Serial.print("         ");
  Serial.println();
  delay(500);
}
