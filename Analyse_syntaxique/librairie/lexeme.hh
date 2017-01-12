#ifndef _LEXEME_H_
#define _LEXEME_H_

#include "math.h"
#include <iostream>
#include <set>
#include <sstream>

using namespace std;


class   lexeme { 

	string nom;
	string nature;	
	string role;
	int ligne;
	int colonne;


//	map <string,lexeme *> maplexeme;


public:

	lexeme(const string & nom, const string & nature,const string & role, const int & ligne, const int & colonne):nom(nom),nature(nature),role(role), ligne(ligne),colonne(colonne){
	}

	lexeme(const string & nom, const string & nature,const string & role):nom(nom),nature(nature),role(role), ligne(0),colonne(0){
	}

//
	lexeme(const string & nom, const string & nature, const int & ligne, const int & colonne):nom(nom),nature(nature),role("aucun"), ligne(ligne),colonne(colonne){
	}

	lexeme(const string & nom, const string & nature):nom(nom),nature(nature),role("aucun"), ligne(0),colonne(0){
	}

//
	lexeme(const string & nom, const int & ligne, const int & colonne):nom(nom),nature("aucun"),role("aucun"), ligne(ligne),colonne(colonne){
	}

	lexeme(const string & nom):nom(nom),nature("aucun"),role("aucun"), ligne(0),colonne(0){
	}
//

	lexeme():nom("aucun"),nature("aucun"),role("aucun"), ligne(0),colonne(0){
	}

	~lexeme() {}



//////////////////////GET////////////////////////
		
	const string & getnom() const {
		return this->nom;
	} 

	const string & getnature() const {
		return this->nature;
	} 

	const string & getrole() const {
		return this->role;
	} 

	const int & getligne() const {
		return this->ligne;
	} 

	const int & getcolonne() const {
		return this->colonne;
	} 

/////////////////METHODE////////////////////

	void getposition()  {
		cout << " Ligne " << this->ligne << " colonne " << this->colonne << endl;
	}


/////////////////SET/////////////////

	void setnature( const string & nature) {
		this->nature=nature;
	}

	void setrole( const string & role) {
		this->role=role;
	}

	void setligne( const int & ligne) {
		this->ligne=ligne;
	}

	void setcolonne( const int & colonne) {
		this->colonne=colonne;
	}


/*
	double getpoids() const {
		return this->poids;
	} 

	void setpoids( const int & poids) {
		if (poids <= 0) {
			cout << "erreur de poid"<<endl;
		}
		else {
			this->poids=poids;
		}
	}

	virtual double getcout()=0; 

	virtual double getration()=0;

	virtual const string & getespece()=0;

	virtual void getparente()=0;
*/
//	virtual void getdescendant()=0;
	 
	//autres fonction

//	virtual string tostring(){
//		stringstream s; 
//		s << "l'animal " << this->getnom << ", pèse " << this->getpoids << " ";
//		return s.str();
//	}


	//fonction amis

//	friend ostream& operator << (ostream& out,const animal &f);
	
};

#endif
