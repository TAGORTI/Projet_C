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

#include <iosfwd>

#include <list>


using namespace std;

void afficher_arbre(const tree<lexeme> & arbre){
    tree<lexeme>::iterator arbre_it (arbre.begin()), arbre_end(arbre.end());
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
}


int main() {


list<lexeme> listlexeme;// = creer_liste ;//  list de lexeme

listlexeme.push_back(lexeme("entity","entity"));


listlexeme.push_back(lexeme("filter","id"));
listlexeme.push_back(lexeme("is","is"));
listlexeme.push_back(lexeme("port","port"));
listlexeme.push_back(lexeme("(","parenthese_ouvrante"));

listlexeme.push_back(lexeme("A","id"));
listlexeme.push_back(lexeme(":","deux_points"));
listlexeme.push_back(lexeme("in","in"));
listlexeme.push_back(lexeme("std_logic","type"));
listlexeme.push_back(lexeme(";","endligne"));

listlexeme.push_back(lexeme("B","id"));
listlexeme.push_back(lexeme(":","deux_points"));
listlexeme.push_back(lexeme("in","in"));
listlexeme.push_back(lexeme("std_logic","type"));
listlexeme.push_back(lexeme(";","endligne"));

listlexeme.push_back(lexeme("C","id"));
listlexeme.push_back(lexeme(",","virgule"));
listlexeme.push_back(lexeme("D","id"));
listlexeme.push_back(lexeme(":","deux_points"));
listlexeme.push_back(lexeme("in","in"));
listlexeme.push_back(lexeme("std_logic","type"));

listlexeme.push_back(lexeme(")","parenthese_fermante"));
listlexeme.push_back(lexeme(";","endligne"));

//string l = (*(listlexeme.begin())).getnom();


cout << (*(listlexeme.begin())).getnom() << endl;
cout << (*(listlexeme.begin())).getnature() << endl;
cout << (*(listlexeme.begin())).getrole() << endl;


afficher_liste(listlexeme);

//tree<string> arbre = get_arbre_primaire(listlexeme);
tree<lexeme> arbre = get_arbre_primaire(listlexeme);


}
/*
cout << l<<endl;
}
/*
cout << listlexeme<1>.getnature()<<endl;
cout << listlexeme<1>.getrole()<<endl;

}

//arbre = get_arbre_primaire (listlexeme);


//Puis la vérification de l'arbre en le comparent
/*
Comparing trees While the STL equal algorithm can be used to compare the values of the
nodes in two different trees, it does not know about the structure of the tree. If you want
the comparison to take this into account, use the equal(iterator, iterator, iterator,
BinaryPredicate) call of the tree class. As an addition to the STL algorithm, the length of
the first range does not have to be equal to the length of the range pointed to by the second
iterator.
There is also an equal subtree algorithm which takes only two iterators, pointing to the
(single-node) heads of two subtrees.
*/


/*
 table std::vector<lexeme>;

 
 table.push_back( new lexeme (")","parenthese_fermante") );

 table<0>

 table.push_back( new lexeme (";","endligne") );

 table<1>
*/
