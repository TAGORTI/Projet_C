#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main()

{
  ifstream fichier("test.txt", ios::in);  // on ouvre en lecture
  if(fichier)  // si l'ouverture a fonctionné
  {
    string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
    while (fichier != NULL){
        getline(fichier, contenu);  // on met dans "contenu" la ligne
      //  cout << contenu<<endl;  // on affiche la ligne
        string buf; // Have a buffer string
       // stringstream ss(contenu); // Insert the string into a stream
        vector<string> tokens; // Create vector to hold our words
        
//////////////////////////////////////////////////////////////////////////////////////////
int longueurChaine = contenu.size();
string inter;
for (int i=0; i<longueurChaine; i++){
  if (contenu[i]=='#'){  
   int rest=longueurChaine-i;
   i=i+rest;
  }
// else if (contenu[i]==':' || contenu[i]=='(' || contenu[i]==')' ){
else if (contenu[i]>= 33 && contenu[i]<= 47 || contenu[i]>= 58 && contenu[i]<= 62  || contenu[i]>= 123 && contenu[i]<= 126 ){
   inter.push_back(' ');
   inter.push_back(contenu[i]);
   inter.push_back(' ');
  }   
  else{ 
   inter.push_back(contenu[i]);
  }  
}

//cout<< inter<<endl;
///////////////////////////////////////////////////////////////////////////////////////////
 stringstream ss(inter);
        while (ss >> buf)
          tokens.push_back(buf);
          //cout<<tokens.size()<<endl;
      for (int i = 0; i < tokens.size(); i++) {
        
            cout << tokens[i] <<endl;
        }      
     }
    fichier.close();
   }  
   else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
   return 0;
}
