
//DECLARACIÓN CÓDIGO MOTORES I2C
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Ultrasonic.h>

#define CMD                 (byte)0x00                        // Values of 0 eing sent using write have to be cast as a byte to stop them being misinterperted as NULL
                                                              // This is a but with arduino 1

#define MD25ADDRESS         0x58                              // Address of the MD25
#define SOFTWAREREG         0x0D                              // Byte to read the software version
#define SPEED1              (byte)0x00                        // Byte to send speed to first motor
#define SPEED2              0x01                              // Byte to send speed to second motor
#define ENCODERONE          0x02                              // Byte to read motor encoder 1
#define ENCODERTWO          0x06                              // Byte to read motor encoder 2
#define VOLTREAD            0x0A                              // Byte to read battery volts
#define RESETENCODERS       0x20

#define LCD_RX              0x02                              // RX and TX pins used for LCD0303 serial port
#define LCD_TX              0x03
#define LCD03_HIDE_CUR      0x04
#define LCD03_CLEAR         0x0C
#define LCD03_SET_CUR       0x02

String a;


//DECLARACIÓN DE SENSORES
int data;

Ultrasonic ultraleft(10,11);  // (Trig PIN, Echo PIN)
Ultrasonic ultraright(8,9); // (Trig PIN, Echo PIN)

int value1 = 0;
int value2 = 0;

const int sensorPin1 = 4;
const int sensorPin2 = 5;


//DECLARACIÓN DE ACTIVACIÓN DE SENSORES Y MOTORES
bool actmotors = false;
bool actIR= false; 
bool actUS= false; 

SoftwareSerial lcd_03 =  SoftwareSerial(LCD_RX, LCD_TX);    // Defines software serial port for LCD03

int x=0, y=0;                                                    // int x stores a value to be used as speed data for the motors

void setup() {
  Wire.begin();
  lcd_03.begin(9600);
  Serial.begin(38400);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  delay(500);
  lcd_03.write(LCD03_CLEAR);
  lcd_03.write(LCD03_HIDE_CUR);
  lcd_03.print("Ejemplo MD25: LJB ");
  //Serial.println("Hola soy Arduino. Instrucciones activación: 1)actmotores 2)actUS 3)actIR 4)desmot 5)desUS 6)desIR");
  //Serial.println("Instrucciones ordenes: U) ultrasonidos I) Infrarrojos F) Delante B) Detras L) Izquierda R) Derecha S) Parar");
  encodeReset();
}

void loop() {
  while(Serial.available()){
    data = Serial.read();
    switch (data)
    {
      case '1': 
        EnciendeMOT();
      break;

      case '2':
        EnciendeUS();
      break;

      case '3':
        EnciendeIR();
      break;
      
      case '4':
        ApagaMOT();
      break; 
      
      case '5':
        ApagaUS();
      break;
      
      case '6':
        ApagaIR();
      break;
      
      case 'U': 
        dame_ultrasonidos();
      break;
      
      case 'I':
        dame_infrarrojos();
      break;

      case 'F':
        Adelante();
      break;

      case 'B':
        Atras();
      break;

      case 'L':
        Izquierda();
      break;

      case 'R':
        Derecha();
      break;

      case 'S':
        Parar();
      break;
      
      default:
      break; 
      }
    }  
}

//FUNCIONES CONTROL
void EnciendeMOT(){
    actmotors = true;
    Serial.println("Motores activados");
}

void EnciendeUS(){
    actUS = true;
    Serial.println("Ultrasonidos activados");  
}

void EnciendeIR()
{
    actIR = true;
    Serial.println("Infrarrojos activados"); 
}

void ApagaMOT(){
    actmotors = false; 
    Serial.println("Motores desactivados");
}

void ApagaUS(){
    actUS = false;
    Serial.println("Ultrasonidos desactivados");
}

void ApagaIR(){
    actIR = false;
    Serial.println("Infrarrojos desactivados");
}


//FUNCIONES SENSORES
void dame_ultrasonidos()
{
        if(actUS == true)
        {
            Serial.print("Left: ");
            Serial.print(ultraleft.read(CM)); //CM or INC
            Serial.print("cm      ");
            delay(50);
            Serial.print("Right: ");
            Serial.print(ultraright.read(CM)); //CM or INC
            Serial.print("cm      ");
            Serial.println("");
            delay(50);
         }
         else if(actUS == false){
            Serial.println("Activa ultrasonidos primero.");
         }
}

