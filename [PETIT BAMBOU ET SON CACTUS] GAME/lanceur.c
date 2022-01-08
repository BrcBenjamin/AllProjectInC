#include <allegro.h>
#include "header.h"

void AffLanceur(t_bot1*lanceur1,t_bot1*lanceur2,t_bdFeu*hache,t_bdFeu*hache2,BITMAP*page,int *psx,int*psy)
{
    int rouge=makecol(255,0,0);
    int orange=makecol(255,255,0);
    ///EXPLOSIONS SI LE LANCEUR1 N'A PLUS DE PV
    if(lanceur1->vie==0)
    {
        circlefill(page,lanceur1->x,lanceur1->y,100,rouge);
        lanceur1->y=2000;
        clear_bitmap(lanceur1->imgBot1);
    }
    ///EXPLOSIONS SI LE LANCEUR2 N'A PLUS DE PV
    if(lanceur2->vie==0)
    {
        circlefill(page,lanceur2->x,lanceur2->y,100,rouge);
        lanceur2->y=2000;
        clear_bitmap(lanceur2->imgBot1);
    }
    ///TIR ET RECHARGEMENT LANCEUR 1
    if(lanceur1->tir==200 && lanceur1->vie>0)
    {
        hache->x=lanceur1->x;
        hache->y=lanceur1->y;
    }
    if(lanceur1->tir>500)
    {
            lanceur1->tir=0;
    }
    ///TIR ET RECHARGEMENT LANCEUR 2
    if(lanceur2->tir==200 && lanceur2->vie>0)
    {
        hache2->x=lanceur2->x;
        hache2->y=lanceur2->y;
    }
    if(lanceur2->tir>500)
    {
            lanceur2->tir=0;
    }
    else
    {
        masked_blit(lanceur1->imgBot1,page,0,0,lanceur1->x-*psx,lanceur1->y-*psy,lanceur1->tx,lanceur1->ty);
        masked_blit(lanceur2->imgBot1,page,0,0,lanceur2->x-*psx,lanceur2->y-*psy,lanceur2->tx,lanceur2->ty);
    }
}

void tirlanceur(t_bot1*lanceur1,t_bot1*lanceur2,t_bdFeu*hache,t_bdFeu*hache2,t_ninja*ninja,BITMAP*page,int *psx)
{
    ///HACHE 1
    hache->y = hache->y + hache->vy;
        masked_blit(hache->bouledeFeu,page,0,0,hache->x-*psx,hache->y,hache->tx,hache->ty);
    ///HACHE 2
    hache2->y = hache2->y + hache2->vy;
        masked_blit(hache2->bouledeFeu,page,0,0,hache2->x-*psx,hache2->y,hache2->tx,hache2->ty);
    ///COLLISIONS PREMIERE HACHE
    if(hache->y==ninja->y+ninja->ty && hache->x>=ninja->x && hache->x<=ninja->x+ninja->tx)
    {
        hache->y=2000;
        ninja->vie-=1;
    }
    ///COLLISIONS DEUXIEME HACHE
    if(hache2->y==ninja->y+ninja->ty && hache2->x>=ninja->x && hache2->x<=ninja->x+ninja->tx)
    {
        hache2->y=2000;
        ninja->vie-=1;
    }
}
