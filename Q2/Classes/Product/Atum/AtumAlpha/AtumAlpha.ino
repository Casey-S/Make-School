/*  OctoWS2811 BasicTest.ino - Basic RGB LED Test
    http://www.pjrc.com/teensy/td_libs_OctoWS2811.html
    Copyright (c) 2013 Paul Stoffregen, PJRC.COM, LLC
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
  Required Connections
  --------------------
    pin 2:  LED Strip #1    OctoWS2811 drives 8 LED Strips.
    pin 14: LED strip #2    All 8 are the same length.
    pin 7:  LED strip #3
    pin 8:  LED strip #4    A 100 ohm resistor should used
    pin 6:  LED strip #5    between each Teensy pin and the
    pin 20: LED strip #6    wire to the LED strip, to minimize
    pin 21: LED strip #7    high frequency ringining & noise.
    pin 5:  LED strip #8
    pin 15 & 16 - Connect together, but do not use
    pin 4 - Do not use
    pin 3 - Do not use as PWM.  Normal use is ok.
  This test is useful for checking if your LED strips work, and which
  color config (WS2811_RGB, WS2811_GRB, etc) they require.
*/

#include <OctoWS2811.h>
#include <Wire.h>
//#include <math.h>
#include <GroveColorSensor.h>

//#define DEBUG

const int ledsPerStrip = 36;


DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

void setup() {
  Wire.begin();
  leds.begin();
  leds.show();
  
  Serial.begin(9600);

  Serial.println("setupOurStuff");
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
//GroveColorSensor colorSensor;

#define COLOR_LENGTH 10

void loop() {
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

    if (red > 255) red = 255;
    if (green > 255) green = 255;
    if (blue > 255) blue = 255;

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
    colorFade(old_red, old_green, old_blue, red, green, blue);
#endif

  }
}

void testColorFade (void)
{
  colorFade (32, 192, 64, 224, 16, 128);
}

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
  for (count = 0; count < STEPS; count++)
  {
    inter_red   += red_step;
    inter_green += green_step;
    inter_blue  += blue_step;
    
    for (int i=0; i < leds.numPixels(); i++)
    {
      leds.setPixel(i, inter_red, inter_green, inter_blue);
    }
    leds.show();
    
    delayMicroseconds(15000);
  }

// write exact final color here
  for (int i=0; i < leds.numPixels(); i++)
  {
    leds.setPixel(i, end_red, end_green, end_blue);
  }
  leds.show();
}


// depreceated
void colorWipe(int red, int green, int blue, int wait)
{

  for (int i=0; i < leds.numPixels(); i++)
  {
    leds.setPixel(i, red, green, blue);
  }
  leds.show();
  //delayMicroseconds(wait);
}

