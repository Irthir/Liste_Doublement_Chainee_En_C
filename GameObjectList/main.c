#include "entete.h"

int main()
{
    tListe *pListe;

    if ((pListe = (tListe *) malloc (sizeof (tListe))) == NULL)
        return -1;

    InitialiserListe(pListe);

    //Création d'une série de GameObjet avec le même mesh et même position.

    tVect3 vVect3;
    setVect3X (&vVect3,1);
    setVect3Y (&vVect3,2);
    setVect3Z (&vVect3,3);

    char * cMeshGameObjet="Mesh";

    tGameObject gGameA = CreatGameObjet(1,cMeshGameObjet,vVect3);
    AfficheID(gGameA);
    tGameObject gGameB = CreatGameObjet(2,cMeshGameObjet,vVect3);
    AfficheID(gGameB);
    tGameObject gGameC = CreatGameObjet(3,cMeshGameObjet,vVect3);
    AfficheID(gGameC);
    tGameObject gGameD = CreatGameObjet(4,cMeshGameObjet,vVect3);
    AfficheID(gGameD);
    tGameObject gGameE = CreatGameObjet(5,cMeshGameObjet,vVect3);
    AfficheID(gGameE);

    //5 GameObjets créés.

    //Ajoutons les GameObjets à la liste.
    AjoutListe(pListe,gGameA);
    AjoutListe(pListe,gGameB);
    AjoutListe(pListe,gGameC);
    AjoutListe(pListe,gGameD);
    AjoutListe(pListe,gGameE);

    printf("Affichons la liste.\n");
    AfficheListe(pListe);

    printf("\nRetirons le GameObjet d'ID 4.\n");
    ExtraireListe(pListe,4);

    printf("\nAffichons la liste.\n");
    AfficheListe(pListe);

    printf("\nAjoutons a nouveau cet objet en tete, cette fois.\n");
    AjoutTeteListe(pListe,gGameD);

    printf("\nAffichons la liste.\n");
    AfficheListe(pListe);

    printf("\nSupprimons un objet en index 2.\n");
    ExtraireIndexListe(pListe,2);

    printf("\nAffichons la liste.\n");
    AfficheListe(pListe);

    printf("\nAjoutons un objet d'ID 1 en index 3.\n");
    AjoutIndexListe(pListe,gGameA,3);

    printf("\nAffichons la liste.\n");
    AfficheListe(pListe);

    printf("\nAffichons la liste dans l'ordre inverse.\n");
    AfficheListeInverse(pListe);

    printf("\nFin du Programme.\n");
    return 0;
}
