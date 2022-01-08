#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
///MODIFIER UNE FICHE SELON UN CRITERE
void recherche_modifier(t_film**premier, char nomFilm[50], char nomRealisateur[50], int annee)
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
                printf("TITRE DU FILM ?\n");
                gets(&courant->nomFilm);
                printf("NOM DU REALISATEUR?\n");
                gets(&courant->nomRealisateur);
                printf("L'ANNEE ?(L'annee est forcement comprise entre 1892(annee du premier dessin animé) et 2020)\n");
                scanf("%d", &courant->annee);
                getchar();
                if(courant->annee>=2020 || courant->annee<=1891)
                {
                    printf("Cette annee n'a pas lieu d'etre, ressaissisez une annee svp \n");
                    scanf("%d", &courant->annee);
                }
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
