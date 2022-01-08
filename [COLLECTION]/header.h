///Définition des structures et liste chainées
typedef struct film
{
    char nomFilm[50] ;
    char nomRealisateur[50] ;
    int annee ;

    struct film*suivant ;

} t_film ;

typedef struct collection
{
    t_film *premier;

} t_collection ;

///Prototype des sous programmes:
t_film*creer (sauvegarde);
void ajouter (t_film **premier, t_film*nouv);
void afficher_collection(t_film*premier);
void supprimer (t_film**pfilm);
void recherche_supprime(t_film**premier, char nomFilm[50], char nomRealisateur[50], int annee);
void afficher_caracteristique(t_film**premier, char nomFilm[50], char nomRealisateur[50], int annee);
void supprimerUneFiche(t_film**premier, char nomFilm[50], char nomRealisateur[50], int annee);
int menu();
