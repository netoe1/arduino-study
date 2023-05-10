#define PINOTRIG 33 // pin for trigger
#define PINOECHO 31 // pin for sensor's echo
#define CDW_MS 250 // constant cooldown in ms for delay.



float tempo = 0.0;
float distancia = 0.0;
void setup()
{
  pinMode(PINOTRIG,OUTPUT);
  pinMode(PINOECHO,INPUT);
}


void loop(){
  digitalWrite(PINOTRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINOTRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINOTRIG, LOW);
  tempo = pulseIn(PINOECHO, HIGH);
  distancia = (tempo*0.0343)/2;
  Serial.println(distancia);
  delay(CDW_MS);
}
