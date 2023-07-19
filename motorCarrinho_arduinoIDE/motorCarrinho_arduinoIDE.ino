// C++ code
/*
  Thinker cad!
*/

#define PIN_ENTRADA_1 31
#define PIN_ENTRADA_2 33
#define PIN_ENTRADA_3 35
#define PIN_ENTRADA_4 37

int pwm = 0;

void backward_motor1(); // Andar para trás m1
void forward_motor1();   // Andar para frente m1
void stop_motor1(); 
void stop_motor2();
void backward_motor2(); // Andar para trás m2
void forward_motor2();  // Andar para frente m2

//  Funções para os motores em conjunto!

void forward();
void backward();
void stop_();
void right();
void left();

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_ENTRADA_1, OUTPUT);
  pinMode(PIN_ENTRADA_2,OUTPUT);
  pinMode(PIN_ENTRADA_3, OUTPUT);
  pinMode(PIN_ENTRADA_4,OUTPUT);
}

void pwm_teste()
{
  for(pwm = 0;pwm < 256;pwm++)
    {
      analogWrite(PIN_ENTRADA_2,pwm);
      delay(50);
    }
}

void loop()
{
  forward();
  backward();
  left();
  right();
}

void backward_motor1()
{
  digitalWrite(PIN_ENTRADA_1,LOW);
  digitalWrite(PIN_ENTRADA_2,HIGH);
  delay(5000);
}

void forward_motor1()
{ 
  digitalWrite(PIN_ENTRADA_1,HIGH);
  digitalWrite(PIN_ENTRADA_2,LOW);
  delay(5000);
}

void forward_motor2()
{
  digitalWrite(PIN_ENTRADA_3,LOW);
  digitalWrite(PIN_ENTRADA_4,HIGH);
  delay(5000);
}

void backward_motor2()
{
  digitalWrite(PIN_ENTRADA_3,HIGH);
  digitalWrite(PIN_ENTRADA_4,LOW);
  delay(5000);
}


void stop_motor1()
{
  digitalWrite(PIN_ENTRADA_1,LOW);
  digitalWrite(PIN_ENTRADA_2,LOW);
  delay(5000);
}

void stop_motor2()
{
  digitalWrite(PIN_ENTRADA_3,LOW);
  digitalWrite(PIN_ENTRADA_4,LOW);
  delay(5000);
}

void forward()
{
   digitalWrite(PIN_ENTRADA_1,HIGH);
   digitalWrite(PIN_ENTRADA_2,LOW);
   digitalWrite(PIN_ENTRADA_3,HIGH);
   digitalWrite(PIN_ENTRADA_4,LOW);
   delay(5000);
}
void backward()
{
  digitalWrite(PIN_ENTRADA_1,LOW);
  digitalWrite(PIN_ENTRADA_2,HIGH);
  digitalWrite(PIN_ENTRADA_3,LOW);
  digitalWrite(PIN_ENTRADA_4,HIGH);
  delay(5000);
}
void stop_()
{
  digitalWrite(PIN_ENTRADA_1,LOW);
  digitalWrite(PIN_ENTRADA_2,LOW);
  digitalWrite(PIN_ENTRADA_3,LOW);
  digitalWrite(PIN_ENTRADA_4,LOW);
  delay(5000);
}
void right()
{
  digitalWrite(PIN_ENTRADA_1,HIGH);
  digitalWrite(PIN_ENTRADA_2,LOW);
  digitalWrite(PIN_ENTRADA_3,LOW);
  digitalWrite(PIN_ENTRADA_4,LOW);
  delay(5000);
}
void left()
{
  digitalWrite(PIN_ENTRADA_1,LOW);
  digitalWrite(PIN_ENTRADA_2,LOW);
  digitalWrite(PIN_ENTRADA_3,HIGH);
  digitalWrite(PIN_ENTRADA_4,LOW);
  delay(5000);
}
