/*
 * Sketch to control the pins of Arduino via serial interface
 *
 * Commands implemented with examples:
 *
 * - RD13 -> Reads the Digital input at pin 13
 * - RA4 - > Reads the Analog input at pin 4
 * - WD13:1 -> Writes 1 (HIGH) to digital output pin 13
 * - WA6:125 -> Writes 125 to analog output pin 6 (PWM)
 */

//#include <OctoWS2811.h>
#include <Wire.h>
//#include <math.h>
#include <GroveColorSensor.h>

//#define DEBUG

const int ledsPerStrip = 36;


//DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

//const int config = WS2811_GRB | WS2811_800kHz;

//OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);
void controlLoop(void);

void setup() {
  Wire.begin();
//  leds.begin();
//  leds.show();
  
  Serial.begin(9600);

  Serial.println("setupOurStuff");
  
  //From the traffic light
  Serial.setTimeout(100); // Instead of the default 1000ms, in order
                          // to speed up the Serial.parseInt()
//  lightSetup ();
}

//#define RED    0xFF0000
//#define GREEN  0x00FF00
//#define BLUE   0x0000FF
//#define YELLOW 0xFFFF00
//#define PINK   0xFF1088
//#define ORANGE 0xE05800
//#define WHITE  0xFFFFFF

// Less intense...

#define RED    0x160000
#define GREEN  0x001600
#define BLUE   0x000016
#define YELLOW 0x101400
#define PINK   0x120009
#define ORANGE 0x100400
#define WHITE  0x101010
/*
struct rgb_t {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} rgbColor;
*/
//  colorSensor.ledStatus = 1;  // When turn on the color sensor LED, ledStatus = 1; When turn off the color sensor LED, ledStatus = 0.

int microsec = 1; 

int lightMode = 0;  // 0 = normal, 1 = emergency
//GroveColorSensor colorSensor;

#define COLOR_LENGTH 10

void loop() {
  //From traffic light
  //lightController ();
  
  int red, green, blue;
  int old_red, old_green, old_blue;
  int red_avg, green_avg, blue_avg;
  int count;
  int redArray[COLOR_LENGTH];
  int greenArray[COLOR_LENGTH];
  int blueArray[COLOR_LENGTH];

  for (count = 0; count < COLOR_LENGTH; count++)
  {
    redArray[count] = 0;
    greenArray[count] = 0;
    blueArray[count] = 0;
  }

  while (1) {
    Serial.println("loop");
  
  // uncomment for voltage controlled speed
  // millisec = analogRead(A9) / 40;

#ifdef DEBUG
    testColorFade();
#else
    GroveColorSensor colorSensor;
    old_red = red;
    old_green = green;
    old_blue = blue;
    
    colorSensor.readRGB(&red, &green, &blue);   //Read RGB values to variables.

    //red = red / 2;
    //green = green / 2;
    //blue = blue / 2;
    if (lightMode == 1) {
      red   = 255;
      green = 255;
      blue  = 255;
    } else if (lightMode == 2) {
      //blue  = 255;
      //red   = 255;
      colorFadeLong(50, 50, 230, 200, 190, 10);
      colorFadeLong(200, 190, 10, 230, 50, 0);
      delay(3000);
      lightMode = 0;
    } else if (lightMode == 3) {
      red   = 255;
      //green = 1;
      //blue  = 1;
    }

    
    if (red   > 255) red = 255;
    if (green > 255) green = 255;
    if (blue  > 255) blue = 255;
    /*
    if (red   < 20) red = 20;
    if (green < 20) green = 18;
    if (blue  < 20) blue = 5;
    */

//    if (red > green) red = green - 10;
//    if (green > 255) green = 255;
//    if (blue > 255) blue = 255;

//    for (count = 0; count < (COLOR_LENGTH - 1); count++)
//    {
//      redArray[count] = redArray[count + 1];
//      greenArray[count] = greenArray[count + 1];
//      blueArray[count] = blueArray[count + 1];
//    }
//
//    redArray[COLOR_LENGTH - 1] = red;
//    greenArray[COLOR_LENGTH - 1] = green;
//    blueArray[COLOR_LENGTH - 1] = blue;
//
//    red_avg = redArray[0];
//    green_avg = greenArray[0];
//    blue_avg = blueArray[0];
//
//    for (count = 1; count < COLOR_LENGTH; count++)
//    {
//      red_avg += redArray[count];
//      green_avg += greenArray[count];
//      blue_avg += blueArray[count];
//    }
//
//    red = red_avg / COLOR_LENGTH;
//    green = green_avg / COLOR_LENGTH;
//    blue = blue_avg / COLOR_LENGTH;
    
    //delay(0);
    Serial.print("The RGB value are: RGB( ");
    Serial.print(red,DEC);
    Serial.print(", ");
    Serial.print(green,DEC);
    Serial.print(", ");
    Serial.print(blue,DEC);
    Serial.println(" )");
    colorSensor.clearInterrupt();

//  colorWipe(red, green, blue, microsec);
//    colorFade(old_red, old_green, old_blue, red, green, blue);
#endif

  }
}

