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

#include <iosfwd>

#include <list>


using namespace std;

void afficher_arbre(const tree<lexeme> & arbre){
	tree<lexeme>::iterator 
	arbre_it(arbre.begin()), 
	arbre_end(arbre.end());
	for(;arbre_it!=arbre_end;++arbre_it) {
		for (int i=0; i<arbre.depth(arbre_it); ++i){
		cout << "   ";
		}
	cout << (*arbre_it).getnom() << ' ' << (*arbre_it).getnature()  << ' ' << (*arbre_it).getrole() << endl;

	}
}



void afficher_liste(const list<lexeme> & l){
    list<lexeme>::const_iterator
        lit (l.begin()),
        lend(l.end());
    for(;lit!=lend;++lit) cout << (*lit).getnom() << ' ' << (*lit).getnature() << ' ' << (*lit).getrole()<< endl;
    cout << endl;
}


int main() {


list<lexeme> listlexeme;// = creer_liste ;//  list de lexeme

listlexeme.push_back(lexeme("library","library",2,1));
listlexeme.push_back(lexeme("IAEE","id",2,2));
listlexeme.push_back(lexeme(";","endligne",2,3));

listlexeme.push_back(lexeme("use","use",3,1));
listlexeme.push_back(lexeme("IBEE","id",3,2));
listlexeme.push_back(lexeme(".","point",3,3));
listlexeme.push_back(lexeme("std_logic_1164","id",3,4));
listlexeme.push_back(lexeme(".","point",3,5));
listlexeme.push_back(lexeme("all","all",3,6));
listlexeme.push_back(lexeme(";","endligne",3,7));

listlexeme.push_back(lexeme("use","use",4,1));
listlexeme.push_back(lexeme("iCee","id",4,2));
listlexeme.push_back(lexeme(".","point",4,3));
listlexeme.push_back(lexeme("numeric_std","id",4,4));
listlexeme.push_back(lexeme(".","point",4,5));
listlexeme.push_back(lexeme("all","all",4,6));
listlexeme.push_back(lexeme(";","endligne",4,7));
/*
listlexeme.push_back(lexeme("entity","entity",6,1));
listlexeme.push_back(lexeme("fsm","id",6,2));
listlexeme.push_back(lexeme("is","is",6,3));

listlexeme.push_back(lexeme("port","port",7,1));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",7,2));
listlexeme.push_back(lexeme("clk","id",7,3));
listlexeme.push_back(lexeme(",","virgule",7,4));
listlexeme.push_back(lexeme("Reset","id",7,5));
listlexeme.push_back(lexeme(":","deux_points",7,6));
listlexeme.push_back(lexeme("in","in",7,7));
listlexeme.push_back(lexeme("std_logic","std_logic",7,8));
listlexeme.push_back(lexeme(";","endligne",7,9));

listlexeme.push_back(lexeme("adc_eocb","id",8,1));
listlexeme.push_back(lexeme(":","deux_points",8,2));
listlexeme.push_back(lexeme("in","in",8,3));
listlexeme.push_back(lexeme("std_logic","std_logic",8,4));
listlexeme.push_back(lexeme(";","endligne",8,5));

listlexeme.push_back(lexeme("adc_convstb","id",9,1));
listlexeme.push_back(lexeme(":","deux_points",9,2));
listlexeme.push_back(lexeme("out","in",9,3));
listlexeme.push_back(lexeme("std_logic","std_logic",9,4));
listlexeme.push_back(lexeme(";","endligne",9,5));

listlexeme.push_back(lexeme("adc_rdb","id",10,1));
listlexeme.push_back(lexeme(":","deux_points",10,2));
listlexeme.push_back(lexeme("out","in",10,3));
listlexeme.push_back(lexeme("std_logic","std_logic",10,4));
listlexeme.push_back(lexeme(";","endligne",10,5));

listlexeme.push_back(lexeme("adc_csb","id",11,1));
listlexeme.push_back(lexeme(":","deux_points",11,2));
listlexeme.push_back(lexeme("out","in",11,3));
listlexeme.push_back(lexeme("std_logic","std_logic",11,4));
listlexeme.push_back(lexeme(";","endligne",11,5));

listlexeme.push_back(lexeme("dac_wrb","id",12,1));
listlexeme.push_back(lexeme(":","deux_points",12,2));
listlexeme.push_back(lexeme("out","in",12,3));
listlexeme.push_back(lexeme("std_logic","std_logic",12,4));
listlexeme.push_back(lexeme(";","endligne",12,5));

listlexeme.push_back(lexeme("dac_csb","id",13,1));
listlexeme.push_back(lexeme(":","deux_points",13,2));
listlexeme.push_back(lexeme("out","in",13,3));
listlexeme.push_back(lexeme("std_logic","std_logic",13,4));
listlexeme.push_back(lexeme(";","endligne",13,5));

listlexeme.push_back(lexeme("ldacb","id",14,1));
listlexeme.push_back(lexeme(":","deux_points",14,2));
listlexeme.push_back(lexeme("out","in",14,3));
listlexeme.push_back(lexeme("std_logic","std_logic",14,4));
listlexeme.push_back(lexeme(";","endligne",14,5));

listlexeme.push_back(lexeme("clrb","id",15,1));
listlexeme.push_back(lexeme(":","deux_points",15,2));
listlexeme.push_back(lexeme("out","in",15,3));
listlexeme.push_back(lexeme("std_logic","std_logic",15,4));
listlexeme.push_back(lexeme(";","endligne",15,5));

listlexeme.push_back(lexeme("rom_address","id",16,1));
listlexeme.push_back(lexeme(":","deux_points",16,2));
listlexeme.push_back(lexeme("out","in",16,3));
listlexeme.push_back(lexeme("std_logic_vector","std_logic_vector",16,4));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",16,5));
listlexeme.push_back(lexeme("4","chifre",16,6));
listlexeme.push_back(lexeme("downto","downto",16,7));
listlexeme.push_back(lexeme("0","chiffre",16,8));
listlexeme.push_back(lexeme(")","parenthese_fermante",16,9));
listlexeme.push_back(lexeme(";","endligne",16,10));

listlexeme.push_back(lexeme("delay_line_address","id",17,1));
listlexeme.push_back(lexeme(":","deux_points",17,2));
listlexeme.push_back(lexeme("out","in",17,3));
listlexeme.push_back(lexeme("std_logic_vector","std_logic_vector",17,4));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",17,5));
listlexeme.push_back(lexeme("4","chifre",17,6));
listlexeme.push_back(lexeme("downto","downto",17,7));
listlexeme.push_back(lexeme("0","chiffre",17,8));
listlexeme.push_back(lexeme(")","parenthese_fermante",17,9));
listlexeme.push_back(lexeme(";","endligne",17,10));

listlexeme.push_back(lexeme("delay_line_sample_shift","id",18,1));
listlexeme.push_back(lexeme(":","deux_points",18,2));
listlexeme.push_back(lexeme("out","in",18,3));
listlexeme.push_back(lexeme("std_logic","std_logic",18,4));
listlexeme.push_back(lexeme(";","endligne",18,5));

listlexeme.push_back(lexeme("accu_ctrl","id",19,1));
listlexeme.push_back(lexeme(":","deux_points",19,2));
listlexeme.push_back(lexeme("out","in",19,3));
listlexeme.push_back(lexeme("std_logic","std_logic",19,4));
listlexeme.push_back(lexeme(";","endligne",19,5));

listlexeme.push_back(lexeme("buff_oe","id",20,1));
listlexeme.push_back(lexeme(":","deux_points",20,2));
listlexeme.push_back(lexeme("out","in",20,3));
listlexeme.push_back(lexeme("std_logic","std_logic",20,4));
listlexeme.push_back(lexeme(";","endligne",20,5));

listlexeme.push_back(lexeme("end","endprocess",21,1));
listlexeme.push_back(lexeme("fsm","id",21,2));
listlexeme.push_back(lexeme(";","endligne",21,3));


listlexeme.push_back(lexeme("architecture","architecture",24,1));
listlexeme.push_back(lexeme("behavior","id",24,2));
listlexeme.push_back(lexeme("of","of",24,3));
listlexeme.push_back(lexeme("fsm","id",24,4));
listlexeme.push_back(lexeme("is","is",24,5));

listlexeme.push_back(lexeme("type","type",25,1));
listlexeme.push_back(lexeme("state","id",25,2));
listlexeme.push_back(lexeme("is","is",25,3));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",25,4));
listlexeme.push_back(lexeme("s0","id",25,5));
listlexeme.push_back(lexeme(",","virgule",25,6));
listlexeme.push_back(lexeme("s1","id",25,7));
listlexeme.push_back(lexeme(",","virgule",25,8));
listlexeme.push_back(lexeme("s2","id",25,9));
listlexeme.push_back(lexeme(",","virgule",25,10));
listlexeme.push_back(lexeme("s3","id",25,11));
listlexeme.push_back(lexeme(",","virgule",25,12));
listlexeme.push_back(lexeme("s4","id",25,13));
listlexeme.push_back(lexeme(",","virgule",25,14));
listlexeme.push_back(lexeme("s6","id",25,15));
listlexeme.push_back(lexeme(",","virgule",25,16));
listlexeme.push_back(lexeme("s8","id",25,17));
listlexeme.push_back(lexeme(",","virgule",25,18));
listlexeme.push_back(lexeme("s9","id",25,19));
listlexeme.push_back(lexeme(",","virgule",25,20));
listlexeme.push_back(lexeme("s10","id",25,21));
listlexeme.push_back(lexeme(",","virgule",25,22));
listlexeme.push_back(lexeme("s1delay","id",25,23));
listlexeme.push_back(lexeme(",","virgule",25,24));
listlexeme.push_back(lexeme("s1delay2","id",25,25));
listlexeme.push_back(lexeme(",","virgule",25,26));
listlexeme.push_back(lexeme("s9delay","id",25,27));
listlexeme.push_back(lexeme(")","parenthese_fermante",25,28));
listlexeme.push_back(lexeme(";","endligne",25,29));

listlexeme.push_back(lexeme("signal","signal",26,1));
listlexeme.push_back(lexeme("current_state","id",26,2));
listlexeme.push_back(lexeme(":","deux_points",26,3));
listlexeme.push_back(lexeme("state","id",26,4));
listlexeme.push_back(lexeme(";","endligne",26,5));

listlexeme.push_back(lexeme("signal","signal",27,1));
listlexeme.push_back(lexeme("next_state","id",27,2));
listlexeme.push_back(lexeme(":","deux_points",27,3));
listlexeme.push_back(lexeme("state","id",27,4));
listlexeme.push_back(lexeme(";","endligne",27,5));

listlexeme.push_back(lexeme("signal","signal",28,1));
listlexeme.push_back(lexeme("counter_I","id",28,2));
listlexeme.push_back(lexeme(":","deux_points",28,3));
listlexeme.push_back(lexeme("unsigned","unsigned",28,4));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",28,5));
listlexeme.push_back(lexeme("4","chifre",28,6));
listlexeme.push_back(lexeme("downto","downto",28,7));
listlexeme.push_back(lexeme("0","chiffre",28,8));
listlexeme.push_back(lexeme(")","parenthese_fermante",28,9));
listlexeme.push_back(lexeme(";","endligne",28,10));

listlexeme.push_back(lexeme("signal","signal",29,1));
listlexeme.push_back(lexeme("counter_J","id",29,2));
listlexeme.push_back(lexeme(":","deux_points",29,3));
listlexeme.push_back(lexeme("unsigned","unsigned",29,4));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",29,5));
listlexeme.push_back(lexeme("4","chifre",29,6));
listlexeme.push_back(lexeme("downto","downto",29,7));
listlexeme.push_back(lexeme("0","chiffre",29,8));
listlexeme.push_back(lexeme(")","parenthese_fermante",29,9));
listlexeme.push_back(lexeme(";","endligne",29,10));

listlexeme.push_back(lexeme("signal","signal",30,1));
listlexeme.push_back(lexeme("counter_I_temp","id",30,2));
listlexeme.push_back(lexeme(":","deux_points",30,3));
listlexeme.push_back(lexeme("unsigned","unsigned",30,4));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",30,5));
listlexeme.push_back(lexeme("4","chifre",30,6));
listlexeme.push_back(lexeme("downto","downto",30,7));
listlexeme.push_back(lexeme("0","chiffre",30,8));
listlexeme.push_back(lexeme(")","parenthese_fermante",30,9));
listlexeme.push_back(lexeme(";","endligne",30,10));

listlexeme.push_back(lexeme("signal","signal",31,1));
listlexeme.push_back(lexeme("counter_j_temp","id",31,2));
listlexeme.push_back(lexeme(":","deux_points",31,3));
listlexeme.push_back(lexeme("unsigned","unsigned",31,4));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",31,5));
listlexeme.push_back(lexeme("4","chifre",31,6));
listlexeme.push_back(lexeme("downto","downto",31,7));
listlexeme.push_back(lexeme("0","chiffre",31,8));
listlexeme.push_back(lexeme(")","parenthese_fermante",31,9));
listlexeme.push_back(lexeme(";","endligne",31,10));

listlexeme.push_back(lexeme("begin","begin",33,1));

listlexeme.push_back(lexeme("p_state","id",36,1));
listlexeme.push_back(lexeme(":","deux_points",36,2));
listlexeme.push_back(lexeme("process","process",36,3));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",36,4));
listlexeme.push_back(lexeme("clk","id",36,5));
listlexeme.push_back(lexeme(",","virgule",36,6));
listlexeme.push_back(lexeme("reset","id",36,7));
listlexeme.push_back(lexeme(")","parenthese_fermante",36,8));

listlexeme.push_back(lexeme("begin","begin",37,1));

listlexeme.push_back(lexeme("if","if",38,1));
listlexeme.push_back(lexeme("reset","id",38,2));
listlexeme.push_back(lexeme("=","egale",38,3));
listlexeme.push_back(lexeme("'","apostrophe",38,4));
listlexeme.push_back(lexeme("1","chiffre",38,5));
listlexeme.push_back(lexeme("'","apostrophe",38,6));
listlexeme.push_back(lexeme("then","then",38,7));
listlexeme.push_back(lexeme("current_state","id",38,8));
listlexeme.push_back(lexeme("<=","assignation",38,9));
listlexeme.push_back(lexeme("s0","id",38,10));
listlexeme.push_back(lexeme(";","endligne",38,11));

listlexeme.push_back(lexeme("counter_i","id",39,1));
listlexeme.push_back(lexeme("<=","assignation",39,2));
listlexeme.push_back(lexeme("\"","guillemet",39,3));
listlexeme.push_back(lexeme("00000","nombre",39,4));
listlexeme.push_back(lexeme("\"","guillemet",39,5));
listlexeme.push_back(lexeme(";","endligne",39,6));

listlexeme.push_back(lexeme("counter_J","id",40,1));
listlexeme.push_back(lexeme("<=","assignation",40,2));
listlexeme.push_back(lexeme("\"","guillemet",40,3));
listlexeme.push_back(lexeme("00000","nombre",40,4));
listlexeme.push_back(lexeme("\"","guillemet",40,5));
listlexeme.push_back(lexeme(";","endligne",40,6));

listlexeme.push_back(lexeme("elseif","elseif",41,1));
listlexeme.push_back(lexeme("clk","id",41,2));
listlexeme.push_back(lexeme("'","apostrope",41,3));
listlexeme.push_back(lexeme("event","event",41,4));
listlexeme.push_back(lexeme("and","and",41,4));
listlexeme.push_back(lexeme("clk","id",41,5));
listlexeme.push_back(lexeme("=","egale",41,6));
listlexeme.push_back(lexeme("'","apostrophe",41,7));
listlexeme.push_back(lexeme("1","chiffre",41,8));
listlexeme.push_back(lexeme("'","apostrophe",41,9));
listlexeme.push_back(lexeme("then","then",41,10));
listlexeme.push_back(lexeme(";","endligne",41,11));

listlexeme.push_back(lexeme("current_state","id",42,1));
listlexeme.push_back(lexeme("<=","assignation",42,2));
listlexeme.push_back(lexeme("next_state","id",42,3));
listlexeme.push_back(lexeme(";","endligne",42,4));

listlexeme.push_back(lexeme("counter_i","id",43,1));
listlexeme.push_back(lexeme("<=","assignation",43,2));
listlexeme.push_back(lexeme("counter_i_temp","id",43,3));
listlexeme.push_back(lexeme(";","endligne",43,4));

listlexeme.push_back(lexeme("counter_j","id",44,1));
listlexeme.push_back(lexeme("<=","assignation",44,2));
listlexeme.push_back(lexeme("counter_j_temp","id",44,3));
listlexeme.push_back(lexeme(";","endligne",44,4));

listlexeme.push_back(lexeme("end","endprocess",45,1));
listlexeme.push_back(lexeme("if","if",45,2));
listlexeme.push_back(lexeme(";","endligne",45,3));

listlexeme.push_back(lexeme("end","endprocess",45,1));
listlexeme.push_back(lexeme("process","process",45,2));
listlexeme.push_back(lexeme("p_state","id",45,3));
listlexeme.push_back(lexeme(";","endligne",45,4));

listlexeme.push_back(lexeme("p_fsm","id",48,1));
listlexeme.push_back(lexeme(":","deux_points",48,2));
listlexeme.push_back(lexeme("process","process",48,3));
listlexeme.push_back(lexeme("(","parenthese_ouvrante",48,4));
listlexeme.push_back(lexeme("current_state","id",48,5));
listlexeme.push_back(lexeme(",","virgule",48,6));
listlexeme.push_back(lexeme("adc_eocb","id",48,7));
listlexeme.push_back(lexeme(",","virgule",48,8));
listlexeme.push_back(lexeme("counter_i","id",48,9));
listlexeme.push_back(lexeme(",","virgule",48,10));
listlexeme.push_back(lexeme("counter_j","id",48,11));
listlexeme.push_back(lexeme(")","parenthese_fermante",48,12));

listlexeme.push_back(lexeme("begin","begin",49,1));

listlexeme.push_back(lexeme("case","case",50,1));
listlexeme.push_back(lexeme("current_state","id",50,2));
listlexeme.push_back(lexeme("is","is",50,3));
listlexeme.push_back(lexeme("when","when",50,4));
listlexeme.push_back(lexeme("s0","id",50,5));
listlexeme.push_back(lexeme("=>","induit",50,6));
listlexeme.push_back(lexeme("adc_csb","id",50,7));
listlexeme.push_back(lexeme("<=","assignation",50,8));
listlexeme.push_back(lexeme("'","apostrope",50,9));
listlexeme.push_back(lexeme("0","chiffre",50,10));
listlexeme.push_back(lexeme("'","apostrope",50,11));
listlexeme.push_back(lexeme(";","endligne",50,12));

listlexeme.push_back(lexeme("adc_convstd","id",51,1));
listlexeme.push_back(lexeme("<=","assignation",51,2));
listlexeme.push_back(lexeme("'","apostrope",51,3));
listlexeme.push_back(lexeme("1","chiffre",51,4));
listlexeme.push_back(lexeme("'","apostrope",51,5));
listlexeme.push_back(lexeme(";","endligne",51,6));

listlexeme.push_back(lexeme("adc_rdb","id",52,1));
listlexeme.push_back(lexeme("<=","assignation",52,2));
listlexeme.push_back(lexeme("'","apostrope",52,3));
listlexeme.push_back(lexeme("1","chiffre",52,4));
listlexeme.push_back(lexeme("'","apostrope",52,5));
listlexeme.push_back(lexeme(";","endligne",52,6));

listlexeme.push_back(lexeme("dac_csb","id",53,1));
listlexeme.push_back(lexeme("<=","assignation",53,2));
listlexeme.push_back(lexeme("'","apostrope",53,3));
listlexeme.push_back(lexeme("0","chiffre",53,4));
listlexeme.push_back(lexeme("'","apostrope",53,5));
listlexeme.push_back(lexeme(";","endligne",53,6));

listlexeme.push_back(lexeme("dac_wrb","id",54,1));
listlexeme.push_back(lexeme("<=","assignation",54,2));
listlexeme.push_back(lexeme("'","apostrope",54,3));
listlexeme.push_back(lexeme("1","chiffre",54,4));
listlexeme.push_back(lexeme("'","apostrope",54,5));
listlexeme.push_back(lexeme(";","endligne",54,6));

listlexeme.push_back(lexeme("ldacb","id",55,1));
listlexeme.push_back(lexeme("<=","assignation",55,2));
listlexeme.push_back(lexeme("'","apostrope",55,3));
listlexeme.push_back(lexeme("1","chiffre",55,4));
listlexeme.push_back(lexeme("'","apostrope",55,5));
listlexeme.push_back(lexeme(";","endligne",55,6));

listlexeme.push_back(lexeme("clrb","id",56,1));
listlexeme.push_back(lexeme("<=","assignation",56,2));
listlexeme.push_back(lexeme("'","apostrope",56,3));
listlexeme.push_back(lexeme("0","chiffre",56,4));
listlexeme.push_back(lexeme("'","apostrope",56,5));
listlexeme.push_back(lexeme(";","endligne",56,6));

listlexeme.push_back(lexeme("counter_i_temp","id",58,1));
listlexeme.push_back(lexeme("<=","assignation",58,2));
listlexeme.push_back(lexeme("\"","guillemet",58,3));
listlexeme.push_back(lexeme("0","chiffre",58,4));
listlexeme.push_back(lexeme("\"","guillemet",58,5));
listlexeme.push_back(lexeme(";","endligne",58,6));

//////////////////////////

listlexeme.push_back(lexeme("when","when",150,1));
listlexeme.push_back(lexeme("others","others",150,2));
listlexeme.push_back(lexeme("=>","induit",150,3));
listlexeme.push_back(lexeme("next_state","id",150,4));
listlexeme.push_back(lexeme("<=","assignation",150,5));
listlexeme.push_back(lexeme("current_state","id",150,6));
listlexeme.push_back(lexeme(";","endligne",150,7));

listlexeme.push_back(lexeme("end","endprocess",153,1));
listlexeme.push_back(lexeme("case","case",153,2));
listlexeme.push_back(lexeme(";","endligne",153,3));

listlexeme.push_back(lexeme("end","endprocess",154,1));
listlexeme.push_back(lexeme("process","process",154,2));
listlexeme.push_back(lexeme("p_fsm","id",154,3));
listlexeme.push_back(lexeme(";","endligne",154,4));

listlexeme.push_back(lexeme("end","endprocess",155,1));
listlexeme.push_back(lexeme("behavior","id",155,2));
listlexeme.push_back(lexeme(";","endligne",155,3));

*/




///////afficher_liste(listlexeme);


tree<lexeme> arbre ;

get_arbre_primaire(listlexeme,arbre);

//arbre.erase_children(arbre.begin());

afficher_arbre(arbre);

cin.get();

(*(listlexeme.begin())).getposition();

afficher_liste(listlexeme);

}
























/*
cout << l<<endl;
}
/*
cout << listlexeme<1>.getnature()<<endl;
cout << listlexeme<1>.getrole()<<endl;

}

//arbre = get_arbre_primaire (listlexeme);


//Puis la vérification de l'arbre en le comparent
/*
Comparing trees While the STL equal algorithm can be used to compare the values of the
nodes in two different trees, it does not know about the structure of the tree. If you want
the comparison to take this into account, use the equal(iterator, iterator, iterator,
BinaryPredicate) call of the tree class. As an addition to the STL algorithm, the length of
the first range does not have to be equal to the length of the range pointed to by the second
iterator.
There is also an equal subtree algorithm which takes only two iterators, pointing to the
(single-node) heads of two subtrees.
*/


/*
 table std::vector<lexeme>;

 
 table.push_back( new lexeme (")","parenthese_fermante") );

 table<0>

 table.push_back( new lexeme (";","endligne") );

 table<1>
*/
