#include "detecteur_carte.h"
#include "led.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  initialisationLed();
}

void loop()
{
  char tour;
  int nbAddress;
  int addressPCF8574 [4] = {57, 58, 59, 60};                            // 57 = 0x39 58 = 0x3A 59 = 0x3B 60 = 0x3C 
  int lecturebrochePCF8574 [4][8] = {{1, 1, 1, 1, 1, 1, 1, 1},          //etat initiale du PCF8574
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
  };
  int ledRGB [4][7] = {{0, 1, 2, 3, 4, 5, 6},
    {7, 8, 9, 10, 11, 12, 13},
    {14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27}
  };
  int resChang [8], c, changement;                                      //
  continu();
  tour = tirage();
  delay(400);
  for (int test = 0; test < 100; test++)                                  //
  {
    if (test == 4 || test == 5)
    {
        gainPv();
    }
    else if (test == 3 || test == 6)
    {
        pertPv();
    }
    else if (test == 7)
    {
      hasard();
    }
    for (nbAddress = 0; nbAddress < 4; nbAddress++)                     //
    {
      c = addressPCF8574[nbAddress];
      changement = detection(c);
      convertionBinaire(resChang, changement);
      if (modif(lecturebrochePCF8574, resChang, nbAddress) == false)
      {
        invertionTableau(lecturebrochePCF8574, resChang, nbAddress);
      }
      carte(lecturebrochePCF8574, ledRGB, nbAddress);
    }
    tour=finTour(tour);
    delay(200);
  }
}
