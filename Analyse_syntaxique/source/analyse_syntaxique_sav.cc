//============================================================================
// Name        : as.c
// Author      : Valérian
// Version     : 0.1
// Copyright   : PHELMA
// Description : Module d'analyse syntaxique du projet C
//============================================================================



#include "lexeme.hh"
#include "analyse_syntaxique.hh" //analyse synthaxique
#include "tree.hh"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;


//tree<string> get_arbre_primaire(const list<lexeme> & l){

//void get_arbre_primaire(list<lexeme>* list, tree<lexeme>*  arbre){

/*void generate_mot_cle_nature (){

	map<string,fonction???> map_protocole;// = creer_mpa ;//  list de mots clés

/////


typedef void(*FunctionPointer)();
FunctionPointer FunctionPointers[] = { Stuff here };

//////


void func1(){}
 void func2(){}
 void func3(){}

 typedef void (*FP)();


 int main()
 {
     const FP ar[3]= {&func1, &func2, &func3};
 }

}*/


void get_arbre_primaire( list<lexeme> & l, tree<lexeme> & arbre){
	//tree<lexeme> arbre;
	list<lexeme>::const_iterator 
		lit(l.begin()), 
		lend(l.end()),
		previous_lexeme(lit);
	tree<lexeme>::iterator 
		previous_branche, 
		current_branche,
		root;// next, loc, banana;
	previous_branche=arbre.insert(arbre.end(), *lit);


	++lit;
	list<tree<lexeme>::iterator> listroot;
	listroot.push_back(previous_branche);

	recursive_action( l, arbre, lit, lend, previous_lexeme, previous_branche,  current_branche, listroot);

}



void recursive_action ( list<lexeme> & l, tree<lexeme> & arbre, list<lexeme>::const_iterator & lit, list<lexeme>::const_iterator & lend, list<lexeme>::const_iterator & previous_lexeme, tree<lexeme>::iterator & previous_branche, tree<lexeme>::iterator & current_branche, /*tree<lexeme>::iterator & root*/ list<tree<lexeme>::iterator> listroot){

	for(;lit!=lend;++lit,++previous_lexeme){
		//if (*lit=="entity")
		//	arbre.insert(arbre.end(), *lit);
	//	case  if XXXXXXXXXXXXXXXXXXXXXXXXXXxxxxx
//			current=arbre.insert_after(previous, *lit);
//			previous=current;
		if ( ((*lit).getnature()).compare("endprocess")== 0) {

			cout << listroot.size() <<endl;
			previous_branche=*(listroot.begin()); //faire une liste de root

			current_branche=arbre.insert_after(previous_branche, *lit);
			previous_branche=current_branche;


			listroot.pop_back();
			cout << listroot.size() <<endl;
		}

		else if ( ((*previous_lexeme).getnature()).compare("entity")== 0 ) {
			//root=previous_branche;
			listroot.push_back(previous_branche);
			
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			++lit,++previous_lexeme;

			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;


//			current_branche=arbre.append_child(previous_branche, *lit);
//			previous_branche=current_branche;
			//++lit,++previous_lexeme;				
			
		}

/*		else if ( ((*previous_lexeme).getnature()).compare("port")== 0) {
			//root=previous_branche;
			listroot.push_back(previous_branche);

			current_branche=arbre.insert_after(previous_branche, *lit); //append_child
			previous_branche=current_branche;

		}

*/	/*	else if ( ((*previous_lexeme).getnature()).compare("endprocess")== 0) {

			previous_branche=*listroot.end(); //faire une liste de root


			listroot.pop_back();
		}*/

		else { 
			current_branche=arbre.insert_after(previous_branche, *lit);
			previous_branche=current_branche;
		}


		
	
	}//fin du for


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
}*/

/*
string identify_lexeme(const list<lexeme> & l){
list<lexeme>::const_iterator
    lit (l.begin()),
    lend(l.end());     
    string deux;      
    string val;
    for(;lit!=lend;++lit){
      deux=(*lit).getnom();
     //deux= ("test").c_str(); 
     if (deux.compare("entity")== 0)
      { val= "ENTITY";
       return val;}
     else if (deux.compare("port")== 0){
      val= "PORT";  
      return val;}
     else   {
      val= "AUCUN";
      return val;}
    }
      
}*/
