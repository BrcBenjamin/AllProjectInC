#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "header.h"

int vieNinja(BITMAP*page, t_ninja*ninja, int*psx,int*psy)
{
    BITMAP*coeur=load_bitmap("Coeur.bmp",NULL);
    BITMAP*gameover=load_bitmap("GameOver.bmp",NULL);
    BITMAP*soin=load_bitmap("soins.bmp",NULL);
    if(ninja->vie==3)
    {
        masked_blit(coeur,page,0,0,0,0,30,30);
        masked_blit(coeur,page,0,0,45,0,30,30);
        masked_blit(coeur,page,0,0,90,0,30,30);
    }
    else if(ninja->vie==2)
    {
        masked_blit(coeur,page,0,0,0,0,30,30);
        masked_blit(coeur,page,0,0,45,0,30,30);
    }
    else if(ninja->vie==1)
    {
        masked_blit(coeur,page,0,0,0,0,30,30);
    }
    else if(ninja->vie<=0)
    {
        clear_bitmap(page);
        masked_blit(gameover,page,0,0,200,150,400,115);
    }
    return ninja->vie;
}
