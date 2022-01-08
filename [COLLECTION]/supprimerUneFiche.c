#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
///SUPPRIMER UNE FICHE EST LE MEME SOUS PROGRAMME QUE SUPPRIMER TOUTES LES FICHES SELON UNE CARACTERISITIQUE
/// A L'EXCEPTION QUE LA CONDITION N'EST PLUS COMPOSE DE OU MAIS DE ET.
void supprimerUneFiche(t_film**premier, char nomFilm[50], char nomRealisateur[50], int annee)
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
            if (courant->nomFilm == nomFilm && courant->nomRealisateur ==nomRealisateur && courant->annee == annee)
            {
                ///SI C'EST LE PREMIER ON LE SUPPRIME
                if(courant == *premier)
                {
                    supprimer (premier) ;
                    pfilm = *premier ;
                    courant = *premier ;

                }
                ///SINON ON RECOLLE LA FICHE D'AVANT AVEC LA FICHE D'APRES PAR RAPPORT A LA FICHE SUPPRIMEE
                else
                {
                    pfilm->suivant = courant->suivant ;
                    free(courant) ;
                    courant = pfilm->suivant ;
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
