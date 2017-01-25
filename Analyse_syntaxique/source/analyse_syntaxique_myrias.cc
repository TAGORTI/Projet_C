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

/////////////////////////////////////////// PROCESS PROTOCOL /////////////////////////////////////////
bool archi_begin_process_protocol (list<lexeme> & l, tree<lexeme> & arbre, list<lexeme>::iterator & lit, list<lexeme>::iterator & lend, list<lexeme>::iterator & previous_lexeme, tree<lexeme>::iterator & previous_branche, tree<lexeme>::iterator & current_branche, list<tree<lexeme>::iterator> & listroot, list<list<lexeme>::iterator> & listfilo, list<lexeme>::iterator & next_lexeme, string architecture_name){
	bool error_bit=0;
	
			string process_name=(*lit).getnom(); //Saving the name for checking
//			listfilo.push_front(lit); // save list position	
			
			current_branche=arbre.append_child(previous_branche, *(++next_lexeme); //Lexem is process
			--next_lexeme;
			previous_branche=current_branche;
			listroot.push_front(current_branche);
			
			current_branche=arbre.append_child(previous_branche, *(lit); //Lexem is process's name
			previous_branche=*listroot.begin();
			//previous_branche=*listroot.begin();

			++lit,++previous_lexeme,++next_lexeme;
			// ICI on est au deux points
			
			// VERIFIER LA LISTE DE SENSIBILITE  puis BEGIN et instructions sequentielles 4 cas.
			
			for(;lit!=lend;){

				if ( ((*lit).getnature()).compare("endligne")== 0) {  //authorized lexeme and test exit

					
					if ( ((*previous_lexeme).getnom()).compare(process_name)==0 and ((*previous_lexeme).getnature()).compare("id")==0 and ((*(--previous_lexeme)).getnature()).compare("process")==0  and ((*(--previous_lexeme)).getnature()).compare("endprocess")==0 ){   
					// test exit
						++previous_lexeme; ++previous_lexeme; // compensate the iteration done in the condition
					//	cout << (*next_lexeme).getnom()<< endl;
//						lit=*listfilo.begin(); // return to saved list position
//						previous_lexeme=(--(lit));
//						++lit;
//						next_lexeme= (++(lit));
//						--lit;
//						cout << (*lit).getnom()<< endl;
//						cout << (*previous_lexeme).getnom()<< endl;

//						listfilo.pop_front(); // delete used saved position
						listroot.pop_front(); // delete process position
						previous_branche=*listroot.begin();// supposed to return to architecture
						
						cout << "Protocol checked"<< endl;
						goto fin_protocol; // exit loop
						
					}

					else {    // unauthorized previous lexeme
						cout << "error at specified lexem";		
						(*previous_lexeme).getposition();
						error_bit=1;
						goto sortie_erreur_protocol;
					}
				}	
				
				else if ( ((*lit).getnature()).compare("id")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("endprocess")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}					
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						error_bit=1;
						goto sortie_erreur_protocol;
					}
							
				}
				
				else { //  unauthorized lexeme
					cout << "error at specified lexem";// << "E";		
					(*lit).getposition();
					error_bit=1;
					goto sortie_erreur_protocol;
				}
			}
			fin_protocol:;
					////////////////////////////////// TREE IS CONSTRUCTED DURING VERIFICATION ////////////////////////////////////
			sortie_erreur_protocol:;
			if (error_bit==1){
				return 1;
			}
			else {return 0;
			}
			
}
///////////////////////////////////////////// END PROCESS PROTOCOL /////////////////////////////////////

