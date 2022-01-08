#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
///SUPPRIMER EN TETE ET FONCTION COMPLEMENTAIRE DE LA FONCTION RECHERCHER UN TITRE
void supprimer (t_film**pfilm)
{
    t_film*temporaire ;
    if(*pfilm == NULL)
        printf("LA MEDIATHEQUE EST VIDE\n") ;
    else {
        temporaire = *pfilm ;
        *pfilm = temporaire->suivant ;
        free(temporaire) ;
    }
}
