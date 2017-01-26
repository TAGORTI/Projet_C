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

int main (int argc, char *argv[]){
 list<lexeme> listlexeme;
 string file_name;
 file_name=argv[1];
parser(listlexeme,file_name);
//cout<<listlexeme.size()<<endl;      
return 0;
}
