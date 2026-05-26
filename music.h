#ifndef MUSIC_H
#define MUSIC_H

class music {
private:
    int buzzer;
    void playNote(int note, int duration);
    void littleStar();
public:
    // constructor
    // sets the buzzer pin
    music(int b);
    
    void playSong(int songSelection);
};

#endif
