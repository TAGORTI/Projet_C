#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "lexeme.hh"
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;


void afficher_liste( list<lexeme> & l){
    list<lexeme>::iterator
        lit (l.begin()),
        lend(l.end());

    for(;lit!=lend;++lit) 
	{
	cout << (*lit).getnom() << ' ' << (*lit).getnature() << ' ' << (*lit).getrole()<< endl;
     (*lit).getposition();
	 }
}

/*********************************************************************************************************************************/




string identify_lexeme(const list<lexeme> & l, const map<string,string> &mymap){
list<lexeme>::const_iterator
    lit (l.begin()),
    lend(l.end());     
    string val;      
    string key;
    int cpt=0;
string lexeme_value;
lexeme_value=(*lit).getnom();
//for(int i=1; i<lexeme_value.size(); i++){
if ( lexeme_value[0]>= 123 && lexeme_value[0]<= 126|| lexeme_value[0]>= 123 && lexeme_value[0]<= 126|| lexeme_value[0]>= 93 && lexeme_value[0]<= 96|| lexeme_value[0]>= 123 && lexeme_value[0]<= 126){
  cerr<<"ERROR: the first character shoud not be a _ for this lexeme:"<<lexeme_value<<endl;
  		exit (1);
 
}
//}
if (lexeme_value[0]>=48 && lexeme_value[0]<=57  ){
  for(int i=1; i<lexeme_value.size(); i++){
  	if (lexeme_value[i]<48 || lexeme_value[i]>57 ){
  		cerr<<"ERROR: the first character shoud not be a number for this lexeme:"<<lexeme_value<<endl;
  		exit (1);
    }
	else if(lexeme_value[i]>=48 && lexeme_value[i]<=57){
		cpt++;
		if (cpt==lexeme_value.size()-1) {
			val= "nombre";
			return val;
		}
	}
	
  }
 val= "chiffre";
 return val;
}


map<string, string>::const_iterator itMap ;
for(itMap = mymap.begin() ; itMap!=mymap.end() ; ++itMap){
    key=itMap->first;
    if (key.compare((*lit).getnom())==0)
    {
        val=itMap->second;
        return val;
    }     
}



    	val= "identifiant";
		return val;
	

  /*  for(;lit!=lend;++lit){
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
    }*/
      
}

 //ifstream (const string& filename, ios_base::openmode mode = ios_base::in);

void parser (list<lexeme> & listlexeme,string file_name )

{
//list<lexeme> listlexeme;
int nb_ligne=0;
 int nb_colonne=0;
//////------------generate_lexeme_data_base----------------------------------///////////////////////////////////
string tab[2];
 bool attribute=false;
 map<string, string> mymap; 
// char path=lexeme_db_file;
 ifstream db("lexeme_db.txt", ios::in);  // on ouvre en lecture
 
  
     string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
     while (getline(db,contenu)){	            
        string ligne;
        std::istringstream ss(contenu);
        int i=0;         
         while (ss >> ligne){             
           tab[i]=ligne;          
           i++;          

         //if (i>2){cout<<"ERRORR check the lexeme_db writing rules"<<endl; exit(1);}
         }      
        //cout<<tab[0]<<"------>"<<tab[1]<<endl;
         mymap.insert (pair<string,string>(tab[0],tab[1]));         
    }
//////------------end_generate_lexeme_data_base----------------------------------/////////////////////////////



  ifstream fichier(file_name.c_str(), ios::in);  // on ouvre en lecture
  if(fichier)  // si l'ouverture a fonctionné
  {
    string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
    while (fichier != NULL){
    	nb_ligne++;
    	nb_colonne=0;
        getline(fichier, contenu);  // on met dans "contenu" la ligne
      //  cout << contenu<<endl;  // on affiche la ligne
        string buf; // Have a buffer string
       // stringstream ss(contenu); // Insert the string into a stream
        vector<string> tokens; // Create vector to hold our words
        
//////////////////////////////////////////////////////////////////////////////////////////
int longueurChaine = contenu.size();
string inter;
/////---start treat comments-------///////////////////////////
for (int i=0; i<longueurChaine; i++){
  attribute=false;
  if (contenu[i]=='-'&& contenu[i+1]=='-'){  
   int rest=longueurChaine-i;
   i=i+rest;
  }
  /////---end treat comments-------///////////////////////////

////----- start adding a space before and after caracters used like separator------////////////////// 
else if (contenu[i]>= 33 && contenu[i]<= 47 || contenu[i]>= 58 && contenu[i]<= 62  || contenu[i]>= 123 && contenu[i]<= 126 ){
   ///////---------treat variable and signal assignation-----------------------//////
   
  
    if ((contenu[i]=='<'&&contenu[i+1]=='=')||(contenu[i]=='='&&contenu[i+1]=='>') || (contenu[i]==':'&&contenu[i+1]=='=')||(contenu[i]=='>'&&contenu[i+1]=='=')||(contenu[i]==92 && contenu[i+1]=='=') ){
		
	    inter.push_back(' ');
		inter.push_back(contenu[i]);    	
    	inter.push_back(contenu[i+1]);
    	inter.push_back(' ');
    	i=i+1;
    
	}

	/*else if (contenu[i]==34||contenu[i]==39){
		if((contenu[i+1]>=48 && contenu[i+1]<=57)){
		inter.push_back(' ');		
	    }
	    else if((contenu[i-1]>=48 && contenu[i-1]<=57)){
		inter.push_back(' ');		
	    }
	    else {
	    	inter.push_back(contenu[i]);
		}
	   // inter.push_back(contenu[i]);
	}
   /* else if ((contenu[i]==39)&&(contenu[i+1]=='e')){
    	inter.push_back(contenu[i]);
	}*/
	
	else{
	
   inter.push_back(' ');
   inter.push_back(contenu[i]);   
   inter.push_back(' ');
   }
   
    
   
  } 
  
 /* if (contenu[i]==39&& (contenu[i+1]>=97 && contenu[i+1]<=122)){
                 cout<<"*******************************************************************************************"<<endl;
                   attribute=true; 
                 } */
////----- end adding a space before and after caracters used like separator------//////////////////  
////-----  start pass all lexeme to downcrase----------------------------------------------------//-/-/-////  
 
 
  else{
   if (contenu[i]>= 65 && contenu[i]<= 90){ 
    contenu[i]= contenu[i]+32;   
    inter.push_back(contenu[i]);
    }
    else{
    inter.push_back(contenu[i]);
    }
  ////----- end  pass all lexeme to downcrase----------------------------------------------------//-/-/-////  
  }  
}

//cout<< inter<<endl;
///////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////

 // = creer_liste ;//  list de lexeme
  list<lexeme> inter_listlexeme;
  list<lexeme>::iterator it;
 
 stringstream ss(inter);      
        while (ss >> buf){
          string id;
           //id= "hello"; 
          inter_listlexeme.push_back(lexeme(buf));         
          id = identify_lexeme(inter_listlexeme,mymap);
          nb_colonne++;         
          listlexeme.push_back(lexeme(buf,id,nb_ligne,nb_colonne));
          inter_listlexeme.pop_back();
        }
             
   /*for (it=mylist.begin(); it!=mylist.end(); ++it){           
           cout <<*it<<endl;
           //cout <<' '<<*it;           
        }  */   
    
     }
     afficher_liste(listlexeme); 
    fichier.close();
   cout<<"la taille de la liste chainée est: "<<listlexeme.size()<<endl;
   }  
   else
    cerr << "Impossible d'ouvrir le fichier !!" << endl;
   
}
