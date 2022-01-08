#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"

int main()
{

    t_film*premier = NULL;
    t_film*nouv;
    int choix, choix2, choix3 ;
    int annee;
    char nomFilm[50];
    char nomRealisateur[50];

    ///LE FICHIER DE SAUVEGARDE
    FILE*sauvegarde=NULL;
    sauvegarde=fopen("sauvegarde.txt","r+");
    if(sauvegarde!=NULL)
        printf("ERREUR");

    ///CREATION PAGE D'ACCEUIL AVANT LE LANCEMENT DU MENU
    printf("******************************************************************\n");
    printf("*                 BIENVENUE DANS VOTRE MEDIATHEQUE               *\n");
    printf("******************************************************************\n");
    Sleep(2000);
    system("cls");
    printf("                  CHARGEMENT DE VOS DONNES");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(" .");
    Sleep(1000);
    printf("  .");
    system("cls");
    printf("                  VOS DONNEES SONT CHARGEES                         ");
    Sleep(2000);
    system("cls");



    ///LANCEMENT BOUCLE DO WHILE DE L'APPLICATION
    do
    {
        choix = menu();
        switch(choix)
        {
        case 1 :
            ///CREER UNE STRUCTURE ET LA REMPLIR
            system("cls");
            nouv = creer(sauvegarde) ;
            ajouter(&premier, nouv);
            break ;
        case 2 :
            ///AFFICHER TOUTE LA MEDIATHEQUE
            system("cls");
            afficher_collection(premier) ;
            break ;

        case 3:
            ///MODIFIER UNE FICHE DE FILM SELON LE NOM DU FILM, LE REALISATEUR OU L'ANNEE DE SORTIE
            system("cls");
            printf("Vous voulez modifier un film selon : \n") ;
            printf("1. Son annee de sortie \n" ) ;
            printf("2. Son titre ?\n") ;
            printf("3. Son realisateur ?\n") ;
            scanf("%d", &choix2);
            getchar();
            switch(choix2)
            {
            case 1 :
                printf("Quelle est l'annee ?\n") ;
                scanf("%d", &annee);
                getchar();
                recherche_modifier(&premier, nomFilm, nomRealisateur, annee) ;
                printf("La fiche de cette annee a ete modifie de la mediatheque\n") ;
                break ;
            case 2 :
                printf("Quel est le titre du film ?\n");
                scanf("%s",&nomFilm);
                getchar();
                recherche_modifier(&premier, nomFilm, nomRealisateur, annee) ;
                printf("La fiche de ce titre a ete modifier de la mediatheque \n") ;
                break ;
            case 3 :
                printf("Quel est le realisateur?\n");
                scanf("%s",&nomRealisateur);
                getchar();
                recherche_modifier(&premier, nomFilm, nomRealisateur, annee) ;
                printf("La fiche de ce realisateur a ete modifie de la mediatheque \n") ;
                break ;
            }
            break;

        case 4:
            ///AFFICHER TOUTE LES FICHES AYANT LA MEME CARACTERISTIQUE
            system("cls");
            printf("Vous voulez affichez toutes les fiches communes selon: \n") ;
            printf("1. Leur annees de sortie \n" ) ;
            printf("2. Leur titres ?\n") ;
            printf("3. Leur realisateur ?\n") ;
            scanf("%d",&choix3);
            getchar();
            switch(choix3)
            {
            case 1 :
                printf("Quelle est l'annee ?\n") ;
                scanf("%d", &annee) ;
                afficher_caracteristique(&premier, nomFilm, nomRealisateur, annee) ;
                printf("Les films de cette annee ont ete supprimes de la mediatheque\n") ;
                break ;
            case 2 :
                printf("Quel est le titre commun des film ?\n");
                gets(&nomFilm);
                getchar();
                afficher_caracteristique(&premier, nomFilm, nomRealisateur, annee) ;
                printf("Les films de ce titre ont ete supprimes de la mediatheque \n") ;
                break ;
            case 3 :
                printf("Quel est le realisateur commun ?\n");
                gets(&nomRealisateur);
                getchar();
                afficher_caracteristique(&premier, nomFilm, nomRealisateur, annee);
                printf("Les films de ce realisateur ont ete supprimes de la mediatheque \n") ;
                break ;
            }
            break;

        case 5 :
            ///SUPPRIMER LES FICHE DE FILM SELON UNE CARACTERISTIQUE COMMUNE
            system("cls");
            printf("Vous voulez supprimer les films selon : \n") ;
            printf("1. Son annee de sortie \n" ) ;
            printf("2. Son titre ?\n") ;
            printf("3. Son realisateur ?\n") ;
            scanf("%d",&choix3);
            getchar();
            switch(choix3)
            {
            case 1 :
                printf("Quelle est l'annee ?\n") ;
                scanf("%d", &annee) ;
                recherche_supprime(&premier, nomFilm, nomRealisateur, annee) ;
                printf("Les films de cette annee ont ete supprimes de la mediatheque\n") ;
                break ;
            case 2 :
                printf("Quel est le titre du film ?\n");
                gets(&nomFilm);
                getchar();
                recherche_supprime(&premier, nomFilm, nomRealisateur, annee) ;
                printf("Les films de ce titre ont ete supprimes de la mediatheque \n") ;
                break ;
            case 3 :
                printf("Quel est le realisateur?\n");
                gets(&nomRealisateur);
                getchar();
                recherche_supprime(&premier, nomFilm, nomRealisateur, annee) ;
                printf("Les films de ce realisateur ont ete supprimes de la mediatheque \n") ;
                break ;
            }
            break;

        case 6 :
            ///SUPPRIMER UNE SEULE FICHE SELON SES 3 CARACTERISTIQUE
            printf("Quelle est l'annee de sortie de la fiche a supprimer ?\n") ;
            scanf("%d", &annee);
            getchar();
            printf("Quel est le titre du film ?\n");
            gets(&nomFilm);
            printf("Quel est le realisateur ?\n");
            gets(&nomRealisateur);
            supprimerUneFiche(&premier, nomFilm, nomRealisateur, annee);
            printf("La fiche correspondante a bien ete supprimee \n\n");
            break ;
        }
    }

    while (choix != 0) ;
    ///FERMETURE DU FICHIER ET SAUVEGARDE
    fclose(sauvegarde);
    ///MESSAGE DE FIN DE PROGRAMME QUAND L'UTILISATEUR ENTRE 0 ET QUITTE:
    printf("FIN D'UTILISATIONS DE LA MEDIATHEQUE, VOS DONNEES SONT ENREGISTREES\n");

    return 0;
}

