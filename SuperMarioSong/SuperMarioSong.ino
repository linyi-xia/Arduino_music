/*
  Arduino Mario Bros Tunes
  With Piezo Buzzer and PWM

  Connect the positive side of the Buzzer to pin 3,
  then the negative side to a 1k ohm resistor. Connect
  the other side of the 1 k ohm resistor to
  ground(GND) pin on the Arduino.

  by: Dipto Pratyaksa
  last updated: 31/3/13
*/

/*************************************************
 * Public Constants
 *************************************************/

#include "pitches.h"
#include "melody.h"
#include "underworldMelody.h"

int LED1 = 10;
int LED2 = 11;
int LED3 = 12;
int LED = LED1;
void setup(void)
{
  Serial.begin(9600);
  pinMode(melodyPin, OUTPUT);//buzzer
  pinMode(13, OUTPUT);//led indicator when singing a note
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  //sing the tunes
  int arraySize = sizeof(melody) / sizeof(int);
  Serial.print(arraySize);
  sing(melody,tempo,arraySize);
  arraySize = sizeof(underworld_tempo) / sizeof(int);
  Serial.print(arraySize);
  sing(underworld_melody,underworld_tempo,arraySize);
  noTone(melodyPin);
  Serial.print('end');
}
void loop()
{

}


void sing(int* melody, int* tempo,int arraySize) {
  for (int thisNote = 0; thisNote < arraySize; thisNote++) {
    Serial.print(thisNote);
    Serial.print(' ');
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1500/tempo[thisNote];
    tone(8, melody[thisNote],noteDuration);
    digitalWrite(LED, HIGH);
    LED++;
    if (LED> LED3)
    {
      LED = LED1; 
    }
    digitalWrite(LED, LOW);
    
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(melodyPin);
  }
}
