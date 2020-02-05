#include "led.h"

Adafruit_NeoPixel test1(NOMBRELED, PIN, NEO_GRB + NEO_KHZ800);

void initialisation()
{
  test1.begin();
  test1.show();
}

void allumage()
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

void clignotement(int allumer)
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
}

void reverse()
{
  for (int i = NOMBRELED; i > -1; i--)
  {
    if (i % 5 == 0)
    {
      unique(i);
    }
    else
    {
      test1.setPixelColor(i, 0, 150, 150);
      test1.show();
      delay(DELAY1);
    }
  }
}

void unique(int seul)
{
  test1.setPixelColor(seul, 150, 150, 0);
  test1.show();
  delay(DELAY2);
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
