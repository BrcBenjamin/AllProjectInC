#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "header.h"

int deplacerBot1(t_bot1 *bot1,t_ninja *ninja,t_bdFeu*bdFeu,t_bdFeu*bdFeuG,BITMAP*page,int *psx, int *psy)
{
    int rouge=makecol(255,0,0);
    int orange=makecol(255,255,0);
    ///EXPLOSIONS SI LE BOT1 N'A PLUS DE PV
    if(bot1->vie==0)
    {
        circlefill(page,bot1->x,bot1->y,100,rouge);
        bot1->y=2000;
        clear_bitmap(bot1->bot1Attaque);
    }
    if(bot1->tir==200 && bot1->vie>0)
    {
        bdFeu->x=bot1->x+bot1->tx;                    bdFeuG->x=bot1->x;
        bdFeu->y=bot1->y;                             bdFeuG->y=bot1->y;
    }
    if(bot1->tir>500)
    {
            bot1->tir=0;
    }
    else
    {
        masked_blit(bot1->bot1Attaque,page,0,0,bot1->x-*psx,bot1->y-*psy,bot1->tx,bot1->ty);
    }
    return ninja->vie;
}
