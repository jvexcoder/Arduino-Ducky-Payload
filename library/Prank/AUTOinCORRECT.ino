// [ ===== Created using duckify.spacehuhn.com @ dev 2a10f486 ===== ] //
// Duckify is a free and Open-Source web-app for converting Ducky Script into Arduino code.
// Please consider supporting us on ko-fi.com/spacehuhn <3
// Learn more about us at spacehuhn.com

// Platform: Digispark
// Keyboard Layout: US

#include "DigiKeyboard.h"

// winword
const uint8_t key_arr_0[] PROGMEM = {0,26, 0,12, 0,17, 0,26, 0,18, 0,21, 0,7};
// options spelling
const uint8_t key_arr_1[] PROGMEM = {0,18, 0,19, 0,23, 0,12, 0,18, 0,17, 0,22, 0,44, 0,22, 0,19, 0,8, 0,15, 0,15, 0,12, 0,17, 0,10};
// the
const uint8_t key_arr_2[] PROGMEM = {0,23, 0,11, 0,8};
// teh
const uint8_t key_arr_3[] PROGMEM = {0,23, 0,8, 0,11};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed

    // Title: AUTOinCORRECT
    // Author: the-jcksn
    // Description: Creates a custom Microsoft Word Autocorrect rule, default sets rule to change "the" to "teh". Can be changed to any words you wish.
    // Target: Windows 10 / Microsoft Word
    // Version: 1.0
    // Category: Prank
    DigiKeyboard.delay(2000); // DELAY 2000
    // OPEN NEW MICROSOFT WORD DOCUMENT
    DigiKeyboard.sendKeyStroke(21, 8); // GUI r
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING winword
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(1000); // DELAY 1000
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    // EDIT AUTOCORRECT RULES
    DigiKeyboard.sendKeyStroke(20, 4); // ALT q
    DigiKeyboard.delay(300); // DELAY 300
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING options spelling
    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    // AUTOCORRECT "the" TO "teh" ~~~ change these below to whatever words you want to add a rule for ~~~~~
    duckyString(key_arr_2, sizeof(key_arr_2)); // STRING the
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    duckyString(key_arr_3, sizeof(key_arr_3)); // STRING teh
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(4, 4); // ALT a
    DigiKeyboard.delay(200); // DELAY 200
    // SAVE AND EXIT
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(43, 2); // SHIFT TAB
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(61, 4); // ALT F4
    DigiKeyboard.delay(200); // DELAY 200
}

void loop() {}

// Created using duckify.spacehuhn.com @ dev 2a10f486
