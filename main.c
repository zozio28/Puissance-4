#include <stdio.h>
#include <stdlib.h>
#include "puissance4.h"

int main(){
  int taille = 7;
  int** tab = NULL;
  int joueur = 1;

  tab = allouer(taille);
  initialiser(tab, taille);
  afficher(tab, taille);
  for (int i=0; i<; i++){
    jouer(tab,taille,joueur);
    afficher(tab, taille);
  }

  free(tab);
  tab = NULL;

  return 0;
}
