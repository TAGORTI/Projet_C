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


//	map <string,lexeme *> maplexeme;


public:


	lexeme(const string & nom, const string & nature,const string & role):nom(nom),nature(nature),role(role){
	}

	lexeme(const string & nom, const string & nature):nom(nom),nature(nature),role("aucun"){
	}

	lexeme(const string & nom):nom(nom),nature("aucun"),role("aucun"){
	}

	lexeme():nom("aucun"),nature("aucun"),role("aucun"){
	}

	~lexeme() {}



	//Methode getset
		
	const string & getnom() const {
		return this->nom;
	} 

	const string & getnature() const {
		return this->nature;
	} 

	const string & getrole() const {
		return this->role;
	} 


	void setnature( const string & nature) {
		this->nature=nature;
	}

	void setrole( const string & role) {
		this->role=role;
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
