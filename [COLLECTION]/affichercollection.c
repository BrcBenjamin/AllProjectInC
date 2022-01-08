#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
///FONCTION RECURSIVE POUR AFFICHER TOUTE LA MEDIATEQUE DE FILM.
void afficher_collection(t_film*premier)
{
    if(premier != NULL)
    {
        printf("TITRE DU FILM : %s\n", premier->nomFilm) ;
        printf("NOM DU REALISATEUR : %s\n", premier->nomRealisateur) ;
        printf("ANNEE DE SORTIE : %d\n\n", premier->annee) ;

        afficher_collection(premier->suivant) ;
    }

    else printf("IL N'Y A PLUS DE FICHE A AFFICHER \n\n") ;

}

