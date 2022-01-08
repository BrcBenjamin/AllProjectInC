#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"
///fonction qui relancera l'affichage du menu
int menu(choix)
{
    printf("QUE VOULEZ-VOUS FAIRE ?\n");
    printf("0. Quitter\n");
    printf("1. Ajouter une fiche d'un film a la mediatheque\n");
    printf("2. Afficher la mediatheque \n");
    printf("3. Rechercher une fiche pour la modifier \n");
    printf("4. Afficher toutes les fiches ayant la caracteristique choisis\n");
    printf("5. Supprimer toutes les fiches ayant une caracteristique choisis\n");
    printf("6. Supprimer UNE seule fiche choisis par ses caractéristique \n\n");
    scanf("%d",&choix);
    getchar();
    return choix;
}
