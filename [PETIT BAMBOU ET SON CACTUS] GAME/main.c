#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "header.h"

int main()
{
    ///INITIALISATION ALLEGRO
    srand(time(NULL));
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth (desktop_color_depth());
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

    ///CHARGEMENT DES IMAGES, BUFFER ET TEST
    BITMAP*MENUJEU;
    BITMAP*MENU2;
    MENUJEU=load_bitmap("MENUJEU.bmp",NULL);
    MENU2=load_bitmap("MENU2.bmp",NULL);
    BITMAP*CINEMATIQUE=load_bitmap("bossFinal.bmp",NULL);
    BITMAP*CINEMATIQUE2=load_bitmap("inverse.bmp",NULL);
    /// DOUBLE BUFFER
    BITMAP*page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    ///CREATION BITMAP NIVEAU ACTUEL
    BITMAP*nivactuel;
    ///AFFICHAGE PREMIERE PAGE DU JEU
    blit(MENUJEU,page,0,0,0,0,SCREEN_W,SCREEN_H);

    while (!key[KEY_P]) ///P POUR QUITTER DEFINITIVEMENT LE JEU
    {

        ///ZONE JOUER
        if(key[KEY_1])
        {
            printf("JOUER");
            clear_bitmap(page);
            blit(MENU2,page,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        ///ZONE RAPIDE
        if(key[KEY_2])
        {
            printf("SPEED RUN");
        }


        ///NIVEAU1
        if(key[KEY_3])
        {
            nivactuel=load_bitmap("niv1.bmp",NULL);
            NIVEAU1(page,MENUJEU,nivactuel);
        }
        ///NIVEAU2
        if(key[KEY_4])
        {
            nivactuel=load_bitmap("niv2.bmp",NULL);
            NIVEAU2(page,MENUJEU,nivactuel);
        }
        ///NIVEAU3
        if(key[KEY_5])
        {
            nivactuel=load_bitmap("niv3.bmp",NULL);
            clear_bitmap(page);
            textprintf_ex(page,font,100,100,makecol(255,0,0),0,"TU ES ENFIN LA");
            textprintf_ex(page,font,100,110,makecol(255,0,0),0,"MOUHAHAHAHAHAH");
            textprintf_ex(page,font,100,120,makecol(255,0,0),0,"TU NE RETROUVERAS JAMAIS CACTUS!");
            masked_blit(CINEMATIQUE,page,0,0,315,100,163,160);
            textprintf_ex(page,font,300,400,makecol(0,255,0),0,"J'EN SUIS PAS SI SUR");
            textprintf_ex(page,font,300,410,makecol(0,255,0),0,"VIENS TE BATTRE!");
            textprintf_ex(page,font,300,420,makecol(0,255,0),0,"CACTUS J'ARRIVE");
            masked_blit(CINEMATIQUE2,page,0,0,100,400,95,95);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(3500);
            NIVEAU3(page,MENUJEU,nivactuel);
        }

        ///CHARGER UNE PARTIE
        if(key[KEY_6])
        {
            printf("CHARGER");
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

}
END_OF_MAIN();

