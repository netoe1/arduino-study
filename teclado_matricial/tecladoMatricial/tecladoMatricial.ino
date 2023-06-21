
void setup()
{
  //LINHAS
  pinMode(4, OUTPUT); //1
  pinMode(5, OUTPUT); //2
  pinMode(6, OUTPUT); //3
  pinMode(7, OUTPUT); //4
   
  //COLUNAS
  pinMode(8, INPUT); //5
  digitalWrite(8, HIGH);//resistor pull-up
  pinMode(9, INPUT); //6
  digitalWrite(9, HIGH);//resistor pull-up
  pinMode(10, INPUT); //7
  digitalWrite(10, HIGH);//resistor pull-up
   
  Serial.begin(9600);
  Serial.println("Aperte uma tecla:");
  Serial.println();
}
 
void loop(){

  for (int linha=4; linha<8; linha++){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(linha, LOW);

  
    if (digitalRead(8)==LOW){
      if (linha==4)
      {
        Serial.println("TECLA 1");
      }
      else if (linha==5)
      
      {
          Serial.println("TECLA 4");      
      }
      else if (linha==6)
      {
          Serial.println("TECLA 7");        
      }
      else if (linha==7)
      {
          Serial.println("TECLA *");        
      }
      while(digitalRead(j)==LOW);

      if (digitalRead(9)==LOW){
        if (linha==4)
        {
          Serial.println("TECLA 1");
        }
        else if (linha==5)
        
        {
            Serial.println("TECLA 4");      
        }
        else if (linha==6)
        {
            Serial.println("TECLA 7");        
        }
        else if (linha==7)
        {
            Serial.println("TECLA *");        
        }
        while(digitalRead(j)==LOW);

      if (digitalRead(10)==LOW){
        if (linha==4)
        {
          Serial.println("TECLA 1");
        }
        else if (linha==5)
        
        {
            Serial.println("TECLA 4");      
        }
        else if (linha==6)
        {
            Serial.println("TECLA 7");        
        }
        else if (linha==7)
        {
            Serial.println("TECLA *");        
        }
        while(digitalRead(j)==LOW);
  }
 
  //INSERIR CÓDIGO AQUI (para tratar das outras colunas)

  delay(10);
 
 }
