#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

void pousser(char Animaux[7][7],char Orientation[7][7],int x,int y,int *victoire);

void affconsole(char Animaux[7][7], char Orientation[7][7],int x,int y);

void Color(int couleurDuTexte,int couleurDeFond);

void deplacer(char Animaux[7][7],char Orientation[7][7],int x,int y);

void entrerA(char Animaux[7][7], char Orientation[7][7],int x,int y, int *PointeurJoueur,int *NbrElephant, int *NbrRhino);

void orienter(char Animaux[7][7], char Orientation[7][7],int x,int y, int *PointeurJoueur);

void sortir(char Animaux[7][7],char Orientation[7][7],int x,int y,int *PointeurJoueur,int *NbrElephant, int *NbrRhino);

#endif // HEADER_H_INCLUDED
