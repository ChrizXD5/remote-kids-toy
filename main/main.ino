// digital pin output
#define IR_RECEIVE_PIN 11
#define BUZZER_PIN 12
#define LED0_PIN 2
#define LED1_PIN 3
#define LED2_PIN 6
#define LED3_PIN 4

#include <IRremote.h>
#include "music.h"

void setup() {
    Serial.begin(9600);

    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

    Serial.println("IR Receiver Ready");

    pinMode(LED0_PIN, OUTPUT);
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);
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
        if (digitalRead(LED0_PIN) == LOW)
            digitalWrite(LED0_PIN, HIGH);
        else
            digitalWrite(LED0_PIN, LOW);
        break;
        // 2
        case 0xB946FF00:
        if (digitalRead(LED1_PIN) == LOW)
            digitalWrite(LED1_PIN, HIGH);
        else
            digitalWrite(LED1_PIN, LOW);
        break;
        // 3
        case 0xB847FF00:
        if (digitalRead(LED2_PIN) == LOW)
            digitalWrite(LED2_PIN, HIGH);
        else
            digitalWrite(LED2_PIN, LOW);
        break;
        // 4
        case 0xBB44FF00:
        if (digitalRead(LED3_PIN) == LOW)
            digitalWrite(LED3_PIN, HIGH);
        else
            digitalWrite(LED3_PIN, LOW);
        break;
        default:
        break;
    }
}
