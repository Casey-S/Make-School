/*macro definition of Speaker pin*/
#define SPEAKER 8
#define TOUCH 6
#define ULTRA 4
#include "Ultrasonic.h"

//int BassTab[] = {1911,1702,1516,1431,1275,1136,1012};//bass 1~7
int BassTab[]  = {1911, 1702, 1516, 1431, 1275, 1136, 1012, 956, 851, 758, 715, 638, 568, 506, 478, 426, 379, 358, 319, 284, 253};
char NoteTab[] = {'B',  'C',  'D',  'E',  'F',  'G',  'A',  'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A'};

Ultrasonic ultrasonic(ULTRA);

void setup()
{
    Serial.begin(115200);
    pinInit();
}
void loop()
{
  long RangeInCentimeters;
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  delay(20);

int note = RangeInCentimeters / 5;

if (note > 20) {
  note = 20;
}

Serial.print("Note = ");
Serial.println(NoteTab[note]);
sound(note);
  
        /*sound bass 1~7*/
    for(int note_index=0;note_index<21;note_index++)
    {
        sound(note_index);
        //delay(500);
    }
}
void pinInit()
{
    pinMode(SPEAKER,OUTPUT);
    digitalWrite(SPEAKER,LOW);
    pinMode(TOUCH, INPUT);
}
void sound(uint8_t note_index)
{
    while(digitalRead(TOUCH))
    //for(int i=0;i<100;i++)
    {
        digitalWrite(SPEAKER,HIGH);
        delayMicroseconds(BassTab[note_index]);
        digitalWrite(SPEAKER,LOW);
        delayMicroseconds(BassTab[note_index]);
    }
}
