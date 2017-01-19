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

using namespace std;

#define N 50
#include <string>

using namespace std;

/*string keywordList[N] = {
	"library",
	"use",
	"all",	
	"entity",
	"is",
	"port",
	"in",
	"out",
	"downto",
	"upto",
	"end",
 	"architecture",
	"of",
	"signal",
	"variable",
	"begin",
	"process",
	"case",
	"when",
	"others",
	"if",
	"then",
	"else",
	"elsif"	
};*/

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

/*void sortie_erreur(list<lexeme>::const_iterator & erreur_lexeme){ //ca ne veut pas compiler , le goto dans une autre fonction ne fonctionne pas et une erreur de const sur lexeme
		cout << "erreur au lexeme suivant";		
		(*erreur_lexeme).getposition();
		goto sortie_erreur;
	}
*/ 


void get_arbre_primaire( list<lexeme> & l, tree<lexeme> & arbre){

	list<lexeme>::iterator  //itérateur sur liste
		lit(l.begin()), 
		lend(l.end()),
		previous_lexeme(lit);
		

	l.push_front(lexeme("root_liste",1,1));
		previous_lexeme=l.begin();

//		cout << (*lit).getnom()<< endl;
//		cout << (*previous_lexeme).getnom() << endl;
		

	tree<lexeme>::iterator  //itérateur sur l'arbre
		previous_branche, 
		current_branche,
		root;

	previous_branche=arbre.insert(arbre.end(), lexeme("root_arbre")); // creation de la racine de l'arbre

	list<tree<lexeme>::iterator> listroot;
	listroot.push_front(previous_branche); // Pile FILO firts in Last Out pour l'arbre

	list<list<lexeme>::iterator> listfilo; // Pile FILO firts in Last Out pour la liste
//	listfilo.push_front(lit);

	recursive_action( l, arbre, lit, lend, previous_lexeme, previous_branche, current_branche,listroot, listfilo);//mise en fonction du contenue pour recursivité possible

//	cout << listroot.size() <<endl;
}

