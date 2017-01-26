
CC=g++
INCSRC=source
INCLIB=librairie
INCLUDE=-I$(INCLIB) -I$(INCSRC)
CFLAGS=-g --std=c++11 $(INCLUDE) -llstdc++
LDFLAGS=
EXEC=test_as

all: $(EXEC)

test_as: lexeme test_analyse_syntaxique analyse_syntaxique  parseur
	$(CC) -o $@ $^ $(LDFLAGS)

test_analyse_syntaxique: source/test_analyse_syntaxique.cc
	$(CC) -o $@ -c $< $(CFLAGS)

lexeme: source/lexeme.cc librairie/lexeme.hh
	$(CC) -o $@ -c $< $(CFLAGS)

analyse_syntaxique: source/analyse_syntaxique.cc librairie/analyse_syntaxique.hh
	$(CC) -o $@ -c $< $(CFLAGS)

parseur : ../parseur/src/parseur.cc   librairie/parseur.h
	$(CC) -o $@ -c $< $(CFLAGS)




clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)


