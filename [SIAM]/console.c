#ifndef AFFCONSOLE_C_INCLUDED
#define AFFCONSOLE_C_INCLUDED


void affconsole(char Animaux[7][7], char Orientation[7][7],int x,int y)
{
   printf("-----+----+----+----+----+----+\n",Color(3,0));
   for(y=0;y<6;y++)
    {
        printf("|",Color(3,0));
        for(x=0;x<6;x++)
        {
            printf("%c",Animaux[x][y],Color(15,0));
            printf("%c",Orientation[x][y],Color(4,0));
            printf("  |",Color(3,0));
        }
        printf("\n-----+----+----+----+----+----+\n",Color(3,0));
    }
}



#endif // AFFCONSOLE_C_INCLUDED

