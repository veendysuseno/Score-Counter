#include <TM1637Display.h>
#define CLK 10
#define DIO 11
#define TEST_DELAY   300

TM1637Display display(CLK, DIO);

uint8_t blank[] = { 0x0, 0x0, 0x0, 0x0 };
const int tambahPin = 9;
const int resetPin = 12;
const int touchDelay = 500;
int count = 0;

void setup() {
    pinMode(tambahPin, INPUT);
    pinMode(resetPin, INPUT_PULLUP);
    display.setBrightness(0x0f);// pengatur kecerahan display
    uint8_t data8888[] = { 0xff, 0xff, 0xff, 0xff };  // all segments show
    display.setSegments(data8888); // menampilkan 8888 sebagai penanda set up sistem
    delay(3000);// delay set up
    display.setSegments(blank); // menampilkan nilai kosong
    display.showNumberDec(0);// menampilkan nilai 0
}

void loop() {
int tambahValue = digitalRead(tambahPin);
if (tambahValue == LOW) {  // apabila tombol tambah bernilai LOW
    count++;// tambah counter
    display.setSegments(blank);  //menampilkan nilai kosong
    display.showNumberDec(count);  // display counter
    delay(touchDelay);
}

if (digitalRead(resetPin) == LOW) { // apabila reset tambah bernilai LOW
    count = 0; // reset counter;
    display.setSegments(blank);// menampilkan nilai kosong
    display.showNumberDec(count);// display counter
}
}
