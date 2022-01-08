#include <allegro.h>
#include "header.h"

void collisionMur(t_ninja*ninja,int*pmur)
{
    if(ninja->x+(ninja->tx/2)>=120 && ninja->x<=185 && ninja->y+ninja->ty==390)
    {
        *pmur=1;
        ninja->y=390-ninja->ty;
    }
    else if(ninja->x+(ninja->tx/2)>=210 && ninja->x<=500 && ninja->y+ninja->ty==310)
    {
        *pmur=1;
        ninja->y=310-ninja->ty;
    }
    else if(ninja->x+(ninja->tx/2)>=550 && ninja->x<=630 && ninja->y+ninja->ty==385)
    {
        *pmur=1;
        ninja->y=385-ninja->ty;
    }
    else if(ninja->x+(ninja->tx/2)>=1440 && ninja->x<=1520 && ninja->y+ninja->ty==360)
    {
        *pmur=1;
        ninja->y=360-ninja->ty;
    }
    else if(ninja->x+(ninja->tx/2)>=1650 && ninja->x<=1700 && ninja->y+ninja->ty==290)
    {
        *pmur=1;
        ninja->y=290-ninja->ty;
    }
    else if(ninja->x+(ninja->tx/2)>=1800 && ninja->x<=1850 && ninja->y+ninja->ty==360)
    {
        *pmur=1;
        ninja->y=360-ninja->ty;
    }
    else
        *pmur=0;
}

int collisionCassable(t_ninja*ninja,t_OBJcassable*bambou,t_kunai*kunai,int*psx)
{
    if(kunai->x>=bambou->x-*psx && kunai->x<=bambou->x+bambou->tx-*psx)
    {
        if(kunai->y<500)
        {
            bambou->pv=bambou->pv-1;
            kunai->y=2000;
        }
    }
    return bambou->pv;
}

int collisionBot1(t_ninja*ninja,t_bot1*bot1,t_kunai*kunai,int*psx)
{
    if(kunai->x>=bot1->x-*psx && kunai->x+35<=bot1->x+bot1->tx-*psx)
    {
        if(kunai->y>=bot1->y && kunai->y+11<=bot1->y+bot1->ty)
        {
            bot1->vie=bot1->vie-1;
            kunai->y=2000;
        }
    }
    if(mouse_b&1 && ninja->x+ninja->tx-*psx>=bot1->x &&  ninja->x+ninja->tx-*psx<=bot1->x)
    {
        if(ninja->y>=bot1->y && ninja->y+ninja->tx<=bot1->y+bot1->ty)
        {
            bot1->vie=bot1->vie-1;
        }
    }
    return bot1->vie;
}

int collisionBot2(t_ninja*ninja,t_bot2*bot2,t_kunai*kunai)
{
    if(kunai->x>=bot2->x && kunai->x+35<=bot2->x+bot2->tx)
    {
        if(kunai->y>=bot2->y && kunai->y+11<=bot2->y+bot2->ty)
        {
            bot2->vie=bot2->vie-1;
            kunai->y=2000;
        }
    }
    if(mouse_b&1 && ninja->x+ninja->tx==bot2->x)
    {
        if(ninja->y>=bot2->y && ninja->y+ninja->tx<=bot2->y+bot2->ty)
        {
            bot2->vie=bot2->vie-1;
        }
    }
    return bot2->vie;
}

int collisionBoss(t_ninja*ninja,t_boss*boss,t_kunai*kunai,int*psx)
{
    if(kunai->x>=boss->x-*psx && kunai->x+35<=boss->x+boss->tx-*psx)
    {
        if(kunai->y>=boss->y && kunai->y+11<=boss->y+boss->ty)
        {
            kunai->y=2000;
            boss->vie=boss->vie-1;
        }
    }
    if(mouse_b&1 && ninja->x+ninja->tx>=boss->x &&  ninja->x+ninja->tx<=boss->x)
    {
        if(ninja->y>=boss->y && ninja->y+ninja->tx<=boss->y+boss->ty)
        {
            boss->vie=boss->vie-1;
        }
    }
    return boss->vie;
}

            /// NIVEAU 2
