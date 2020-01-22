int capteur = 3;
int detection;

void setup() 
{
  pinMode(capteur, INPUT); // broche "capteur" (3) en ENTREE
}

void loop() 
{
  detection = digitalRead(capteur); // on lit la broche capteur
  // la sortie OUT du capteur est active sur niveau bas
  while (detection == 0) { // objet détecté = niveau 0 sur OUT capteur
    detection = digitalRead(capteur);
    Serial.println("carte poser");
  }
  Serial.println("carte retirer");

}
