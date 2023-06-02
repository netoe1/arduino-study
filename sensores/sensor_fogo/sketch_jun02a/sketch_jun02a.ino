#define PIN_LED 31
#define PIN_SENSOR 33
#define SERIAL_HZ 9600
#define DELAY_MS 1000
int estado_sensor = 0;

void setup() {
  Serial.begin(SERIAL_HZ);
  pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_SENSOR,INPUT);
}

void loop() {
    estado_sensor = digitalRead(PIN_SENSOR);
    Serial.print("Estado sensor:" + estado_sensor);
    digitalWrite(PIN_LED,estado_sensor);
    delay(DELAY_MS);

}