void recursive_action ( list<lexeme> & l, tree<lexeme> & arbre, list<lexeme>::iterator & lit, list<lexeme>::iterator & lend, list<lexeme>::iterator & previous_lexeme, tree<lexeme>::iterator & previous_branche, tree<lexeme>::iterator & current_branche, list<tree<lexeme>::iterator> & listroot, list<list<lexeme>::iterator> & listfilo){

	for(;lit!=lend;++lit,++previous_lexeme){

		if ( ((*lit).getnature()).compare("endprocess")== 0) {

			//previous_branche=*(listroot.end()); //faire une liste de root

			current_branche=arbre.insert_after(previous_branche, *lit);
			previous_branche=*listroot.begin();

			//cout << listroot.size();
			if (listroot.size()==0){
				cout << "erreur il y a un end de trop" << endl;
				goto sortie_erreur;
			}
			else {
				listroot.pop_front();
			}
		}

		else if ( ((*lit).getnature()).compare("library")== 0 ) { // SOUS ARBRE
			
			listfilo.push_front(lit); // sauvegarde de l'emplacement courrant (itérateur) dans listfilo, un point de sauvegarde		
			++lit,++previous_lexeme;

			for(;lit!=lend;){//debut de la verification
				
				if ( ((*lit).getnom()).compare(";")== 0) {

					if ( ((*(++lit)).getnature()).compare("use")== 1){// test de la sortie
						--lit;

						lit=*listfilo.begin(); // recharge du dernier point d'encrage pour remonter dans la liste
						previous_lexeme=(--(lit));
						++lit;

						listfilo.pop_front();
						goto arbriser_library;
					}

					else if ( ((*previous_lexeme).getnature()).compare("id")== 0){
						--lit;
						++lit,++previous_lexeme;
					}

					else if ( ((*previous_lexeme).getnature()).compare("all")== 0){
						--lit;
						++lit,++previous_lexeme;
					}

					else {
						cout << "erreur au lexeme suivant";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
				}	

					//tous les lexemes possible dans ce sous arbre
				else if ( ((*lit).getnature()).compare("use")== 0) { 
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						++lit,++previous_lexeme;
					}
					else {
						cout << "erreur au lexeme suivant"<< "A";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}
				else if ( ((*lit).getnature()).compare("id")== 0) { 
					if (((*previous_lexeme).getnature()).compare("library")== 0){
						++lit,++previous_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("use")== 0){
						++lit,++previous_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("point")== 0){
						++lit,++previous_lexeme;
					}

					else { //////////////////ERREUR ICI
						cout << "erreur au lexeme suivant"<< "B" << (*previous_lexeme).getnature() <<(*lit).getnom();		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("all")== 0) { 
					if (((*previous_lexeme).getnature()).compare("point")== 0){
						++lit,++previous_lexeme;
					}
					else {
						cout << "erreur au lexeme suivant"<< "C";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}
				else if ( ((*lit).getnature()).compare("point")== 0) { 
					if (((*previous_lexeme).getnature()).compare("id")== 0){
						++lit,++previous_lexeme;
					}

					else {
						cout << "erreur au lexeme suivant"<< "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

						//else if { } // autre lexeme possible
						
				else { // un lexeme qui n'est pas autorisé dans cette sous branche
					cout << "erreur au lexeme suivant" << "E";		
					(*lit).getposition();
					goto sortie_erreur;
				}

				
			} // fin du FOR de vérification
		arbriser_library:;

			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			++lit,++previous_lexeme;

			listroot.push_front(current_branche);

			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			++lit,++previous_lexeme;		

		finlibrairy:;	
		} // fin du else if librairy

//////////////////////////////////////////////////////////////////////////////////////////////dessous des exemples
/*		else if ( ((*lit).getnature()).compare("use")== 0 ) {
			
		}

		else if ( ((*lit).getnature()).compare("entity")== 0 ) {
			else if ( ((*lit).getnature()).compare("port")== 0 ) {
				
			}
		}

		else if ( ((*lit).getnature()).compare("architecture")== 0 ) {

			else if ( ((*lit).getnature()).compare("component")== 0 ) {
				else if ( ((*lit).getnature()).compare("port")== 0 ) {
					//EMPLACEMENT pour declaration du composant
				}
			}

			else if ( ((*lit).getnature()).compare("begin")== 0 ) {
				else if ( ((*lit).getnature()).compare("port")== 0 ) {
					//EMPLACEMENT POUR instanciation explicite du composant
				}
			}
		}


///////////////////////////////////////////////// en dessous comment se deplacer ter faire l'arbre

		else if ( ((*lit).getnature()).compare("entity")== 0 ) {
			



			current_branche=arbre.insert_after(previous_branche, *lit); // insertion du lexeme en frere et sauvegarde de l'emplacement courrant dans l'arbre dans current_branche

			listroot.push_front(current_branche); // sauvegarde de l'emplacement courrant (itérateur) dans listroot, un point d'ancrage

			previous_branche=current_branche; // avance manuelle itération : 
			++lit,++previous_lexeme; // avance manuelle itération

			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			
			++lit,++previous_lexeme;
			
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;


//			current_branche=arbre.append_child(previous_branche, *lit);
//			previous_branche=current_branche;
			//++lit,++previous_lexeme;				
			
		}

		else if ( ((*lit).getnature()).compare("port")== 0) {

			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			++lit,++previous_lexeme;
				
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			++lit,++previous_lexeme;
				

			cout << ((*lit).getnom());
			listroot.push_front(current_branche);
			
			
			for(;lit!=lend;){
				for(;lit!=lend;){
				

	//			break;
					if ( ((*lit).getnom()).compare(";")== 0) {
						current_branche=arbre.append_child(previous_branche, *lit);
						previous_branche=current_branche;
						++lit,++previous_lexeme;
						
						previous_branche=*listroot.begin(); // rechage du dernier point d'encrage pour remonter dans l'arborescence
						//listroot.pop_front();
						break;
					}
					else if ( ((*lit).getnom()).compare(")")== 0) {
						
						current_branche=arbre.append_child(previous_branche, *lit);
						previous_branche=current_branche;
						++lit,++previous_lexeme;
						
						current_branche=arbre.append_child(previous_branche, *lit);
						previous_branche=current_branche;
							
											
						previous_branche=*listroot.begin();
						listroot.pop_front();
						goto stop;
					} 	
					else {
						current_branche=arbre.append_child(previous_branche, *lit);
						previous_branche=current_branche;
						++lit,++previous_lexeme;
					}		
				}		
				
			}
			stop:;
//			cout << "fin";
//			break;
		}
		

		else if ( ((*lit).getnature()).compare("architecture")== 0) {
			current_branche=arbre.insert_after(previous_branche, *lit);

			listroot.push_front(current_branche);

			previous_branche=current_branche;
			
			++lit,++previous_lexeme;
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			
			++lit,++previous_lexeme;	
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			
			++lit,++previous_lexeme;	
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			
			++lit,++previous_lexeme;	
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
			
			++lit,++previous_lexeme;	
			current_branche=arbre.append_child(previous_branche, *lit);
			previous_branche=current_branche;
		}

*/

		else { 
			current_branche=arbre.insert_after(previous_branche, *lit);
			previous_branche=current_branche;
		}
		
	
	}//fin du for GENERAL
goto saut_erreur;

sortie_erreur:;

arbre.erase_children(arbre.begin());

saut_erreur:;
	//return arbre;
}



