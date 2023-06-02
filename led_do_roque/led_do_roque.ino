#include <LiquidCrystal.h>

/*  Functions */


/*
  LEFT:   481,478,480,481;
  RIGHT:  0;
  UP:     129,130, 131;
  DOWN:   300,307;
  SELECT: 722, 721, 774.
*/


/*Setting pin's*/


const int PIN_ANALOG_READ = 0;
const int PIN_RS = 8;
const int PIN_EN = 9;
const int PIN_D4 = 4;
const int PIN_D5 = 5;
const int PIN_D6 = 6;
const int PIN_D7 = 7;
const int PIN_BL = 10;

/*Setting constants*/
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
    lcd.print("Tecla:");
}

void loop() {
    static int x = analogRead(PIN_ANALOG_READ);
    Serial.println(x);
    lcd.setCursor(7,2);

    if  (x < 100)
    {
        lcd.println("RIGHT ");
    }
    else if (x < 200)
    {
        lcd.println("UP    ");
    }
    else if (x < 400)
    {
        lcd.println("DOWN  ");
    }
    else if (x < 600)
    {
        lcd.println("LEFT  ");  
    }
    else if (x < 800)
    {
      lcd.println("SELECT  ");  
    }
    
    delay(500);
}
