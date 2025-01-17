
/***************************************************
 *          Arduino MD25 example code              *
 *          MD25 running in serial code            *
 *          
 *          by James Henderson 2012                *
 ***************************************************/

 #include <SoftwareSerial.h>

 //Values of 0 being sent using serial.write() have to be cast as a byte 
 //to stop them being misinterpreted as NULL
 //this is a bug with arduino 1
 #define CMD                (byte)0x00          // MD25 command byte of 0

 #define WRITESP1          0x31                // Byte writes speed to motor 1
 #define WRITEACCEL         0x33                // Byte writes a value of acceleration
 #define RESETREG            0x35                // Byte resets encoders
 #define SETMODE            0x34                // Byte sets mode 
 #define READIVS            0x2C                // Byte reads motor currents and battery voltage
 #define READENCS           0x25                // Byte reads both encoders
 #define GET_VER            0x29

 #define LCD_RX             0x02                // RX and TX pins used for LCD0303 serial port
 #define LCD_TX             0x03
 #define LCD03_HIDE_CUR     0x04
 #define LCD03_CLEAR        0x0C
 #define LCD03_SET_CUR      0x02

SoftwareSerial lcd03 = SoftwareSerial(LCD_RX, LCD_TX);   //Define the serial port for the LCD03

long encValue = 0;
byte softwareRev = 0;

void setup(){
  Serial.begin(38400);
  lcd03.begin(9600);

  Serial.write(CMD);              //Set MD25 acceleration value
  Serial.write(WRITEACCEL);
  Serial.write(10);
  delayMicroseconds(10);          // Wait for this to be processed
  Serial.write(CMD);              //Reset the encoder registers to 0
  Serial.write(RESETREG);
  Serial.write(CMD);
  Serial.write(SETMODE);
  Serial.write(2);

  Serial.write(CMD);              //Get software version of MD25
  Serial.write(GET_VER);
  while(Serial.available() < 1){} //Whait for byte to become available  
  softwareRev = Serial.read();

  lcd03.write(LCD03_CLEAR);       //Clear the LCD03 screen
  lcd03.write(LCD03_HIDE_CUR);    //Hide the LCD03 cursor
  
  }

void loop(){
  while(encValue < 3000){         //While encoder 1 value less than 3000 move forward
    Serial.write(CMD);            //Set motors to drive forward at full speed
    Serial.write(WRITESP1);
    Serial.write(150);
    encValue = readEncoder();
    readVolts();
    }
    delay(100);
    
    while(encValue > 100){          //Drive motors reverse at full speed  
    Serial.write(CMD);
    Serial.write(WRITESP1);
    Serial.write(100);
    encValue = readEncoder();
    readVolts();      
    }
    delay(100);
}

 long readEncoder(){               //Function to read and display the value of both encoders, returns value of first encoder   
    long result1 = 0;
    long result2 = 0;
    Serial.write(CMD);
    Serial.write(READENCS);
    while(Serial.available() < 8){} //Wait for 8 bytes, first 4 encoder 1 values second 4 encoder 2 values
    result1 = Serial.read();        //First byte for encoder 1, HH,
    result1 <<=8; 
    result1 +=Serial.read();        //Second byte for encoder 1, HL
    result1 <<=8;
    result1 +=Serial.read();        //Third byte for encoder 1, LH
    result1 <<=8;
    result1 +=Serial.read();        //Fourth byte for encoder 1, LL 
    
    result2 = Serial.read();
    result2 <<=8;
    result2 +=Serial.read();
    result2 <<=8;
    result2 +=Serial.read();
    result2 <<=8;
    result2 +=Serial.read();

    lcd03.write(LCD03_SET_CUR);     //Set the LCD03 cursor position
    lcd03.write(21);
    lcd03.print("Encoder 1:");      //Displays data to the LCD03 screen
    lcd03.print(result1,DEC);
    lcd03.print(" ");               //Print a black space to clear any unwanted characters that are leftover on the LCD03 display

    delay(5);                       //Delay for LCD03 to process data

    lcd03.write(LCD03_SET_CUR);
    lcd03.write(41);
    lcd03.print("Encoder 2:");
    lcd03.print(result2,DEC);
    lcd03.print(" ");
    return result1;
 } 

 void readVolts()                  //Function reads current for both motors and battery voltage
 {
    byte batteryVolts, mot1_current, mot2_current = 0;
    Serial.write(CMD);
    Serial.write(READIVS);        //Send byte to read battery voltage and motor currents
    while(Serial.available() <3){}
    batteryVolts = Serial.read();
    mot1_current = Serial.read();
    mot2_current = Serial.read();

    lcd03.write(LCD03_SET_CUR);
    lcd03.write(61);
    lcd03.print("Mot1 I:");
    lcd03.print(mot1_current,DEC);
    lcd03.print("Mot2 I:");
    lcd03.print(mot2_current,DEC);
    lcd03.print(" ");

    delay(5);

    lcd03.write(LCD03_SET_CUR);
    lcd03.write(1);
    lcd03.print("Rev:");
    lcd03.print(softwareRev, DEC);
    lcd03.print(" ");
    lcd03.print("Volts:");
    lcd03.print(batteryVolts/10,DEC);
    lcd03.print(".");
    lcd03.print(batteryVolts%10,DEC);
    lcd03.print(" ");
  
  }
