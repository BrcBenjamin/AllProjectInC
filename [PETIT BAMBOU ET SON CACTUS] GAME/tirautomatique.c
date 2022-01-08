#include <allegro.h>
#include "header.h"
///ACTUALISATION DES TIR
void tirbdFeu(t_bdFeu*bdFeu,t_bdFeu*bdFeuG,t_ninja*ninja,BITMAP*page,int*psx)
{
    ///BOULE DE FEU GAUCHE
    bdFeuG->x = bdFeuG->x + bdFeuG->vx;
        masked_blit(bdFeuG->bouledeFeu,page,0,0,bdFeuG->x-*psx,bdFeuG->y,bdFeuG->tx,bdFeuG->ty);
    ///BOULE DE FEU DROITE
    bdFeu->x = bdFeu->x + bdFeu->vx;
        masked_blit(bdFeu->bouledeFeu,page,0,0,bdFeu->x-*psx,bdFeu->y,bdFeu->tx,bdFeu->ty);
    if(bdFeuG->x==ninja->x && bdFeuG->y==ninja->y || bdFeu->x==ninja->x && bdFeu->y==ninja->y)
    {
        bdFeuG->y=2000;
        bdFeu->y=2000;
        ninja->vie-=1;
    }
}

int tir1(t_boss*boss,t_ninja*ninja,BITMAP*page,int*psx,int*psy,t_bdFeu*D1TIR,t_bdFeu*D2TIR,t_bdFeu*D3TIR,t_bdFeu*D4TIR)
{
    ///DIAGONALE HAUT GAUCHE
    D1TIR->x = D1TIR->x + D1TIR->vx;
    D1TIR->y = D1TIR->y + D1TIR->vy;
        masked_blit(D1TIR->bouledeFeu,page,0,0,D1TIR->x-*psx,D1TIR->y,D1TIR->tx,D1TIR->ty);
    ///DIAGONALE HAUT DROITE
    D2TIR->x = D2TIR->x + D2TIR->vx;
    D2TIR->y = D2TIR->y + D2TIR->vy;
        masked_blit(D2TIR->bouledeFeu,page,0,0,D2TIR->x-*psx,D2TIR->y,D2TIR->tx,D2TIR->ty);
    ///DIAGONALE BAS GAUCHE
    D3TIR->x = D3TIR->x + D3TIR->vx;
    D3TIR->y = D3TIR->y + D3TIR->vy;
        masked_blit(D3TIR->bouledeFeu,page,0,0,D3TIR->x-*psx,D3TIR->y,D3TIR->tx,D3TIR->ty);
    ///DIAGONALE BAS DROITE
    D4TIR->x = D4TIR->x + D4TIR->vx;
    D4TIR->y = D4TIR->y + D4TIR->vy;
        masked_blit(D4TIR->bouledeFeu,page,0,0,D4TIR->x-*psx,D4TIR->y,D4TIR->tx,D4TIR->ty);
    ///COLLISISONS
    if(D1TIR->x<=ninja->x+ninja->tx && D1TIR->x>=ninja->x && D1TIR->y>=ninja->y && D1TIR->y<=ninja->y+ninja->ty || D2TIR->x+D2TIR->tx>=ninja->x && D2TIR->x+D2TIR->tx<=ninja->x+ninja->tx && D2TIR->y>=ninja->y && D2TIR->y<=ninja->y+ninja->ty || D3TIR->x<=ninja->x+ninja->tx && D3TIR->x>=ninja->x && D3TIR->y>=ninja->y && D3TIR->y<=ninja->y+ninja->ty || D4TIR->x+D4TIR->tx>=ninja->x && D4TIR->x+D4TIR->tx<=ninja->x+ninja->tx && D4TIR->y>=ninja->y && D4TIR->y<=ninja->y+ninja->ty)
    {
        D1TIR->x=4000;
        D2TIR->x=4000;
        D3TIR->x=4000;
        D4TIR->x=4000;
        ninja->vie-=1;
    }
    return ninja->vie;
}
