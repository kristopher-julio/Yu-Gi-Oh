#ifndef DETECTEUR_CARTE_H
#define DETECTEUR_CARTE_H

#include "Arduino.h"
#include <Wire.h>

int detection(int address);
void convertionBinaire(int* tabInverse,int nombre);
boolean modif(int (*tabFinal)[8],int* tab,int numAddress);
void invertionTableau(int (*tabFinal)[8],int* tab,int numAddress);

#endif
