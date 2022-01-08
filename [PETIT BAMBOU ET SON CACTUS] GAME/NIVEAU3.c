#include <allegro.h>
#include "header.h"

void NIVEAU3(BITMAP*page,BITMAP*MENUJEU,BITMAP*nivactuel)
{
    int fin=0;

    ///INTIALISATION DES COORDONNES DU SCROLL
    int screenx=0;
    int screeny=0;
    int *psx=screenx;
    int *psy=screeny;

    ///INITIALISATION DU PERSONNAGE
    t_ninja*ninja;
    ninja=(t_ninja*)malloc(1*sizeof(t_ninja));
    ninja->x=0;
    ninja->y=400;
    ninja->tx=85;
    ninja->ty=85;
    ninja->cx=0;
    ninja->cy=0;
    ninja->vie=3;

    ///INITIALISATION DU KUNAI
    t_kunai*kunai;
    kunai=(t_kunai*)malloc(1*sizeof(t_kunai));
    kunai->cdelai=1000;

    ///INITIALISATION DU BOSS
    t_boss*boss;
    boss=(t_boss*)malloc(1*sizeof(t_boss));
    boss->x=350;
    boss->y=150;
    boss->vx=0;
    boss->vy=0;
    boss->tx=163;
    boss->ty=160;
    boss->vie=3;
    boss->tir=0;

    ///INITIALISATION DE LA STRUCTURE BDFEU 1 ET 2
    t_bdFeu*bdFeu;                                t_bdFeu*bdFeuG;
    bdFeu=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));    bdFeuG=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));
    bdFeu->tx=61;                                 bdFeuG->tx=61;
    bdFeu->ty=46;                                 bdFeuG->ty=46;
    bdFeu->vx=1;                                  bdFeuG->vx=-1;

    ///INITIALISATION DES MISSILES DU BOSS1
    t_bdFeu*D1TIR=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));   t_bdFeu*D2TIR=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));
    D1TIR->tx=51;                                        D2TIR->tx=53;
    D1TIR->ty=40;                                        D2TIR->ty=40;
    D1TIR->vx=-1;                                        D2TIR->vx=1;
    D1TIR->vy=-1;                                        D2TIR->vy=-1;

    t_bdFeu*D3TIR=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));   t_bdFeu*D4TIR=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));
    D3TIR->tx=51;                                        D4TIR->tx=53;
    D3TIR->ty=40;                                        D4TIR->ty=40;
    D3TIR->vx=-1;                                        D4TIR->vx=1;
    D3TIR->vy=1;                                         D4TIR->vy=1;

    ///INTIALISATION LANCEUR DE HACHE
    t_bot1*lanceur1;                                t_bot1*lanceur2;
    lanceur1=(t_bot1*)malloc(1*sizeof(t_bot1));     lanceur2=(t_bot1*)malloc(1*sizeof(t_bot1));
     ///INITIALISATION DE LA STRUCTURE HACHE 1 ET 2
    t_bdFeu*hache;                                t_bdFeu*hache2;
    hache=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));    hache2=(t_bdFeu*)malloc(1*sizeof(t_bdFeu));
    hache->tx=60;                                 hache2->tx=60;
    hache->ty=60;                                 hache2->ty=60;
    hache->vy=-1;                                 hache2->vy=-1;
    ///INITIALISATION DU BOT2
    t_bot2*bot2;
    bot2=(t_bot2*)malloc(1*sizeof(t_bot2));

    ///INITIALISATION BAMBOU
    t_OBJcassable*bambou=(t_OBJcassable*)malloc(1*sizeof(t_OBJcassable));
    bambou->tx=30;
    bambou->ty=500;
    bambou->x=1000;
    bambou->y=0;
    bambou->pv=1;
    ///INITIALISATION CACTUS
    t_OBJcassable*cactus=(t_OBJcassable*)malloc(1*sizeof(t_OBJcassable));
    cactus->x=1500;
    cactus->y=300;

    ///CHARGEMENT DES IMAGES NINJA
    ninja->imgNinja=load_bitmap("Personnage.bmp",NULL);
    ninja->inverse=load_bitmap("inverse.bmp",NULL);
    kunai->kunai=load_bitmap("kunai.bmp",NULL);
    kunai->kunaiinverse=load_bitmap("kunaiinverse.bmp",NULL);
    ///CHARGEMENT BOSS1
    boss->image=load_bitmap("bossFinal.bmp",NULL);
    D1TIR->bouledeFeu=load_bitmap("diagonale.bmp",NULL);
    D2TIR->bouledeFeu=load_bitmap("diagonaleD.bmp",NULL);
    D3TIR->bouledeFeu=load_bitmap("diagonalebas.bmp",NULL);
    D4TIR->bouledeFeu=load_bitmap("diagonalebasD.bmp",NULL);
    bdFeu->bouledeFeu=load_bitmap("bouledeFeu.bmp",NULL);
    bdFeuG->bouledeFeu=load_bitmap("bouledeFeuG.bmp",NULL);
    ///CHARGEMENT IMAGES LANCEURS
    lanceur1->imgBot1=load_bitmap("lanceur.bmp",NULL);
    lanceur2->imgBot1=load_bitmap("lanceur.bmp",NULL);
    hache->bouledeFeu=load_bitmap("hache.bmp",NULL);
    hache2->bouledeFeu=load_bitmap("hache.bmp",NULL);
    ///CHARGEMENT IMAGES BOT2
    bot2->imgBot2=load_bitmap("imgBot2.bmp",NULL);
    bot2->inverseBot2=load_bitmap("inverseBot2.bmp",NULL);
    ///CHARGEMENT DU BAMBOU + CACTUS
    bambou->image=load_bitmap("bambou.bmp",NULL);
    cactus->image=load_bitmap("cactus.bmp",NULL);
    ///AFFICHAGE DU CURSEUR SUR LE BUFFER
    BITMAP*curseur=load_bitmap("curseur.bmp",NULL);

    ///INITIALISATION MUR
    int mur=0;
    int*pmur=mur;
    clear_bitmap(page);

     while(fin!=1)///QUITTER LE NIVEAU
    {

        ///SCROLLING SUIVI CAMERA
        if(ninja->x + ninja->tx -screenx > 3*SCREEN_W/4)
            screenx=ninja->x + ninja->tx - 3*SCREEN_W/4;
        psx=screenx;
        if(ninja->x -screenx < SCREEN_W/4)
            screenx=ninja->x - SCREEN_W/4;
        psx=screenx;
        if ( screenx < 0 )
            screenx=0;
        psx=screenx;
        if ( screenx > nivactuel->w - SCREEN_W )
            screenx=nivactuel->w - SCREEN_W;
        psx=screenx;

        ///AFFICHAGE INTIALE DU NIVEAU
        stretch_blit(nivactuel,page,screenx,screeny,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
        masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-screenx,ninja->y-screeny,ninja->tx,ninja->ty);

        ///GRAVITE
        if(ninja->y!=400)
        {
            if(pmur==0)
            {
                ninja->y+=1;
                clear_bitmap(page);
                stretch_blit(nivactuel,page,screenx,screeny,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
                masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-screenx,ninja->y-screeny,ninja->tx,ninja->ty);

            }
            else
            {
                ninja->y+=0;
                clear_bitmap(page);
                stretch_blit(nivactuel,page,screenx,screeny,nivactuel->w/3,nivactuel->h,0,0,SCREEN_W,SCREEN_H);
                masked_blit(ninja->imgNinja,page,ninja->cx,ninja->cy,ninja->x-screenx,ninja->y-screeny,ninja->tx,ninja->ty);
            }
        }

                ///DEPLACEMENT VERS LE HAUT
        if(key[KEY_W])
        {
            clear_bitmap(page);
            Up(ninja,page,nivactuel,&psx,&psy);
        }
        ///DEPLACEMENT VERS LE BAS
        if(key[KEY_S])
        {
            clear_bitmap(page);
            Down(ninja,page,nivactuel,&psx,&psy);
        }

        ///DEPLACEMENT A DROITE
        if(key[KEY_D])
        {
            clear_bitmap(page);
            Right(ninja,page,nivactuel,&psx,&psy);
        }

        ///TELEPORTATION A DROITE
        if(key[KEY_D]&&key[KEY_SPACE])
        {
            clear_bitmap(page);
            BoostRight(ninja,page,nivactuel,&psx,&psy);
        }

        ///DEPLACEMENT A GAUCHE
        if(key[KEY_A])
        {
            clear_bitmap(page);
            Left(ninja,page,nivactuel,&psx,&psy);
        }

        ///TELEPORTATION A GAUCHE
        if(key[KEY_A]&&key[KEY_SPACE])
        {
            clear_bitmap(page);
            BoostLeft(ninja,page,nivactuel,&psx,&psy);
        }

        ///COUP D'EPEE DU NINJA (CORPS A CORPS)
        if(mouse_b&1)
        {
            clear_bitmap(page);
            CoupEpee(ninja,page,nivactuel,&psx,&psy);
        }

        ///TIR AU KUNAI (TIR A DISTANCE AVEC ENTRE 2 ET 3 SECONDES DE DELAI)
        if(mouse_b&2 && kunai->cdelai>=1000)
        {
            clear_bitmap(page);
            lancerKunai(ninja,kunai,page,nivactuel,&psx,&psy);

        }
        ///CONDITION DE FIN
        if(ninja->x==cactus->x)fin=1;
        ///DEPACEMENT KUNAI+DELAI
        kunai->cdelai++;
        afficherdelai(kunai,page);
        deplaKunai(kunai,page,&psx,&psy);

        ///DEPLACEMENT BOSS
        boss->tir++;
        dplBossFinal(ninja,boss,page,&psx,D1TIR,D2TIR,D3TIR,D4TIR,bdFeu,bdFeuG,bot2,lanceur1,lanceur2,hache,hache2);
        tir1(boss,ninja,page,&psx,&psy,D1TIR,D2TIR,D3TIR,D4TIR);
        tirbdFeu(bdFeu,bdFeuG,ninja,page,&psx);
        ///DEPLACEMENT INVOCATIONS
        lanceur1->tir++; lanceur2->tir++;
        AffLanceur(lanceur1,lanceur2,hache,hache2,page,&psx,&psy);
        tirlanceur(lanceur1,lanceur2,hache,hache2,ninja,page,&psx);
        deplacerBot2(bot2,ninja,page);

        ///COLLISIONS
        collisionBot2(ninja,bot2,kunai);
        collisionBoss(ninja,boss,kunai,&psx);
        collisionLanceur(ninja,lanceur1,lanceur2,kunai,&psx);
        collisionCassable(ninja,bambou,kunai,&psx);
        FIN(bambou,page,&psx,&psy,ninja,boss,bot2);

        ///AFFICHAGE CURSEUR + BUFFER + POINT DE VIE
        masked_blit(curseur,page,0,0,mouse_x,mouse_y,50,50);
        vieNinja(page,ninja,&psx,&psy);
        masked_blit(cactus->image,page,0,0,cactus->x-screenx,cactus->y-screeny,100,123);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    clear_bitmap(page);
    textprintf_ex(page,font,100,100,makecol(255,0,0),0,"TU M'AS RETROUVE");
    textprintf_ex(page,font,100,110,makecol(255,0,0),0,"MERCI");
    masked_blit(cactus->image,page,0,0,315,100,163,160);
    textprintf_ex(page,font,300,400,makecol(0,255,0),0,"Y'A PAS DE QUOI");
    textprintf_ex(page,font,300,410,makecol(0,255,0),0,"MON AMI");
    masked_blit(ninja->inverse,page,0,0,100,400,95,95);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    rest(2500);
    blit(MENUJEU,page,0,0,0,0,SCREEN_W,SCREEN_H);
}
