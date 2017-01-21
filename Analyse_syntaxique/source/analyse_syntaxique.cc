//============================================================================
// Author      : MYRIAS
// Version     : v0.5 
// Copyright   : PHELMA
// Description : Module d'analyse syntaxique du projet C
//============================================================================



#include "..\librairie\lexeme.hh"
#include "..\librairie\analyse_syntaxique.hh" //analyse synthaxique
#include "..\librairie\tree.hh"

//#include "lexeme.hh"
//#include "analyse_syntaxique.hh" //analyse synthaxique
//#include "tree.hh"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;
/////////////////////////////// HEADER END /////////////////////////////////////////

/*
#define N 50
#include <string>

using namespace std;

string keywordList[N] = {
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
		cout << "error at specified lexem";		
		(*erreur_lexeme).getposition();
		goto sortie_erreur;
	}
*/ 

/////////////////////////////////////////// GET TREE FUNCTION ////////////////////////////////////
void get_arbre_primaire( list<lexeme> & l, tree<lexeme> & arbre){

	list<lexeme>::iterator  //list iterator
		lit(l.begin()), 
		lend(l.end()),
		previous_lexeme(lit),
		next_lexeme(lit);
		
		++lit;
		next_lexeme=lit; // CARE with this one to not call outside at the end of the list
		--lit;

	l.push_front(lexeme("root_liste",0,0));
		previous_lexeme=l.begin();

//		cout << (*previous_lexeme).getnom() << endl;
//		cout << (*lit).getnom()<< endl;                       // Debog code
//		cout << (*next_lexeme).getnom() << endl;
		

	tree<lexeme>::iterator  // tree iterator
		previous_branche, 
		current_branche,
		root;

	previous_branche=arbre.insert(arbre.end(), lexeme("root_arbre")); // Adding root to tree
	
	list<tree<lexeme>::iterator> listroot;
	listroot.push_front(previous_branche); // tree,  Pile FILO firts in Last Out 

	list<list<lexeme>::iterator> listfilo; // list,  Pile FILO firts in Last Out
//	listfilo.push_front(lit);  // Debog code

	recursive_action( l, arbre, lit, lend, previous_lexeme, previous_branche, current_branche,listroot, listfilo, next_lexeme); // code put in function in prevision of recursivity

//	cout << listroot.size() <<endl; // Debog code
}
////////////////////////////////////////////// END OF GET TREE FUNCTION/////////////////////////////////////////

