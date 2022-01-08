#ifndef COLOR_C_INCLUDED
#define COLOR_C_INCLUDED
#include <string.h>
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond)
/// fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
///Condition Tableau i et k = R ou E afficher Color

}

#endif // COLOR_C_INCLUDED

