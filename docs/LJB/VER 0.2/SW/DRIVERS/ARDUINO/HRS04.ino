/* Ultrasonic sensor pins:
 *  VCC: +5VDC
 *  Trig: Trigger (INPUT) - Pin11
 *  Echo: Echo (OUTPUT) - PIn12
 *  GND: GND
 */

 int trigPin = 11; //Trigger 
 int echoPin = 12; //Echo

 long duration, cm, inches; 

 void setup(){
  //Serial Port begin
  Serial.begin(9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  }

 void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");

  delay(250);
  }
