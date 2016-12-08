#ifndef _ANALYSE_SYNTAXIQUE_H_
#define _ANALYSE_SYNTAXIQUE_H_


#include "lexeme.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include "tree.hh"
using namespace std;


//int dessinerLigne(MesImages *p_im, int x1, int y1, int x2, int y2, unsigned char couleur);


//tree<string> get_arbre_primaire(const list<lexeme> & l);

//tree<lexeme> get_arbre_primaire(const list<lexeme> & l);

//void get_arbre_primaire( list<lexeme>* list, tree<lexeme>*  arbre);

void get_arbre_primaire( list<lexeme> & list, tree<lexeme> & arbre);

//void get_arbre_primaire( list<lexeme> & list, tree<lexeme> & arbre);

void recursive_action( list<lexeme> & l, tree<lexeme> & arbre, list<lexeme>::const_iterator & lit, list<lexeme>::const_iterator & lend, list<lexeme>::const_iterator & previous_lexeme, tree<lexeme>::iterator & previous_branche, tree<lexeme>::iterator & current_branche, /*tree<lexeme>::iterator & root*/ list<tree<lexeme>::iterator> listroot);

#endif
