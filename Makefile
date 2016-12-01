all : test_as




test_as :  test_analyse_syntaxique.o  lexeme.o
	g++ -o test_as 


clean:
	rm -f *.o *~ test test_as
