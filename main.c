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
  afficher(tab, taille);
  
  for (int i=0; i<taille*taille; i++){
    tourDeJeu(tab,&joueur,taille);
    nbCoups++;    
    if(aGagne(tab,taille)){
      printf("\nJoueur %d a gagné !\n\n",joueur);
      break;
    }else if(nbCoups == taille*taille){
      printf("\nMatch nul !\n\n");
      break;
    }
  }

  libere(tab,taille);

  return 0;
}