void testColorFade (void)
{
//  colorFade (32, 192, 64, 224, 16, 128);
}

//******

void colorFadeLong(int start_red, int start_green, int start_blue, int end_red, int end_green, int end_blue)
{
  int red_step, green_step, blue_step;
  int inter_red, inter_green, inter_blue;
  int count;

  int STEPS = 60;

  inter_red   = start_red;
  inter_green = start_green;
  inter_blue  = start_blue;

  if (start_red >= end_red)
  {
    red_step = - ((start_red - end_red) / STEPS);
  } else 
  {
    red_step = (end_red - start_red) / STEPS;
  }

  if (start_green >= end_green)
  {
     green_step = - ((start_green - end_green) / STEPS);
  } else 
  {
     green_step = (end_green - start_green) / STEPS;
  }

  if (start_blue >= end_blue)
  {
    blue_step = - ((start_blue - end_blue) / STEPS);
  } else 
  {
    blue_step = (end_blue - start_blue) / STEPS;
  }

#ifdef DEBUG
    Serial.print("The step value are: Red Green Blue( ");
    Serial.print(red_step,DEC);
    Serial.print(", ");
    Serial.print(green_step,DEC);
    Serial.print(", ");
    Serial.print(blue_step,DEC);
    Serial.println(" )");
#endif

// loop 32 times writing slightly different color at each iteration  
//  for (count = 0; count < STEPS; count++)
//  {
//    inter_red   += red_step;
//    inter_green += green_step;
//    inter_blue  += blue_step;
//    
//    for (int i=0; i < leds.numPixels(); i++)
//    {
//      leds.setPixel(i, inter_red, inter_green, inter_blue);
//    }
//    leds.show();
//
//    myDelayLong();
// 
//  }
//
//// write exact final color here
//  for (int i=0; i < leds.numPixels(); i++)
//  {
//    leds.setPixel(i, end_red, end_green, end_blue);
//  }
//  leds.show();
}

void myDelayLong (void) {
    long endTime = millis() + 120;
    while(millis() < endTime) {
        controlLoop();
    }
}

//******


#define STEPS 15

void colorFade(int start_red, int start_green, int start_blue, int end_red, int end_green, int end_blue)
{
  int red_step, green_step, blue_step;
  int inter_red, inter_green, inter_blue;
  int count;

  inter_red   = start_red;
  inter_green = start_green;
  inter_blue  = start_blue;

  if (start_red >= end_red)
  {
    red_step = - ((start_red - end_red) / STEPS);
  } else 
  {
    red_step = (end_red - start_red) / STEPS;
  }

  if (start_green >= end_green)
  {
     green_step = - ((start_green - end_green) / STEPS);
  } else 
  {
     green_step = (end_green - start_green) / STEPS;
  }

  if (start_blue >= end_blue)
  {
    blue_step = - ((start_blue - end_blue) / STEPS);
  } else 
  {
    blue_step = (end_blue - start_blue) / STEPS;
  }

#ifdef DEBUG
    Serial.print("The step value are: Red Green Blue( ");
    Serial.print(red_step,DEC);
    Serial.print(", ");
    Serial.print(green_step,DEC);
    Serial.print(", ");
    Serial.print(blue_step,DEC);
    Serial.println(" )");
#endif

// loop 32 times writing slightly different color at each iteration  
//  for (count = 0; count < STEPS; count++)
//  {
//    inter_red   += red_step;
//    inter_green += green_step;
//    inter_blue  += blue_step;
//    
//    for (int i=0; i < leds.numPixels(); i++)
//    {
//      leds.setPixel(i, inter_red, inter_green, inter_blue);
//    }
//    leds.show();
//
//    myDelay();
// 
//  }

// write exact final color here
//  for (int i=0; i < leds.numPixels(); i++)
//  {
//    leds.setPixel(i, end_red, end_green, end_blue);
//  }
//  leds.show();
}

void myDelay (void) {
    long endTime = millis() + 15;
    while(millis() < endTime) {
        controlLoop();
    }
}

// depreceated
//void colorWipe(int red, int green, int blue, int wait)
//{
//
//  for (int i=0; i < leds.numPixels(); i++)
//  {
//    leds.setPixel(i, red, green, blue);
//  }
//  leds.show();
  //delayMicroseconds(wait);
//}


//*******************************************************************************************

double startTime;
double lastTime = 0;

char operation; // Holds operation (R, W, ...)
char mode; // Holds the mode (D, A)
int pin_number; // Holds the pin number
int digital_value; // Holds the digital value
int analog_value; // Holds the analog value
int value_to_write; // Holds the value that we want to write
int wait_for_transmission = 25; // Delay in ms in order to receive the serial data

