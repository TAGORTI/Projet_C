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
#include "parseur.h"
#include <string.h>
#include <map>
using namespace std;

int main (){
 list<lexeme> listlexeme;
parser( listlexeme);
cout<<listlexeme.size()<<endl;

       /* lit (listlexeme.begin()),
        lend(listlexeme.end());

  cout<<listlexeme.size()<<endl;
    for(;lit!=lend;++lit) 
	{
	cout << (*lit).getnom() << ' ' << (*lit).getnature() << ' ' << (*lit).getrole()<< endl;
    }*/
return 0;
}
