#ifndef ORIENTER_C_INCLUDED
#define ORIENTER_C_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void orienter(char Animaux[7][7], char Orientation[7][7],int x,int y,int *PointeurJoueur)
{
    char o;
    char a;
    int findechec=0;
    if(*PointeurJoueur==1)
        {
            a='E';
        }
    if(*PointeurJoueur==2)
        {
            a='R';
        }

while(findechec!=1)
{
    printf("Rentrez les coordonnees x et y de la piece a orienter \n");
    printf("Veuillez a ne pas rentrer les coordonnees d'une piece de l'adversaire \n");
    scanf("%d%d",&x,&y);
    getchar();

    if(Animaux[x][y]==a)
    {
        printf("\nVous pouvez choisir parmis : h b d g\n");

        scanf("%c",&o);
        getchar();
        if(o=='h')
        {
            Orientation[x][y]= o;
            findechec=1;
        }
        else if(o=='b')
        {
            Orientation[x][y]= o;
            findechec=1;
        }
        else if(o=='d')
        {
            Orientation[x][y]= o;
            findechec=1;
        }
        else if(o=='g')
        {
            Orientation[x][y]= o;
            findechec=1;
        }
        else
        {
            printf("Vous n'avez pas choisis une orientation possible entre h b g d \n");
        }


    }
    else
    {
        printf("Il n'y a pas d'animal a orienter\n");
        printf("Ou vous souhaitez orienter un animal adversaire ce qui est impossible \n \n");
    }
}
}


#endif // ORIENTER_C_INCLUDED

