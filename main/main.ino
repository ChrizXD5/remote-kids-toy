// Uncomment to enable debug mode
// Debug info can be seen through serial monitor at 9600 baud
#define DEBUG_MODE

#define IR_USE_AVR_TIMER1

// digital pin output
#define PIN_IR_RECEIVE 11
#define PIN_BUZZER 12
#define PIN_LED0 2
// LED BROKEN :(
//#define PIN_LED1 4
#define PIN_LED2 3
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

    #ifdef DEBUG_MODE
        Serial.begin(9600);
        Serial.println("DEBUG ENABLED");
    #endif

    IrReceiver.begin(PIN_IR_RECEIVE);

    pinMode(PIN_LED0, OUTPUT);
    // LED BROKEN
	// pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_LED3, OUTPUT);
    pinMode(PIN_LED4, OUTPUT);
    pinMode(PIN_LED5, OUTPUT);
    pinMode(PIN_LED6, OUTPUT);
    pinMode(PIN_LED7, OUTPUT);

    #ifdef DEBUG_MODE
        Serial.println("SETUP DONE");
    #endif
}

void loop() {
    music player(PIN_BUZZER);
    char currentCode;

    while (true)
    {
        if (IrReceiver.decode())
        {
            unsigned long data = IrReceiver.decodedIRData.decodedRawData;
            char receivedCode = translateCode(data);

            if (receivedCode >= '0' && receivedCode <= '9')
            {
                numberTone(receivedCode);
				numberLED(receivedCode);
                delay(75);
                noTone(PIN_BUZZER);
            }
			else {
				switch (receivedCode) {
					case '*':
					case '#':
					numberTone('0');
					numberLED(receivedCode);
                    delay(75);
                    noTone(PIN_BUZZER);
					break;

					// UP
					case 'U':
					player.play(1);
					break;
					// DOWN
					case 'D':
					player.play(2);
					break;
					// LEFT
					case 'L':
					player.play(3);
					break;
					// RIGHT
					case 'R':
					player.play(4);
					break;

					// OK
					case 'O':
					default:
					break;
				}
			}

            #ifdef DEBUG_MODE
                Serial.println(data, HEX);
                Serial.println(translateCode(data));
            #endif

            IrReceiver.resume();
        }
    }
}

// translates remote code into a char
char translateCode(unsigned long code) {
    switch (code) {
        case REMOTE_1:
        return '1';
        break;
        case REMOTE_2:
        return '2';
        break;
        case REMOTE_3:
        return '3';
        break;
        case REMOTE_4:
        return '4';
        break;
        case REMOTE_5:
        return '5';
        break;
        case REMOTE_6:
        return '6';
        break;
        case REMOTE_7:
        return '7';
        break;
        case REMOTE_8:
        return '8';
        break;
        case REMOTE_9:
        return '9';
        break;
        case REMOTE_0:
        return '0';
        break;
        case REMOTE_STAR:
        return '*';
        break;
        case REMOTE_POUND:
        return '#';
        break;
        case REMOTE_UP:
        return 'U';
        break;
        case REMOTE_DOWN:
        return 'D';
        break;
        case REMOTE_LEFT:
        return 'L';
        break;
        case REMOTE_RIGHT:
        return 'R';
        break;
        case REMOTE_OK:
        return 'O';
        break;
        
        // when the same button is held down this is returned
        case 0x0:
        return '=';

        default:
        break;
    }

    return '?';
}

// the offset is used to convert a char into a int
// 48 is decimal code for '0' in ASCII
#define OFFSET 48
void numberTone(char input) {
	noTone(PIN_BUZZER);
	int multiplier = input - OFFSET;
    tone(PIN_BUZZER, (75 * multiplier) + 200);
}

void numberLED(char input) {
	switch (input) {
		case '*':
		toggleLED(PIN_LED7);
		case '#':
		toggleLED(PIN_LED5);
		case '0':
		toggleLED(PIN_LED2);
		toggleLED(PIN_LED4);
		case '9':
		toggleLED(PIN_LED3);
		toggleLED(PIN_LED6);
		case '8':
		toggleLED(PIN_LED7);
		case '7':
		toggleLED(PIN_LED6);
		case '6':
		toggleLED(PIN_LED5);
		case '5':
		toggleLED(PIN_LED4);
		case '4':
		toggleLED(PIN_LED3);
		case '3':
		toggleLED(PIN_LED2);
		case '2':
		// LED BROKEN
		// toggleLED(PIN_LED1);
		case '1':
		toggleLED(PIN_LED0);
		default:
		break;
	}
}


void toggleLED(const int PIN_NUMBER) {
    if (digitalRead(PIN_NUMBER) == LOW) {
        digitalWrite(PIN_NUMBER, HIGH);
        
        #ifdef DEBUG_MODE
            Serial.print("PIN " + String(PIN_NUMBER) + " ON\n");
        #endif
    }
    else {
        digitalWrite(PIN_NUMBER, LOW);
        
        #ifdef DEBUG_MODE
            Serial.print("PIN " + String(PIN_NUMBER) + " OFF\n");
        #endif
    }
}
