#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

typedef struct ninja
{
    ///INITIALISATION COORDONNEES + COORDONNEES PRECEDENTES POUR COLLISIONS
    int x,y;
    ///INITIALISATION IMAGE ET TAILLES DE L'IMAGE,COORDONNES DU SPRITE SUR L'IMAGE PERSONNAGE.
    BITMAP*imgNinja;
    BITMAP*inverse;
    int tx,ty,cx,cy;
    int vie;

}t_ninja;

 typedef struct kunai
 {
    ///INITIALISATION COORDONNES + COORDONNEES PRECEDENTES POUR COLLISIONS
    int x,y;
    ///INITIALISATION VECTEUR DEPLACEMENT
    int vx,vy;
    ///INITIALISATION COMPTEUR DELAI
    int cdelai;
    ///INITIALISATION IMAGE ET TAILLES DE L'IMAGE
    BITMAP*kunai;
    BITMAP*kunaiinverse;
 }t_kunai;

 typedef struct bot1
{
    ///INITIALISATION COORDONNEES
    int x,y;
    ///INITIALISATION VECTEUR DEPLACEMENT
    int vx,vy;
    ///INITIALISATION IMAGE ET TAILLES DE L'IMAGE
    BITMAP*imgBot1;
    BITMAP*bot1Attaque;
    int tx,ty;
    int vie;
    ///COMPTEUR TIR
    int tir;
}t_bot1;

typedef struct bot2
{
    ///INITIALISATION COORDONNEES
    int x,y;
    ///INITIALISATION VECTEUR DEPLACEMENT
    int vx,vy;
    ///INITIALISATION IMAGE ET TAILLES DE L'IMAGE
    BITMAP*imgBot2;
    BITMAP*inverseBot2;
    int tx,ty;
    int vie;

}t_bot2;

typedef struct boss
{
    ///INITIALISATION COORDONEES
    int x,y,vx,vy;
    ///INITIALISATION IMAGES ET TAILLES
    BITMAP*image;
    int tx,ty;
    int vie;
    int tir;
}t_boss;

typedef struct bdFeu
{
    ///INITIALISATION COORDONNEES
    int x,y,vx,vy;
    ///INITIALISATION IMAGE ET TAILLES DE L'IMAGE
    int tx,ty;
    BITMAP*bouledeFeu;
}t_bdFeu;

typedef struct OBJcassable
{
    int pv;
    ///INITIALISATION COORDONNEES
    int x,y;
    ///INITIALISATION IMAGE ET TAILLES DE L'IMAGE
    int tx,ty;
    BITMAP*image;
}t_OBJcassable;

///DEPLACEMENT DES ACTEUR AUTOMATIQUE
//niveau1
int deplacerBot1(t_bot1 *bot1, t_ninja *ninja,t_bdFeu*bdFeu,t_bdFeu*bdFeuG,BITMAP*page,int *psx, int *psy);
void tirbdFeu(t_bdFeu*bdFeu,t_bdFeu*bdFeuG,t_ninja*ninja,BITMAP*page,int*psx);
void deplacerBot2(t_bot2 *bot2, t_ninja *ninja,BITMAP*page);
void deplaKunai(t_kunai*kunai,BITMAP*page,int*psx,int*psy);
void destructionbambou(t_OBJcassable*bambou,BITMAP*page,int *psx, int *psy,t_ninja*ninja,t_bot1*bot1,t_bot2*bot2);
void afficherdelai(t_kunai*kunai,BITMAP*page);
void dplBoss1(t_ninja*ninja,t_boss*boss1,BITMAP*page,int*psx,t_bdFeu*D1TIR,t_bdFeu*D2TIR,t_bdFeu*D3TIR,t_bdFeu*D4TIR,t_bdFeu*bdFeu,t_bdFeu*bdFeuG);
int tir1(t_boss*boss,t_ninja*ninja,BITMAP*page,int*psx,int*psy,t_bdFeu*D1TIR,t_bdFeu*D2TIR,t_bdFeu*D3TIR,t_bdFeu*D4TIR);
//niveau2
void AffLanceur(t_bot1*lanceur1,t_bot1*lanceur2,t_bdFeu*hache,t_bdFeu*hache2,BITMAP*page,int *psx,int*psy);
void tirlanceur(t_bot1*lanceur1,t_bot1*lanceur2,t_bdFeu*hache,t_bdFeu*hache2,t_ninja*ninja,BITMAP*page,int *psx);
//niveau 3
void dplBossFinal(t_ninja*ninja,t_boss*boss,BITMAP*page,int*psx,t_bdFeu*D1TIR,t_bdFeu*D2TIR,t_bdFeu*D3TIR,t_bdFeu*D4TIR,t_bdFeu*bdFeu,t_bdFeu*bdFeuG,t_bot2*bot2,t_bot1*lanceur1,t_bot1*lanceur2,t_bdFeu*hache,t_bdFeu*hache2);
///COMMANDE UTILISATEUR
void Up(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);
void Down(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);
void Right(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);
void BoostRight(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);
void Left(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);
void BoostLeft(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);
void CoupEpee(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);
void lancerKunai(t_ninja*ninja,t_kunai*kunai,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy);

///FONCTION COLLISIONS
//niveau 1
void collisionMur(t_ninja*ninja,int*pmur);
int collisionBot1(t_ninja*ninja,t_bot1*bot1,t_kunai*kunai,int*psx);
int collisionBot2(t_ninja*ninja,t_bot2*bot2,t_kunai*kunai);
int collisionBoss(t_ninja*ninja,t_boss*boss,t_kunai*kunai,int*psx);
int collisionCassable(t_ninja*ninja,t_OBJcassable*bambou,t_kunai*kunai,int*psx);
//niveau 2
void collisionMur2(t_ninja*ninja,int*pmur);
void collisionMurKunai(t_kunai*kunai,int*psx);
int collisionLanceur(t_ninja*ninja,t_bot1*lanceur1,t_bot1*lanceur2,t_kunai*kunai,int*psx);
//niveau 3
void FIN(t_OBJcassable*bambou,BITMAP*page,int *psx, int *psy,t_ninja*ninja,t_boss*boss,t_bot2*bot2);

///CALCUL VIE NINJA
int vieNinja(BITMAP*page, t_ninja*ninja,int*psx,int*psy);

///NIVEAUX
void NIVEAU1(BITMAP*page,BITMAP*MENUJEU,BITMAP*nivactuel);
void NIVEAU2(BITMAP*page,BITMAP*MENUJEU,BITMAP*nivactuel);
void NIVEAU3(BITMAP*page,BITMAP*MENUJEU,BITMAP*nivactuel);
