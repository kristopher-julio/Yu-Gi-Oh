#include "led.h"

void setup()
{
  initialisation();
}

void loop()
{
    allumage();
    reverse();
    
    continu();
    eteindre();
    delay(2000);
}
