
CC=g++
INCSRC=source
INCLIB=librairie
INCLUDE=-I$(INCLIB) -I$(INCSRC)
CFLAGS=-g --std=c++11 $(INCLUDE) -llstdc++
LDFLAGS=
EXEC=test_as

all: $(EXEC)

test_as: lexeme.o test_analyse_syntaxique.o analyse_syntaxique.o
	$(CC) -o $@ $^ $(LDFLAGS)

test_analyse_syntaxique.o: source/test_analyse_syntaxique.cc
	$(CC) -o $@ -c $< $(CFLAGS)

lexeme.o: source/lexeme.cc librairie/lexeme.h
	$(CC) -o $@ -c $< $(CFLAGS)

analyse_syntaxique.o: source/analyse_syntaxique.cc librairie/analyse_syntaxique.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)


