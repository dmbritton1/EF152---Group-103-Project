#include "pitches.h"

//MELODY

//-----------------------------------------------------------------------

//quarter note, eigth note etc.
int noteDurations[] = {

  4, 4, 4, 4, 4, 4, 4, 4, 4
};

//notes in the melody:

int melody[] = {

  D4, A4, REST, D4, A4, F4, A4, AS4, A4
};


//-----------------------------------------------------------------------

//PINS


int ledPins[] = {

  1, 2, 3, 4
};

int speakerPin = 5;
int buttonPin = 6;
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

    int noteDuration = 1000 / noteDurations[thisNote];


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

  randomSeed(analogRead(0));

  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    playSong(noteCount, noteDurations, speakerPin);
  }

  delay(5000);
}