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

/*
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
*/
/*
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

  /////////////////////////////

    //keep the mqtt up and running
  if (awsWSclient.connected ()) {
      digitalWrite(LED_BUILTIN, HIGH);
      client->yield(3000);
      digitalWrite(LED_BUILTIN, LOW);
      if (digitalRead(4) == HIGH)
        sendmessage();
  } else {
    //handle reconnection
    if (connect ()){
      //subscribe ();      
    }
  }
}
*/

/*void Color(void) //color values saved as ints; "red", "green", "blue"
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

}*/


//////////////////////////////////////////////////////////////////


#include <Arduino.h>
#include <Stream.h>
#include <stdlib.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

//AWS
#include "sha256.h"
#include "Utils.h"
#include "AWSClient2.h"

//WEBSockets
#include <Hash.h>
#include <WebSocketsClient.h>

//MQTT PAHO
#include <SPI.h>
#include <IPStack.h>
#include <Countdown.h>
#include <MQTTClient.h>



//AWS MQTT Websocket
#include "Client.h"
#include "AWSWebSocketClient.h"
#include "CircularByteBuffer.h"

//AWS IOT config, change these:
char wifi_ssid[]       = "shanroute";
char wifi_password[]   = "make1234";
char aws_endpoint[]    = "a3ztff83wu2hw.iot.us-west-2.amazonaws.com";
char aws_key[]         = "AKIAJJBOCCLJ2HRB3TDQ";
char aws_secret[]      = "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";
char aws_region[]      = "us-west-2";
const char* aws_topic  = "topic1";
int port = 443;

//MQTT config
const int maxMQTTpackageSize = 512;
const int maxMQTTMessageHandlers = 1;
ESP8266WiFiMulti WiFiMulti;
AWSWebSocketClient awsWSclient(1000);
IPStack ipstack(awsWSclient);
MQTT::Client<IPStack, Countdown, maxMQTTpackageSize, maxMQTTMessageHandlers> *client = NULL;
//# of connections
long connection = 0;
//generate random mqtt clientID
char* generateClientID () {
  char* cID = new char[23]();
  for (int i=0; i<22; i+=1)
    cID[i]=(char)random(1, 256);
  return cID;
}
//count messages arrived
int arrivedcount = 0;
//callback to handle mqtt messages
/*
void messageArrived(MQTT::MessageData& md)
{
  MQTT::Message &message = md.message;
  Serial.print("Message ");
  Serial.print(++arrivedcount);
  Serial.print(" arrived: qos ");
  Serial.print(message.qos);
  Serial.print(", retained ");
  Serial.print(message.retained);
  Serial.print(", dup ");
  Serial.print(message.dup);
  Serial.print(", packetid ");
  Serial.println(message.id);
  Serial.print("Payload ");
  char* msg = new char[message.payloadlen+1]();
  memcpy (msg,message.payload,message.payloadlen);
  Serial.println(msg);
  delete msg;
}
*/
//connects to websocket layer and mqtt layer
bool connect () {
    if (client == NULL) {
      client = new MQTT::Client<IPStack, Countdown, maxMQTTpackageSize, maxMQTTMessageHandlers>(ipstack);
    } else {
      if (client->isConnected ()) {    
        client->disconnect ();
      }  
      delete client;
      client = new MQTT::Client<IPStack, Countdown, maxMQTTpackageSize, maxMQTTMessageHandlers>(ipstack);
    }
    //delay is not necessary... it just help us to get a "trustful" heap space value
    delay (1000);
    Serial.print (millis ());
    Serial.print (" - conn: ");
    Serial.print (++connection);
    Serial.print (" - (");
    Serial.print (ESP.getFreeHeap ());
    Serial.println (")");
   int rc = ipstack.connect(aws_endpoint, port);
    if (rc != 1)
    {
      Serial.println("error connection to the websocket server");
      return false;
    } else {
      Serial.println("websocket layer connected");
    }
    Serial.println("MQTT connecting");
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.MQTTVersion = 3;
    char* clientID = generateClientID ();
    data.clientID.cstring = clientID;
    rc = client->connect(data);
    delete[] clientID;
    if (rc != 0)
    {
      Serial.print("error connection to MQTT server");
      Serial.println(rc);
      return false;
    }
    Serial.println("MQTT connected");
    return true;
}
//subscribe to a mqtt topic
/*
void subscribe () {
   //subscript to a topic
    int rc = client->subscribe(aws_topic, MQTT::QOS0, messageArrived);
    if (rc != 0) {
      Serial.print("rc from MQTT subscribe is ");
      Serial.println(rc);
      return;
    }
    Serial.println("MQTT subscribed");
}
*/
//send a message to a mqtt topic & find color values
void sendmessage () {

  
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

  
    //send a message
    MQTT::Message message;
    char buf[100];
    //strcpy(buf, "{\"state\":{\"reported\":{\"on\": false}, \"desired\":{\"on\": false}}}");
    //char buf[8];
    itoa(red, buf, 10);
    strcpy(buf, buf);
    message.qos = MQTT::QOS0;
    message.retained = false;
    message.dup = false;
    message.payload = (void*)buf;
    message.payloadlen = strlen(buf)+1;
    int rc = client->publish(aws_topic, message); 
}
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


    pinMode(4, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    
    delay (2000);
    Serial.setDebugOutput(1);
    //fill with ssid and wifi password
    WiFiMulti.addAP(wifi_ssid, wifi_password);
    Serial.println ("connecting to wifi");
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
        Serial.print (".");
    }
    Serial.println ("\nconnected");
    //fill AWS parameters    
    awsWSclient.setAWSRegion(aws_region);
    awsWSclient.setAWSDomain(aws_endpoint);
    awsWSclient.setAWSKeyID(aws_key);
    awsWSclient.setAWSSecretKey(aws_secret);
    awsWSclient.setUseSSL(true);
    if (connect ()){
     // subscribe ();
     // sendmessage ();
    }
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
  
  //Color();

  /////////////////////////////

    //keep the mqtt up and running.
  if (awsWSclient.connected ()) {
      digitalWrite(LED_BUILTIN, HIGH);
      //client->yield(3000); //Comm rate with AWS server, also controls speed of loop, color acquisition
      digitalWrite(LED_BUILTIN, LOW);
      if (digitalRead(4) == HIGH)
        sendmessage();
  } else {
    //handle reconnection
    if (connect ()){
      //subscribe ();      
    }
  }
}

