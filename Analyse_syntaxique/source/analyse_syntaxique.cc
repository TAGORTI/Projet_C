//============================================================================
// Name        : as.c
// Author      : Valérian
// Version     : 0.1
// Copyright   : PHELMA
// Description : Module d'analyse syntaxique du projet C
//============================================================================



#include "lexeme.h"
//#include "analyse_syntaxique.h" //analyse synthaxique
#include "tree.hh"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;


/*
int dessinerLigne(MesImages *p_im, int x1, int y1, int x2, int y2, unsigned char couleur){
	int errorDraw = 0;
	int i;
	double x = x2 - x1;
	double y = y2 - y1;
	double length = sqrt( x*x + y*y );
	double addx = x / length;
	double addy = y / length;
	x = x1;
	y = y1;
	
	for ( i = 0; i < length; i += 1) {
		errorDraw |= putPixel(p_im, x, y, couleur);
		x += addx;
		y += addy;		
	}
}
*/


tree get_arbre_primaire(const list<lexeme> & l){
	tree<lexeme> arbre;
	tree<lexeme>::iterator precedent, courrant, suivant;

	list<lexeme>::const_iterator
		lit (l.begin()),
		lend(l.end());
	courrant=arbre.insert(arbre.begin(), (*lit));
	++lit;	
	for(;lit!=lend;++lit){
		arbre.insert_next(*lit);
		//cout << (*lit).getnom() << ' ' << (*lit).getnature() << ' ' << (*lit).getrole()<< endl;
		}
	cout << endl;
	return arbre;
}
