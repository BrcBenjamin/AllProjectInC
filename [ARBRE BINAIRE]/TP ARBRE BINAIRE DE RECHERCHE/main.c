#include <stdio.h>
#include <stdlib.h>


///LES SOURCES UTILISES;
/// http://gallium.inria.fr/~maranget/X/421/poly/arbre-bin.html
/// https://codes-sources.commentcamarche.net/source/54848-dictionnaire-dans-un-arbre-binaire
/// Et un pdf sur les arbres binaires mais je ne retrouve pas le lien.



FILE*fichier;

///CREATION STRUCTURE D'ACCEUIL DE LA FUTUR QUESTION OU REPONSE SI IL N'Y A PLUS DE QUESTION APRES (LES POINTEURS G ET D SONT NULL)
typedef struct rep
{
    ///NUMERO PERMET DE PLACER LA REPONSE DANS L'ABR LE NOM DONNE l'ANIMAL OU LA QUESTION
    int num;
    char nom[30];
}rep;

///CREATION D'UNE STRUCTURE NOEUD
typedef struct noeud
{
    rep*rep;
    struct noeud * G;
    struct noeud * D;
}noeud;

///SOUS PROGRAMME POUR CREER UN NOUVEAU NOEUD (NOUVELLE QUESTION)
void Creer(rep*rep,noeud**abr) //on utiliste abr pour initialiser un Arbre Binaire de Recherche
{
    noeud*courant;
    noeud*nouv=(noeud*)malloc(sizeof(noeud));
    nouv->rep=rep;
    nouv->D=NULL;
    nouv->G=NULL;
    ///ON VERIFIE L'ALLOCATION
    if(nouv==NULL)
    {
        printf("ERREUR D'ALLOCATION");
        return NULL;
    }
    ///ON VERIFIE QUE L'ARBRE EXISTE, SI L'ARBRE EST VIDE ALORS LE NOUVEAU NOEUD DEVIENS LA RACINE DE L'ARBRE
    if(*abr==NULL)*abr=nouv;
    ///SINON ON COMPARE LES VALEURS DES NOEUD POUR PLACER LE NOUVEAU NOEUD EN BON ENDROIT GRACE AU POINTEUR noeud*p
    else
    {
        courant=*abr;
        while(courant!=NULL)
        {
            ///DEUX CAS POSSIBLE: <=0 OU >0
            if(strcmp(rep->nom,courant->rep->nom)<=0)
            {
                if(courant->G!=NULL)courant=courant->G;
                else
                {
                    courant->G=nouv;
                    courant=NULL;
                }
            }
            else
            {
                if(courant->D!=NULL)courant=courant->D;
                else
                {
                    courant->D=nouv;
                    courant=NULL;
                }
            }
        }
    }
}

///SOUS PROGRAMME D'INSERTION DU NOEUD
/// DEVENU INUTILE CAR RAJOUTE AU SOUS PROGRAMME DE CREATION DE NOEUD
noeud*InserNoeud(noeud*courant,noeud*nouv)
{
    if(courant==NULL)
        return nouv;
    if(strcmp(nouv->rep->nom,courant->rep->nom)<0)
        courant->G=InserNoeud(courant->G,nouv);
    else if(strcmp(nouv->rep->nom,courant->rep->nom)>0)
        courant->D=InserNoeud(courant->D,nouv);
    ///SI LE MOT EXISTE DEJA:
    else
    {
        printf("La question existe deja \n");
        free(nouv);
    }
    return courant;
}

///SOUS PROGRAMME POUR PARCOURIR L'ARBRE INFIXE EN PARTANT DE LA DROITE COMME DANS L'EXEMPLE DE TP
/// ON AFFICHE UNIQUEMENT LA QUESTION IL N'EST PAS NECESSAIRE D'AFFICHER LE NUMERO
void Parcourir(noeud*abr)
{
    if(abr!=NULL)
    {
        Parcourir(abr->D);
        printf("%s\n",abr->rep->nom);
        Parcourir(abr->G);
    }
}

///SOUS PROGRAMME POUR JOUER (CREATION DE L'ARBRE SUR FICHIER)
noeud* jouer()
{
    noeud*abr=NULL;
    rep*tampon;
    FILE*fichier=fopen("sauvegarde.txt","r+");
    if(fichier!=NULL)
    {
        while(!feof(fichier));
        {
            tampon=malloc(sizeof(rep));
            fscanf(fichier,"%d",&tampon->num);
            fscanf(fichier,"%s", &tampon->nom);
            printf("num=%d, nom=%s\n\n4",tampon->num,tampon->nom);
            Creer(tampon,&abr);
        }
        fclose(fichier);
        return abr;
    }
    else
        printf("ERREUR D'INITIALISATION DE FICHIER");
    return NULL;
}

///DEUX SOUS PROGRAMME DE SAUVEGARDE DE L'ARBRE
void sauve(noeud*courant)
{
    fprintf(fichier,"%c",courant->rep->nom?courant->rep->nom:'0');
    for(courant=courant->D; courant; courant=courant->G)
        sauve(courant);
    fputc('#',fichier);
}

void sauvegarde(noeud*courant)
{
    if(courant==NULL)
        return;
    if(fichier=fopen("sauvegarde.txt","r+"))
    {
        sauve(courant);
        while(courant->G)
        {
            courant=courant->G;
            fputc('$',fichier);
            sauve(courant);
        }
    }
    fclose(fichier);
}

/// LE MAIN
int main()
{
    noeud*abr;
    noeud*rep;
    Creer(rep,&abr);
    abr=jouer();
    Parcourir(abr);
        return 0;
}
