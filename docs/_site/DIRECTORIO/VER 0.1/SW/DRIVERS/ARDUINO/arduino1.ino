#define LED 13



void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available())
  {
    char serialListener = Serial.read();
    if (serialListener == 'H')
    {
      digitalWrite(LED, HIGH);
    }
    else if (serialListener == 'L')
    {
      digitalWrite(LED, LOW);
    }
  }

}
