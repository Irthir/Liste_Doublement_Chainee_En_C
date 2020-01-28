#include "GameObject.h"

int getGameObjetClef(tGameObject gObjet)
{
    return gObjet.nClef;
}

void setGameObjetClef(tGameObject *gObjet,int nClef)
{
    gObjet->nClef=nClef;
}

char* getGameObjetMesh(tGameObject gObjet)
{
    return gObjet.cMesh;
}

void setGameObjetMesh(tGameObject *gObjet,char* cMesh)
{
    gObjet->cMesh=cMesh;
}

tVect3 getGameObjetVect3(tGameObject gObjet)
{
    return gObjet.vPos;
}

void setGameObjetVect3(tGameObject *gObjet,tVect3 vPos)
{
    gObjet->vPos=vPos;
}

int getVect3X (tVect3 vVecteur)
{
    return vVecteur.nX;
}

void setVect3X (tVect3 *vVecteur,int nX)
{
    vVecteur->nX=nX;
}

int getVect3Y (tVect3 vVecteur)
{
    return vVecteur.nY;
}

void setVect3Y (tVect3 *vVecteur,int nY)
{
    vVecteur->nY=nY;
}

int getVect3Z (tVect3 vVecteur)
{
    return vVecteur.nZ;
}

void setVect3Z (tVect3 *vVecteur,int nZ)
{
    vVecteur->nZ=nZ;
}

tGameObject CreatGameObjet(int nClef, char* cMesh, tVect3 vVecteur)
{
    tGameObject gNouveau;
    setGameObjetClef(&gNouveau,nClef);
    setGameObjetMesh(&gNouveau,cMesh);
    setGameObjetVect3(&gNouveau,vVecteur);
    return gNouveau;
}

void AfficheID(tGameObject gObjet)
{
    printf("La clef est %d.\n",gObjet.nClef);
}
