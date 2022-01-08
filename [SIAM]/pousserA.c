#ifndef POUSSER_C_INCLUDED
#define POUSSER_C_INCLUDED
#include <stdio.h>

void pousser(char Animaux[7][7],char Orientation[7][7],int x,int y,int *victoire)
{
    int i,j;
    printf("X et Y\n");
    scanf("%d%d",&x,&y);
    getchar();
    int X=x;
    int Y=y;
    float DEF=0;
    float ATQ=0;
    float force=0;
    int finwhile=0;

    if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='h')///Cas uniquement pour un pousser vers le haut
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='R'&& Orientation[X][Y]=='h')
            {
                if(Animaux[X][Y+1]=='R'&& Orientation[X][Y+1]=='h')///On verifie si dans la case en dessous il y a un rhino bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='b')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[X][0])
                finwhile=1;
            Y=Y-1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
    }

    else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='h')///Cas uniquement pour un pousser vers le haut
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='E'&& Orientation[X][Y]=='h')
            {
                if(Animaux[X][Y+1]=='E'&& Orientation[X][Y+1]=='h')///On verifie si dans la case en dessous il y a un Elephant bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='b')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[x][0])
                finwhile=1;
            Y=Y-1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
        printf("LA FORCE EST : %f \n",force);
    }
    if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='b')///Cas uniquement pour un pousser vers le bas
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='R'&& Orientation[X][Y]=='b')
            {
                if(Animaux[X][Y-1]=='R'&& Orientation[X][Y-1]=='b')///On verifie si dans la case en d'avant il y a un rhino bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='h')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[X][0])
                finwhile=1;
            Y=Y+1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
    }

    else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='b')///Cas uniquement pour un pousser vers le bas
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='E'&& Orientation[X][Y]=='b')
            {
                if(Animaux[X][Y-1]=='E'&& Orientation[X][Y-1]=='b')///On verifie si dans la case d'avant il y a un Elephant bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='h')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[x][0])
                finwhile=1;
            Y=Y+1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
    }
    if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='g')///Cas uniquement pour un pousser vers la gauche
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='R'&& Orientation[X][Y]=='g')
            {
                if(Animaux[X+1][Y]=='R'&& Orientation[X+1][Y]=='g')///On verifie si dans la case d'avant il y a un Elephant bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='d')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[X][0])
                finwhile=1;
            X=X-1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
    }

    else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='g')///Cas uniquement pour un pousser vers la gauche
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='E'&& Orientation[X][Y]=='g')
            {
                if(Animaux[X+1][Y]=='E'&& Orientation[X+1][Y]=='g')///On verifie si dans la case d'avant il y a un Elephant bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='d')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[x][0])
                finwhile=1;
            X=X-1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
    }
    if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='d')///Cas uniquement pour un pousser vers la droite
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='R'&& Orientation[X][Y]=='d')
            {
                if(Animaux[X-1][Y]=='R'&& Orientation[X-1][Y]=='d')///On verifie si dans la case d'avant il y a un rhino bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='g')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[X][0])
                finwhile=1;
            X=X+1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
    }

    else if(Animaux[X][Y]=='E'&&Orientation[X][Y]=='d')///Cas uniquement pour un pousser vers la droite
    {
        ATQ+=1;
        do
        {
            if(Animaux[X][Y]=='E'&& Orientation[X][Y]=='d')
            {
                if(Animaux[X-1][Y]=='E'&& Orientation[X-1][Y]=='d')///On verifie si dans la case d'avant il y a un Elephant bien orienter
                    ATQ+=1;
            }
            else if(Animaux[X][Y]=='R'&&Orientation[X][Y]=='g')
                DEF+=1;
            else if(Animaux[X][Y]=='M')
                DEF+=0.9;
            else if(Animaux[X][Y]==' ')
                finwhile=1;
            else if(Animaux[X][Y]==Animaux[x][0])
                finwhile=1;
            X=X+1;
        }
        while(finwhile!=1);
        force=ATQ-DEF;
    }


    if(force>0)
    {
        if(Orientation[x][y]=='h')
        {
            for(j=0; j<=6; j++)
            {
                Animaux[x][j]=Animaux[x][j+1];
                Orientation[x][j]=Orientation[x][j+1];
            }
            Animaux[x][5]='+';
            Orientation[x][5]=' ';
        }
        else if(Orientation[x][y]=='b')
        {
            for(j=6; j>=0; j--)
            {
                Animaux[x][j]=Animaux[x][j-1];
                Orientation[x][j]=Orientation[x][j-1];
            }
            Animaux[x][1]='+';
            Orientation[x][1]=' ';
        }
        else if(Orientation[x][y]=='g')
        {
            for(i=0; i<=6; i++)
            {
                Animaux[i][y]=Animaux[i+1][y];
                Orientation[i][y]=Orientation[i+1][y];
            }
            Animaux[5][y]='+';
            Orientation[5][y]=' ';
        }
        else if(Orientation[x][y]=='d')
        {
            for(i=6; i>=0; i--)
            {
                Animaux[i][y]=Animaux[i-1][y];
                Orientation[i][y]=Orientation[i-1][y];
            }
            Animaux[1][y]='+';
            Orientation[1][y]=' ';
        }
        if(Animaux[x][y]=='M') /// condition de victoire
        {
            if(x>=0&&x<=6 && y==0||y==6)
                *victoire=1;
            if(x==0||x==6 && y>=1 &&y<=5)
                *victoire=1;

        }


        ///Re print du cadres exterieurs
        Animaux[0][0] = 'y';
        Animaux[0][1] = '1';
        Animaux[0][2] = '2';
        Animaux[0][3] = '3';
        Animaux[0][4] = '4';
        Animaux[0][5] = '5';
        Orientation[0][1] = ' ';
        Orientation[0][2] = ' ';
        Orientation[0][3] = ' ';
        Orientation[0][4] = ' ';
        Orientation[0][5] = ' ';

        Animaux[1][0] = ' ';
        Animaux[2][0] = ' ';
        Animaux[3][0] = ' ';
        Animaux[4][0] = ' ';
        Animaux[5][0] = ' ';
        Orientation[0][0] = 'x';
        Orientation[1][0] = '1';
        Orientation[2][0] = '2';
        Orientation[3][0] = '3';
        Orientation[4][0] = '4';
        Orientation[5][0] = '5';
    }
}
#endif // POUSSER_C_INCLUDED