//////////////////////////////////////////// ARCHITECTURE BEGIN PROTOCOL /////////////////////////////////////
bool archi_begin_protocol (list<lexeme> & l, tree<lexeme> & arbre, list<lexeme>::iterator & lit, list<lexeme>::iterator & lend, list<lexeme>::iterator & previous_lexeme, tree<lexeme>::iterator & previous_branche, tree<lexeme>::iterator & current_branche, list<tree<lexeme>::iterator> & listroot, list<list<lexeme>::iterator> & listfilo, list<lexeme>::iterator & next_lexeme, string architecture_name){
	bool error_bit=0;
	
//			listfilo.push_front(lit); // save list position	
			++lit,++previous_lexeme,++next_lexeme;
			
			for(;lit!=lend;){

				if ( ((*lit).getnature()).compare("endligne")== 0) {  //authorized lexeme and test exit

					
					if ( ((*previous_lexeme).getnom()).compare(architecture_name)==0 and ((*previous_lexeme).getnature()).compare("id")==0 and ((*(--previous_lexeme)).getnature()).compare("endprocess")==0  ){   // test exit
						++previous_lexeme; // compensate the iteration done in the condition
					//	cout << (*next_lexeme).getnom()<< endl;
//						lit=*listfilo.begin(); // return to saved list position
//						previous_lexeme=(--(lit));
//						++lit;
//						next_lexeme= (++(lit));
//						--lit;
//						cout << (*lit).getnom()<< endl;
//						cout << (*previous_lexeme).getnom()<< endl;

//						listfilo.pop_front(); // delete used saved position
						cout << "Architecture checked & constructed"<< endl;
						listroot.pop_front(); // supposed to delete architecture save point as it is here ended
						previous_branche=*listroot.begin(); // supposed to be root tree (and open for a new architecture declaration)
						
						goto fin_archi_begin; // exit loop
						
					}

					else {    // unauthorized previous lexeme
						cout << "error at specified lexem";		
						(*previous_lexeme).getposition();
						error_bit=1;
						goto sortie_erreur_archi_begin;
					}
				}	
				
				else if ( ((*lit).getnature()).compare("id")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("endprocess")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}					
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						error_bit=1;
						goto sortie_erreur_archi_begin;
					}
							
				}
				
				else if ( ((*lit).getnature()).compare("endprocess")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("is")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						error_bit=1;
						goto sortie_erreur_archi_begin;
					}
							
				}
				


				else if ( ((*lit).getnature()).compare("id")== 0 and ((*next_lexeme).getnature()).compare("deux_points")== 0 and ((*(++next_lexeme)).getnature()).compare("process")== 0) { 
				//authorized lexeme PROCESS
					--next_lexeme; // compensate the iteration done in the condition
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						
						error_bit=archi_begin_process_protocol( l, arbre, lit, lend, previous_lexeme, previous_branche, current_branche,listroot, listfilo, next_lexeme, architecture_name);///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						
						if (error_bit==1) {
							goto sortie_erreur_archi_begin;	
						}
						else {
							++lit,++previous_lexeme,++next_lexeme; 
						}
					}
					
					else if (((*previous_lexeme).getnature()).compare("begin")== 0){
						
						error_bit=archi_begin_process_protocol( l, arbre, lit, lend, previous_lexeme, previous_branche, current_branche,listroot, listfilo, next_lexeme, architecture_name);;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						
						if (error_bit==1) {
							goto sortie_erreur_archi_begin;	
						}
						else {
							++lit,++previous_lexeme,++next_lexeme; 
						}
					}
					
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						error_bit=1;
						goto sortie_erreur_archi_begin;
					}
							
				}
				
				else if ( ((*lit).getnature()).compare("id")== 0 and ((*next_lexeme).getnature()).compare("assignation")== 0) { 
				//authorized lexeme Affectation Concurrente de signal BONUS
					//////////////// A FAIRE BONUS ///////////////////////////////
/*					if (((*previous_lexeme).getnature()).compare("endprocess")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else if (((*previous_lexeme).getnature()).compare("of")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
*/					++lit,++previous_lexeme,++next_lexeme;		
				}

				else if ( ((*lit).getnature()).compare("id")== 0 and ((*next_lexeme).getnature()).compare("deux_points")== 0 and ((*(++next_lexeme)).getnature()).compare("id")== 0) { 
				//authorized lexeme Instantiation explicite de composant
				--next_lexeme; // compensate the iteration done in the condition
				///////////////// A FAIRE
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else if (((*previous_lexeme).getnature()).compare("begin")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						error_bit=1;
						goto sortie_erreur_archi_begin;
					}
							
				}
				
				else { //  unauthorized lexeme
					cout << "error at specified lexem";// << "E";		
					(*lit).getposition();
					error_bit=1;
					goto sortie_erreur_archi_begin;
				}
		
			}
	
			fin_archi_begin:;
			
			////////////////////////////////// TREE IS CONSTRUCTED DURING VERIFICATION ////////////////////////////////////
			
			sortie_erreur_archi_begin:;
			if (error_bit==1){
				return 1;
			}
			else {return 0;
			}
}

