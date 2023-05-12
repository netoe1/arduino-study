#define PINOTRIG 33 // pin for trigger
#define PINOECHO 31 
#define PINOBUZZER 49// pin for sensor's echo
#define CDW_MS 200 // constant cooldown in ms for delay.

#define D_MAX 100

float tempo = 0.0;
float distancia = 0.0;
int delay_tempo = 50;
void setup()
{
  pinMode(PINOTRIG,OUTPUT);
  pinMode(PINOECHO,INPUT);
  pinMode(PINOBUZZER,OUTPUT);
  Serial.begin(9600);
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

  if(distancia <= 100)
  {
      tone(PINOBUZZER,1000);
      if(distancia < 20)
      {
        delay(50);
        noTone(PINOBUZZER);
      }

      else if(distancia < 50)
      {
        delay(100);
        noTone(PINOBUZZER);
      }

      else
      {
        delay(200);
        noTone(PINOBUZZER);
        delay(200);
      }
  }
}
