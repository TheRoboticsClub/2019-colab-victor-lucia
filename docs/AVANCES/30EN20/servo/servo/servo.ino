/*SERVO*/ 
#include "ParserLib.h"

char demo[] = "SERVO12_185.67";
int demoLength = strlen(demo);

Parser parser((byte*)demo, demoLength);

void setup() 
{
    Serial.begin(9600);
    while(!Serial) { ; }
    Serial.println("Starting Demo");
}

void loop() 
{
    Serial.println("--- Demo loop ---");
    parser.Compare("SERVO", 5,
    []()  {   Serial.print("Received SERVO N:");
           uint8_t servo = parser.Read_Uint8();
           Serial.print(servo);
           parser.SkipWhile(Parser::IsSeparator);
           Serial.print(" Angle:");
           Serial.print(parser.Read_Float());
    });

    parser.Reset();
    delay(2500);
}
