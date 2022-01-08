#ifndef ANIMAUX_C_INCLUDED
#define ANIMAUX_C_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


void entrerA(char Animaux[7][7], char Orientation[7][7],int x,int y, int *PointeurJoueur,int *NbrElephant, int *NbrRhino)
{
    int findechec=0;///Permet de faire une boucle pour si un joueur se trompe de case ou d'orientation
    int lancementwhile=0; ///Permet de lancer la boucle while si le nombre d'animaux > 0
    char a,d;
    ///Prédefinir l'Animal selon le joueur
    if(*PointeurJoueur==1)
    {
        a='E';
        *NbrElephant=*NbrElephant-1;
    }
    if(*PointeurJoueur==2)
    {
        a='R';
        *NbrRhino=*NbrRhino-1;
    }
    ///Boucle d'échec de placement de piece, qui se termine quand un placement est correct avec finechec=1
    while(findechec!=1)
    {
        printf("Entrez les coordonees x et y pour placer un animal\n");
        scanf("%d%d",&x,&y);
        getchar();///enregistre ce qui a été rentré
        printf("entrer l'orientation h b d ou g \n");
        scanf("%c", &d);
        ///Conditions et blind des cases non autorisées
        if(Animaux[x][y]=='+')
        {
            if(x>0&&x<=5 && y==1)
            {

                if(a=='R'||a=='E')
                {

                    if(d=='h')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='b')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='d')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='g')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;

                    }
                    else
                    {
                        printf("Vous n'avez pas choisis une orientation possible entre h b g d \n\n");
                    }
                }
                else
                {
                    printf("Vous n'avez pas selectionner un animal existant \n\n");
                }
            }
            else if(x>0&&x<=5 && y==5)
            {
                if(a=='R'||a=='E')
                {
                    if(d=='h')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='b')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='d')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='g')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else
                    {
                        printf("Vous n'avez pas choisis une orientation possible entre h b g d \n\n");
                    }
                }
                else
                {
                    printf("Vous n'avez pas selectionner un animal existant \n\n");
                }
            }
            else if (x==1||x==5 && y>=1&&y<=4)
            {
                if(a=='R'||a=='E')
                {
                    if(d=='h')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='b')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='d')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else if(d=='g')
                    {
                        Animaux[x][y] =' ';
                        Orientation [x][y] =' ';
                        Animaux[x][y] = a;
                        Orientation [x][y] = d;
                        findechec=1;
                    }
                    else
                    {
                        printf("Vous n'avez pas choisis une orientation possible entre h b g d \n\n");
                    }
                }

            }
        }
        else
        {
        printf("Cette case n'est pas autorisee\n\n");
    }
    }

}


#endif // ANIMAUX_C_INCLUDED