void collisionMur2(t_ninja*ninja,int*pmur)
{
    ///EN HAUT DU PREMIER PALMIER
    if(ninja->x+(ninja->tx/2)>=300 && ninja->x<=355 && ninja->y+ninja->ty<=100)
    {
        *pmur=1;
        ninja->y=100-ninja->ty;
    }
    /// COTER GAUCHE DU PREMIER PALMIER
    else if(ninja->x+(ninja->tx/2)==300 && ninja->y+ninja->ty>=100)
    {
        *pmur=1;
        ninja->x=300-ninja->tx;
    }
    /// COTER DROIT DU PREMIER PALMIER
    else if(ninja->x+(ninja->tx/2)==355 && ninja->y+ninja->ty>=100)
    {
        *pmur=1;
        ninja->x=355;
    }
    ///EN HAUT DU DEUXIEME PALMIER
    else if(ninja->x+(ninja->tx/2)>=490 && ninja->x<=545 && ninja->y+ninja->ty<=100)
    {
        *pmur=1;
        ninja->y=100-ninja->ty;
    }
    /// COTER GAUCHE DU DEUXIE%E PALMIER
    else if(ninja->x+(ninja->tx/2)==490 && ninja->y+ninja->ty>=100)
    {
        *pmur=1;
        ninja->x=490-ninja->tx;
    }
    /// COTER DROIT DU DEUXIEME PALMIER
    else if(ninja->x+(ninja->tx/2)==545 && ninja->y+ninja->ty>=100)
    {
        *pmur=1;
        ninja->x=545;
    }
    ///EN HAUT DU TROISIEME PALMIER
    else if(ninja->x+(ninja->tx/2)>=800 && ninja->x<=855 && ninja->y+ninja->ty<=100)
    {
        *pmur=1;
        ninja->y=100-ninja->ty;
    }
    /// COTER GAUCHE DU TROISIEME PALMIER
    else if(ninja->x+(ninja->tx/2)==800 && ninja->y+ninja->ty>=100)
    {
        *pmur=1;
        ninja->x=800-ninja->tx;
    }
    /// COTER DROIT DU TROISIEME PALMIER
    else if(ninja->x+(ninja->tx/2)==855 && ninja->y+ninja->ty>=100)
    {
        *pmur=1;
        ninja->x=855;
    }
    else
        *pmur=0;
}

void collisionMurKunai(t_kunai*kunai,int*psx)
{
    /// COTER GAUCHE DU PREMIER PALMIER
    if(kunai->x+35==300-*psx && kunai->y+11>=100)
    {
        kunai->y=2000;
    }
    /// COTER DROIT DU PREMIER PALMIER
    else if(kunai->x+35==355-*psx && kunai->y+11>=100)
    {
        kunai->y=2000;
    }
    /// COTER GAUCHE DU DEUXIE%E PALMIER
    else if(kunai->x+35==490-*psx && kunai->y+11>=100)
    {
        kunai->y=2000;
    }
    /// COTER DROIT DU DEUXIEME PALMIER
    else if(kunai->x+35==545-*psx && kunai->y+11>=100)
    {
        kunai->y=2000;
    }
     /// COTER GAUCHE DU TROISIEME PALMIER
    else if(kunai->x+35==800-*psx && kunai->y+11>=100)
    {
        kunai->y=2000;
    }
    /// COTER DROIT DU TROISIEME PALMIER
    else if(kunai->x+35==855-*psx && kunai->y+11>=100)
    {
        kunai->y=2000;
    }
}

int collisionLanceur(t_ninja*ninja,t_bot1*lanceur1,t_bot1*lanceur2,t_kunai*kunai,int*psx)
{
    ///LANCEUR 1
    if(kunai->x>=lanceur1->x-*psx && kunai->x+35<=lanceur1->x+lanceur1->tx-*psx)
    {
        if(kunai->y>=lanceur1->y && kunai->y+11<=lanceur1->y+lanceur1->ty)
        {
            lanceur1->vie=lanceur1->vie-1;
            kunai->y=2000;
        }
    }
    if(mouse_b&1 && ninja->x+ninja->tx-*psx>=lanceur1->x &&  ninja->x+ninja->tx-*psx<=lanceur1->x)
    {
        if(ninja->y>=lanceur1->y && ninja->y+ninja->tx<=lanceur1->y+lanceur1->ty)
        {
            lanceur1->vie=lanceur1->vie-1;
        }
    }
    ///LANCEUR 2
    if(kunai->x>=lanceur2->x-*psx && kunai->x+35<=lanceur2->x+lanceur2->tx-*psx)
    {
        if(kunai->y>=lanceur2->y && kunai->y+11<=lanceur2->y+lanceur2->ty)
        {
            lanceur2->vie=lanceur2->vie-1;
            kunai->y=2000;
        }
    }
    if(mouse_b&1 && ninja->x+ninja->tx-*psx>=lanceur2->x &&  ninja->x+ninja->tx-*psx<=lanceur2->x)
    {
        if(ninja->y>=lanceur2->y && ninja->y+ninja->tx<=lanceur2->y+lanceur2->ty)
        {
            lanceur2->vie=lanceur2->vie-1;
        }
    }
    return lanceur1->vie;
    return lanceur2->vie;
}
