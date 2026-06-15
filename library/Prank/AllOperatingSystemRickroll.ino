// [ ===== Created using duckify.spacehuhn.com @ dev 2a10f486 ===== ] //
// Duckify is a free and Open-Source web-app for converting Ducky Script into Arduino code.
// Please consider supporting us on ko-fi.com/spacehuhn <3
// Learn more about us at spacehuhn.com

// Platform: Arduino
// Keyboard Layout: US


#include <HID.h>

namespace keyboard {
    typedef struct report {
        uint8_t modifiers;
        uint8_t reserved;
        uint8_t keys[6];
    } report;
    
    report prev_report = report { 0x00, 0x00, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };
    
    const uint8_t keyboardDescriptor[] PROGMEM {
        0x05, 0x01, 0x09, 0x06, 0xa1, 0x01, 0x85, 0x02, 0x05, 0x07, 0x19, 0xe0, 0x29, 0xe7, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01, 0x95, 0x08, 0x81, 0x02, 0x95, 0x01, 0x75, 0x08, 0x81, 0x03, 0x95, 0x06, 0x75, 0x08, 0x15, 0x00, 0x25, 0x73, 0x05, 0x07, 0x19, 0x00, 0x29, 0x73, 0x81, 0x00, 0xc0,
    };
    
    report makeReport(uint8_t modifiers = 0, uint8_t key1 = 0, uint8_t key2 = 0, uint8_t key3 = 0, uint8_t key4 = 0, uint8_t key5 = 0, uint8_t key6 = 0);
    
    report makeReport(uint8_t modifiers, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t key6) {
        return report { modifiers, 0x00, { key1, key2, key3, key4, key5, key6 } };
    }
    
    void begin() {
        static HIDSubDescriptor node(keyboardDescriptor, sizeof(keyboardDescriptor));
        HID().AppendDescriptor(&node);
    }
    
    void send(report* k) {
        HID().SendReport(2, (uint8_t*)k, sizeof(report));
    }
    
    void release() {
        prev_report = makeReport();
        send(&prev_report);
    }

    void type(uint8_t key0, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t modifiers) {
        prev_report.keys[0] = key0;
        prev_report.keys[1] = key1;
        prev_report.keys[2] = key2;
        prev_report.keys[3] = key3;
        prev_report.keys[4] = key4;
        prev_report.keys[5] = key5;
        prev_report.modifiers = modifiers;
        send(&prev_report);
        release();
    }
}


// Chrome
const uint8_t key_arr_0[] PROGMEM = {2,6, 0,11, 0,21, 0,18, 0,16, 0,8};
// https://www.youtube.com/watch?v=xvFZjo5PgG0
const uint8_t key_arr_1[] PROGMEM = {0,11, 0,23, 0,23, 0,19, 0,22, 2,51, 0,56, 0,56, 0,26, 0,26, 0,26, 0,55, 0,28, 0,18, 0,24, 0,23, 0,24, 0,5, 0,8, 0,55, 0,6, 0,18, 0,16, 0,56, 0,26, 0,4, 0,23, 0,6, 0,11, 2,56, 0,25, 0,46, 0,27, 0,25, 2,9, 2,29, 0,13, 0,18, 0,34, 2,19, 0,10, 2,10, 0,39};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        keyboard::type(pgm_read_byte_near(keys + i+1), 0, 0, 0, 0, 0, pgm_read_byte_near(keys + i));
    }
}

void setup() {
    keyboard::begin();
    delay(2000);

    // made by J0K3RS-L4UGH
    // Basically it enters chrome and rickrolls with no ads
    keyboard::type(0, 0, 0, 0, 0, 0, 8); // GUI
    delay(2000); // DELAY 2000
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING Chrome
    delay(2000); // DELAY 2000
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(2000); // DELAY 2000
    keyboard::type(7, 0, 0, 0, 0, 0, 4); // ALT d
    delay(2000); // DELAY 2000
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING https://www.youtube.com/watch?v=xvFZjo5...
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
}

void loop() {}

// Created using duckify.spacehuhn.com @ dev 2a10f486
