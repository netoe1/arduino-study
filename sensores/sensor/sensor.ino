#define PINOTRIG 33 // pin for trigger
#define PINOECHO 31 
#define PINOBUZZER 49// pin for sensor's echo
#define CDW_MS 500 // constant cooldown in ms for delay.

#define D_MAX 100
#define D_MIN 0
#define CONST_SOM 0.0343
#define CONST_BIP_TIME D_MAX * 4

float tempo = 0.0;
float distancia = 0.0;

void calc_distancia(float *ptr_distancia,float tempo,float __CONST_SOM)
{
  *ptr_distancia = (tempo * __CONST_SOM ) / 2;
}

void bip_sensor(int freq,int time_)
{
  delay(time_);
  tone(PINOBUZZER,freq);
  delay(time_);
  noTone(PINOBUZZER);
}

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
  calc_distancia(&distancia,pulseIn(PINOECHO,HIGH),CONST_SOM);
  Serial.println(distancia);
  delay(CDW_MS / 2);

  if(distancia <= D_MAX && distancia >= D_MIN)
  {
    bip_sensor(1000,CDW_MS / (distancia / CONST_BIP_TIME));  
  }
}
