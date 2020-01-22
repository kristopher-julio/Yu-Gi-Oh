#include <Wire.h>
#include "detecteur_carte.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  char addressPCF8574 [4][5]= {{"0x3B"},{"0x3C"},{"0x3A"},{"0x39"}};
  int lecturebrochePCF8574 [4][9]= {{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};
}

void loop()
{
  detection();
}
