#include "Liste.h"

void InitialiserListe(tListe *pInit)
//BUT : Initialiser la liste.
//ENTREE : Rien.
//SORTIE : Une liste vide initialis�e.
{
    pInit->pDebut=NULL;
    pInit->pFin=NULL;
    pInit->nTaille=0;
}

void AjoutListe(tListe *pListeAjout,tGameObject gAjout)
//BUT : Ajouter une valeur � la queue de la liste.
//ENTREE : Un GameObjet et la liste.
//SORTIE : La liste mise � jour avec un �l�ment suppl�mentaire.
{
    tElementListe *pNouveau;
    if (((pNouveau=(tElementListe *)malloc(sizeof(tElementListe)))==NULL)||(pListeAjout==NULL))
        exit(EXIT_FAILURE);

    pNouveau->gDonnee=gAjout;
    pNouveau->pPrecedent=NULL;
    pNouveau->pSuivant=NULL;

    //Si on est dans le cas o� la liste est vide.
    if (pListeAjout->pDebut==NULL && pListeAjout->pFin==NULL && pListeAjout->nTaille<1)
    {
        pListeAjout->pDebut=pNouveau;
        pListeAjout->pFin=pNouveau;
        pListeAjout->nTaille=1;
    }
    //Si on est dans le cas o� la liste n'est pas vide.
    else if (pListeAjout->pDebut!=NULL && pListeAjout->pFin!=NULL && pListeAjout->nTaille>=1)
    {
        pListeAjout->pFin->pSuivant=pNouveau;
        pNouveau->pPrecedent=pListeAjout->pFin;
        pListeAjout->pFin=pNouveau;
        pListeAjout->nTaille++;
    }
    //Dans les autres cas il y a une erreur dans la liste.
    else
    {
        printf("Erreur dans l'ajout a la liste.\n");
    }
}

void AjoutTeteListe(tListe *pListeAjout,tGameObject gAjout)
//BUT : Ajouter une valeur � la t�te de la liste.
//ENTREE : Un GameObjet et la liste.
//SORTIE : La liste mise � jour avec un �l�ment suppl�mentaire.
{
    tElementListe *pNouveau;
    if (((pNouveau=(tElementListe *)malloc(sizeof(tElementListe)))==NULL)||(pListeAjout==NULL))
        exit(EXIT_FAILURE);

    pNouveau->gDonnee=gAjout;
    pNouveau->pPrecedent=NULL;
    pNouveau->pSuivant=NULL;

    //Si on est dans le cas o� la liste est vide.
    if (pListeAjout->pDebut==NULL && pListeAjout->pFin==NULL && pListeAjout->nTaille<1)
    {
        pListeAjout->pDebut=pNouveau;
        pListeAjout->pFin=pNouveau;
        pListeAjout->nTaille=1;
    }
    //Si on est dans le cas o� la liste n'est pas vide.
    else if (pListeAjout->pDebut!=NULL && pListeAjout->pFin!=NULL && pListeAjout->nTaille>=1)
    {
        pListeAjout->pDebut->pPrecedent=pNouveau;
        pNouveau->pSuivant=pListeAjout->pDebut;
        pListeAjout->pDebut=pNouveau;
        pListeAjout->nTaille++;
    }
    //Dans les autres cas il y a une erreur dans la liste.
    else
    {
        printf("Erreur dans l'ajout a la liste.\n");
    }
}

void AjoutQueueListe(tListe *pListeAjout,tGameObject gAjout)
//BUT : Ajouter une valeur � la queue de la liste.
//ENTREE : Un GameObjet et la liste.
//SORTIE : La liste mise � jour avec un �l�ment suppl�mentaire.
{
    tElementListe *pNouveau;
    if (((pNouveau=(tElementListe *)malloc(sizeof(tElementListe)))==NULL)||(pListeAjout==NULL))
        exit(EXIT_FAILURE);

    pNouveau->gDonnee=gAjout;
    pNouveau->pPrecedent=NULL;
    pNouveau->pSuivant=NULL;

    //Si on est dans le cas o� la liste est vide.
    if (pListeAjout->pDebut==NULL && pListeAjout->pFin==NULL && pListeAjout->nTaille<1)
    {
        pListeAjout->pDebut=pNouveau;
        pListeAjout->pFin=pNouveau;
        pListeAjout->nTaille=1;
    }
    //Si on est dans le cas o� la liste n'est pas vide.
    else if (pListeAjout->pDebut!=NULL && pListeAjout->pFin!=NULL && pListeAjout->nTaille>=1)
    {
        pListeAjout->pFin->pSuivant=pNouveau;
        pNouveau->pPrecedent=pListeAjout->pFin;
        pListeAjout->pFin=pNouveau;
        pListeAjout->nTaille++;
    }
    //Dans les autres cas il y a une erreur dans la liste.
    else
    {
        printf("Erreur dans l'ajout a la liste.\n");
    }
}

