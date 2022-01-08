#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
///FONCTION CREER UNE FICHE QUI SERA COMPLETER PAR UNE FONCTION AJOUTER UN FILM EN TETE DE LISTE
t_film*creer (sauvegarde)
{
    ///LIBERE L'ESPACE MEMOIRE POUR CREER UNE NOUVELLE FICHE
    t_film*pfilm = NULL;
    pfilm = (t_film*)malloc(sizeof(t_film));

    ///CREATION DES CHAINE A SAUVEGARDER
    char nomFilmSauv[50];
    char nomRealisateurSauv[50];
    int anneeSauv;

    ///ECRIS LES DONNEES DANS LA STRUCTURE
    if (pfilm != NULL)
    {
        printf("TITRE DU FILM ?\n");
        gets(&pfilm->nomFilm);
        printf("NOM DU REALISATEUR?\n");
        gets(&pfilm->nomRealisateur);
        printf("L'ANNEE ?(L'annee est forcement comprise entre 1892(annee du premier dessin animé) et 2020)\n");
        scanf("%d", &pfilm->annee);
        getchar();
        if(pfilm->annee>=2020 || pfilm->annee<=1891)
        {
            printf("Cette annee n'a pas lieu d'etre, ressaissisez une annee svp \n");
            scanf("%d", &pfilm->annee);
        }
        pfilm->suivant = NULL ;

    }

    return pfilm ;
}
