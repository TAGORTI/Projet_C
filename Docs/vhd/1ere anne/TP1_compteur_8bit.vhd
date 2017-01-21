library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity Compteur_8bit is --crer l'entité compteur
	port(	reset,clock,enable,up_down	: in std_logic;
		count				: out unsigned(3 downto 0)) ;
		
end Compteur_8bit;

architecture A of Compteur_8bit is

signal count_mem: unsigned(3 downto 0);-- ne peut pas utiliser count donc crer count_mem

begin

process (clock,reset,enable)
begin

if (reset='0') then count <="0000"; count_mem <= "0000" ;
elsif (enable='1') then
	if clock'event and clock='1' then
	
		case up_down is
			when '1' => count_mem<= count_mem-"0001";  --mode soustraction
 			when '0' => count_mem <= count_mem + "0001";	--mode addition
			when others => count_mem<= count_mem;
		
		end case;

	end if;
end if;

count <=  count_mem; -- application en sortie du résultat
end process;

end A;
    
    

