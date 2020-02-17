/*LED */

#include "ParserLib.h"

char demo[] = "LED#1-OFF";
int demoLength = strlen(demo);

Parser parser((byte*)demo, demoLength);

void setup()
{
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println("Starting Demo");
}

void loop()
{
  Serial.println("--- Demo loop ---");
  parser.Compare("LED", 3, 
  []() {    Serial.print("Received LED N:");
        parser.SkipWhile(Parser::IsSeparator);
        Serial.print(parser.Read_Uint8());
        parser.SkipWhile(Parser::IsSeparator);
        parser.Compare("ON", 2, []() {Serial.println(" Action: TURN ON"); });
        parser.Compare("OFF", 3, []() {Serial.println(" ACTION: TURN OFF"); });
  });

  parser.Reset();
  delay(2500);
}
