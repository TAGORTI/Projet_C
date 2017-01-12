//============================================================================
// Name        : as.c
// Author      : Valérian
// Version     : 0.1
// Copyright   : PHELMA
// Description : Module d'analyse syntaxique du projet C
//============================================================================



//#include "..\librairie\lexeme.hh"
//#include "..\librairie\analyse_syntaxique.hh" //analyse synthaxique
//#include "..\librairie\tree.hh"

#include "lexeme.hh"
#include "analyse_syntaxique.hh" //analyse synthaxique
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
	tree<lexeme>::iterator 
	arbre_it(arbre.begin()), 
	arbre_end(arbre.end());
	for(;arbre_it!=arbre_end;++arbre_it) {
		for (int i=0; i<arbre.depth(arbre_it); ++i){
		cout << "   ";
		}
	cout << (*arbre_it).getnom() << ' ' << (*arbre_it).getnature()  << ' ' << (*arbre_it).getrole() << endl;

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

listlexeme.push_back(lexeme("entity","entity",1,1));


listlexeme.push_back(lexeme("filter","id",2,2));
listlexeme.push_back(lexeme("is","is",3,3));
listlexeme.push_back(lexeme("port","port"));
listlexeme.push_back(lexeme("(","parenthese_ouvrante"));

listlexeme.push_back(lexeme("a","id"));
listlexeme.push_back(lexeme(":","deux_points"));
listlexeme.push_back(lexeme("in","in"));
listlexeme.push_back(lexeme("std_logic","type"));
listlexeme.push_back(lexeme(";","endligne"));

listlexeme.push_back(lexeme("b","id"));
listlexeme.push_back(lexeme(":","deux_points"));
listlexeme.push_back(lexeme("in","in"));
listlexeme.push_back(lexeme("std_logic","type"));
listlexeme.push_back(lexeme(";","endligne"));

listlexeme.push_back(lexeme("c","id"));
listlexeme.push_back(lexeme(",","virgule"));
listlexeme.push_back(lexeme("d","id"));
listlexeme.push_back(lexeme(":","deux_points"));
listlexeme.push_back(lexeme("in","in"));
listlexeme.push_back(lexeme("std_logic","type"));

listlexeme.push_back(lexeme(")","parenthese_fermante","endport"));
listlexeme.push_back(lexeme(";","endligne"));

listlexeme.push_back(lexeme("end","endprocess","endentity"));
listlexeme.push_back(lexeme("filter","id", "entity"));
listlexeme.push_back(lexeme(";","endligne"));

listlexeme.push_back(lexeme("architecture","architecture"));
listlexeme.push_back(lexeme("behavior","id"));
listlexeme.push_back(lexeme("of","of"));
listlexeme.push_back(lexeme("filter","id"));
listlexeme.push_back(lexeme("is","is"));

listlexeme.push_back(lexeme("c","id"));
listlexeme.push_back(lexeme("<=","assignation"));

listlexeme.push_back(lexeme("B","id"));
listlexeme.push_back(lexeme("+","plus","logic_ou"));
listlexeme.push_back(lexeme("A","id"));
listlexeme.push_back(lexeme(";","endligne"));

listlexeme.push_back(lexeme("end","endprocess","endarchitecture"));
listlexeme.push_back(lexeme("behavior","id","architcture"));
listlexeme.push_back(lexeme(";","endligne"));

//string l = (*(listlexeme.begin())).getnom();


//cout << (*(listlexeme.begin())).getnom() << endl;
//cout << (*(listlexeme.begin())).getnature() << endl;
//cout << (*(listlexeme.begin())).getrole() << endl;


//afficher_liste(listlexeme);

//tree<string> arbre = get_arbre_primaire(listlexeme);
tree<lexeme> arbre ;

get_arbre_primaire(listlexeme,arbre);

//get_arbre_primaire(&listlexeme,&arbre);

//afficher_arbre(arbre);

cin.get();

(*(listlexeme.begin())).getposition();

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
