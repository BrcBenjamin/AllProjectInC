#ifndef DEPLACER_C_INCLUDED
#define DEPLACER_C_INCLUDED

void deplacer(char Animaux[7][7],char Orientation[7][7],int x,int y,int *PointeurJoueur)
{
    int choix=0;
    char A,O;
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
        printf("Entrez les coordonnees x et y de l'animal a deplacer\n");
        scanf("%d%d",&x,&y);
        getchar();
        A=Animaux[x][y];
        O=Orientation[x][y];

        if(Animaux[x][y]==a)
        {
            if(O=='h')
            {
                if (Animaux[x][y-1]==' ' || Animaux[x][y-1]=='+')
                {
                    Animaux[x][y]='+';
                    Orientation[x][y]=' ';
                    Animaux[x][y-1]=A;
                    Orientation[x][y-1]=O;
                    findechec=1;

                }
                else if(Animaux[x][y-1]=='R' || Animaux[x][y-1]=='E' || Animaux[x][y-1]=='M')
                {
                    printf("Vous ne pouvez pas vous deplacer, vous devez utiliser la fonction pousser\n");
                }
            }
            else if(O=='b')
            {
                if (Animaux[x][y+1]==' ' || Animaux[x][y+1]=='+')
                {
                    Animaux[x][y]='+';
                    Orientation[x][y]=' ';
                    Animaux[x][y+1]=A;
                    Orientation[x][y+1]=O;
                    findechec=1;

                }
                else if(Animaux[x][y+1]=='R' || Animaux[x][y+1]=='E' || Animaux[x][y+1]=='M')
                {
                    printf("Vous ne pouvez pas vous deplacer, vous devez utiliser la fonction pousser\n");
                }
            }
            else if(O=='g')
            {
                if (Animaux[x-1][y]==' ' || Animaux[x-1][y]=='+')
                {
                    Animaux[x][y]='+';
                    Orientation[x][y]=' ';
                    Animaux[x-1][y]=A;
                    Orientation[x-1][y]=O;
                    findechec=1;

                }
                else if(Animaux[x-1][y]=='R' || Animaux[x-1][y]=='E' || Animaux[x-1][y]=='M')
                {
                    printf("Vous ne pouvez pas vous deplacer, vous devez utiliser la fonction pousser\n");
                }
            }
            else if(O=='d')
            {
                if (Animaux[x+1][y]==' ' || Animaux[x+1][y]=='+')
                {
                    Animaux[x][y]='+';
                    Orientation[x][y]=' ';
                    Animaux[x+1][y]=A;
                    Orientation[x+1][y]=O;
                    findechec=1;

                }
                else if(Animaux[x+1][y]=='R' || Animaux[x+1][y]=='E' || Animaux[x+1][y]=='M')
                {
                    printf("Vous ne pouvez pas vous deplacer, vous devez utiliser la fonction pousser\n");
                }
            }
            else
            {
                printf("Vous sortez de la zone on ne peut donc pas effectuer ce deplacement\n\n");
            }
        }
        else
            printf("Ce n'est pas votre animal ou bien cette case est vide\n");
    }
}


#endif // DEPLACER_C_INCLUDED

