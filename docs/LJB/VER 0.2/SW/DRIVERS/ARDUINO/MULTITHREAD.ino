/*MD 25*/
#include <SoftwareSerial.h>
#include <Wire.h>

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

SoftwareSerial lcd_03 =  SoftwareSerial(LCD_RX, LCD_TX);    // Defines software serial port for LCD03

int x=0, y=0;                                                    // int x stores a value to be used as speed data for the motors


/*MULTITHREADING*/

#include "Thread.h"
#include "ThreadController.h"

#include <TimerOne.h>

#include <Ultrasonic.h>


class SensorThread: public Thread
{
  public: 
    int value; 
    int pin;
    
    void run(){
          value= map(analogRead(pin), 0,1023,0,255);
          runned(); 
      }
};

SensorThread analog1 = SensorThread();
SensorThread analog2 = SensorThread();

class Sensor2Thread: public Thread
{
  public: 
    int value2;
    int trigPin;
    int echoPin;
    
    void run(){
          Ultrasonic ultra(trigPin, echoPin);
          value2= map(ultra.read(CM),0,1023,0,255);
          runned();
      }
};

Sensor2Thread digital1 = Sensor2Thread();
Sensor2Thread digital2 = Sensor2Thread();

 
ThreadController controller = ThreadController();

void timerCallBack(){
    controller.run();
  }

void setup() {
  Wire.begin();
  lcd_03.begin(9600);
  Serial.begin(38400);
  delay(100);
  lcd_03.write(LCD03_CLEAR);
  lcd_03.write(LCD03_HIDE_CUR);
  lcd_03.print("Ejemplo MD25: LJB ");

  //encodeReset();
  
  analog1.pin = A1;
  analog1.setInterval(100);

  analog2.pin = A2;
  analog2.setInterval(100);

  digital1.trigPin = 7;
  digital1.echoPin = 6;
  digital1.setInterval(100);

  digital2.trigPin = 5;
  digital2.echoPin = 4;
  digital2.setInterval(100);
  
  controller.add(&analog1);
  controller.add(&analog2);

  controller.add(&digital1);
  controller.add(&digital2);
  
  Timer1.initialize(20000);
  Timer1.attachInterrupt(timerCallBack);
  Timer1.start();

}

void loop() {
  delay(1000);
  if(Serial.available()){
  switch (Serial.read()){
      case 'F':
      Adelante();
      break;
      case 'B': 
      Atras();
      break;
      case 'R':
      Derecha();
      break;
      case 'L':
      Izquierda();
      break;
      case 'S':
      Parar();
      break;
    }
  
  Serial.print("Analog1 Thread: ");
  Serial.println(analog1.value);

  Serial.print("Analog2 Thread: ");
  Serial.println(analog2.value);

  Serial.print("Digital1 Thread: ");
  Serial.println(digital1.value2);

  Serial.print("Digital2 Thread: ");
  Serial.println(digital2.value2);
  
  }
  
  delay(1000);
}

/*MD25 FUNCTIONS*/
void Adelante(){
      x = 250;
    encodeReset();
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
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED2);
  Wire.write(128);                                           // Sends a value of 128 to motor 2 this value stops the motor
  Wire.endTransmission();
  
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED1);
  Wire.write(128);
  Wire.endTransmission();
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

long encoder2(){                                            // Function to read and display velue of encoder 2 as a long
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

void volts(){                                               // Function to read and display battery volts as a single byte
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

void stopMotor(){                                           // Function to stop motors
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED2);
  Wire.write(128);                                           // Sends a value of 128 to motor 2 this value stops the motor
  Wire.endTransmission();
  
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED1);
  Wire.write(128);
  Wire.endTransmission();
}  
