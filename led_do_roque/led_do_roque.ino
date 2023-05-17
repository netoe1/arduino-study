#include <LiquidCrystal.h>


const int PIN_RS = 8;
const int PIN_EN = 9;
const int PIN_D4 = 4;
const int PIN_D5 = 5;
const int PIN_D6 = 6;
const int PIN_D7 = 7;
const int PIN_BL = 10;
const int SRL_CFG = 9600;

const int SCREEN_X = 16;
const int SCREEN_Y = 2;

LiquidCrystal lcd(PIN_RS,PIN_EN,PIN_D4,PIN_D5,PIN_D6,PIN_D7);

void setup() {
    Serial.begin(SRL_CFG);
    lcd.begin(SCREEN_X,SCREEN_Y);
    lcd.setCursor(0,0);
    lcd.print("anthem");
    lcd.setCursor(0,1);
}

void loop() {
    static int x = analogRead(0);
    Serial.println("x");
    delay(500);
}
