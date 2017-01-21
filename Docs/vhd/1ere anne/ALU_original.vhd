library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity ALU is --crer l'entité ALU
	port(	A,B		: in STD_LOGIC_VECTOR(7 downto 0) ;  --definie les entrée/sortie et leurs formats de l'entité ALU
		CMD		: in STD_LOGIC_VECTOR(2 downto 0) ;
		Zero		: out std_logic;
		S		: out STD_LOGIC_VECTOR(7 downto 0)) ;
		
end ALU;

architecture A of ALU is --décrit le fonctionnement de ALU

signal result: unsigned (8 downto 0); -- crer les signaux result, a_u et b_u
signal a_u: unsigned (7 downto 0);
signal b_u: unsigned (7 downto 0);

begin

S<= std_logic_vector(result(7 downto 0)); --assigne a la sortie S la valeur de result mais écrété du 9ième bit (S a 8 bit et result en a 9)
a_u<= unsigned(a);--memorisation des valeur a,b dans leur signaux "tampon"
b_u<= unsigned(b);

--détermination de la valeur de result suivant la valeur de CMD
with CMD select result<= "000000000" when "000",  --quand CMD = "000" -> result = 0 au sens arithmétique
--a_u et b_u sont concaténé avec un 0 à gauche car result est de dimenssion 9 là ou a et b sont de dimmensions 8 il faut affecter à result une valeur de meme taille
--ce 0 arithmetiquement permet de sauvegarder la retenue  et éviter un dépassement de longueur de mots, genre: a = 11111111 + b= 11111111 -> result = 100000000 au lieu de 00000000 qui serait faux
			 ('0' & a_u) + ('0' & b_u ) when "011", --quand CMD = "011" -> result = a + b au sens arithmétique  		
   			 ('0' & a_u) - ('0' & b_u ) when "010", --quand CMD = "010" -> result = a - b au sens arithmétique
			 ('0' & b_u) - ('0' & a_u ) when "001", --quand CMD = "001" -> result = b - a au sens arithmétique
			 ('0' & a_u) XOR ('0' & b_u ) when "100", --quand CMD = "100" -> result = a XOR b au sens logique
			 ('0' & a_u) AND ('0' & b_u ) when "110", --quand CMD = "110" -> result = a AND b au sens logique
			 ('0' & a_u) OR ('0' & b_u ) when "101", --quand CMD = "101" -> result = a OR b au sens logique
    			 "111111111" when others;


zero<= '1' when result(7 downto 0) = "00000000" else '0'; -- met la sortie zero à 1 si result = 0 au sens arithmetique

end A;
    
    