void dame_infrarrojos()
{
      if(actIR == true){
          value1 = digitalRead(sensorPin1);
          value2 = digitalRead(sensorPin2);
          Serial.print("Ir1: ");
          Serial.print(value1);
          Serial.print("         ");
          delay(50);
          Serial.print("Ir2: ");
          Serial.print(value2);
          Serial.print("         ");
          Serial.println("");
          delay(50);
      }
      else if(actIR == false){ 
          Serial.println("Activa infrarrojos primero.");
      }
     
}

//FUNCIONES MOTORES 

void Adelante()
{
    x = 250;
    encodeReset();
    if(actmotors == true){
      do{                                                        // Start loop to drive motors forward
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 2 at speed value stored in x
    Wire.write(SPEED2);
    Wire.write(x);                                           
    Wire.endTransmission();
  
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 1 at speed value stored in x
    Wire.write(SPEED1);
    Wire.write(x);
    Wire.endTransmission();
 
    encoder1();                                             // Calls a function that reads and displays value of encoder 1 to LCD03
    encoder2();                                             // Calls a function that reads and displays value of encoder 2 to LCD03
    volts();                                                // Calls function that reads and displays battery volts
    }while(encoder1() < 5000 && encoder2() < 5000);          // Loop untill encoder 1 is 5000 or more
    }
    else if(actmotors == false)
    {
      Serial.println("Activa motores primero.");
    }
    //stopMotor();
    //delay(1000);
      
/*      
      Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED2);
      Wire.write(x);

      Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED1);
      Wire.write(x);
      Wire.endTransmission();

      encoder1();
      encoder2();
      volts();
      delay(10000);
      stopMotor();
      delay(1000);
  
*/
}

  
void Atras()
{
      encodeReset();
      x = 10;
   if(actmotors == true){
      do{                                                        // Start loop to drive motors forward
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 2 at speed value stored in x
    Wire.write(SPEED2);
    Wire.write(x);                                           
    Wire.endTransmission();
  
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 1 at speed value stored in x
    Wire.write(SPEED1);
    Wire.write(x);
    Wire.endTransmission();
 
    encoder1();                                             // Calls a function that reads and displays value of encoder 1 to LCD03
    encoder2();                                             // Calls a function that reads and displays value of encoder 2 to LCD03
    volts();                                                // Calls function that reads and displays battery volts
    }while(encoder1() >0 && encoder2() >0);          // Loop untill encoder 1 is 5000 or more
   }
   else if(actmotors == false){
    Serial.println("Activa motores primero.");
    }
      
/*     Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED2);
      Wire.write(x);

      Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED1);
      Wire.write(x);
      Wire.endTransmission();
      
      encoder1();
      encoder2();
      volts();
      delay(10000);
      stopMotor();
      delay(1000);
  */

  
}
  
void Derecha(){
      x = 250;
      y = 10;
      encodeReset();
    if(actmotors == true){
    do{                                               // Start loop to drive motors forward
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 2 at speed value stored in x
    Wire.write(SPEED2);
    Wire.write(x);                                           
    Wire.endTransmission();
  
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 1 at speed value stored in x
    Wire.write(SPEED1);
    Wire.write(y);
    Wire.endTransmission();
 
    encoder1();                                             // Calls a function that reads and displays value of encoder 1 to LCD03
    encoder2();                                             // Calls a function that reads and displays value of encoder 2 to LCD03
    volts();                                                // Calls function that reads and displays battery volts
    }while(encoder2()<5000);
    }
    else if(actmotors == false)
    {
      Serial.println("Activa motores primero.");
      }
/*     
      Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED2);
      Wire.write(y);

      Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED1);
      Wire.write(x);
      Wire.endTransmission();

      encoder1();
      encoder2();
      volts();
      delay(10000);
      stopMotor();
      delay(1000);
*/
     
}
  
void Izquierda()
{
    x = 10;
    y = 250;
    if(actmotors == true){
    encodeReset();
    do{                                                        // Start loop to drive motors forward
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 2 at speed value stored in x
    Wire.write(SPEED2);
    Wire.write(x);                                           
    Wire.endTransmission();
  
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 1 at speed value stored in x
    Wire.write(SPEED1);
    Wire.write(y);
    Wire.endTransmission();
 
    encoder1();                                             // Calls a function that reads and displays value of encoder 1 to LCD03
    encoder2();                                             // Calls a function that reads and displays value of encoder 2 to LCD03
    volts();                                                // Calls function that reads and displays battery volts
    }while(encoder2() >0);          // Loop untill encoder 1 is 5000 or more
    }
    else if(actmotors == false)
    {
      Serial.println("Activa motores primero.");
      }
/*   
     Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED2);
      Wire.write(x);

      Wire.beginTransmission(MD25ADDRESS);
      Wire.write(SPEED1);
      Wire.write(y);
      Wire.endTransmission();

      encoder1();
      encoder2();
      volts();
      delay(10000);
      stopMotor();
      delay(1000);
*/

}

