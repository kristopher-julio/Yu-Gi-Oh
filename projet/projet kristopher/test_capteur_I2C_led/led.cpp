#include "led.h"

Adafruit_NeoPixel test1(NOMBRELED, PIN, NEO_GRB + NEO_KHZ800);

void initialisationLed()
{
  test1.begin();
  test1.show();
}

void animationAllumage()
{
  for (int i = 0; i < NOMBRELED; i++)
  {
    if (i == 10)
    {
      clignotement(i);
    }
    test1.setPixelColor(i, 0, 0, 150);
    test1.show();
    delay(DELAY1);
  }
}

void eteindre()
{
  test1.clear();
}

/*void clignotement(int allumer)
{
  for (int test = 0; test < 5; test++)
  {
    for (int i = 0; i < allumer; i++)
    {
      test1.setPixelColor(i, 150, 0, 0);
    }
    test1.show();
    delay(DELAY2);
    for (int i = 0; i < allumer; i++)
    {
      test1.setPixelColor(i, 0, 150, 0);
    }
    test1.show();
    delay(DELAY2);
  }
}*/

void reverse()
{
  for (int i = NOMBRELED; i > -1; i--)
  {
    test1.setPixelColor(i, 0, 150, 150);
    test1.show();
    delay(DELAY1);
  }
}

void unique(int seul, int presence)
{
  if (presence == 0)
  {
    test1.setPixelColor(seul, 150, 150, 0);
  }
  else
  {
    test1.setPixelColor(seul, 75, 0, 75);
  }
}

void continu()
{
  for (int i = 0; i < NOMBRELED; i++)
  {
    test1.setPixelColor(i, 150, 0, 150);

  }
  test1.show();
  delay(DELAY1);
}

void gainPv()
{
  for (int i = (NOMBRELED - 4) / 2; i < NOMBRELED - 2; i++)
  {
    test1.setPixelColor(i, 250, 0, 0);
  }
  test1.show();
  delay(DELAY4);
  for (int i = (NOMBRELED - 4) / 2; i < NOMBRELED - 2; i++)
  {
    test1.setPixelColor(i, 0, 0, 0);
  }
  test1.show();
  delay(DELAY4);
}

void pertPv()
{
  for (int i = 0; i < (NOMBRELED - 4) / 2; i++)
  {
    test1.setPixelColor(i, 0, 250, 0);
  }
  test1.show();
  delay(DELAY4);
  for (int i = 0; i < (NOMBRELED - 4) / 2; i++)
  {
    test1.setPixelColor(i, 0, 0, 0);
  }
  test1.show();
  delay(DELAY4);
}

void carte(int (*tabBroche)[8], int (*tabLed)[7], int numAddress)
{
  int led;
  for (int broche = 0; broche < 8; broche++)
  {
    led = tabLed [numAddress][broche - 1];
    if (led == NOMBRELED - 2 && numAddress == 3)
    {
      broche = 7;
    }
    else if (tabBroche [numAddress][broche] == 0)
    {
      unique(led, 0);
    }
    else
    {
      unique(led, 1);
    }
  }
  test1.show();
  delay(DELAY3);
}

char tirage()
{
  int premier = random(5,10);
    for (int tir = 0; tir < premier; tir++)
    {
      test1.setPixelColor(NOMBRELED - 2,0, 150, 150);
      test1.setPixelColor(NOMBRELED - 1 ,0, 0, 0);
      test1.show();
      delay(DELAY2);
      test1.setPixelColor(NOMBRELED - 1,0, 150, 150);
      test1.setPixelColor(NOMBRELED - 2,0, 0, 0);
      test1.show();
      delay(DELAY2);
    }
    if(premier%2==0)
    {
      test1.setPixelColor(NOMBRELED - 2,0, 150, 150);
      test1.setPixelColor(NOMBRELED - 1 ,0, 0, 0);
      test1.show();
      delay(DELAY2);
      return 'p';
    }
    else
    {
      return 'i';
    }
    
}

char fin(char change)
{
    if(change=='p')
    {
      test1.setPixelColor(NOMBRELED - 1,0, 150, 150);
      test1.setPixelColor(NOMBRELED - 2,0, 0, 0);
      test1.show();
      delay(DELAY2);
      return 'i';
    }
    else
    {
      test1.setPixelColor(NOMBRELED - 2,0, 150, 150);
      test1.setPixelColor(NOMBRELED - 1,0, 0, 0);
      test1.show();
      delay(DELAY2);
      return 'p';
    }
}
