// Morse code encoder project for devices and IOT class
// Skeleton coded by Shannon Bailey, 11/9/2016
// Updated with MorseCodeLetters arrays corrected 11/13/2016
#include <Arduino.h>

double dotRate = (200) / (60);
char   letter;
double lastTime = 0;
int    letterIndex;
int    letterLength;
int    ditsDahs;
int    count;
int    ditOrDah;

// A table of MorseCode letters are coded as the length of each letter, and in
// in dits and dahs which are coded as 0 bits = dits and 1 bits = dahs
// There are 8 Bits in a Byte and like decimal numbers have thousands, hundreds, tens and ones,
// binary number bits are powers of 2 which are 128, 64, 32, 16, 8, 4, 2, 1
// for example: Morse code letter 'C' is length 4 and dah, dit, dah, dit or 1010 in binary and 
// binary 1010 has a 1 in the 4th bit and 2nd bit so its value is 8 + 2 = 10 in decimal.
char MorseCodeLetters[]        = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
//                                  A     B       C       D      E    F       G      H       I     J       K      L       M     N     O      P       Q       R      S      T    U      V       W      X       Y       Z       1        2        3        4        5        6        7        8        9        0
int  MorseCodeLetterLengths[]  = {  2,    4,      4,      3,     1,   4,      3,     4,      2,    4,      3,     4,      2,    2,    3,     4,      4,      3,     3,     1,   3,     4,      3,     4,      4,      4,      5,       5,       5,       5,       5,       5,       5,       5,       5,       5    };
int  MorseCodeLetterDitsDahs[] = {0b01, 0b1000, 0b1010, 0b100, 0b0, 0b0010, 0b110, 0b0000, 0b00, 0b0111, 0b101, 0b0100, 0b11, 0b10, 0b111, 0b0110, 0b1101, 0b010, 0b000, 0b1, 0b001, 0b0001, 0b011, 0b1001, 0b1011, 0b1100, 0b01111, 0b00111, 0b00011, 0b00001, 0b00000, 0b10000, 0b11000, 0b11100, 0b11110, 0b11111};
//int MorseCodeLetterDitsDahs[] ={  1,    8,      10,     4,     0,   2,      6,     0,      0,    7,      5,     4,      3,    2,    7,     6,      13,     2,     0,     1,   1,     1,      3,     9,      11,     12,     15,      7,       3,       1,       0,       16,      24,      28,      30,      31   };

void setup(){
    Serial.begin(115200);
    pinMode(10, OUTPUT);
}

void loop() {
    if((Serial.available()) > (0)){
        letter = toupper( Serial.read() );
        Serial.write(letter);

// check for space character and wait for 7 dot time slots        
        if (letter == ' '){
            lastTime = millis()/1000.0;
            while(!((millis()/1000.0) > (lastTime + (7) / (dotRate))));
        } else {
          for (letterIndex = 0; letterIndex < sizeof(MorseCodeLetters); letterIndex++)
          {
            if (letter == MorseCodeLetters [ letterIndex ] )
            {
              letterLength = MorseCodeLetterLengths[ letterIndex ];
              ditsDahs = MorseCodeLetterDitsDahs[ letterIndex ]; 

              for (count = 1; count <= letterLength; count++)
              {
                ditOrDah = (1 & (ditsDahs >> (letterLength - count) ) ) ? 3 : 1;
                digitalWrite(10, 1);
                lastTime = millis()/1000.0;
                while(!((millis()/1000.0) >= (lastTime + (ditOrDah) / (dotRate))));
                digitalWrite(10, 0);
                lastTime = millis()/1000.0;
                while(!((millis()/1000.0) > (lastTime + (1) / (dotRate))));
              }
              lastTime = millis()/1000.0;
              while(!((millis()/1000.0) >= (lastTime + (3) / (dotRate))));
              break;
 
            }
          }
        }
// You can use a for loop and if statement comparing each letter to MorseCodeLetters[letterIndex] to find the letterIndex
            {
// note: a faster solution would use if statements to check the range A-Z and 0-9 and calculate the letterIndex
                {
                    letterLength = MorseCodeLetterLengths[ letterIndex ];
                    ditsDahs     = MorseCodeLetterDitsDahs[ letterIndex ];

// use a for loop to iterate through each bit
                    {
// shift and isolate each bit and set its to 1 if a dit, and 3 if a dah
// use the right shift operator >>   use the bitwise (binary) AND operator &   and ternary (true/false) ? trueValue : falseValue
// be careful to compute the amount to shift correctly starting with the left most bit, so for a length 4, shift 3, 2, 1, 0

//                      ditOrDah = ? ;
                        letterLength = MorseCodeLetterLengths[ letterIndex ];
                        ditsDahs   = MorseCodeLetterDitsDahs[ letterIndex];
                        digitalWrite(10, 1);
// wait for dit or dah time

                        digitalWrite(10, 0);
                        lastTime = millis()/1000.0;
                        while(!((millis()/1000.0) >= (lastTime + (3) / (dotRate))));
                
// wait for 1 dit time

                    }
// after each letter, add a 3 dit time wait between each letter
                  lastTime = millis()/1000.0;
                  while(!((millis()/1000.0) >= (lastTime + (3) / (dotRate))));
// do you need to break out of the for loop?
                }
            }
        }
}

