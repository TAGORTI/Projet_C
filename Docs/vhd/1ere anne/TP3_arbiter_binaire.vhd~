library IEEE ;
use IEEE.std_logic_1164.ALL ;

entity arbiter is --crer l'entite arbiter et en definie els entrée/sortie
port (	clk 	: in std_logic ;
	resetn	: in std_logic ;
	R	: in std_logic_vector(1 to 2) ;
	ACK	: out std_logic_vector(1 to 2) );
end arbiter ;


architecture behaviour of arbiter is

type state_arbiter is (Idle, Proc1, Proc2, Proc3) ; -- déclaration des etats
signal current_state : state_arbiter ;  --déclaration des signaux d'etat
signal next_state : state_arbiter ;

begin
P_state : process (clk, resetn) --process de synchronisme des etats

begin

if (resetn = '0') then  --commande de reset 
	current_state <= Idle;

elsif (clk'event and clk='1') then -- synchronisme des passage d'etat
	current_state <= next_state;

end if;

end process P_state ;


P_Next_State_output : process (current_state,R) --process qui pour chaque etat définit -- 1: l'action executer lors de l'etat
-- 2: les conditions de passage à l'état suivant (mode grafcet)
begin

case current_state is
	when Idle =>  ack <= "00"; --etat initial
		if  (R="01") then next_state <= Proc1; 
		elsif (R="10") then next_state <= Proc2; 
		elsif (R="11") then next_state <= Proc3; 
		else next_state <= Idle; ack <= "00";
		end if;

	when PROC1 =>  ack <= "01"; --proc1 accede a la memoire
		if (R="00") then next_state <= Idle; ack <= "00";
		else next_state <= Proc1;
		end if;

	when PROC2 => ack <= "10"; --proc2 accede a la memoire
		if (R= "00") then next_state <= Idle; ack <= "00";
		else next_state <= Proc2;
		end if;
 
	when PROC3 => ack <= "11"; --proc3 accede a la memoire
		if (R="00") then next_state <= Idle; ack <= "00";
		else next_state <= Proc3;
		end if;
end case;

end process P_Next_State_output ;

end behaviour ;
