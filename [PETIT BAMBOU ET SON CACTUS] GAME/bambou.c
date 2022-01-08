#include <allegro.h>
#include "header.h"

void destructionbambou(t_OBJcassable*bambou,BITMAP*page,int *psx, int *psy,t_ninja*ninja,t_bot1*bot1,t_bot2*bot2)
{
    if(bambou->pv<1 && bot1->vie<1 && bot2->vie<1)
    {
        bambou->y=2000;
        masked_blit(bambou->image,page,0,0,bambou->x-*psx,bambou->y-*psy,bambou->tx,bambou->ty);
        clear_bitmap(bambou->image);
    }
    else
    {
        if(ninja->x+ninja->tx>=bambou->x)ninja->x=bambou->x-ninja->tx;
        masked_blit(bambou->image,page,0,0,bambou->x-*psx,bambou->y-*psy,bambou->tx,bambou->ty);
    }
}

void FIN(t_OBJcassable*bambou,BITMAP*page,int *psx, int *psy,t_ninja*ninja,t_boss*boss,t_bot2*bot2)
{
    if(bambou->pv<1 && boss->vie<1 && bot2->vie<1)
    {
        bambou->y=2000;
        masked_blit(bambou->image,page,0,0,bambou->x-*psx,bambou->y-*psy,bambou->tx,bambou->ty);
        clear_bitmap(bambou->image);
    }
    else
    {
        if(ninja->x+ninja->tx>=bambou->x)ninja->x=bambou->x-ninja->tx;
        masked_blit(bambou->image,page,0,0,bambou->x-*psx,bambou->y-*psy,bambou->tx,bambou->ty);
    }
}
