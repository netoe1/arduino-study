#define PIN_LED 31
#define PIN_SENSOR 33
#define PIN_BUZZER 22
#define SERIAL_HZ 9600
#define DELAY_MS 1000


#define BUZZER_FREQ 5000

int estado_sensor = 0;

void setup() {
  Serial.begin(SERIAL_HZ);
  pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_SENSOR,INPUT);
  pinMode(PIN_BUZZER,OUTPUT);
}

void loop() {
    estado_sensor = digitalRead(PIN_SENSOR);
    noTone(PIN_BUZZER);
    Serial.print("\nEstado sensor:");
    Serial.println(estado_sensor);
    digitalWrite(PIN_LED,!estado_sensor);

    if(!estado_sensor == 1)
    {
      tone(PIN_BUZZER,BUZZER_FREQ);     
      delay(100);
    }
    
    //delay(DELAY_MS);

}
