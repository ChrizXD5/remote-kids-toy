#ifndef MUSIC_H
#define MUSIC_H

class music {
private:
    int buzzer;
public:
    // constructor
    // sets the buzzer pin
    music(int b);
    
    void play(int songSelection);
};

#endif
