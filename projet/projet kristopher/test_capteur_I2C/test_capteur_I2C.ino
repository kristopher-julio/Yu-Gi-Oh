#include "detecteur_carte.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  int address;
  int addressPCF8574 [4] = {60, 58, 57, 59};                                                                                                    // 59 = 0x3B 60 = 0x3C 58 = 0x3A 57 = 0x39
  int lecturebrochePCF8574 [4][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}};   //etat initiale du PCF8574
  int resChang [8], c, changement;                                                                                                              //
  for (int test = 0; test < 3; test++)                                                                                                          //
  {
    for (address = 0; address < 4; address++)                                                                                               //
    {
      Serial.print("affichage lecteur briche initial :");
      for (int i = 0; i < 8; i++)
      {
        Serial.print(lecturebrochePCF8574[address][i]);                                                                                         //
      }
      Serial.println("");
      c = addressPCF8574[address];

      Serial.print("affichage addresse :");                                                                                                     //
      Serial.println(c, HEX );
      changement = detection(c);

      Serial.print("valeur broche I2C retourner :");
      Serial.println(changement);

      Serial.print("convertion binaire avant inversion :");
      convertionBinaire(resChang, changement);
      for (int i = 0; i < 8; i++)
      {
        Serial.print(resChang[i]);
      }
      Serial.println("");
      if (modif(lecturebrochePCF8574, resChang, address) == false)
      {
        Serial.print("affichage lecteur broche final :");
        invertionTableau(lecturebrochePCF8574, resChang, address);
        for (int i = 0; i < 8; i++)
        {
          Serial.print(lecturebrochePCF8574[address][i]);
        }
        Serial.println("");
      }
      Serial.println(""); 
    }
    delay(4000);
  }
}
