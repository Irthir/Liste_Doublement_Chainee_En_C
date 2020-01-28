#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tVect3
{
    int nX;
    int nY;
    int nZ;
}tVect3;

typedef struct tGameObject
{
    int nClef;
    char *cMesh;
    tVect3 vPos;
}tGameObject;

int getGameObjetClef(tGameObject gObjet);
void setGameObjetClef(tGameObject *gObjet, int nClef);
char* getGameObjetMesh(tGameObject gObjet);
void setGameObjetMesh(tGameObject *gObjet,char* cMesh);
tVect3 getGameObjetVect3(tGameObject gObjet);
void setGameObjetVect3(tGameObject *gObjet,tVect3 vPos);
int getVect3X (tVect3 vVecteur);
void setVect3X (tVect3 *vVecteur,int nX);
int getVect3Y (tVect3 vVecteur);
void setVect3Y (tVect3 *vVecteur,int nY);
int getVect3Z (tVect3 vVecteur);
void setVect3Z (tVect3 *vVecteur,int nZ);

tGameObject CreatGameObjet(int nClef, char* cMesh, tVect3 vVecteur);

void AfficheID(tGameObject gObjet);


#endif