void Parar()
{
  if(actmotors == true){
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED2);
  Wire.write(128);                                           // Sends a value of 128 to motor 2 this value stops the motor
  Wire.endTransmission();
  
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED1);
  Wire.write(128);
  Wire.endTransmission();
  }
  else if(actmotors== false){
    Serial.println("Activa motores primero");
    }
}

      
byte getSoft(){                                              // Function that gets the software version
  Wire.beginTransmission(MD25ADDRESS);                      // Send byte to read software version as a single byte
  Wire.write(SOFTWAREREG);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 1);                         // request 1 byte form MD25
  while(Wire.available() < 1);                              // Wait for it to arrive
  byte software = Wire.read();                            // Read it in
  return(software);
}

void encodeReset(){                                        // This function resets the encoder values to 0
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(CMD);
  Wire.write(0x20);                                         // Putting the value 0x20 to reset encoders
  Wire.endTransmission(); 
}

long encoder1(){                                            // Function to read and display value of encoder 1 as a long
  Wire.beginTransmission(MD25ADDRESS);                      // Send byte to get a reading from encoder 1
  Wire.write(ENCODERONE);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 4);                         // Request 4 bytes from MD25
  while(Wire.available() < 4);                              // Wait for 4 bytes to arrive
  long poss1 = Wire.read();                                 // First byte for encoder 1, HH.
  poss1 <<= 8;
  poss1 += Wire.read();                                     // Second byte for encoder 1, HL
  poss1 <<= 8;
  poss1 += Wire.read();                                     // Third byte for encoder 1, LH
  poss1 <<= 8;
  poss1  +=Wire.read();                                     // Fourth byte for encoder 1, LL

  lcd_03.write(LCD03_SET_CUR);  
  lcd_03.write(21);                                         // Move cursor to space 21
  lcd_03.print("Encoder 1 ");
  lcd_03.print(poss1, DEC);                                 // Print encoder 1 value to LCD03
  lcd_03.print("   ");                                      // Print some spaces to clear space after encoder value
  delay(50);                                                // Wait for everything to make sure everything is sent
  
  return(poss1);
}

long encoder2()
{                                            // Function to read and display velue of encoder 2 as a long
  Wire.beginTransmission(MD25ADDRESS);           
  Wire.write(ENCODERTWO);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 4);                         // Request 4 bytes from MD25
  while(Wire.available() < 4);                              // Wait for 4 bytes to become available
  long poss2 = Wire.read();
  poss2 <<= 8;
  poss2 += Wire.read();                
  poss2 <<= 8;
  poss2 += Wire.read();                
  poss2 <<= 8;
  poss2  +=Wire.read();               
  
  lcd_03.write(LCD03_SET_CUR);
  lcd_03.write(41);                                   
  lcd_03.print("Encoder 2 ");
  lcd_03.print(poss2, DEC);                                 
  lcd_03.print("   ");                                      // Print some spaces to clear space after encoder value
  delay(50);                                                // Wait to make sure everything is sent
   
  return(poss2);
}

void volts()
{                                               // Function to read and display battery volts as a single byte
  Wire.beginTransmission(MD25ADDRESS);                      // Send byte to read volts
  Wire.write(VOLTREAD);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 1);
  while(Wire.available() < 1);                               
  int batteryVolts = Wire.read();
  
  lcd_03.write(LCD03_SET_CUR);
  lcd_03.write(61);
  lcd_03.print("Battery v = ");
  lcd_03.print(batteryVolts/10, DEC);                       // Print batery volts / 10 to give you the number of whole volts
  lcd_03.print(".");                                        // As arduino has truncates floating point numbers we print a . here to act as a decimal point
  lcd_03.print(batteryVolts%10, DEC);                       // Prints Battery volts % 10 to give us the 
  
  delay(50);                                                // Wait to make sure everything is sent
}

void stopMotor()
{                                           // Function to stop motors
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED2);
  Wire.write(128);                                           // Sends a value of 128 to motor 2 this value stops the motor
  Wire.endTransmission();
  
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED1);
  Wire.write(128);
  Wire.endTransmission();
}  
