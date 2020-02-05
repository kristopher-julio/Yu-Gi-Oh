#include "detecteur_carte.h"

int detection(int address)
{
  int c;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 1);
  while (Wire.available())
  {
    c = Wire.read();
  }
  return c;
}

void convertionBinaire(int* tabInverse, int nombre)
{
  for (int i = 0; nombre > 0; i++)
  {
    tabInverse[i] = nombre % 2;
    nombre = nombre / 2;
  }
}

boolean modif(int (*tabFinal)[8],int* tab,int numAddress)
{
  int somme1 = 0, somme2 = 0 ;
  for (int a = 0; a < 8; a++)
  {
    somme1 = somme1 + tabFinal[numAddress][a];
  }
  for (int b = 0; b < 8; b++)
  {
    somme2 = somme2 + tab[b];
  }
  if(somme1 == somme2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void invertionTableau(int (*tabFinal)[8],int* tab,int numAddress)
{
  for (int i = 0; i < 8; i++)
  {
    tabFinal[numAddress][i] = tab[7 - i];
  }
}
