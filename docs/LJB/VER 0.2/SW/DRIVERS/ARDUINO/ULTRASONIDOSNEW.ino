#include <Ultrasonic.h>

Ultrasonic ultraleft(6,5);  // (Trig PIN, Echo PIN)
Ultrasonic ultraright(4,3); // (Trig PIN, Echo PIN)

void setup(){
  Serial.begin(9600);
  
  }

void loop()
{
  Serial.print("Left: ");
  Serial.print(ultraleft.read(CM)); //CM or INC
  Serial.print("cm      ");
  delay(50);
  Serial.print("Right: ");
  Serial.print(ultraright.read(CM)); //CM or INC
  Serial.print("cm      ");
  delay(50);
  Serial.println();
  delay(500);
}
