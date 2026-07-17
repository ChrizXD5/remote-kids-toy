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
#define NOTE_C5   523
#define NOTE_CS5  554
#define NOTE_D5   587
#define NOTE_DS5  622
#define NOTE_E5   659
#define NOTE_F5   698
#define NOTE_FS5  740
#define NOTE_G5   784
#define NOTE_GS5  831
#define NOTE_A5   880
#define NOTE_AS5  932
#define NOTE_B5   988

void playTone(int note, int duration, int buzzer) {
  tone(buzzer, note);
  delay(duration);

  noTone(buzzer);
  delay(50);
}

namespace songs {

  void littleStar(int buzzer) {
    bool done = false;
    bool pass1 = false;
    bool pass2 = false;

    while (!done)
    {
      playTone(NOTE_C4, 500, buzzer);
      playTone(NOTE_C4, 500, buzzer);
      playTone(NOTE_G4, 500, buzzer);
      playTone(NOTE_G4, 500, buzzer);

      playTone(NOTE_A4, 500, buzzer);
      playTone(NOTE_A4, 500, buzzer);
      playTone(NOTE_G4, 1000, buzzer);

      playTone(NOTE_F4, 500, buzzer);
      playTone(NOTE_F4, 500, buzzer);
      playTone(NOTE_E4, 500, buzzer);
      playTone(NOTE_E4, 500, buzzer);
      
      playTone(NOTE_D4, 500, buzzer);
      playTone(NOTE_D4, 500, buzzer);
      playTone(NOTE_C4, 1000, buzzer);

      if (pass2) done = true;
      while (!pass1 || !pass2)
      {
        playTone(NOTE_G4, 500, buzzer);
        playTone(NOTE_G4, 500, buzzer);
        playTone(NOTE_F4, 500, buzzer);
        playTone(NOTE_F4, 500, buzzer);
        
        playTone(NOTE_E4, 500, buzzer);
        playTone(NOTE_E4, 500, buzzer);
        playTone(NOTE_D4, 1000, buzzer);
        
        if (!pass1) pass1 = true;
        else pass2 = true;
      }
    }
  }

  void happyBirthday(int buzzer) {
    playTone(NOTE_G4, 750, buzzer);
    playTone(NOTE_G4, 300, buzzer);
    playTone(NOTE_A4, 750, buzzer);
    playTone(NOTE_G4, 750, buzzer);
    playTone(NOTE_C5, 750, buzzer);
    playTone(NOTE_B4, 750, buzzer);

    playTone(NOTE_G4, 750, buzzer);
    playTone(NOTE_G4, 300, buzzer);
    playTone(NOTE_A4, 750, buzzer);
    playTone(NOTE_G4, 750, buzzer);
    playTone(NOTE_D5, 750, buzzer);
    playTone(NOTE_C5, 750, buzzer);

    playTone(NOTE_G4, 750, buzzer);
    playTone(NOTE_G4, 750, buzzer);
    playTone(NOTE_G5, 750, buzzer);
    playTone(NOTE_E4, 750, buzzer);
    playTone(NOTE_C4, 750, buzzer);
    playTone(NOTE_B4, 750, buzzer);
    playTone(NOTE_A4, 750, buzzer);
    delay(300);

    playTone(NOTE_F4, 750, buzzer);
    playTone(NOTE_F4, 300, buzzer);
    playTone(NOTE_E4, 750, buzzer);
    playTone(NOTE_C4, 750, buzzer);
    playTone(NOTE_D4, 750, buzzer);
    playTone(NOTE_C4, 1500, buzzer);
  }
}

// constructor
// sets buzzer pin
music::music(int b) : buzzer(b) {}

void music::play(int songSelection) {
  switch(songSelection)
  {
    case 1:
    songs::littleStar(buzzer);
    break;
    case 2:
    songs::happyBirthday(buzzer);
    break;
    default:
    break;
  }
}


