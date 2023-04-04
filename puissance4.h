#ifndef __puissance4_H_
#define __puissance4_H_

int** allouer(int taille);
void initialiser(int** maGrille,int taille);
void afficher(int** maGrille,int taille);
int jouer(int** maGrille,int taille, int joueur);
int aGagne(int** maGrille,int taille);
void tourDeJeu(int** maGrille,int taille);

#endif
