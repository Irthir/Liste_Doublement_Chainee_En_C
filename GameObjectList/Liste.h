#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "GameObject.h"

typedef struct tElementListe
{
    tGameObject gDonnee;
    struct tElementListe *pSuivant;
    struct tElementListe *pPrecedent;
} tElementListe;

typedef struct tListe
{
    tElementListe *pDebut;
    tElementListe *pFin;
    int nTaille;
} tListe;

void InitialiserListe(tListe *pInit);

void AjoutListe(tListe *pListeAjout,tGameObject gAjout);
void AjoutTeteListe(tListe *pListeAjout,tGameObject gAjout);
void AjoutQueueListe(tListe *pListeAjout,tGameObject gAjout);
void AjoutIndexListe(tListe *pListeAjout,tGameObject gAjout,int nIndex);

void ExtraireListe(tListe *pListeExtract,int nClefGameObjet);
void SuppDebut(tListe *pListe);
void SuppFin(tListe *pListe);
void DetruireListe(tListe *pListe);
void ExtraireIndexListe(tListe *pListeSuppr,int nIndex);

void AfficheListe(tListe *pListe);
void AfficheListeInverse(tListe *pListe);


#endif
