#include <NewPing.h>

#define TRIGGER_PIN 11 //Arduino pin tied to trigger pin on the ultrasonic sensor
#define ECHO_PIN 12    //Arduino pin tied to echo pin on the ultrasonic sensor
#define MAX_DISTANCE 200 //Maximum distance we want to ping for (in centimeters)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //NewPing setup of pins and maximum distance. 

void setup()
{
  Serial.begin(9600); //Open serial monitor at 9600 baud to see ping results   
}

void loop()
{
  Serial.println(sonar.ping_cm());
  delay(20);
}
