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


const int ledsPerStrip = 36;

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

void setup() {
  leds.begin();
  leds.show();
  Serial.begin(9600);
  Wire.begin();
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

void loop() {

  int red, green, blue;
  Serial.println("loop");
  
  // uncomment for voltage controlled speed
  // millisec = analogRead(A9) / 40;

    GroveColorSensor colorSensor;

    colorSensor.readRGB(&red, &green, &blue);   //Read RGB values to variables.
    //delay(0);
    Serial.print("The RGB value are: RGB( ");
    Serial.print(red,DEC);
    Serial.print(", ");
    Serial.print(green,DEC);
    Serial.print(", ");
    Serial.print(blue,DEC);
    Serial.println(" )");
    colorSensor.clearInterrupt();

  colorWipe(red, green, blue, microsec);
}


void colorWipe(int red, int green, int blue, int wait)
{

  for (int i=0; i < leds.numPixels(); i++)
  {
    leds.setPixel(i, red, green, blue);
  }
  leds.show();
  //delayMicroseconds(wait);
}

