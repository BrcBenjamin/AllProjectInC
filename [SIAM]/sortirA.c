#ifndef SORTIR_C_INCLUDED
#define SORTIR_C_INCLUDED


void sortir(char Animaux[7][7],char Orientation[7][7],int x,int y,int *PointeurJoueur,int *NbrElephant, int *NbrRhino)
{

char a;
if(*PointeurJoueur==1)
    {
        a='E';
        *NbrElephant=*NbrElephant+1;
    }
if(*PointeurJoueur==2)
    {
        a='R';
        *NbrRhino=*NbrRhino+1;
    }


int findechec=0;
while(findechec!=1)
{
    printf("Rentrer les coordonnees x et y  d un pion a sortir\n");
    scanf("%d %d",&x, &y);
    getchar();

    if(Animaux[x][y]==a)
    {

        if(x>0&&x<=5 && y==1)
        {
           Animaux[x][y] ='+';
           Orientation [x][y] =' ';
           findechec=1;

        }

        else if(x>0&&x<=5 && y==5)
        {
            Animaux[x][y] ='+';
            Orientation [x][y] =' ';
            findechec=1;
        }


        else if(x==1||x==5 && y>=1&&y<=4)
        {
           Animaux[x][y] ='+';
           Orientation [x][y] =' ';
           findechec=1;
        }

    }
    else
        printf("Ce pion ne peut etre sorti \n");

}
}




#endif // SORTIR_C_INCLUDED

