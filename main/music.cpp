#include "music.h"
#include "Arduino.h"

// Note frequencies
#define NOTE_C4   262
#define NOTE_CS4  277
#define NOTE_D4   294
#define NOTE_DS4  311
#define NOTE_E4   330
#define NOTE_F4   349
#define NOTE_FS4  370
#define NOTE_G4   392
#define NOTE_GS4  415
#define NOTE_A4   440
#define NOTE_AS4  466
#define NOTE_B4   494

void music::littleStar() {
  bool done = false;
  bool pass1 = false;
  bool pass2 = false;

  while (!done)
  {
    playTone(NOTE_C4, 500);
    playTone(NOTE_C4, 500);
    playTone(NOTE_G4, 500);
    playTone(NOTE_G4, 500);

    playTone(NOTE_A4, 500);
    playTone(NOTE_A4, 500);
    playTone(NOTE_G4, 1000);

    playTone(NOTE_F4, 500);
    playTone(NOTE_F4, 500);
    playTone(NOTE_E4, 500);
    playTone(NOTE_E4, 500);
    
    playTone(NOTE_D4, 500);
    playTone(NOTE_D4, 500);
    playTone(NOTE_C4, 1000);

    if (pass2) done = true;
    while (!pass1 || !pass2)
    {
      playTone(NOTE_G4, 500);
      playTone(NOTE_G4, 500);
      playTone(NOTE_F4, 500);
      playTone(NOTE_F4, 500);
      
      playTone(NOTE_E4, 500);
      playTone(NOTE_E4, 500);
      playTone(NOTE_D4, 1000);
      
      if (!pass1) pass1 = true;
      else pass2 = true;
    }
  }
}

// constructor
// sets buzzer pin
music::music(int b) : buzzer(b) {}

void music::playTone(int note, int duration) {
  tone(buzzer, note);
  delay(duration);

  noTone(buzzer);
  delay(50);
}

void music::play(int songSelection) {
  switch(songSelection)
  {
    case 1:
    littleStar();
  }
}


