/*********************
Digole Serial display module with touch screen demo
NOTE: if you using UART mode, you need to disconnect the RX from Arduino
When you uploading your sketch
**********************/
#define _Digole_Serial_I2C_  //To tell compiler compile the special communication only, 
#define _ESP8266_
#define VER 40    // Set the right firmware Version currently 4.0
//all available are:_Digole_Serial_UART_, _Digole_Serial_I2C_ and _Digole_Serial_SPI_
#include <DigoleSerial.h>
//--------UART setup
#if defined(_Digole_Serial_UART_)
DigoleSerialDisp mydisp(&Serial, 38400); //UART:Arduino UNO: Pin 1(TX)on arduino to RX on module
#endif
//--------I2C setup
#if defined(_Digole_Serial_I2C_)
#if defined(_ESP8266_)
#include <SlowSoftWire.h>
SlowSoftWire Wire = SlowSoftWire(4, 5);       // ESP8266
//SlowSoftWire Wire = SlowSoftWire(21, 22);       // ESP32
//SlowSoftWire Wire = SlowSoftWire(20, 21);   // Mega2560
#else
//#include <Wire.h>
#endif
DigoleSerialDisp mydisp(&Wire,'\x27');  //I2C:Arduino UNO: SDA (data line) is on analog input pin 4, and SCL (clock line) is on analog input pin 5 on UNO and Duemilanove
#endif
//--------SPI setup
#if defined(_Digole_Serial_SPI_)
//IMPORTANT: A 4.7K~20K PULL DOWN RESISTOR NEEDED BETWEEN SI(11) AND GROUND IN ORDER TO OPERATE TOUCH SCREEN
//AND FLASH MEMORY CORRECTLY
DigoleSerialDisp mydisp(8,9,10,11);  //SPI:Pin 8: data, 9:clock, 10: SS, 11:SI. you can assign 255 to SS, and hard ground SS pin on module
#endif

#include <GroveColorSensor.h>

void readTouchScreen(void);
int x,y;

void setup() {
  Serial.begin(115200);
  delay (2000);
  
  mydisp.begin();
  mydisp.setBgColor(0x0); //set another back ground color
  mydisp.setColor(0xFF); //set fore ground color, 8bit format, for 24bit color format, use:setTrueColor(R,G,B)
  mydisp.clearScreen();
  mydisp.setColor(0xFF);

//  mydisp.print("Clear screen,\nNext Line.\r-Return-\n\rNew Line...");
    mydisp.setPrintPos(0,40,1);
    mydisp.print("Color Sensor RGB Values");

//  mydisp.setColor(0B11111100);  //256 color format RRRGGGBB
//  mydisp.setTrueColor(63,63,0);  //262K color format Red, Green, Blue 0~63    
  mydisp.drawStr(7,10,"Touch Screen Test");
  mydisp.setColor(0xFF);
//  delay(20);
}

void loop()
{
//  mydisp.readTouchScreen(&x, &y);
  mydisp.readTouchScreen();

    x=mydisp.read1();
    x<<=8;
    x+=mydisp.read1();
    y=mydisp.read1();
    y<<=8;
    y+=mydisp.read1();
    
  if (y < 500) {  
#ifdef _PRINT_
    Serial.print("Touch X,Y = ");
    Serial.print(x, DEC);
    Serial.print(" ");
    Serial.print(y, DEC);
    Serial.println(" ");
#endif

    mydisp.setColor(0x0);
    mydisp.drawBox(0, 0, 60, 16); 

    mydisp.setColor(0xFF);
    mydisp.setPrintPos(0,16,1);
    mydisp.print(x);
    mydisp.print(',');
    mydisp.print(y);
  }
  
  if ((x < 240) || (y < 400) ) {
    mydisp.drawPixel(x,y);
  }
  
  if ((x < 50) && (y < 50) ) {
    mydisp.clearScreen();
  }
  
  Color();
}


void Color(void)
{
  uint8_t closestColor;
  int red, green, blue;
  GroveColorSensor colorSensor;
  colorSensor.ledStatus = 1;  // When turn on the color sensor LED, ledStatus = 1; When turn off the color sensor LED, ledStatus = 0.

  colorSensor.readRGB(&red, &green, &blue);   //Read RGB values to variables.
//    delay(300);
#ifdef _PRINT_
  Serial.print("RGB = ");
  Serial.print(red,DEC);
  Serial.print(", ");
  Serial.print(green,DEC);
  Serial.print(", ");
  Serial.println(blue,DEC);
#endif

//  closestColor = (red & 0xE0) | ((green >> 3) & 0x1C) | ((blue >> 6) & 0x03);
  mydisp.setColor(closestColor);
  
  mydisp.setTrueColor(red >> 2, green >> 2, blue >> 2);  //262K color format Red, Green, Blue 0~63    
  mydisp.drawBox(0, 40, 80, 80); 
  
  mydisp.setColor(0xFF);
  mydisp.setPrintPos(0,60,1);
  mydisp.print(red);
  mydisp.print(',');
  mydisp.print(green);
  mydisp.print(',');
  mydisp.print(blue);

  colorSensor.clearInterrupt();
}

