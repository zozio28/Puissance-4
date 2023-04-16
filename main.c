#include <stdio.h>
#include <stdlib.h>
#include "puissance4.h"

int main(){
  int taille = 7;
  int** tab = NULL;
  int joueur = 1;
  int nbCoups = 0;

  tab = allouer(taille);
  initialiser(tab, taille);
  
  for (int i=0; i<taille*taille; i++){
    afficher(tab, taille);
    tourDeJeu(tab,&joueur,taille);
    jouer(tab,taille,joueur);
    nbCoups++;
    if(aGagne(tab,taille)){
      afficher(tab,taille);
      printf("Joueur %d a gagné !\n",joueur);
      break;
    }else if(nbCoups == taille*taille){
      afficher(tab,taille);
      printf("Match nul !\n");
      break;
    }
  }

  libere(tab,taille);

  return 0;
}
