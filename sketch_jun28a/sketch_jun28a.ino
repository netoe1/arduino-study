#include <SoftwareSerial.h>

SoftwareSerial hc06(50,51);

void setup()
{
  Serial.begin(9600);
  hc06.begin(9600);
}

void loop()
{
  // Do HC-06 o monitor serial

  if(hc06.available())
  {
    Serial.write(hc06.read());
  }

  if(hc06.available())
  {
    hc06.write(Serial.read());
  }
}
