#include "pitches.h"

//MELODY

//-----------------------------------------------------------------------

//DURATIONS
//8 = eighth note, 16 = sixteenth note
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8, 8, 16, 8, 16, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16, 8, 16, 8, 8, 8, 8, 8
};

//NOTES
int melody[] = {
  FS5, REST, FS5, REST, FS5, REST, FS5, REST,
  A5, REST, A5, REST, B5, REST,
  B5, FS5, E5, D5, B4,
  FS5, REST, FS5, REST, FS5, REST,
  E5, REST, E5, REST, FS5, REST,
  E5, D5, B4
};

//-----------------------------------------------------------------------

//PINS


int ledPins[] = {

  8, 9, 10, 11

};
int speakerPin = 7;
int buttonPin = 2;

int buttonState = 0; 


//array counts

int noteCount = sizeof(melody) / sizeof(melody[0]);

int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);




void playSong(int len, int noteDurations[], int speakerPin) {


  //iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < len; thisNote++) {

    //gets random number for light

    int rand = random(0, ledCount);



    //1000/length of note you want

    int noteDuration = 1500 / noteDurations[thisNote];


    //Plays note and activates random light

    if (melody[thisNote] != 0) {  //check for rest

      digitalWrite(ledPins[rand], HIGH);
    }


    tone(speakerPin, melody[thisNote], noteDuration);


    //wait between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    //turns light and note off
    digitalWrite(ledPins[rand], LOW);
    noTone(speakerPin);
  }
}

void setup() {
  
  Serial.begin(9600);

  randomSeed(analogRead(0));

  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  buttonState = digitalRead(buttonPin);
  
  Serial.print("Button state: ");
  Serial.println(buttonState);

  int rand = random(0, ledCount);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    playSong(noteCount, noteDurations, speakerPin);
    if(buttonState == HIGH){
      digitalWrite(ledPins[rand], HIGH);
    }
    
    delay(600);

  }

  delay(50);
}
