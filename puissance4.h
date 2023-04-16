#ifndef __puissance4_H_
#define __puissance4_H_

int** allouer(int taille);
void initialiser(int** maGrille,int taille);
void afficher(int** maGrille,int taille);
int jouer(int** maGrille,int taille,int joueur);
void tourDeJeu(int** maGrille, int* joueur, int taille);
int verificationLignes(int** maGrille,int taille);
int verificationColonnes(int** maGrille,int taille);
int verificationDiag1(int** maGrille,int taille);
int verificationDiag2(int** maGrille, int taille);
int aGagne(int** maGrille,int taille);
void libere (int** maGrille,int taille);

#endif
