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

const int ledsPerStrip = 36;

DMAMEM int displayMemory[ledsPerStrip*6];

int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);


void setup() {
  leds.begin();
  leds.show();
}


// Less intense...
//.......................
//#define RED    0x160000
//#define GREEN  0x001600
//#define BLUE   0x000016
//#define YELLOW 0x101400
//#define PINK   0x120009
//#define ORANGE 0x100400
//#define WHITE  0x101010
//INTENSE
//#define RED    0xFF0000
//#define GREEN  0x00FF00
//#define BLUE   0x0000FF
//#define YELLOW 0xFFFF00
//#define PINK   0xFF1088
//#define ORANGE 0xE05800
//#define WHITE  0xFFFFFF

#define Candle 0xFF9329
#define WTungsten 0xFFC58F
#define Tungsten 0xFFD6AA
#define Halogen 0xFFF1E0
#define CarbonArc 0xFFFAF4
#define HighNoonSun 0xFFFFFB
#define day0 0xA9D8D7
#define day1 0xAAD8D8
#define day2 0xA5CCCB
#define day3 0xA1C0BE
#define day4 0x9CADA8
#define day5 0x9DA59D
#define day6 0x9EA196
#define day7 0xA09E8D
#define day8 0xA39B88
#define day9 0xAC9A83
#define day10 0xA9D8D7
#define day11 0xB29A80
#define day12 0xBA9C7C
#define day13 0xC7A07C
#define day14 0xD4A67B

#define toNight 0x7a5f00
#define toNight2 0x564300
#define toNight3 0x382b00
#define midnight 0x010101



void colorWipe(int color, int wait)
{
    for (int i=0; i < leds.numPixels(); i++)
    {
         leds.setPixel(i, color);
    }
     
    leds.show();

    delay(wait);

}

void loop() {
  int microsec = 1000000 / leds.numPixels();  // change them all in 2 seconds

  // uncomment for voltage controlled speed
  // millisec = analogRead(A9) / 40;
  colorWipe(midnight, microsec);
  colorWipe(toNight3, microsec);
  colorWipe(toNight2, microsec);
  colorWipe(toNight, microsec);
  colorWipe(Candle, microsec);
  colorWipe(WTungsten, microsec);
  colorWipe(Tungsten, microsec);
  colorWipe(Halogen, microsec);
  colorWipe(CarbonArc, microsec);
  colorWipe(HighNoonSun, microsec);
  colorWipe(HighNoonSun, microsec);
  colorWipe(day14, microsec);
  colorWipe(day13, microsec);
  colorWipe(day12, microsec);
  colorWipe(day11, microsec);
  colorWipe(day10, microsec);
  colorWipe(day9, microsec);
  colorWipe(day8, microsec);
  colorWipe(day7, microsec);
  colorWipe(day6, microsec);
  colorWipe(day5, microsec);
  colorWipe(day4, microsec);
  colorWipe(day3, microsec);
  colorWipe(day2, microsec);
  colorWipe(day1, microsec);
  colorWipe(day0, microsec);
  colorWipe(day0, microsec);
  colorWipe(day1, microsec);
  colorWipe(day2, microsec);
  colorWipe(day3, microsec);
  colorWipe(day4, microsec);
  colorWipe(day5, microsec);
  colorWipe(day6, microsec);
  colorWipe(day7, microsec);
  colorWipe(day8, microsec);
  colorWipe(day9, microsec);
  colorWipe(day10, microsec);
  colorWipe(day11, microsec);
  colorWipe(day12, microsec);
  colorWipe(day13, microsec);
  colorWipe(day14, microsec);
  colorWipe(HighNoonSun, microsec);
  colorWipe(CarbonArc, microsec);
  colorWipe(Halogen, microsec);
  colorWipe(Tungsten, microsec);
  colorWipe(WTungsten, microsec);
  colorWipe(Candle, microsec);
  colorWipe(toNight, microsec);
  colorWipe(toNight2, microsec);
  colorWipe(toNight3, microsec);
  colorWipe(midnight, microsec);
  colorWipe(midnight, microsec);



}

