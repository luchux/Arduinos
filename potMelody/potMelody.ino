 /*
  Melody
 
 Plays a melody and adjust notes with petonciometer. 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 * potenciometor on serial A0
 
 by Luchux 

 */
 #include "pitches.h"

const int analogInPin = A0; //Analog input that potenciometer is attached to

int sensorValue = 0; //value read from the potenciometer
int noteValue = 0;   //value mapped from potenciometer to note scales. 

//amount of notes 
int indexNotes = 7;

// notes in the melody:
int melody[] = {
  NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 4,4,4,4,4 };
  
  

void setup() {
  // iterate over the notes of the melody:
  sensorValue = analogRead(analogInPin);
  noteValue = map(sensorValue, 0, 1023, 0, indexNotes);
  Serial.begin(9600); 
  
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t noteh = ");      
  Serial.println(noteValue);   
  
  //for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  int noteDuration = 1000/noteDurations[noteValue];
  tone(8, melody[noteValue],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
    // stop the tone playing:
  noTone(8);
}

void loop() {
  // no need to repeat the melody.
  setup();
  delay(10);
}
