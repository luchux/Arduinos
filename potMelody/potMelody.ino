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
const int analogInPin2 = A1; 

const int TEMPOS = 8;

int sensorValue = 0; //value read from the potenciometer
int noteValue = 0;   //value mapped from potenciometer to note scales. 

int sensorValue2 = 0; //value read from the potenciometer
int tempoValue = 0;   //value mapped from potenciometer to note scales. 

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
  
  sensorValue2 = analogRead(analogInPin2);
  tempoValue = map(sensorValue2, 0, 1023, 0, TEMPOS);
  
  Serial.begin(9600); 
  
  // print the results to the serial monitor:
  Serial.print("sensor 1 = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t note 1 = ");      
  Serial.println(noteValue);   
  
    // print the results to the serial monitor:
  Serial.print("sensor 2 = " );                       
  Serial.print(sensorValue2);      
  Serial.print("\t note 2 = ");      
  Serial.println(tempoValue);   
  
  //for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  
  // noteValue2 will represent time of tone
  tone(8, melody[noteValue], 1000/tempoValue);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
  int pauseBetweenNotes = (1000/tempoValue) * 1.30;
  delay(pauseBetweenNotes);
    // stop the tone playing:
  noTone(8);
}

void loop() {
  // no need to repeat the melody.
  setup();
  delay(10);
}
