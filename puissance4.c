#include <stdio.h>
#include <stdlib.h>
#include "puissance4.h"
/* corps des différentes fonctions/procédures */

int** allouer(int taille){
  int** ptab = NULL;
  ptab = malloc(taille * sizeof(int*));
  for (int i=0; i<taille; i++){
    ptab[i] = malloc(taille * sizeof(int));
  }
  return ptab;
}

void initialiser(int** maGrille,int taille){
  for (int i=0; i<taille; i++){
    for (int j=0; j<taille; j++){
      maGrille[i][j]=-1;
    }
  }
}

void afficher(int** maGrille,int taille){
  for (int i=0; i<taille; i++){
    printf("|");
    for (int j=0; j<taille; j++){
      switch (maGrille[i][j]) {
        case 1:
          printf(" X |");
          break;
        case 2:
          printf(" 0 |");
          break;
        default:
          printf("   |");
          break;
      }
    }
    printf("\n");
  }
  printf("\n");
}

int jouer(int** maGrille,int taille, int joueur){
  int colonne;
  int l=taille-1;

  printf("Veuillez saisir une colonne ? \n");
  scanf("%d", &colonne);

  if ((colonne > taille) || (colonne < 0) || (maGrille[0][colonne]!=-1)){
    printf("-----Erreur de saisie----- \n");
    return 0;
  }else{
    while (maGrille[l][colonne]!=-1){
      l-=1;
    }
    maGrille[l][colonne] = joueur;
    return 1;
  }
}

int aGagne(int** maGrille,int taille){

}

void tourDeJeu(int** maGrille,int taille){

}
