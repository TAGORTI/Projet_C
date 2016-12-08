/*int main() {
list<string> l;
l.push_back(string("si"));
l.push_back(string("six"));
l.push_back(string("scies"));
l.push_back(string("scient"));
l.push_back(string("six"));
l.push_back(string("cyprès"));
l.push_back(string("si"));
l.push_back(string("près"));*/
// une table associative qui associe chaque clé
// de type "chaine de caractères" à un entier
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "lexeme.h"
#include <stdio.h>
#include <string.h>
#include <map>
int main() {
 string tab[2];
 map<string, string> mymap; 
 ifstream fichier("lexeme_db.txt", ios::in);  // on ouvre en lecture
 
  
     string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
     while (getline(fichier,contenu)){         
        string ligne;
        std::istringstream ss(contenu);
        int i=0;         
         while (ss >> ligne){             
           tab[i]=ligne;          
           i++;  
         //if (i>2){cout<<"ERRORR check the lexeme_db writing rules"<<endl;}
        }      
        cout<<tab[0]<<"------>"<<tab[1]<<endl;
         mymap.insert (pair<string,string>(tab[0],tab[1]));         
    }
     
return 0;
}



