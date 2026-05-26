// digital pin output
#define IR_RECEIVE_PIN 11
#define BUZZER_PIN 2

#include <IRremote.h>
#include "music.h"

void setup() {
    Serial.begin(9600);

    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

    Serial.println("IR Receiver Ready");
}

void loop() {
    music player(BUZZER_PIN);
    if (IrReceiver.decode()) {

        Serial.print("Code: ");
        //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        Serial.print(IrReceiver.decodedIRData.decodedRawData);
        Serial.print("\n");

        IrReceiver.resume();
    }
}