/*SERIAL*/

#include "ParserLib.h"

Parser parser;

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}
  Serial.println("Starting demo");
  Serial.setTimeout(10);

}

void loop() {
  if (Serial.available())
  {
    //Try writing some numbers and separators (, . ; # = are valid separators)
    String reader = Serial.readStringUntil('\n');

    if (reader.length() > 0)
    {
      parser.Init(reader);

      parser.DoWhile(
            []()-> bool { return parser.Search(Parser::IsSeparator);},
            []() { Serial.println(parser.Read_Int8()); parser.SkipWhile(Parser::IsSeparator);},
            []() { Serial.println(parser.Read_Int8()); }
            );
            parser.Reset();
                
    }
  }

}
