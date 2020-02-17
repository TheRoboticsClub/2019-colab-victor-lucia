/*SIMPLE: SENCILLO*/
#include <ParserLib.h>

char demo[] = "AA-123#CC;;276.56__-,;#__abcd-16";
int demoLength = strlen(demo);
Parser parser((byte*)demo, demoLength);

void setup()
{
  Serial.begin(9600);
  while(!Serial) {;}
  Serial.println("Starting demo");
}

void loop()
{
   Serial.println("--- Demo loop ---");
 
   // Demo Prints AA 123 CC 276.56 -16
 
   Serial.println(parser.Read_String('-'));    // Read string until - (AA)
   parser.Skip(1);                           //Ignore -
 
   Serial.println(parser.Read_Int16()); // Read INT16 (123)
   parser.Skip(1); //Ignore #
   
   Serial.println(parser.Read_String(';'));   //Read string until ; (CC)
   parser.SkipWhile(';');  //Ignore ;;
 
   Serial.println(parser.Read_Float());  //Read Float (276.56)
   parser.SkipWhile(Parser::IsSeparator);   // Ignore separators __-,;#__
 
   parser.JumpTo(Parser::IsNumeric);  //Jump to next number (ignore abcd)
   Serial.println(parser.Read_Int32());  //Read Int32 (-16)
 
   parser.Reset();
   delay(2500);
}