/////////////////////////////////////////////////// RECURSIVE FUNCTION ////////////////////////////////////////
void recursive_action ( list<lexeme> & l, tree<lexeme> & arbre, list<lexeme>::iterator & lit, list<lexeme>::iterator & lend, list<lexeme>::iterator & previous_lexeme, tree<lexeme>::iterator & previous_branche, tree<lexeme>::iterator & current_branche, list<tree<lexeme>::iterator> & listroot, list<list<lexeme>::iterator> & listfilo, list<lexeme>::iterator & next_lexeme){

	for(;lit!=lend;){  // master  loop

		if ( ((*lit).getnature()).compare("endprocess")== 0) {


			current_branche=arbre.insert_after(previous_branche, *lit);
			previous_branche=*listroot.begin(); // return to saved tree position

			//cout << listroot.size();
			if (listroot.size()==0){
				cout << "erreur il y a un end de trop" << endl;
				goto sortie_erreur;
			}
			else {
				listroot.pop_front();
			}
		}

//////////////////////////////////////// LIBRARY SUB LOOP ///////////////////////////////////////////////////////////
		else if ( ((*lit).getnature()).compare("library")== 0 ) { 
			
			listfilo.push_front(lit); // save list position	
			++lit,++previous_lexeme,++next_lexeme;

			for(;lit!=lend;){    // start verification loop

				if ( ((*lit).getnature()).compare("endligne")== 0) {  //authorized lexeme

					
					if ( ((*next_lexeme).getnature()).compare("use")!=0 ){   // test exit
					//	cout << (*next_lexeme).getnom()<< endl;
						lit=*listfilo.begin(); // return to saved list position
//						cout << (*previous_lexeme).getnom()<< endl;
//						cout << (*lit).getnom()<< endl;
						previous_lexeme=(--(lit));
//						cout << (*lit).getnom()<< endl;
						++lit;
//						cout << (*lit).getnom()<< endl;
//						cout << (*previous_lexeme).getnom()<< endl;

						listfilo.pop_front(); // delete used saved position
						cout << "Library checked"<< endl;
						goto arbriser_library; // exit loop
					}

					else if ( ((*previous_lexeme).getnature()).compare("id")== 0){ //authorized previous lexeme
						++lit,++previous_lexeme,++next_lexeme; 
					}

					else if ( ((*previous_lexeme).getnature()).compare("all")== 0){
						++lit,++previous_lexeme,++next_lexeme; 
					}

					else {    // unauthorized previous lexeme
						cout << "error at specified lexem";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
				}	


				else if ( ((*lit).getnature()).compare("use")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem";  // Debog code << "A";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}
				else if ( ((*lit).getnature()).compare("id")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("library")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("use")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("point")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else { 
						cout << "error at specified lexem";  // Debog code << "B" << (*previous_lexeme).getnature() <<(*lit).getnom();		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("all")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("point")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem"<< "C";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}
				else if ( ((*lit).getnature()).compare("point")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("id")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

						
				else { //  unauthorized lexeme
					cout << "error at specified lexem";// << "E";		
					(*lit).getposition();
					goto sortie_erreur;
				}

				
			} // END OF VERIFICATION
			
// Debog code	cout << "NE DOIT PAS SORTIR ICI"<< endl;
			
			arbriser_library:;	
	//	cout << (*lit).getnom()<< endl;

			current_branche=arbre.append_child(previous_branche, *lit); //Lexem is LIBRARY 
			previous_branche=current_branche;
			++lit,++previous_lexeme,++next_lexeme;

			current_branche=arbre.append_child(previous_branche, *lit); //Lexem is  LIBRARY's name
			previous_branche=current_branche;
			string library_name=(*lit).getnom(); //Saving the name for checking with use
			listroot.push_front(current_branche); // Saving tree position
			++lit,++previous_lexeme,++next_lexeme;		
			
			++lit,++previous_lexeme,++next_lexeme;
			
			for(;lit!=lend;){    // start construction loop
				if ( ((*lit).getnature()).compare("use")== 0) {  //authorized lexeme
					++lit,++previous_lexeme,++next_lexeme;
					
					if ( ((*lit).getnom()).compare(library_name)== 0) {
						cout << "used library name checked"<< endl;
						
						++lit,++previous_lexeme,++next_lexeme;
						++lit,++previous_lexeme,++next_lexeme;
						
						current_branche=arbre.append_child(previous_branche, *lit); //Lexem is LIBRARY 
						previous_branche=current_branche;
						++lit,++previous_lexeme,++next_lexeme;
						++lit,++previous_lexeme,++next_lexeme;
						
						current_branche=arbre.append_child(previous_branche, *lit); //Lexem is LIBRARY 
						previous_branche=current_branche;
						++lit,++previous_lexeme,++next_lexeme;
						++lit,++previous_lexeme,++next_lexeme;
							
						previous_branche=*listroot.begin(); // return to saved tree position
					}
					
					else {
						cout << "error on used library name";// << "E";		
						(*lit).getposition();
						goto sortie_erreur;
					}
					
					
				}
				else {
					listroot.pop_front();	// delete used save position
					
					previous_branche=*listroot.begin(); //  return to saved tree position -> suposed to be root_tree
					
					break;
				}
			}

		finlibrairy:;
		cout << "Library tree constructed"<< endl; 	
		} 
///////////////////////////////////////////////// END LIBRARY SUB LOOP /////////////////////////////////////////////////

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
			++lit,++previous_lexeme,++next_lexeme;
		}
		
	
	}//END OF MASTER LOOP
	
	// ERROR EXIT
goto saut_erreur;

sortie_erreur:;

arbre.erase_children(arbre.begin());

saut_erreur:;
	// EXIT
}
///////////////////////////////////// END OF RECURCIVE FUNCTION ///////////////////////////////////////////////


