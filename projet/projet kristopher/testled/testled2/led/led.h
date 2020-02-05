#ifndef LED_H
#define LED_H

#include <Adafruit_NeoPixel.h>

#define PIN 8
#define NOMBRELED 50
#define DELAY1 200
#define DELAY2 500


void unique();

void initialisation();

void eteindre();

void clignotement(int allumer);

void allumage();

void reverse();

void unique(int seul);

void continu();

#endif