void set_pin_mode(int pin_number, char mode){
    /*
     * Performs a pinMode() operation depending on the value of the parameter
     * mode :
     * - I: Sets the mode to INPUT
     * - O: Sets the mode to OUTPUT
     * - P: Sets the mode to INPUT_PULLUP
     */

    switch (mode){
        case 'I':
            pinMode(pin_number, INPUT);
            break;
        case 'O':
            pinMode(pin_number, OUTPUT);
            break;
        case 'P':
            pinMode(pin_number, INPUT_PULLUP);
            break;
    }
}

void digital_read(int pin_number){
    /*
     * Performs a digital read on pin_number and returns the value read to serial
     * in this format: D{pin_number}:{value}\n where value can be 0 or 1
     */

    digital_value = digitalRead(pin_number);
    Serial.print('D');
    Serial.print(pin_number);
    Serial.print(':');
    Serial.println(digital_value); // Adds a trailing \n
}

void analog_read(int pin_number){
    /*
     * Performs an analog read on pin_number and returns the value read to serial
     * in this format: A{pin_number}:{value}\n where value ranges from 0 to 1023
     */

    analog_value = analogRead(pin_number);
    Serial.print('A');
    Serial.print(pin_number);
    Serial.print(':');
    Serial.println(analog_value); // Adds a trailing \n
}

void digital_write(int pin_number, int digital_value){
    /*
     * Performs a digital write on pin_number with the digital_value
     * The value must be 1 or 0
     */
  digitalWrite(pin_number, digital_value);
}

void analog_write(int pin_number, int analog_value){
    /*
   * Performs an analog write on pin_number with the analog_value
   * The value must be range from 0 to 255
     */
  analogWrite(pin_number, analog_value);
}

/*void setup() {
    Serial.begin(9600); // Serial Port at 9600 baud
    Serial.setTimeout(100); // Instead of the default 1000ms, in order
                            // to speed up the Serial.parseInt()
    lightSetup ();
}*/

//int lightMode = 0;  // 0 = normal, 1 = emergency

/*
void loop() {
  lightController ();
}
*/

void controlLoop() {
    // Check if characters available in the buffer
    if (Serial.available() > 0) {
        operation = Serial.read();
        delay(wait_for_transmission); // If not delayed, second character is not correctly read
        mode = Serial.read();
        pin_number = Serial.parseInt(); // Waits for an int to be transmitted
        if (Serial.read()==':'){
            value_to_write = Serial.parseInt(); // Collects the value to be written
        }
        switch (operation){
            case 'R': // Read operation, e.g. RD12, RA4
                if (mode == 'D'){ // Digital read
                    digital_read(pin_number);
                } else if (mode == 'A'){ // Analog read
                    analog_read(pin_number);
                } else {
                  break; // Unexpected mode
                }
                break;

            case 'W': // Write operation, e.g. WD3:1, WA8:255
                if (mode == 'D'){ // Digital write
                    digital_write(pin_number, value_to_write);
                    if (pin_number == 10) {
                      if (value_to_write == 1) {
                        lightMode = 1;
                      } else if (value_to_write == 2) {
                        lightMode = 2;
                      } else {
                        lightMode = 0;
                      }
                    }
                    
                } else if (mode == 'A'){ // Analog write
                    analog_write(pin_number, value_to_write);
                } else {
                    break; // Unexpected mode
                }
                break;

            case 'N': // Normal Mode
                lightMode = 0;  
                digitalWrite(10,0);              
                break;

            case 'E': // Emergency Mode
                lightMode = 1;   
                digitalWrite(10,1);             
                break;

            case 'M': // Pin mode, e.g. MI3, MO3, MP3
                set_pin_mode(pin_number, mode); // Mode contains I, O or P (INPUT, OUTPUT or PULLUP_INPUT)
                break;
                
             default: // Unexpected char
                break;
        }
    }
}

void lightSetup(){
    //pinMode(4,OUTPUT);
    //pinMode(2,INPUT);
    //pinMode(6,OUTPUT);
    pinMode(10,OUTPUT);
}
/*
void lightController () {
    controlLoop();
        
    if (lightMode == 0)
    {
        digitalWrite(8,0);
        
        digitalWrite(4,1);
        lastTime = millis()/1000.0;
        startTime = lastTime;
        while(!(((lastTime) > ((startTime) + (5))) || (((1)==(digitalRead(2))))))
        {
            controlLoop();
            lastTime = millis()/1000.0;
        }
        digitalWrite(4,0);
        digitalWrite(6,1);
        
        _delay(2);
        
        digitalWrite(6,0);
        digitalWrite(8,1);
        
        _delay(8);

        digitalWrite(8,0);
    } else
    {
        digitalWrite(4,0);
        digitalWrite(6,0);
        digitalWrite(8,1);
    }
}

void _delay (float seconds) {
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime) {
        controlLoop();
    }
}
*/

