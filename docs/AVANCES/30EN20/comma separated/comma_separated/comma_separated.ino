/*COMMA SEPARATED*/

#include "ParserLib.h"

char demo[] = "12,13,14";
int demoLength = strlen(demo);

Parser parser((byte*)demo, demoLength);

void setup() {
    Serial.begin(9600);
    while (!Serial) {;}
    Serial.println("Starting Demo");
    Serial.setTimeout(2);
}

void loop() {
  Serial.println("--- Demo loop ---");

  //Example without using success Callback
  Serial.println(" - Example 1 -");
  parser.DoWhile(
      []()-> bool { return parser.Search(','); },
      []() {Serial.println(parser.Read_Uint16()); parser.SkipWhile(','); },
      []() {Serial.println(parser.Read_Uint16()); }  
  );

  parser.Reset();
  //Example using success Callback
  Serial.println(" - Example 2 - ");
  parser.DoWhile(
      []()-> bool { return parser.Search(','); },
      []() { parser.Read_Uint16([](uint16_t data) {Serial.println(data); parser.SkipWhile(','); }); },
      []() { parser.Read_Uint16([](uint16_t data) {Serial.println(data); }); }
  );

  parser.Reset();
  delay(2500);
}
  
