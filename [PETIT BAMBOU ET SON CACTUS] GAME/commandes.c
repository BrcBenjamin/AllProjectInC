#include <allegro.h>
#include "header.h"

void Up(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    ninja->tx=80;
    ninja->ty=80;
    ninja->cx=404;
    ninja->cy=704;
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ninja->y-=2;
    masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy+15,ninja->tx,ninja->ty);
    if(ninja->y<0)
        ninja->y=0;///BLINDAGE POUR QUE LE PERSO NE SORTE PAS EN HAUT
    ninja->tx=85;
    ninja->ty=85;
    ninja->cx=0;
    ninja->cy=0;

}

void Down(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    ninja->tx=65;
    ninja->ty=90;
    ninja->cx=515;
    ninja->cy=700;
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ninja->y+=1;
    masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy+15,ninja->tx,ninja->ty);
    if(ninja->y>400)
        ninja->y=400;///BLINDAGE POUR QUE LE PERSO NE SORTE PAS EN BAS
    ninja->tx=85;
    ninja->ty=85;
    ninja->cx=0;
    ninja->cy=0;
}

void Right(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ninja->x+=1;
    ninja->cx=215;
    ninja->cy=200;
    masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy+15,ninja->tx,ninja->ty);
    if(ninja->x+ninja->tx>1897)
        ninja->x=1897-ninja->tx;
    ninja->cx=0;
    ninja->cy=0;
}

void BoostRight(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ninja->x+=2;
    masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy,ninja->tx,ninja->ty);
    if(ninja->x+ninja->tx>1897)
        ninja->x=1897-ninja->tx;
}

void Left(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ninja->x-=1;
    //On fait y+15 car l'image est legerement surelever et donc pas afficher un mec qui vol
    masked_blit(ninja->inverse,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy+15,ninja->tx,ninja->ty);
    if(ninja->x<0)
        ninja->x=0;
}

void BoostLeft(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ninja->x-=2;
    ninja->cx=205;
    ninja->cy=1465;
    //On fait y+15 car l'image est legerement surelever et donc pas afficher un mec qui vol
    masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy+15,ninja->tx,ninja->ty);
    if(ninja->x<0)
        ninja->x=0;
    ninja->cx=0;
    ninja->cy=0;
}

void CoupEpee(t_ninja*ninja,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ///ON MODIFIE L'ANIMATION DU PERSONNAGE
    ninja->tx=140;
    ninja->ty=90;
    ninja->cx=320;
    ninja->cy=510;
    masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy+15,ninja->tx,ninja->ty);
    ///ON REMET LA TAILLE DE L'IMAGE INITIALE
    ninja->tx=85;
    ninja->ty=85;
    ninja->cx=0;
    ninja->cy=0;
}

void lancerKunai(t_ninja*ninja,t_kunai*kunai,BITMAP*page,BITMAP*nivactuel,int*psx,int*psy)
{
    ///ON REAFFICHE LE NIVEAU
    stretch_blit(nivactuel,page,*psx,*psy,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
    ///ON MODIFIE L'ANIMATION DU PERSONNAGE ET ON AJOUTE LE KUNAI SUR LE PERSONNAGE
    ninja->tx=70;
    ninja->ty=60;
    ninja->cx=0;
    ninja->cy=320;
    ///ON DONNE LES COORDONNEES DU KUNAI AU CENTRE DU PERSONNAGE
    kunai->x=ninja->x+35-*psx;
    kunai->y=ninja->y+50;
    ///ON AFFICHE LE KUNAI ET LE PERSONNAGE
    masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-*psx,ninja->y-*psy+15,ninja->tx,ninja->ty);
    masked_blit(kunai->kunai,page,0,0,kunai->x-*psx,kunai->y-*psy,35,11);
    ///CALCUL DU VECTEUR DEPLACEMENT DU KUNAI
    if(mouse_x-kunai->x<0)kunai->vx=-3;
    if(mouse_x-kunai->x>0)kunai->vx=3;
    ///ON REMET LA TAILLE DE L'IMAGE INITIALE
    ninja->tx=85;
    ninja->ty=85;
    ninja->cx=0;
    ninja->cy=0;
    ///REINITIALISE LE COMPTEUR A 0 POUR CREER UN TEMPS DE RECHARGE
    kunai->cdelai=0;
}
