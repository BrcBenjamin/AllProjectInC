#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "header.h"

void deplacerBot2(t_bot2 *bot2, t_ninja *ninja,BITMAP*page)
{
    ///BLINDAGE POUR QUE LE BOT2 NE SORTE PAS DE LA CARTE
    if(bot2->x+bot2->tx>SCREEN_W)
        bot2->vx=-1;

    if(bot2->x<0)
        bot2->vx=1;

    ///EXPLOSIONS SI LE BOT1 N'A PLUS DE PV
    int rouge=makecol(255,0,0);
    int orange=makecol(255,255,0);
    if(bot2->vie==0)
    {
        circlefill(page,bot2->x,bot2->y,50,rouge);
        circlefill(page,bot2->x,bot2->y,50,orange);
        bot2->y=2000;
    }
    else
    {
    ///DEPLACEMENT INDEPENDANT DU BOT2
        bot2->x+=bot2->vx;
    }


    ///BOT2 MANGE LE NINJA
    if(ninja->x+ninja->tx==bot2->x && ninja->y+ninja->ty>=bot2->y && ninja->y+ninja->ty<=bot2->y+bot2->ty || ninja->x==bot2->x+bot2->tx && ninja->y+ninja->ty>=bot2->y && ninja->y+ninja->ty<=bot2->y+bot2->ty)
    {
        ninja->vie-=1;
        bot2->vx=-bot2->vx;
    }

    if(bot2->vx<0)
    {
        masked_blit(bot2->inverseBot2,page,0,0,bot2->x,bot2->y,bot2->tx,bot2->ty);
    }
    else
        masked_blit(bot2->imgBot2,page,0,0,bot2->x,bot2->y,bot2->tx,bot2->ty);
}


