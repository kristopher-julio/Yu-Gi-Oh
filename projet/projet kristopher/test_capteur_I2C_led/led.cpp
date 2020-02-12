#include "led.h"

Adafruit_NeoPixel test1(NOMBRELED, PIN, NEO_GRB + NEO_KHZ800);

void initialisationLed()
{
  test1.begin();                                                    //
  test1.show();                                                     //
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void eteindre()
{
  test1.clear();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void unique(int seul, int presence)                               // presence correspond a une carte presente ou non devant un capteur
// seul correspond a l'indice d'une led
{
  if (presence == 0)                                              // si presence = 0 alors
  {
    test1.setPixelColor(seul, 150, 150, 0);                       // allume la led correspondant a seul en jaune
  }
  else                                                            // sinon
  {
    test1.setPixelColor(seul, 75, 0, 75);                         // allume la led correspondant a seul en cyan
  }
}

void continu()
{
  for (int i = 0; i < NOMBRELED; i++)                             // pour
  {
    test1.setPixelColor(i, 75, 0, 75);                            // configure la led correspondant a i en cyan
  }
  test1.show();                                                   // appelle de la fonction show pour pouvoir voir les couleurs des leds
}

void gainPv()
{
  for (int animGain = 0; animGain < 10; animGain++)
  {
    for (int i = (NOMBRELED - 4) / 2; i < NOMBRELED - 2; i++)       //
    {
      test1.setPixelColor(i, 250, 0, 0);                            // configure la led correspondant a i en vert
    }
    test1.show();                                                   //
    delay(DELAY3);
    for (int i = (NOMBRELED - 4) / 2; i < NOMBRELED - 2; i++)       //
    {
      test1.setPixelColor(i, 0, 0, 0);                              // configure la led correspondant a i en noir (eteint)
    }
    test1.show();
    delay(DELAY3);
  }
}

void pertPv()
{
  for (int animPert = 0; animPert < 10; animPert++)
  {
    for (int i = 0; i < (NOMBRELED - 4) / 2; i++)
    {
      test1.setPixelColor(i, 0, 250, 0);
    }
    test1.show();
    delay(DELAY3);
    for (int i = 0; i < (NOMBRELED - 4) / 2; i++)
    {
      test1.setPixelColor(i, 0, 0, 0);
    }
    test1.show();
    delay(DELAY3);
  }
}

void carte(int (*tabBroche)[8], int (*tabLed)[7], int numAddress)
{
  for (int broche = 1; broche < 8; broche++)
  {
    if (tabBroche [numAddress][broche] == 0)
    {
      unique(tabLed [numAddress][broche - 1], 0);
    }
    else
    {
      unique(tabLed [numAddress][broche - 1], 1);
    }
  }
  test1.show();
}

char tirage()
{
  int premier = random(5, 10);
  for (int tir = 0; tir < premier; tir++)
  {
    test1.setPixelColor(NOMBRELED - 2, 0, 150, 150);
    test1.setPixelColor(NOMBRELED - 1 , 5, 15, 107);
    test1.show();
    delay(DELAY2);
    test1.setPixelColor(NOMBRELED - 1, 0, 150, 150);
    test1.setPixelColor(NOMBRELED - 2, 5, 15, 107);
    test1.show();
    delay(DELAY2);
  }
  if (premier % 2 == 0)
  {
    test1.setPixelColor(NOMBRELED - 2, 0, 150, 150);
    test1.setPixelColor(NOMBRELED - 1 , 5, 15, 107);
    test1.show();
    return 'p';
  }
  else
  {
    return 'i';
  }
}

void hasard()
{
  int un = 0, deux = 10, trois = 15, quatre = 20, couleur = 4;
  for (int l = 0; l < 1000; l++)
  {
    test1.setPixelColor(un, 0, 0, 255);
    test1.setPixelColor(deux, 150, 75, 10);
    test1.setPixelColor(trois , 165, 255, 0);
    test1.setPixelColor(quatre , 108, 253, 158);
    test1.show();
    delay(DELAY1);
    un++;
    deux++;
    trois++;
    quatre++;
    switch (couleur)
    {
      case 1:
        if (un == NOMBRELED)
        {
          un = 0;
          couleur = 4;
        }
        break;
      case 2:
        if (deux == NOMBRELED)
        {
          deux = 0;
          couleur = 1;
        }
        break;
      case 3 :
        if (trois == NOMBRELED)
        {
          trois = 0;
          couleur = 2;
        }
        break;
      case 4:
        if (quatre == NOMBRELED)
        {
          quatre = 0;
          couleur = 3;
        }
        break;
    }
  }
}

char finTour(char change)
{
  if (change == 'p')
  {
    test1.setPixelColor(NOMBRELED - 1, 0, 150, 150);
    test1.setPixelColor(NOMBRELED - 2, 5, 15, 107);
    test1.show();
    return 'i';
  }
  else
  {
    test1.setPixelColor(NOMBRELED - 2, 0, 150, 150);
    test1.setPixelColor(NOMBRELED - 1, 5, 15, 107);
    test1.show();
    return 'p';
  }
}
