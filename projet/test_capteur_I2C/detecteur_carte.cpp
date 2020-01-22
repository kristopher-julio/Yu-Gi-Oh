#include <Wire.h>
#include "detecteur_carte.h"

int detection()
{
  
}

void loop()
{
  int c;                                                      
  Wire.beginTransmission(ADDRESS);                            
  Wire.requestFrom(ADDRESS, 1);                                
  while (Wire.available())                                    
  {
    c = Wire.read();                                         
  }
  if(c== 255)
  {
    Serial.println("pas de carte");
  }
  else if(c== 254)
  {
    Serial.println("piege 1");
  }
  else if(c== 253)
  {
    Serial.println("defence");
  }
  else
  {
    Serial.println("attaque defence");
  }
}
