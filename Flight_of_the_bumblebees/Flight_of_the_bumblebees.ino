/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_E7,  NOTE_DS7,  NOTE_D7,  NOTE_CS7, 
  NOTE_D7,  NOTE_CS7,  NOTE_C7,  NOTE_B6,
  
  NOTE_C7,  NOTE_B6,   NOTE_AS6, NOTE_A6,
  NOTE_GS6, NOTE_G6,   NOTE_FS6, NOTE_F6,
  
  NOTE_E6,  NOTE_DS6,  NOTE_D6,  NOTE_CS6,
  NOTE_D6,  NOTE_CS6,  NOTE_C6,  NOTE_B5,
  
  NOTE_C6,  NOTE_B5,   NOTE_AS5, NOTE_A5,
  NOTE_GS5, NOTE_G5,   NOTE_FS5, NOTE_F5,
  
  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_D5,  NOTE_CS5,  NOTE_C5,  NOTE_B4,
  
  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_D5,  NOTE_CS5,  NOTE_C5,  NOTE_B4,
  
  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_C5,  NOTE_F5,   NOTE_E5,  NOTE_DS5,

  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_C5,  NOTE_CS5,  NOTE_D5,  NOTE_DS5,

  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_C5,  NOTE_F5,   NOTE_E5,  NOTE_DS5,

  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_C5,  NOTE_CS5,  NOTE_D5,  NOTE_DS5,

  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_D5,  NOTE_CS5,  NOTE_C5,  NOTE_B4,

  NOTE_C5,  NOTE_CS5,  NOTE_D5,  NOTE_DS5,
  NOTE_E5,  NOTE_F5,   NOTE_E5,  NOTE_D5,
  
  NOTE_E5,  NOTE_DS5,  NOTE_D5,  NOTE_CS5,
  NOTE_D5,  NOTE_CS5,  NOTE_C5,  NOTE_B4,

  NOTE_C5,  NOTE_CS5,  NOTE_D5,  NOTE_DS5,
  NOTE_E5,  NOTE_FS5,  NOTE_G5,  NOTE_GS5,
  
  NOTE_A5,  NOTE_GS5,  NOTE_G5,  NOTE_FS5,
  NOTE_F5,  NOTE_AS5,  NOTE_A5,  NOTE_GS5,

  NOTE_A5,  NOTE_GS5,  NOTE_G5,  NOTE_FS5,
  NOTE_F5,  NOTE_FS5,  NOTE_G5,  NOTE_GS5,

  NOTE_A5,  NOTE_GS5,  NOTE_G5,  NOTE_FS5,
  NOTE_F5,  NOTE_AS5,  NOTE_A5,  NOTE_GS5,

  NOTE_A5,  NOTE_GS5,  NOTE_G5,  NOTE_FS5,
  NOTE_F5,  NOTE_FS5,  NOTE_G5,  NOTE_GS5,

  NOTE_A5,  NOTE_GS5,  NOTE_G5,  NOTE_FS5,
  NOTE_G5,  NOTE_FS5,  NOTE_F5,  NOTE_E5,
  
  NOTE_F5,  NOTE_FS5,  NOTE_G5,  NOTE_GS5,
  NOTE_A5,  NOTE_AS5,  NOTE_A5,  NOTE_GS5,
  
  NOTE_A5,  NOTE_GS5,  NOTE_G5,  NOTE_FS5,
  NOTE_G5,  NOTE_FS5,  NOTE_F5,  NOTE_E5,
  
  NOTE_F5,  NOTE_FS5,  NOTE_G5,  NOTE_GS5,
  NOTE_A5,  NOTE_AS5,  NOTE_A5,  NOTE_GS5,
  
  NOTE_A5,  NOTE_A4,   NOTE_A4,  NOTE_A4,
  NOTE_A4,  NOTE_A4,   NOTE_A4,  NOTE_A4,
  
  NOTE_AS4, NOTE_AS4,  NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4,  NOTE_AS4, NOTE_AS4,
  
  NOTE_A5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
/*int noteDurations[] = {
  16,  16,  16,  16,
  16,  16,  16,  16, 
  16,  16,  16,  16,
  16,  16,  16,  16 };
*/

const int ARRAY_SIZE = sizeof(melody) / sizeof(int);
int noteDurations[ARRAY_SIZE];
int LED1 = 10;
int LED2 = 11;
int LED3 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  int LED = LED1;
  for(int i=0; i<ARRAY_SIZE; i++)
  {
    noteDurations[i] = 16;
  }
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < ARRAY_SIZE; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
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
    int pauseBetweenNotes = noteDuration * 1.1;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
