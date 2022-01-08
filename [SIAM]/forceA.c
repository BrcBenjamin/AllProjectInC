#ifndef FORCEA_C_INCLUDED
#define FORCEA_C_INCLUDED

void puissance(int *px,int *py,char Animaux[7][7],char Orientation[7][7],int x,int y)
{
    ///Creation de la varibale et de son pointeur pour dire si force ATQ>DEF:
    float Tforce=0;
    float *pTforce=&Tforce;

    ///Creation des valeurs des forces:
    float ATQ=0;
    float DEF=0;

    ///Initialisations des lectures de forces pour tout type d'animal:
    char A,O;
    int i=*py;
    int j;
    int finwhile=0;
    A=Animaux[*px][*py];
    O=Orientation[*px][*py];

    ///Lancement du calcul des forces:
    if(Animaux[*px][*py]==A &&O=='h')///Cas uniquement pour un pousser vers le haut
  	{
  	    ATQ=ATQ+1;
    	do
      {
        if(Animaux[x][i]==A && Orientation[x][i]==O)
        {///On verifie si dans la case en dessous il y'a la meme piece qui pousse (animal et orientation)
          if(Animaux[x][i+1]==A && Orientation[x][i+1]==O)
            ATQ=ATQ+1;
        }
        else if(Animaux[x][i]!=A && Orientation[x][i]=='b')
            DEF=DEF+1;
        else if(Animaux[x][i]=='M')
            DEF=DEF+0.9;
        else if(Animaux[x][i]==' ')
      		finwhile=1;
        else if(Animaux[x][i]==Animaux[x][0])
            finwhile=1;
        i=i--;
        Tforce=ATQ - DEF;
      }
    	while(finwhile!=1);
    	printf("%f",&Tforce);
  	}
}

#endif // FORCEA_C_INCLUDED
