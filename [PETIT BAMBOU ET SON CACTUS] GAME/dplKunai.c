#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "header.h"

void deplaKunai(t_kunai*kunai,BITMAP*page,int*psx,int*psy)
{
    if(kunai->vx>0)
    {
        kunai->x = kunai->x + kunai->vx;
        masked_blit(kunai->kunai,page,0,0,kunai->x,kunai->y,35,11);
    }
    else
    {
        kunai->x = kunai->x + kunai->vx;
        masked_blit(kunai->kunaiinverse,page,0,0,kunai->x,kunai->y,34,10);
    }
}
