/*COMMAND RECEIVE*/

#include "ParserLib.h"

char demo[] = "CMD3";
int demoLength = strlen(demo);

Parser parser((byte*)demo, demoLength);

void setup() 
{
    Serial.begin(9600);
    while(!Serial) {;}
    Serial.println("Starting Demo");
}

void loop() 
{
   Serial.println("---Demo loop ---");
   parser.Compare("CMD1", 4, [] () {Serial.println("Command1 Received"); });
   parser.Compare("CMD2", 4, [] () {Command(2); });
   parser.Compare("CMD3", 4, Command3);

   parser.Reset();
   delay(2500);
   
}

void Command3()
{
  Command(3);  
}

void Command(int num)
{
    Serial.print("Command");
    Serial.print(num);
    Serial.println(" received");  
}
