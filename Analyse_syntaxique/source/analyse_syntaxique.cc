//============================================================================
// Name        : as.c
// Author      : Valérian
// Version     : 0.1
// Copyright   : PHELMA
// Description : Module d'analyse syntaxique du projet C
//============================================================================



#include "lexeme.h"
#include "analyse_syntaxique.h" //analyse synthaxique
#include "tree.hh"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;


//tree<string> get_arbre_primaire(const list<lexeme> & l){

//void get_arbre_primaire(list<lexeme>* list, tree<lexeme>*  arbre){

void get_arbre_primaire( list<lexeme> & l, tree<lexeme> & arbre){
	//tree<lexeme> arbre;
	list<lexeme>::const_iterator 
		lit(l.begin()), 
		lend(l.end());
	tree<lexeme>::iterator previous, current, next, loc, banana;
	previous=arbre.insert(arbre.end(), *lit);
	++lit;


	for(;lit!=lend;++lit){
		//if (*lit=="entity")
		//	arbre.insert(arbre.end(), *lit);
	//	case  if XXXXXXXXXXXXXXXXXXXXXXXXXXxxxxx
			current=arbre.append_child(previous, *lit);
			previous=current;
		
	}


	//return arbre;
}


//   loc=find(tr.begin(), tr.end(), "two");
//   if(loc!=tr.end()) {
//   tree<string>::sibling_iterator sib=tr.begin(loc);


/*
void afficher_arbre(const tree<lexeme> & arbre){
    tree<lexeme>::iterator arbre_it(arbre.begin()), arbre_end(arbre.end());
    for(;arbre_it!=arbre_end;++arbre_it) {
	cout << (*arbre_it).getnom() << endl;

	}
}

void afficher_liste(const list<lexeme> & l){
    list<lexeme>::const_iterator
        lit (l.begin()),
        lend(l.end());
    for(;lit!=lend;++lit) cout << (*lit).getnom() << ' ' << (*lit).getnature() << ' ' << (*lit).getrole()<< endl;
    cout << endl;
}*/

/*
void get_arbre_primaire( list<lexeme> & l, tree<lexeme> & arbre){
   tree<string> tr;
   tree<string>::iterator top, one, two, loc, banana;
   
   top=tr.begin();
   one=tr.insert(top, "one");
   two=tr.append_child(one, "two");
   tr.append_child(two, "apple");
   banana=tr.append_child(two, "banana");
   tr.append_child(banana,"cherry");
   tr.append_child(two, "peach");
   tr.append_child(one,"three");
   
   loc=find(tr.begin(), tr.end(), "two");
   if(loc!=tr.end()) {
   tree<string>::sibling_iterator sib=tr.begin(loc);
   while(sib!=tr.end(loc)) {
     cout << (*sib) << endl;
     ++sib;
     }
   cout << endl;
   tree<string>::iterator sib2=tr.begin(loc);
   tree<string>::iterator end2=tr.end(loc);
   while(sib2!=end2) {
     for(int i=0; i<tr.depth(sib2)-2; ++i) 
        cout << " ";
     cout << (*sib2) << endl;
     ++sib2;
     }
   }
}
*/