void AjoutIndexListe(tListe *pListeAjout,tGameObject gAjout,int nIndex)
//BUT : Ajouter une valeur � l'index.
//ENTREE : Un GameObjet, la liste et l'index.
//SORTIE : La liste mise � jour avec un �l�ment suppl�mentaire.
{
    //Si l'index existe dans la liste on va ajouter notre objet, sinon on met un message d'erreur.
    if (nIndex<=pListeAjout->nTaille)
    {
        int nI=1;

        tElementListe *pActuel; //l'�l�ment pour voir l'indexation.
        pActuel=pListeAjout->pDebut;

        tElementListe *pNouveau; //Le nouvel �l�ment � ajouter.
        if (((pNouveau=(tElementListe *)malloc(sizeof(tElementListe)))==NULL)||(pListeAjout==NULL))
            exit(EXIT_FAILURE);

        pNouveau->gDonnee=gAjout;
        pNouveau->pPrecedent=NULL;
        pNouveau->pSuivant=NULL;


        while(nI!=nIndex)
        {
            pActuel=pActuel->pSuivant;
            nI++;
        }

        pNouveau->pPrecedent=pActuel->pPrecedent;
        pActuel->pPrecedent->pSuivant=pNouveau;
        pActuel->pPrecedent=pNouveau;
        pNouveau->pSuivant=pActuel;
        pListeAjout->nTaille++;

        if(nIndex==1)
        {
            pListeAjout->pDebut=pNouveau;
        }

        //A supprime plus tard, c'est pour le d�bugage.
        //printf("Index demande %d, ajout effectue a l'index %d.",nIndex,nI);
    }
    else
    {
        printf("Impossible d'ajouter a l'index donne.");
    }
}

void ExtraireIndexListe(tListe *pListeSuppr,int nIndex)
//BUT : Retirer une valeur � l'index.
//ENTREE : Un GameObjet, la liste et l'index.
//SORTIE : La liste mise � jour avec un �l�ment suppl�mentaire.
{
    //Si l'index existe dans la liste on va ajouter notre objet, sinon on met un message d'erreur.
    if (nIndex<=pListeSuppr->nTaille)
    {
        int nI=1;

        tElementListe *pActuel; //l'�l�ment pour voir l'indexation.
        pActuel=pListeSuppr->pDebut;

        tElementListe *pSupprime;

        while(nI!=nIndex)
        {
            pActuel=pActuel->pSuivant;
            nI++;
        }

        pSupprime=pActuel;

        pActuel->pSuivant->pPrecedent=pActuel->pPrecedent;
        pActuel->pPrecedent->pSuivant=pActuel->pSuivant;

        if (nIndex==1)
        {
            if (pListeSuppr->nTaille>1)
            {
                //Si on supprime le premier �l�ment on d�place la t�te de liste.
                pListeSuppr->pDebut=pListeSuppr->pDebut->pSuivant;
            }
            else
            {
                //Si on supprime le dernier �l�ment la chaine devient vide.
                pListeSuppr->pDebut=NULL;
                pListeSuppr->pFin=NULL;
            }
        }
        else if (nIndex==pListeSuppr->nTaille)
        {
            //Si on supprime le dernier �l�ment on d�place la queue de liste.
            pListeSuppr->pFin=pListeSuppr->pFin->pPrecedent;
        }

        free(pSupprime);
        pListeSuppr->nTaille--;

        //A supprime plus tard, c'est pour le d�bugage.
        //printf("Index demande %d, suppression effectue a l'index %d.",nIndex,nI);
    }
    else
    {
        printf("Impossible de supprime a l'index donne.");
    }
}

