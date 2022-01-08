#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "header.h"
int main()
{
    int gagner=0;
    ///coordonnees modifiables
    int x,y;

    ///Création des cases du tableau
    char Orientation[7][7];
    Orientation[0][0] = 'x';
    Color(3,0);
    Orientation[1][0] = '1';
    Orientation[2][0] = '2';
    Orientation[3][0] = '3';
    Orientation[4][0] = '4';
    Orientation[5][0] = '5';

    Orientation[0][1] = ' ';
    Orientation[0][2] = ' ';
    Orientation[0][3] = ' ';
    Orientation[0][4] = ' ';
    Orientation[0][5] = ' ';

    Orientation[1][1] = ' ';
    Orientation[2][1] = ' ';
    Orientation[3][1] = ' ';
    Orientation[4][1] = ' ';
    Orientation[5][1] = ' ';

    Orientation[1][2] = ' ';
    Orientation[2][2] = ' ';
    Orientation[3][2] = ' ';
    Orientation[4][2] = ' ';
    Orientation[5][2] = ' ';

    Orientation[1][3] = ' ';
    Orientation[2][3] = ' ';
    Orientation[3][3] = ' ';
    Orientation[4][3] = ' ';
    Orientation[5][3] = ' ';

    Orientation[1][4] = ' ';
    Orientation[2][4] = ' ';
    Orientation[3][4] = ' ';
    Orientation[4][4] = ' ';
    Orientation[5][4] = ' ';

    Orientation[1][5] = ' ';
    Orientation[2][5] = ' ';
    Orientation[3][5] = ' ';
    Orientation[4][5] = ' ';
    Orientation[5][5] = ' ';

    char Animaux[7][7];

    Animaux[0][0] = 'y';
    Animaux[0][1] = '1';
    Animaux[0][2] = '2';
    Animaux[0][3] = '3';
    Animaux[0][4] = '4';
    Animaux[0][5] = '5';

    Animaux[1][0] = ' ';
    Animaux[2][0] = ' ';
    Animaux[3][0] = ' ';
    Animaux[4][0] = ' ';
    Animaux[5][0] = ' ';

    Animaux[1][1] = '+';
    Animaux[2][1] = '+';
    Animaux[3][1] = '+';
    Animaux[4][1] = '+';
    Animaux[5][1] = '+';

    Animaux[1][2] = '+';
    Animaux[2][2] = ' ';
    Animaux[3][2] = ' ';
    Animaux[4][2] = ' ';
    Animaux[5][2] = '+';

    Animaux[1][3] = '+';
    Animaux[2][3] = 'M';
    Animaux[3][3] = 'M';
    Animaux[4][3] = 'M';
    Animaux[5][3] = '+';

    Animaux[1][4] = '+';
    Animaux[2][4] = ' ';
    Animaux[3][4] = ' ';
    Animaux[4][4] = ' ';
    Animaux[5][4] = '+';

    Animaux[1][5] = '+';
    Animaux[2][5] = '+';
    Animaux[3][5] = '+';
    Animaux[4][5] = '+';
    Animaux[5][5] = '+';

    int ChoixAction;
    int compteurRhino= 5;
    int compteurElephant= 5;

    printf("   _______________________________________________________________________   \n  ");
    printf("                                                                          \n");
    printf("                                 LE JEU                                     \n");
    printf("                                   DU                                       \n");
    printf("                                  SIAM                                      \n");
    printf("   _______________________________________________________________________   \n  ");
    printf("                                       par Benjamin Brice et Paul Perrin\n");


    affconsole(&Animaux, &Orientation,&x,&y);

    int nbrE=5;///On défini des pointeurs qui enregistre le nombre de pièce
    int *NbrElephant=&nbrE;

    int nbrR=5;
    int *NbrRhino=&nbrR;

    int Joueur=1;///Pointeurs pour changer de joueur coup par coup
    int *PointeurJoueur=&Joueur;

    int *victoire=&gagner;
    /// Boucle while tant que personne n'a gagnés
    while(gagner!=1)
    {
        if (Joueur==1)
        {
            printf("\nVous etes les Elephants, Vous jouer en premier !\n ");


            printf("******** QUE VOULEZ VOUS FAIRE ? ********\n\n" );
            printf(" *1* ENTRER UNE PIECE \n" );
            printf(" *2* CHANGER D'ORIENTATION  \n" );
            printf(" *3* SE DEPLACER \n" );
            printf(" *4* SORTIR UNE PIECE\n" );
            printf(" *5* POUSSER UNE PIECE\n" );
            scanf("%d",&ChoixAction);

            if (ChoixAction<=5) ///Lancement du menu et blindage du menu
            {
                switch(ChoixAction)
                {
                case 1:
                    printf("\nIl vous reste %d Elephants", *NbrElephant);

                    printf("\nRegle : \n");
                    printf("Vous pouvez entrez une piece seulement sur les cases marques de +\n");
                    printf("Si une piece se trouve sur l emplacement, Choisir fonction poussee ! \n\n");

                    entrerA(&Animaux, &Orientation,&x,&y, PointeurJoueur, &nbrE, &nbrR);


                    break;

                case 2:

                    orienter(&Animaux, &Orientation,&x,&y, PointeurJoueur);
                    break;

                case 3:
                    printf("\nRegle :\n");
                    printf("Vous pouvez vous deplacer sur les cases libres \n");
                    printf("Le deplacement est dans le sens de l'orientation \n");

                    deplacer(&Animaux, &Orientation,&x,&y);
                    break;

                case 4:
                    printf("\nRegle : \n");
                    printf("Vous pouvez sortir une piece seulement si elle se trouve sur les cases marquees de +\n");

                    printf("\nChoisir la piece que vous voulez sortir en rentrant ses coordonnees x et y \n");
                    sortir(&Animaux,&Orientation,&x,&y,PointeurJoueur, &nbrE, &nbrR);
                    printf("Il vous reste %d Elephant \n", *NbrElephant);
                    break;

                case 5:
                    printf("\n Regle : \n");
                    printf("Vous ne pouvez pousser une piece que si votre force est superieur a la piece ou au groupe de piece pousse \n");

                    printf("\n Entrer les coordonnees x et y de la piece qui pousse \n");
                    pousser(&Animaux, &Orientation,&x,&y,victoire);

                    break;

                    return 0;
                }


            }

            else
            {
                printf(" Cette option n'est pas disponible veuillez rentre a nouveau choisir une action");
                scanf("%d",&ChoixAction);
                switch(ChoixAction)
                {
                case 1:
                    affconsole(&Animaux, &Orientation,&x,&y);
                    printf("\nIl vous reste %d Elephants", *NbrElephant);
                    printf("\n Regle : \n");
                    printf("Vous pouvez entrez une pièce seulement sur les cases marqués de +\n");
                    printf("Si une piece se trouve sur l emplacement, Choisir fonction poussee ! \n");

                    entrerA(&Animaux, &Orientation,&x,&y, PointeurJoueur, &nbrE, &nbrR);

                    break;

                case 2:
                    affconsole(&Animaux, &Orientation,&x,&y);

                    orienter(&Animaux, &Orientation,&x,&y, PointeurJoueur);

                    break;

                case 3:
                    affconsole(&Animaux, &Orientation,&x,&y);
                    printf("\n Regle :\n");
                    printf("Vous pouvez vous deplacer dans la direction de votre orientation \n");

                    deplacer(&Animaux, &Orientation,&x,&y);

                    break;

                case 4:
                    affconsole(&Animaux, &Orientation,&x,&y);
                    printf("\n Regle : \n");
                    printf("Vous pouvez sortir une piece seulement si elle se trouve sur les cases marquees de +\n");
                    printf("\n Choisir la piece que vous voulez sortir\n");

                    printf("Pour cela entrer les coordonnees x et y de la piece");

                    sortir(&Animaux,&Orientation,&x,&y,PointeurJoueur, &nbrE, &nbrR);
                    printf("Il vous reste %d Elephant \n", *NbrElephant);

                    break;

                case 5:
                    printf("\n Regle : \n");
                    printf("Vous ne pouvez pousser une piece que si votre force est superieur a la piece ou au groupe de piece pousse \n");

                    printf("\n Entrer les coordonnees x et y de la piece qui pousse \n");
                    printf("\n Entrer les coordonnees x et y de la piece qui subit la pousse \n");

                    pousser(&Animaux, &Orientation,&x,&y,victoire);

                    break;

                    return 0;

                }


            }
            Joueur=(Joueur+1);
            affconsole(&Animaux,&Orientation,&x,&y);
        }

        if (Joueur==2) ///Lancement du menu et blindage pour le joueuer 2
        {
            printf("\nVous etes les Rhinos, A vous de jouer ! \n");

            printf("******** QUE VOULEZ VOUS FAIRE ? ********\n\n" );
            printf(" *1* ENTRER UNE PIECE \n" );
            printf(" *2* CHANGER D'ORIENTATION  \n" );
            printf(" *3* SE DEPLACER \n" );
            printf(" *4* SORTIR UNE PIECE\n" );
            printf(" *5* POUSSER UNE PIECE\n" );
            scanf("%d",&ChoixAction);

            if (ChoixAction<=5)
            {
                switch(ChoixAction)
                {
                case 1:
                    printf("\nIl vous reste %d Rhinos", *NbrRhino);
                    printf("\nRegle : \n");
                    printf("Vous pouvez entrez une piece seulement sur les cases marques de +\n");
                    printf("Si une piece se trouve sur l emplacement, Choisir fonction poussee ! \n\n");

                    entrerA(&Animaux, &Orientation,&x,&y, PointeurJoueur, &nbrE, &nbrR);

                    break;

                case 2:


                    orienter(&Animaux, &Orientation,&x,&y, PointeurJoueur);
                    break;

                case 3:
                    printf("\nRegle :\n");
                    printf("Vous pouvez vous deplacer sur les cases libres \n");
                    printf("Le deplacement est dans le sens de l'orientation \n");

                    deplacer(&Animaux, &Orientation,&x,&y);
                    break;

                case 4:
                    printf("\nRegle : \n");
                    printf("Vous pouvez sortir une piece seulement si elle se trouve sur les cases marquees de +\n");

                    printf("\nChoisir la piece que vous voulez sortir en rentrant ses coordonnees x et y \n");
                    sortir(&Animaux,&Orientation,&x,&y,PointeurJoueur, &nbrE, &nbrR);
                    printf("Il vous reste %d Rhinos \n", *NbrRhino);
                    break;

                case 5:
                    printf("\n Regle : \n");
                    printf("Vous ne pouvez pousser une piece que si votre force est superieur a la piece ou au groupe de piece pousse \n");

                    printf("\n Entrer les coordonnees x et y de la piece qui pousse \n");
                    pousser(&Animaux, &Orientation,&x,&y,victoire);

                    break;

                    return 0;
                }


            }

            else
            {
                printf(" Cette option n'est pas disponible veuillez rentre a nouveau choisir une action");
                scanf("%d",&ChoixAction);
                switch(ChoixAction)
                {
                case 1:
                    printf("\nIl vous reste %d Rhinos", *NbrRhino);
                    affconsole(&Animaux, &Orientation,&x,&y);
                    printf("\n Regle : \n");
                    printf("Vous pouvez entrez une pièce seulement sur les cases marqués de +\n");
                    printf("Si une piece se trouve sur l emplacement, Choisir fonction poussee ! \n");

                    entrerA(&Animaux, &Orientation,&x,&y, PointeurJoueur, &nbrE, &nbrR);

                    break;

                case 2:
                    affconsole(&Animaux, &Orientation,&x,&y);

                    orienter(&Animaux, &Orientation,&x,&y, PointeurJoueur);

                    break;

                case 3:
                    affconsole(&Animaux, &Orientation,&x,&y);
                    printf("\n Regle :\n");
                    printf("Vous pouvez vous deplacer dans la direction de votre orientation \n");

                    deplacer(&Animaux, &Orientation,&x,&y);

                    break;

                case 4:
                    affconsole(&Animaux, &Orientation,&x,&y);
                    printf("\n Regle : \n");
                    printf("Vous pouvez sortir une piece seulement si elle se trouve sur les cases marquees de +\n");
                    printf("\n Choisir la piece que vous voulez sortir\n");

                    printf("Pour cela entrer les coordonnees x et y de la piece");

                    sortir(&Animaux,&Orientation,&x,&y,PointeurJoueur, &nbrE, &nbrR);
                    printf("Il vous reste %d Rhinos \n", *NbrRhino);

                    break;

                case 5:
                    printf("\n Regle : \n");
                    printf("Vous ne pouvez pousser une piece que si votre force est superieur a la piece ou au groupe de piece pousse \n");

                    printf("\n Entrer les coordonnees x et y de la piece qui pousse \n");
                    printf("\n Entrer les coordonnees x et y de la piece qui subit la pousse \n");

                    pousser(&Animaux, &Orientation,&x,&y,victoire);

                    break;

                    return 0;

                }

            }
            Joueur=(Joueur-1);
            affconsole(&Animaux,&Orientation,&x,&y);
        }

    }
    printf("VICTOIRE");
}


