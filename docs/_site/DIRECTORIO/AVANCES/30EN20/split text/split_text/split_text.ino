#include "ParserLib.h"

char demo[] = "AA-BB#CC;DD?";
int demoLength = strlen(demo);

Parser parser((byte*)demo, demoLength);

void setup() 
{
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("Starting Demo");
}

void loop() 
{
  Serial.println("--- Demo loop ---");

  //Example without using success Callback
  Serial.println(" - Example 1 - ");
  parser.DoWhile(
      //Condition
      []()-> bool { return parser.Search(Parser::IsSeparator); },
      //CallBack
      []() { Serial.print("Received:");
        Serial.println(parser.Read_String(Parser::IsSeparator));
        parser.SkipWhile(Parser::IsSeparator); },
      //Finally
      []() { Serial.print("Finally:");
             Serial.println(parser.Read_String(Parser::IsSeparator));}
   );

   parser.Reset();
   //Example using success Callback
   Serial.println(" - Example 2 - ");
   parser.DoWhile(
    //Condition
    []()-> bool { return parser.Search(Parser::IsSeparator); },
    //Callback
    []() { parser.Read_String(Parser::IsSeparator,
         [](String& data) {   Serial.print("Received:");
                           Serial.println(data); });
                           parser.SkipWhile(Parser::IsSeparator); },
    //Finally
    []() { parser.Read_String(Parser::IsSeparator,
        [](String& data) { Serial.print("Finally:");
                      Serial.println(data); }); }
    );

    parser.Reset();
    delay(2500);
}
