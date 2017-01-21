library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity ALU is --crer l'entité ALU
	port(	A,B			: in STD_LOGIC_VECTOR(7 downto 0) ;  --definie les entrée/sortie et leurs formats de l'entité ALU
		CMD			: in STD_LOGIC_VECTOR(2 downto 0) ;
		reset,clock		: in std_logic;
		Zero			: out std_logic;
		S			: out STD_LOGIC_VECTOR(7 downto 0)) ;	
end ALU;

architecture A of ALU is --décrit le fonctionnement de ALU
signal result: unsigned (8 downto 0); -- crer les signaux result, a_u et b_u
signal a_u: unsigned (7 downto 0);
signal b_u: unsigned (7 downto 0);

begin
		a_u<= unsigned(a); --memorisation des valeur a,b dans leur signaux "tampon"
		b_u<= unsigned(b);
process (clock,reset)
begin

if (reset='1') then result <="000000000"; --a_u <="00000000"; b_u <="00000000";
elsif clock'event and clock='1' then
	 	--détermination de la valeur de result suivant la valeur de CMD

	
		case CMD is
			when "000" => result <= ('0' & a_u)  ; 
 			when "001" => result <= ('0' & b_u) - ('0' & a_u );
 			when "010" => result <= ('0' & a_u) - ('0' & b_u );
 			when "011" => result <= ('0' & a_u) + ('0' & b_u );
 			when "100" => result <= ('0' & a_u) XOR ('0' & b_u );
 			when "101" => result <= ('0' & a_u) OR ('0' & b_u );
 			when "110" => result <= ('0' & a_u) AND ('0' & b_u ); 
 			when "111" => result <= ('0' & a_u) + "000000001";
 			when others => result <= "111111111";
		end case;

end if;
end process;
zero<= '1' when result(7 downto 0) = "00000000" else '0'; 
S<= std_logic_vector(result(7 downto 0)); -- assignation de result en sortie
end A;
    
    

