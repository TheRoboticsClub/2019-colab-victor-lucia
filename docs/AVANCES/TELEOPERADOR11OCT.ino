#include <Ultrasonic.h>

int data;

Ultrasonic ultraleft(10,11);  // (Trig PIN, Echo PIN)
Ultrasonic ultraright(8,9); // (Trig PIN, Echo PIN)

int value1 = 0;
int value2 = 0;
  

const int sensorPin1 = 3;
const int sensorPin2 = 4;

void setup(){
  Serial.begin(9600);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  delay(500);
  Serial.println("Hola, soy Arduino. Para ultrasonidos, pulsa 1. Para infrarrojos, pulsa 2. Para motores pulsa 3");
  
}

void loop(){
 while(Serial.available()){
      data = Serial.read();
      if(data =='1' && data !='2')
      {
        dame_ultrasonidos();
        }
      if(data =='2' && data !='1')
      {
        dame_infrarrojos();
      }
          
 }
}

void dame_ultrasonidos()
{
        Serial.print("Left: ");
        Serial.print(ultraleft.read(CM)); //CM or INC
        Serial.print("cm      ");
        delay(50);
        Serial.print("Right: ");
        Serial.print(ultraright.read(CM)); //CM or INC
        Serial.print("cm      ");
        Serial.println("");
        delay(50);
}

void dame_infrarrojos()
{
      value1 = digitalRead(sensorPin1);
      value2 = digitalRead(sensorPin2);
      Serial.print("Ir1: ");
      Serial.print(value1);
      Serial.print("         ");
      delay(50);
      Serial.print("Ir2: ");
      Serial.print(value2);
      Serial.print("         ");
      Serial.println("");
      delay(50);
}
