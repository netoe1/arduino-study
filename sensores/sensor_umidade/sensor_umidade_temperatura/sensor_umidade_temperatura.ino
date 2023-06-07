#include <DHT.h>
#include <DHT_U.h>

#define PIN_DHT A0
#define MODELO_DHT "DHT22"
#define SERIAL_CFG 9600

DHT_Unified dht(PIN_DHT,MODELO_DHT);

uint32_t delayMs;

void setup()
{
     Serial.begin(SERIAL_CFG);
     dht.begin();
     sensor_t sensor;
     dht.temperature().getSensor(&sensor);
     dht.humidity().getSensor(&sensor);
     delayMs = sensor.min_delay / 1000;
}

void loop()
{
  sensors_event_t evento;
  dht.temperature().getEvent(&evento); 
  Serial.print("Temperatura   :");
  Serial.print(evento.temperature);
  Serial.print("°C");

  dht.humidity().getEvent(&evento);
  Serial.print("Umidade:");
  Serial.print(evento.relative_humidity);
  Serial.print("%");
  delay(delayMs);
}
