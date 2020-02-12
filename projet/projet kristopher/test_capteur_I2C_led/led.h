#ifndef LED_H
#define LED_H

#include <Adafruit_NeoPixel.h>

#define PIN 8
#define NOMBRELED 30
#define DELAY1 20
#define DELAY2 200
#define DELAY3 75


void continu();

void initialisationLed();

void eteindre();

void clignotement(int allumer);

void unique(int seul, int presence);

void gainPv();

void pertPv();

void carte(int (*tabBroche)[8],int (*tabLed)[7],int numAddress);

char tirage();

void hasard();

char finTour(char change);

#endif
