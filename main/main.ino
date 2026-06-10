// digital pin output
#define PIN_IR_RECEIVE 11
#define BUZZER_PIN 12
#define PIN_LED0 2
#define PIN_LED1 3
#define PIN_LED2 4
#define PIN_LED3 5
#define PIN_LED4 6
#define PIN_LED5 7
#define PIN_LED6 8
#define PIN_LED7 9

// IR remote codes
#define REMOTE_1 0xBA45FF00
#define REMOTE_2 0xB946FF00
#define REMOTE_3 0xB847FF00
#define REMOTE_4 0xBB44FF00
#define REMOTE_5 0xBF40FF00
#define REMOTE_6 0xBC43FF00
#define REMOTE_7 0xF807FF00
#define REMOTE_8 0xEA15FF00
#define REMOTE_9 0xF609FF00
#define REMOTE_0 0xE619FF00
#define REMOTE_STAR 0xE916FF00
#define REMOTE_POUND 0xF20DFF00
#define REMOTE_UP 0xE718FF00
#define REMOTE_DOWN 0xAD52FF00
#define REMOTE_LEFT 0xF708FF00
#define REMOTE_RIGHT 0xA55AFF00
#define REMOTE_OK 0xE31CFF00

#include <IRremote.h>
#include "music.h"

void setup() {
    Serial.begin(9600);

    IrReceiver.begin(PIN_IR_RECEIVE, ENABLE_LED_FEEDBACK);

    Serial.println("IR Receiver Ready");

    pinMode(PIN_LED0, OUTPUT);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_LED3, OUTPUT);
}

void loop() {
    music player(BUZZER_PIN);
    long data = 0;
    if (IrReceiver.decode()) {

        Serial.print("Code: ");
        data = IrReceiver.decodedIRData.decodedRawData;
        Serial.println(data, HEX);
        IrReceiver.resume();
    }

    switch (data)
    {
        // 1
        case 0xBA45FF00:
        if (digitalRead(PIN_LED0) == LOW)
            digitalWrite(PIN_LED0, HIGH);
        else
            digitalWrite(PIN_LED0, LOW);
        break;
        // 2
        case 0xB946FF00:
        if (digitalRead(PIN_LED1) == LOW)
            digitalWrite(PIN_LED1, HIGH);
        else
            digitalWrite(PIN_LED1, LOW);
        break;
        // 3
        case 0xB847FF00:
        if (digitalRead(PIN_LED2) == LOW)
            digitalWrite(PIN_LED2, HIGH);
        else
            digitalWrite(PIN_LED2, LOW);
        break;
        // 4
        case 0xBB44FF00:
        if (digitalRead(PIN_LED3) == LOW)
            digitalWrite(PIN_LED3, HIGH);
        else
            digitalWrite(PIN_LED3, LOW);
        break;
        default:
        break;
    }
}
