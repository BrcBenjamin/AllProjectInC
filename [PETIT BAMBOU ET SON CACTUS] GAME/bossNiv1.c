#include <allegro.h>
#include "header.h"

void dplBoss1(t_ninja*ninja,t_boss*boss,BITMAP*page,int*psx,t_bdFeu*D1TIR,t_bdFeu*D2TIR,t_bdFeu*D3TIR,t_bdFeu*D4TIR,t_bdFeu*bdFeu,t_bdFeu*bdFeuG)
{
    ///CAS DE LA MORT
    if(boss->vie<=0)
    {
        boss->y=2000;
        clear_bitmap(boss->image);
    }
    ///PREMIERE SERIE DE TIR SELON SES PV
    if(boss->vie==3 && boss->tir==200)
    {
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
    }
    ///DEUXIEME COMBOT DE TIR (LE PREMIER PLUS UN NOUVEAU)
    if(boss->vie==2 && boss->tir==175)
    {
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
    }
    ///TROISIEMES COMBO LES MEMES MISSILES PLUS UN DEPLACEMENT
    if(boss->vie==1 && boss->tir==100)
    {
        boss->vx=1;
        boss->vy=-1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    if(boss->vie==1 && boss->tir==225)
    {
        boss->vx=-1;
        boss->vy=-1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    if(boss->vie==1 && boss->tir==350)
    {
        boss->vx=-1;
        boss->vy=1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    if(boss->vie==1 && boss->tir==475)
    {
        boss->vx=-1;
        boss->vy=1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    if(boss->tir>500)
    {
        boss->tir=0;
    }
    else
    {
        boss->x+=boss->vx;
        boss->y+=boss->vy;
        masked_blit(boss->image,page,0,0,boss->x-*psx,boss->y,boss->tx,boss->ty);
    }

}

void dplBossFinal(t_ninja*ninja,t_boss*boss,BITMAP*page,int*psx,t_bdFeu*D1TIR,t_bdFeu*D2TIR,t_bdFeu*D3TIR,t_bdFeu*D4TIR,t_bdFeu*bdFeu,t_bdFeu*bdFeuG,t_bot2*bot2,t_bot1*lanceur1,t_bot1*lanceur2,t_bdFeu*hache,t_bdFeu*hache2)
{
    int spawnmob=0;
    ///CAS DE LA MORT
    if(boss->vie<=0)
    {
        boss->y=2000;
        clear_bitmap(boss->image);
    }
    ///PREMIERE SERIE DE TIR SELON SES PV
    if(boss->vie==3 && boss->tir==200)
    {
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
    }
    ///DEUXIEME COMBO LES MEMES MISSILES PLUS UN DEPLACEMENT
    if(boss->vie==2 && boss->tir==100)
    {
        boss->vx=1;
        boss->vy=-1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    if(boss->vie==2 && boss->tir==225)
    {
        boss->vx=-1;
        boss->vy=-1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    if(boss->vie==2 && boss->tir==350)
    {
        boss->vx=-1;
        boss->vy=1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    if(boss->vie==2 && boss->tir==475)
    {
        boss->vx=-1;
        boss->vy=1;
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        //ON AJOUTE DES TIR VERS LE HAUT ET LE BAS
    }
    ///DERNIERE PHASE
    if(boss->vie==1&& boss->tir==200)
    {
        ///IL SE RECENTRE
        boss->x=350;
        boss->y=150;
        boss->vx=0;
        boss->vy=0;

        ///REACTIVE CES TIRS DE BASE
        D1TIR->x=boss->x;
        D2TIR->x=boss->x+boss->tx;
        D1TIR->y=boss->y;
        D2TIR->y=boss->y;
        //On double les balles diagonales
        D3TIR->x=boss->x;
        D4TIR->x=boss->x+boss->tx;
        D3TIR->y=boss->y;
        D4TIR->y=boss->y;
        //ON REPRENDS LES BOULE DE FEU DU BOT1 COMME IL EST MORT
        bdFeu->x=boss->x+boss->tx;
        bdFeuG->x=boss->x;
        bdFeu->y=boss->y;
        bdFeuG->y=boss->y;
        ///AUTORISE LES MOBS A SPAWN
        spawnmob=1;
    }
    if(spawnmob==1)
    {
        ///FAIS APPARAITRE LES AUTRES MOBS
        bot2->x=400;
        bot2->y=200;
        bot2->tx=180;
        bot2->ty=120;
        bot2->vx=1;
        bot2->vie=1;
        lanceur1->x=115;
        lanceur2->x=500;
        lanceur1->y=360;
        lanceur2->y=360;
        lanceur1->tx=90;
        lanceur2->tx=90;
        lanceur1->ty=99;
        lanceur2->ty=99;
        lanceur1->vie=1;
        lanceur2->vie=1;
        lanceur1->tir=100;
        lanceur2->tir=0;
        hache->tx=60;
        hache2->tx=60;
        hache->ty=60;
        hache2->ty=60;
        hache->vy=-1;
        hache2->vy=-1;
        spawnmob=0;
    }
    if(boss->tir>500)
    {
        boss->tir=0;
    }
    ///COLLSIONS AVEC LES MURS
    if(boss->x<=0)boss->x=0;
    if(boss->x+boss->tx>=SCREEN_W)boss->x=SCREEN_W-boss->tx;
    if(boss->y<=0)boss->y=0;
    if(boss->y+boss->ty>=SCREEN_H)boss->y=SCREEN_H-boss->ty;
    else
    {
        boss->x+=boss->vx;
        boss->y+=boss->vy;
        masked_blit(boss->image,page,0,0,boss->x-*psx,boss->y,boss->tx,boss->ty);
    }

}
