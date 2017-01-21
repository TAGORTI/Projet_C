library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity reg_11bits is --crer l'entité registre et ses ports
	port(	reset,clock,shift_right,LOAD,serial_in	: in std_logic;
		serial_out: out std_logic;

		data_in: in std_logic_vector(10 downto 0) ;
		data_out: out std_logic_vector(10 downto 0)) ;
		
end reg_11bits;

architecture A of reg_11bits is

signal registre: std_logic_vector(10 downto 0); --creation du signal interne registre

begin

process (clock,reset)
begin

if (reset='1') then registre <="00000000000"; --commande de reset

elsif clock'event and clock='1' then
		if (LOAD ='1') then       --entrée/sortie parallèle prioritaire sur le décalage
			registre <= data_in;
			--data_out <= data_in;

		elsif (shift_right ='1') then --decalage à droite
				serial_out <= registre (0);
				registre <= serial_in & registre ( 10 downto 1); 

		else registre <=registre; -- definition des autres cas

		end if;




end if;
data_out<=registre; --assignation en sortie de la valeur du registre
end process;

end A;
    
    

