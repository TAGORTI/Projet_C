//============================================================================
// Name        : as.c
// Author      : Valérian
// Version     : 0.1
// Copyright   : PHELMA
//
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



void get_arbre_primaire( list<lexeme> & l, tree<lexeme> & arbre){

	list<lexeme>::const_iterator  //itérateur sur liste
		lit(l.begin()), 
		lend(l.end()),
		previous_lexeme(lit);
		
		l.push_front(lexeme("root",1,1));
        previous_lexeme=l.begin();
		

	tree<lexeme>::iterator  //itérateur sur l'arbre
		previous_branche, 
		current_branche,
		root;

	previous_branche=arbre.insert(arbre.end(), lexeme("root")); // creation de la racine de l'arbre

	list<tree<lexeme>::iterator> listroot;
	listroot.push_front(previous_branche); // Pile FILO firts in Last Out pour l'arbre

	list<list<lexeme>::const_iterator> listfilo; // Pile FILO firts in Last Out pour la liste
     listfilo.push_front(lit);
	recursive_action( l, arbre, lit, lend, previous_lexeme, previous_branche,  current_branche, listroot,listfilo);//mise en fonction du contenue pour recursivité possible

//	cout << listroot.size() <<endl;
}


void recursive_action ( list<lexeme> & l, tree<lexeme> & arbre, list<lexeme>::const_iterator & lit, list<lexeme>::const_iterator & lend, list<lexeme>::const_iterator & previous_lexeme, tree<lexeme>::iterator & previous_branche, tree<lexeme>::iterator & current_branche, list<tree<lexeme>::iterator> listroot,list<list<lexeme>::const_iterator> listfilo){

	for(;lit!=lend;++lit,++previous_lexeme){

		if ( ((*lit).getnature()).compare("endprocess")== 0) {

			//previous_branche=*(listroot.end()); //faire une liste de root

			current_branche=arbre.insert_after(previous_branche, *lit);
			previous_branche=*listroot.begin();

			//cout << listroot.size();
			if (listroot.size()==0){
				cout << "erreur il y a un end de trop";
				goto sortie_erreur;
			}
			else {
				listroot.pop_front();
			}
		}
/*
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
		}*/
        

        // gerer les instruction type
         else if  (((*lit).getnom()).compare("type")== 0){         
            listfilo.push_front(lit);//sauver l'iterateur de l'emplacement courant dans une liste filo
            lit++;
           for(;lit!=lend;){
            if (((*lit).getnom()).compare(";")== 0){
             lit=*listfilo.begin();// retourner au l étérateur qui pointe sur type
             listfilo.pop_front();// supprimer cette valeur
              cout<<"erreur you have a ; just after the key word type"<<endl; 
             break;             
            }
            else{
               if (((*lit).getnature()).compare("id")== 0){
                    lit++;                    
                    if((((*lit).getnom()).compare("is")== 0)){
                        lit++;                        
                        if((((*lit).getnom()).compare("(")== 0)){
                                lit++;
                             for(;lit!=lend;){
                               // bool test=false;
                              if ( (((*lit).getnom()).compare(")")== 0)){
                                    lit++;                   
                                    if( ((*lit).getnom()).compare(";")== 0){
                                        cout<<"end of the type instr"<<endl; exit(1); 
                                    }
                                    else{
                                     cout<<"error thier is an ) in your instruction"<<endl;
                                    }
                              }   
                              else if(((*lit).getnature()).compare("id")== 0){                                  
                                        lit++;
                                        if(((*lit).getnom()).compare(",")== 0){
                                            cout<<" vergule detected"<<endl;
                                        }
                                        else{
                                        cout<<"erreur the separator should be an ,"<<endl;
                                        }                                                                 
                                  }
                             else{
                                 cout<<"erreur should be an id after ("<<endl;exit(1);
                               }
                             }                           
                         }
                        else{
                        cout<<"erreur you should have an ( after type/id"<<endl;
                        }
                                    
                    }
                    else{
                     cout<<"erreur you should have an IS  after type/id"<<endl;                   
                    }
               }
               else{
                   cout<<"erreur you should have an identifiant after type"<<endl;
               }
                         
            }
            
           } 
   cout<<"ok "<<endl;           
         }
        //fin  gerer les instruction type

		else { 
			current_branche=arbre.insert_after(previous_branche, *lit);
			previous_branche=current_branche;
		}
		
	
	}//fin du for GENERAL

sortie_erreur:;
	//return arbre;
}


