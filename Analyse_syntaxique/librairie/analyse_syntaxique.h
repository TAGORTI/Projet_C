#ifndef _DESSIN_PHELMA_H_
#define _DESSIN_PHELMA_H_


#include "lexeme.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include "tree.hh"


//int dessinerLigne(MesImages *p_im, int x1, int y1, int x2, int y2, unsigned char couleur);


tree get_arbre_primaire(const list<lexeme> & l);
