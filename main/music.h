#ifndef MUSIC_H
#define MUSIC_H

class music {
private:
    int buzzer;
    void littleStar();
public:
    // constructor
    // sets the buzzer pin
    music(int b);
    
    void playTone(int note, int duration);
    void play(int songSelection);
};

#endif