void ExtraireListe(tListe *pListeExtract,int nClefGameObjet)
//BUT : Sortir une valeur par sa clef de la liste.
//ENTREE : Une clef d'identification et la liste.
//SORTIE : La liste mise � jour avec un �l�ment en moins si il est dans la liste.
{
    int nBoolStop=0;
    //Tant que la liste n'est pas vide.
    if (pListeExtract->pDebut!=NULL && pListeExtract->pFin!=NULL && pListeExtract->nTaille>=1)
    {
        tElementListe *pActuel;
        pActuel=pListeExtract->pDebut;
        if (pActuel->gDonnee.nClef==nClefGameObjet)
        {
            if (pActuel->pSuivant!=NULL)
            {
                pActuel->pSuivant->pPrecedent=NULL;
            }
            pListeExtract->pDebut=pActuel->pSuivant;
            free(pActuel);
            pListeExtract->nTaille--;
        }
        else
        {
            while(pActuel->pSuivant!=NULL && nBoolStop==0)
            {
                pActuel=pActuel->pSuivant;
                if (pActuel->gDonnee.nClef==nClefGameObjet)
                {
                    if (pActuel->pSuivant!=NULL)
                    {
                        pActuel->pPrecedent->pSuivant=pActuel->pSuivant;
                        pActuel->pSuivant->pPrecedent=pActuel->pPrecedent;
                    }
                    else
                    {
                        pActuel->pPrecedent->pSuivant=NULL;
                        pListeExtract->pFin=pActuel->pPrecedent;
                    }
                    free(pActuel);
                    pListeExtract->nTaille--;
                    nBoolStop=1;
                }
            }
        }
    }
    else
    {
        printf("Liste vide, suppression de l'objet impossible.\n");
    }
}

void SuppDebut(tListe *pListe)
//BUT : Supprimer le premier �l�ment de la liste.
//ENTREE : La liste.
//SORTIE : La liste mise � jour avec un �l�ment en moins.
{
    if(pListe->nTaille > 0)
    {
        tElementListe *pElementActuel;
        pElementActuel = pListe->pDebut;
        pListe->pDebut = pListe->pDebut->pSuivant;

        if(pListe->pDebut == NULL)
        {
            pListe->pFin = NULL;
        }
        else
        {
            pListe->pDebut->pPrecedent = NULL;
        }

        free(pElementActuel);
        pListe->nTaille--;
    }
    else
    {
        printf("Suppression impossible, liste vide.\n");
    }
}

void SuppFin(tListe *pListe)
//BUT : Supprimer le dernier �l�ment de la liste.
//ENTREE : La liste.
//SORTIE : La liste mise � jour avec un �l�ment en moins.
{


    if(pListe->nTaille > 0)
    {
        tElementListe *pElementActuel;
        pElementActuel = pListe->pFin;
        pListe->pFin = pListe->pFin->pPrecedent;

        if(pListe->pFin == NULL)
            pListe->pDebut = NULL;
        else
            pListe->pFin->pSuivant = NULL;

        free(pElementActuel);
        pListe->nTaille--;
    }
    else
    {
        printf("Suppression impossible, liste vide.\n");
    }
}

void DetruireListe(tListe *pListe)
//BUT : D�truire la liste.
//ENTREE : La liste.
//SORTIE : La liste d�truite.
{
    while (pListe->nTaille>0)
    {
        SuppDebut(pListe);
    }
    free(pListe);
}

void AfficheListe(tListe *pListe)
//BUT : Afficher la liste.
//ENTREE : La liste.
//SORTIE : Chaque �l�ment de la liste affich�.
{
    tElementListe *pElementActuel;
    pElementActuel=pListe->pDebut;
    while (pElementActuel!=NULL)
    {
        printf("L'ID du GameObjet actuel est : %d.\n",pElementActuel->gDonnee.nClef);
        pElementActuel=pElementActuel->pSuivant;
    }
}

void AfficheListeInverse(tListe *pListe)
//BUT : Afficher la liste en partant de la fin.
//ENTREE : La liste.
//SORTIE : Chaque �l�ment de la liste affich�  en partant de la fin.
{
    tElementListe *pElementActuel;
    pElementActuel=pListe->pFin;
    while (pElementActuel!=NULL)
    {
        printf("L'ID du GameObjet actuel est : %d.\n",pElementActuel->gDonnee.nClef);
        pElementActuel=pElementActuel->pPrecedent;
    }
}
