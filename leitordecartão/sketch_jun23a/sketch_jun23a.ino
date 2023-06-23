#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 9
#define RST_PIN 8
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Instancia o MFRC522

//Pinagem para Arduino Mega:
// RC522    MEGA
// SDA      D9
// SCK      D52
// MOSI     D51
// MISO     D50
// IRQ      N/A
// GND      GND
// RST      D8
// 3.3V     3.3V
 
char st[20];
 
void setup()
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia o barramento SPI
  mfrc522.PCD_Init();   // Inicia o MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();  
}
 
void loop()
{
  // Procura por novos cartões
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Seleciona um cartão
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
     
  }
  Serial.println();

  conteudo.toUpperCase();
  if(conteudo.substring(1) == "B6 F7 C8 EF")
  {
     Serial.println("Cartão valido!");
  }
  else
  {
    Serial.println("Cartão Inválido!");
  }
  delay(1000);
  //INSERIR AQUI A PARTE DE RECONHECIMENTO DE CARTÕES VÁLIDOS

}
