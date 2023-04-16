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
  printf("-----------------------------\n");
}

int jouer(int** maGrille,int taille,int joueur){
  int res = 0;
  int colonne;
  int l=taille-1;

  do {
    printf("Veuillez saisir une colonne ? \n");
    scanf("%d", &colonne);
  } while ((colonne > taille-1) || (colonne < 0));

  while (l >= 0 && !res){
    if(maGrille[l][colonne] == -1){
      maGrille[l][colonne] = joueur;
      res = 1;
    }else{
      l = l - 1;
      if (l >= 0 && maGrille[l][colonne] == -1){
        maGrille[l][colonne] = joueur;
        res = 1;
      }
    }
  }

  return res;
}

void tourDeJeu(int** maGrille,int*joueur,int taille){
  int cptTour = 0;
  int res = -1;
  int place = 0;

  while (res==-1 || cptTour!=taille*taille){
    while(!place){
      place = jouer(maGrille,taille,*joueur);
      if(!place){
        printf("-----Erreur de saisie----- \nVeuillez recommencer \n");
      }
      afficher(maGrille,taille);
    }

    cptTour++;
    res = aGagne(maGrille,taille); 

    //change de joueur
    switch(*joueur){
        case 1 :
            *joueur = 2;
            break;
        case 2 :
            *joueur = 1;
            break;
    }

    place = 0;
  }
}

int verificationLignes(int** maGrille,int taille){
  int joueur = -1;
  int i,j;

  for(int i = 0; i<taille ; i++){
    for(int j = 0 ; j<taille-3 ; j++){
      if((maGrille[i][j]!=-1) && (maGrille[i][j]==maGrille[i][j+1]) && (maGrille[i][j+1]==maGrille[i][j+2]) && (maGrille[i][j+2]==maGrille[i][j+3])){        
        joueur = maGrille[i][j];
      }
    }
  }
  return joueur;
}

int verificationColonnes(int** maGrille,int taille){
  int joueur = -1;
  int i,j;

  for(int i=0 ; i<taille ; i++){
    for(int j=0 ; j<taille-3 ; j++){
      if((maGrille[i][j]!=-1) && (maGrille[i][j]==maGrille[i][j+1]) && (maGrille[i][j+1]==maGrille[i][j+2]) && (maGrille[i][j+2]==maGrille[i][j+3])){
        joueur = maGrille[i][j];
      }
    }
  }
  return joueur;
}

int verificationDiag1(int** maGrille,int taille){
  int joueur = -1;
  int i,j;

  for(int i=0 ; i<taille-3 ; i++){
    for(int j=3 ; j<taille ; j++){
      if((maGrille[i][j]!=-1) && (maGrille[i][j]==maGrille[i][j+1]) && (maGrille[i][j+1]==maGrille[i][j+2]) && (maGrille[i][j+2]==maGrille[i][j+3])){
        joueur = maGrille[i][j];
      }
    }
  }
  return joueur;
}

int verificationDiag2(int** maGrille, int taille){
  int joueur = -1;
  int i,j;

  for(int i=0 ; i<taille-3 ; i++){
    for(int j=0 ; j<taille-3 ; j++){
      if((maGrille[i][j]!=-1) && (maGrille[i][j]==maGrille[i][j+1]) && (maGrille[i][j+1]==maGrille[i][j+2]) && (maGrille[i][j+2]==maGrille[i][j+3])){
        joueur = maGrille[i][j];
      }
    }
  }
  return joueur;
}

int aGagne(int** maGrille,int taille){
  int joueur;

  for(int i = 0; i < taille ; i++){
    if (verificationLignes(maGrille,taille)){
      return 1;
    }
  }

  for(int i = 0; i < taille ; i++){
    if (verificationColonnes(maGrille,taille)){
      return 1;
    }
  }

  if (verificationDiag1(maGrille,taille)){
    return 1;
  }

  if (verificationDiag2(maGrille,taille)){
    return 1;
  }
  return 0;

}

void libere (int** maGrille,int taille){
  for(int i=0 ; i<taille ; i++){
    free(maGrille[i]);
  }
  free(maGrille);
}