#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
///AJOUTER UNE FICHE D'UN FILM EN TETE DE LISTE
void ajouter (t_film **premier, t_film*nouv)
{
    nouv->suivant = *premier ;
    *premier = nouv ;
}
