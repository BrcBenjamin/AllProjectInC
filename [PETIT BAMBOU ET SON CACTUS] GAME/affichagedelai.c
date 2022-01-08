#include <allegro.h>
#include "header.h"

void afficherdelai(t_kunai*kunai,BITMAP*page)
{
    if(kunai->cdelai>=1000)
    textprintf_ex(page,font,630,0,makecol(0,255,0),0,"LE KUNAI EST CHARGE");
    else
    textprintf_ex(page,font,630,0,makecol(255,0,0),0,"LE KUNAI EST EN CHARGE");

}
