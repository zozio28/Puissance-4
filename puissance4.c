#include <stdio.h> //printf, scanf
#include <stdlib.h>
#include "puissance4.h"

//Fonction qui permet d'allouer un tableau dynamique
int** allouer(int taille){
  int** ptab = NULL;
  ptab = malloc(taille * sizeof(int*));
  for (int i=0; i<taille; i++){
    ptab[i] = malloc(taille * sizeof(int));
  }
  return ptab;
}

//Procédure qui permet d'initialiser un tableau dynamique
void initialiser(int** maGrille,int taille){
  for (int i=0; i<taille; i++){
    for (int j=0; j<taille; j++){
      maGrille[i][j]=-1;
    }
  }
}

//Procédure qui permet d'afficher un tableau dynamique
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
  printf("+---+---+---+---+---+---+---+\n");
}

//Fonction demande au joueur de saisir les coordonnées de son pion
int jouer(int** maGrille,int taille,int joueur){
  int res = 0;
  int colonne;
  int l=taille-1;

  //demande au joueur de jouer tant que ses coordonnées sont inexactes
  do {
    printf("Veuillez saisir une colonne (0-6) ? \n");
    scanf("%d", &colonne);
  } while ((colonne > l) || (colonne < 0));

  //enregistre la place du pion du joueur
  while (l >= 0 && !res){
    if(maGrille[l][colonne] == -1){
      maGrille[l][colonne] = joueur;
      res = 1;
    }else{
      l = l - 1;
    }
  }

  return res;
}

//Procédure qui permet de placer le pion du joueur et changer de joueur
void tourDeJeu(int** maGrille,int*joueur,int taille){
  int cptTour = 0;
  int res = -1;

  //place le pion du joueur si ses coordonnées son correctes
  while (res==-1 && cptTour!=taille*taille){
    if (jouer(maGrille,taille,*joueur)) {
      afficher(maGrille,taille);

      res = aGagne(maGrille,taille);
      if (res) {
        break;
      }else if(cptTour==taille*taille){
        break;
      }

      if (!res){
        //augmente le compteur du tour
        cptTour++;

        //change de joueur
        switch(*joueur){
            case 1 :
                *joueur = 2;
                break;
            case 2 :
                *joueur = 1;
                break;
        }
      }
    }
  }

}

//Fonction qui vérifie les lignes
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

//Fonction qui vérifie les colonnes
int verificationColonnes(int** maGrille,int taille){
  int joueur = -1;
  int i,j;

  for(int i=0 ; i<taille-3 ; i++){
    for(int j=0 ; j<taille ; j++){
      if((maGrille[i][j]!=-1) && (maGrille[i][j]==maGrille[i+1][j]) && (maGrille[i+1][j]==maGrille[i+2][j]) && (maGrille[i+2][j]==maGrille[i+3][j])){
        joueur = maGrille[i][j];
      }
    }
  }

  return joueur;
}

//Fonction qui vérifie la diagonale bas-gauche vers haut-droite
int verificationDiag1(int** maGrille,int taille){
  int joueur = -1;
  int i,j;

  for(int i=0 ; i<taille-3 ; i++){
    for(int j=3 ; j<taille ; j++){
      if((maGrille[i][j]!=-1) && (maGrille[i][j]==maGrille[i+1][j-1]) && (maGrille[i+1][j-1]==maGrille[i+2][j-2]) && (maGrille[i+2][j-2]==maGrille[i+3][j-3])){
        joueur = maGrille[i][j];
      }
    }
  }

  return joueur;
}

//Fonction qui vérifie la diagonale haut-gauche vers bas-droite
int verificationDiag2(int** maGrille, int taille){
  int joueur = -1;
  int i,j;

  for(int i=0 ; i<taille-3 ; i++){
    for(int j=0 ; j<taille-3 ; j++){
      if((maGrille[i][j]!=-1) && (maGrille[i][j]==maGrille[i+1][j+1]) && (maGrille[i+1][j+1]==maGrille[i+2][j+2]) && (maGrille[i+2][j+2]==maGrille[i+3][j+3])){
        joueur = maGrille[i][j];
      }
    }
  }
  return joueur;
}

//Fonction qui permet de tester si un joueur a gagné
int aGagne(int** maGrille,int taille){
 
  //vérification des lignes
  if (verificationLignes(maGrille,taille) != -1){
    return 1;
  }

  //vérification des colonnes
  if (verificationColonnes(maGrille,taille) != -1){
    return 1;
  }

  //vérification de la diagonale 1
  if (verificationDiag1(maGrille,taille) != -1){
    return 1;
  }

  //vérificaton de la diagonale 2
  if (verificationDiag2(maGrille,taille) != -1){
    return 1;
  }

  return 0;

}

//Procédure qui libère l'espace alloué
void libere (int** maGrille,int taille){
  for(int i=0 ; i<taille ; i++){
    free(maGrille[i]);
  }
  free(maGrille);
}