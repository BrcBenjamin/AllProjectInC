#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void afficher_caracteristique(t_film**premier, char nomFilm[50], char nomRealisateur[50], int annee)
{
    ///CREATION DES POINTEURS PARCOURANT LES FICHES
    t_film*courant ;
    t_film*pfilm ;

    ///VERIFICATION QUE LA MEDIATHEQUE NE SOIT PAS VIDE
    if(*premier == NULL)
        printf("LA MEDIATHEQUE EST VIDE \n") ;
    ///LANCEMENT DE LA RECHERCHE SI LA MEDIATHEQUE N'EST PAS VIDE
    else
    {
        pfilm = *premier ;
        courant = *premier ;
        ///BOUCLE TANT QUE IL RESTE DES FICHES DE FILMS NON PARCOURUS
        while(courant != NULL)
        {
            ///CONDITIONS DE RECHERCHE
            if (courant->nomFilm == nomFilm || courant->nomRealisateur ==nomRealisateur || courant->annee == annee)
            {
                ///ON AFFICHE LA FICHE ACTUEL QUI CORRESPOND AU CARACTERISTIQUE
                printf("TITRE DU FILM : %s\n", courant->nomFilm);
                printf("NOM DU REALISATEUR : %s\n", courant->nomRealisateur);
                printf("ANNEE DE SORTIE : %d\n\n", courant->annee);
                ///ON PASSE A LA FICHE SUIVANTE
                pfilm = courant ;
                courant = courant->suivant ;
            }
            ///SI LES CONDITIONS NE SONT PAS RESPECTEES ON PASSE A LA FICHE SUIVANTE
            else
            {
                pfilm = courant ;
                courant = courant->suivant ;
            }
        }
    }
}