/////////////////////////////////////////// END OF ARCHITECTURE BEGIN PROTOCOL /////////////////////////////////////////

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

//////////////////////////////////////// LIBRARY PROTOCOL ///////////////////////////////////////////////////////////
		if ( ((*lit).getnature()).compare("library")== 0 ) { 
			
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
						next_lexeme= (++(lit));
						--lit;
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

				
			} // END OF VERIFICATION LOOP
			
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
			} // END OF CONSTRUCTION LOOP

		finlibrairy:;
		cout << "Library tree constructed"<< endl; 	
		} 
///////////////////////////////////////////////// END LIBRARY PROTOCOL /////////////////////////////////////////////////

//////////////////////////////////////////////// ENTITY PROTOCOL /////////////////////////////////////////////////
		else if ( ((*lit).getnature()).compare("entity")== 0 ) { 
			
			listfilo.push_front(lit); // save list position	
			++lit,++previous_lexeme,++next_lexeme;
			string entity_name=(*lit).getnom(); //Saving the name for checking
			int parenthese_count = 0;

			for(;lit!=lend;){    // start verification loop

				if ( ((*lit).getnature()).compare("endligne")== 0) {  //authorized lexeme

					
					if ( ((*previous_lexeme).getnom()).compare(entity_name)==0 and ((*previous_lexeme).getnature()).compare("id")==0 and ((*(--previous_lexeme)).getnature()).compare("endprocess")==0  ){   // test exit
						++previous_lexeme; // compensate iteration done in the condition
					//	cout << (*next_lexeme).getnom()<< endl;
						lit=*listfilo.begin(); // return to saved list position
						previous_lexeme=(--(lit));
						++lit;
						next_lexeme= (++(lit));
						--lit;
//						cout << (*lit).getnom()<< endl;
//						cout << (*previous_lexeme).getnom()<< endl;

						listfilo.pop_front(); // delete used saved position
						if (parenthese_count==0){
							cout << "Entity checked"<< endl;
							goto arbriser_entity; // exit loop
						}
						else {
							cout << "error of number of parenthese in ENTITY definition "  << parenthese_count;	
							goto sortie_erreur;
						}
					}

					else if ( ((*previous_lexeme).getnature()).compare("std_logic")== 0){ //authorized previous lexeme
						++lit,++previous_lexeme,++next_lexeme; 
					}

					else if ( ((*previous_lexeme).getnature()).compare("parenthese_fermante")== 0){
						++lit,++previous_lexeme,++next_lexeme; 
					}

					else {    // unauthorized previous lexeme
						cout << "error at specified lexem";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
				}	


				else if ( ((*lit).getnature()).compare("is")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("id")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem";  // Debog code << "A";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("virgule")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("id")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem";  // Debog code << "A";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}		
				}

				else if ( ((*lit).getnature()).compare("id")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("entity")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("parenthese_ouvrante")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}   
					
					else if (((*previous_lexeme).getnature()).compare("virgule")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					} 
					
					else if (((*previous_lexeme).getnature()).compare("endprocess")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					} 
					else { 
						cout << "error at specified lexem";  // Debog code << "B" << (*previous_lexeme).getnature() <<(*lit).getnom();		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("deux_points")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("id")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem";//<< "C";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}
				else if ( ((*lit).getnature()).compare("port")== 0) { //authorized lexeme 
					if ((((*previous_lexeme).getnature()).compare("is")== 0) and ((((*next_lexeme).getnature()).compare("parenthese_ouvrante")== 0))){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}

				else if ( ((*lit).getnature()).compare("parenthese_ouvrante")== 0) { //authorized lexeme 
					
					if (((*previous_lexeme).getnature()).compare("port")== 0){
						++lit,++previous_lexeme,++next_lexeme;++parenthese_count;
					}
					
					
					else if (((*previous_lexeme).getnature()).compare("std_logic_vector")== 0){
						++lit,++previous_lexeme,++next_lexeme;++parenthese_count;
					}					

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}
					
				else if ( ((*lit).getnature()).compare("parenthese_fermante")== 0) { //authorized lexeme 
					
					if (((*previous_lexeme).getnature()).compare("chiffre")== 0){
						++lit,++previous_lexeme,++next_lexeme;--parenthese_count;
					}
					
					else if (((*previous_lexeme).getnature()).compare("std_logic")== 0){
						++lit,++previous_lexeme,++next_lexeme;--parenthese_count;
					}
					
					else if (((*previous_lexeme).getnature()).compare("parenthese_fermante")== 0){
						++lit,++previous_lexeme,++next_lexeme;--parenthese_count;
					}					
					else if (((*previous_lexeme).getnature()).compare("nombre")== 0){
						++lit,++previous_lexeme,++next_lexeme;--parenthese_count;
					}
					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}		
				}
				
				else if ( ((*lit).getnature()).compare("std_logic")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("in")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else if (((*previous_lexeme).getnature()).compare("out")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}					
					else if (((*previous_lexeme).getnature()).compare("inout")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else if (((*previous_lexeme).getnature()).compare("buffer")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("linkage")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}				

				else if ( ((*lit).getnature()).compare("std_logic_vector")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("in")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else if (((*previous_lexeme).getnature()).compare("out")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}					
					else if (((*previous_lexeme).getnature()).compare("inout")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else if (((*previous_lexeme).getnature()).compare("buffer")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else if (((*previous_lexeme).getnature()).compare("linkage")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}
				
				else if ( ((*lit).getnature()).compare("in")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("deux_points")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
					goto sortie_erreur;
					}			
				}

				else if ( ((*lit).getnature()).compare("out")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("deux_points")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}

				else if ( ((*lit).getnature()).compare("inout")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("deux_points")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}

				else if ( ((*lit).getnature()).compare("buffer")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("deux_points")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}

				else if ( ((*lit).getnature()).compare("linkage")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("deux_points")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}

				else if ( ((*lit).getnature()).compare("chiffre")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("parenthese_ouvrante")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else if (((*previous_lexeme).getnature()).compare("downto")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else if (((*previous_lexeme).getnature()).compare("to")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}


					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}

				else if ( ((*lit).getnature()).compare("nombre")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("parenthese_ouvrante")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else if (((*previous_lexeme).getnature()).compare("downto")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else if (((*previous_lexeme).getnature()).compare("to")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}


					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}
				
				else if ( ((*lit).getnature()).compare("to")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("chiffre")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else if (((*previous_lexeme).getnature()).compare("nombre")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}
				
				else if ( ((*lit).getnature()).compare("downto")== 0) { //authorized lexeme 
					if (((*previous_lexeme).getnature()).compare("chiffre")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else if (((*previous_lexeme).getnature()).compare("nombre")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}

					else {
						cout << "error at specified lexem";  // Debog code << "D";		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}			
				}
				
				else if ( ((*lit).getnature()).compare("endprocess")== 0) { //authorized lexeme 
					if ((((*previous_lexeme).getnature()).compare("endligne")== 0) and ((((*next_lexeme).getnom()).compare(entity_name)== 0))){
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
				
			} // END OF VERIFICATION LOOP
			arbriser_entity:;
			
					
			current_branche=arbre.append_child(previous_branche, *lit); //Lexem is ENTITY
			previous_branche=current_branche;
			++lit,++previous_lexeme,++next_lexeme;
			
			current_branche=arbre.append_child(previous_branche, *lit); //Lexem is ENTITY's name
			previous_branche=current_branche;
			++lit,++previous_lexeme,++next_lexeme;
			
			++lit,++previous_lexeme,++next_lexeme;
			
			current_branche=arbre.append_child(previous_branche, *lit); //Lexem is PORT
			previous_branche=current_branche;
			listroot.push_front(current_branche); // Saving tree position
			++lit,++previous_lexeme,++next_lexeme;
			
			++lit,++previous_lexeme,++next_lexeme;
			/// ici on est au premier identifiant
			
			for(;lit!=lend;){ 
				if (( ((*lit).getnature()).compare("id")== 0) and ( ((*lit).getnom()).compare(entity_name)!= 0)){
					listfilo.push_front(lit);
					
					current_branche=arbre.append_child(previous_branche, *lit); 
					previous_branche=current_branche;
					
					while ( ((*lit).getnature()).compare("deux_points")!= 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					++lit,++previous_lexeme,++next_lexeme;
					
					current_branche=arbre.append_child(previous_branche, *lit); 
					previous_branche=current_branche;
					++lit,++previous_lexeme,++next_lexeme;
					
					if ( ((*lit).getnature()).compare("std_logic")== 0){
						current_branche=arbre.append_child(previous_branche, *lit); 
						previous_branche=*listroot.begin();
						
						lit=*listfilo.begin(); // return to saved list position
						previous_lexeme=(--(lit));
						++lit;
						next_lexeme= (++(lit));
						--lit;
						
						++lit,++previous_lexeme,++next_lexeme;
						++lit,++previous_lexeme,++next_lexeme;
						
						listfilo.pop_front(); // delete used saved position
						cout << "Port checked"<< endl;
						
					}
					else if ( ((*lit).getnature()).compare("std_logic_vector")== 0){
						current_branche=arbre.append_child(previous_branche, *lit); 
						previous_branche=current_branche;
						++lit,++previous_lexeme,++next_lexeme;
						
						++lit,++previous_lexeme,++next_lexeme;
						
						current_branche=arbre.append_child(previous_branche, *lit); 
						previous_branche=current_branche;
						++lit,++previous_lexeme,++next_lexeme;
						
						current_branche=arbre.append_child(previous_branche, *lit); 
						previous_branche=current_branche;
						++lit,++previous_lexeme,++next_lexeme;
						
						current_branche=arbre.append_child(previous_branche, *lit); 
						previous_branche=*listroot.begin();
						
						lit=*listfilo.begin(); // return to saved list position
						previous_lexeme=(--(lit));
						++lit;
						next_lexeme= (++(lit));
						--lit;
						
						++lit,++previous_lexeme,++next_lexeme;
						++lit,++previous_lexeme,++next_lexeme;
						
						listfilo.pop_front(); // delete used saved position
						cout << "Port checked"<< endl;
						
						
						
					}
					
					else {
						cout << "error unknow data type at";// << "E";		
						(*lit).getposition();
						goto sortie_erreur;
					}
					
				}
				else if (( ((*lit).getnature()).compare("id")== 0) and ( ((*lit).getnom()).compare(entity_name)== 0)) {
					listroot.pop_front();	// delete used save position
					
					previous_branche=*listroot.begin(); //  return to saved tree position -> suposed to be root_tree
					//cout << (*previous_branche).getnom(); // use to confime tree position
					++lit,++previous_lexeme,++next_lexeme;
					++lit,++previous_lexeme,++next_lexeme;
					break;
				}
				
				else {
					++lit,++previous_lexeme,++next_lexeme;
				}
			}// END OF CONSTRUCTION LOOP

		finentity:;
		cout << "Entity tree constructed"<< endl; 	
		
		
//		cout << (*previous_branche).getnom();
		} 

//////////////////////////////////////////////// END ENTITY PROTOCOL /////////////////////////////////////////////////

//////////////////////////////////////////////////// ARCHITECTURE PROTOCOL ///////////////////////////////////////////

		else if ( ((*lit).getnature()).compare("architecture")== 0 ) { 
		
			bool error_bit=0;
			
			listfilo.push_front(lit); // save list position	
			
			current_branche=arbre.append_child(previous_branche, *lit); //Lexem is ARCHITECTURE
			previous_branche=current_branche;
			listroot.push_front(current_branche);
			//cout << (*current_branche).getnom();
			
			++lit,++previous_lexeme,++next_lexeme;
			string architecture_name=(*lit).getnom(); //Saving the name for checking
//			int parenthese_count = 0;
			current_branche=arbre.append_child(previous_branche, *lit); //Lexem is architecture name
			previous_branche=current_branche;

			++next_lexeme;
			string entity_name=(*next_lexeme).getnom();
			
			current_branche=arbre.append_child(previous_branche, *next_lexeme); //Lexem is entity name
			previous_branche=*listroot.begin();
			
			--next_lexeme;
			int archi_begin_count = 0;

			for(;lit!=lend;){  
			
//				if ( ((*lit).getnature()).compare("endligne")== 0) {  //authorized lexeme // Took into acount in the archi_begin_protocol
//
//					
//					if ( ((*previous_lexeme).getnom()).compare(architecture_name)==0 and ((*previous_lexeme).getnature()).compare("id")==0 and ((*(--previous_lexeme)).getnature()).compare("endprocess")==0  ){   // test exit
//						++previous_lexeme; // compensate the iteration done in the condition
//					//	cout << (*next_lexeme).getnom()<< endl;
//						lit=*listfilo.begin(); // return to saved list position
//						previous_lexeme=(--(lit));
//						++lit;
//						next_lexeme= (++(lit));
//						--lit;
//						cout << (*lit).getnom()<< endl;
//						cout << (*previous_lexeme).getnom()<< endl;
//
//						listfilo.pop_front(); // delete used saved position
//						if (parenthese_count==0){
//							cout << "Architecture checked"<< endl;
//							goto arbriser_architecture; // exit loop
//						}
//						else {
//							cout << "error of number of parenthese in ENTITY definition "  << parenthese_count;	
//							goto sortie_erreur;
//						}
//					}
//
//					else {    // unauthorized previous lexeme
//						cout << "error at specified lexem";		
//						(*previous_lexeme).getposition();
//						goto sortie_erreur;
//					}
//				}	
//

				if ( ((*lit).getnature()).compare("id")== 0) { //authorized lexeme
//					if (((*previous_lexeme).getnature()).compare("endprocess")== 0){   // Took into acount in the archi_begin_protocol
//						++lit,++previous_lexeme,++next_lexeme;
//					}
					
					if (((*previous_lexeme).getnature()).compare("architecture")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else if (((*previous_lexeme).getnature()).compare("of")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}
				
//				else if ( ((*lit).getnature()).compare("endprocess")== 0) { //authorized lexeme // Took into acount in the archi_begin_protocol
//					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
//						++lit,++previous_lexeme,++next_lexeme;
//					}
//					else if (((*previous_lexeme).getnature()).compare("is")== 0){
//						++lit,++previous_lexeme,++next_lexeme;
//					}
//					else {
//						cout << "error at specified lexem"; 		
//						(*previous_lexeme).getposition();
//						goto sortie_erreur;
//					}
//							
//				}
//
				else if ( ((*lit).getnature()).compare("is")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("id")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("of")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("id")== 0){
						++lit,++previous_lexeme,++next_lexeme;
					}
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("type")== 0) { //authorized lexeme
				//////////////INTERIEUR A FAIRE    PARTIR DANS UNE FONCTION
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						error_bit=0;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						++lit,++previous_lexeme,++next_lexeme;
						if (error_bit==1) {
//							cout << "error at specified lexem"; // Took into acount in the function		
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
						
					}
					else if (((*previous_lexeme).getnature()).compare("is")== 0){
						error_bit=0;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						++lit,++previous_lexeme,++next_lexeme;
						if (error_bit==1) {
//							cout << "error at specified lexem"; 	// Took into acount in the function	
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
					}
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("signal")== 0) { //authorized lexeme
				//////////////INTERIEUR A FAIRE    PARTIR DANS UNE FONCTION
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						error_bit=0;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						++lit,++previous_lexeme,++next_lexeme;
						if (error_bit==1) {
//							cout << "error at specified lexem"; 	// Took into acount in the function
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
					}
					else if (((*previous_lexeme).getnature()).compare("is")== 0){
						error_bit=0;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						++lit,++previous_lexeme,++next_lexeme;
						if (error_bit==1) {
//							cout << "error at specified lexem"; // Took into acount in the function	
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
					}
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("component")== 0) { //authorized lexeme
				//////////////INTERIEUR A FAIRE    PARTIR DANS UNE FONCTION
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						error_bit=0;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						++lit,++previous_lexeme,++next_lexeme;
						if (error_bit==1) {
//							cout << "error at specified lexem"; 		// Took into acount in the function
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
					}
					else if (((*previous_lexeme).getnature()).compare("is")== 0){
						error_bit=0;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						++lit,++previous_lexeme,++next_lexeme;
						if (error_bit==1) {
//							cout << "error at specified lexem"; // Took into acount in the function	
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
					}
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}

				else if ( ((*lit).getnature()).compare("begin")== 0) { //authorized lexeme
					if (((*previous_lexeme).getnature()).compare("endligne")== 0){
						++archi_begin_count;
						error_bit=archi_begin_protocol( l, arbre, lit, lend, previous_lexeme, previous_branche, current_branche,listroot, listfilo, next_lexeme, architecture_name);;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						// here lit should be equal lend;
//						++lit,++previous_lexeme,++next_lexeme; 
						if (error_bit==1) {
//							cout << "error at specified lexem"; // Took into acount in the archi_begin_protocol		
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
						else {
//							cout << "Architecture checked"<< endl; // Took into acount in the archi_begin_protocol
							goto fin_architecture; //EXIT
						}
					}
					else if (((*previous_lexeme).getnature()).compare("is")== 0){
						++archi_begin_count;
						error_bit=archi_begin_protocol( l, arbre, lit, lend, previous_lexeme, previous_branche, current_branche,listroot, listfilo, next_lexeme, architecture_name);;///////////////// PARTIR DANS UNE FONCTION qui retourne error bit
						// here lit should be equal lend;
//						++lit,++previous_lexeme,++next_lexeme;
						if (error_bit==1) {
//							cout << "error at specified lexem"; // Took into acount in the archi_begin_protocol		
//							(*previous_lexeme).getposition();
							goto sortie_erreur;	
						}
						else {
//							cout << "Architecture checked"<< endl; // Took into acount in the archi_begin_protocol
							goto fin_architecture; //EXIT
						}
					}
					else {
						cout << "error at specified lexem"; 		
						(*previous_lexeme).getposition();
						goto sortie_erreur;
					}
							
				}
				else { //  unauthorized lexeme
					cout << "error at specified lexem";// << "E";		
					(*lit).getposition();
					if (archi_begin_count !=1){
						cout << "missing a begin in architecture or error occured before it";
					}
					goto sortie_erreur;
				}

			} // END OF VERIFICATION LOOP

			////////////////////////////////// TREE IS CONSTRUCTED DURING VERIFICATION ////////////////////////////////////
			
			fin_architecture:;
			cout << "Architecture tree constructed"<< endl; 			
		}

/////////////////////////////////////////////END ARCHITECTURE PROTOCOL ////////////////////////////////////////////////////////////

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


