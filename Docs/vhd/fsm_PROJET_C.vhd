------------------------------FSM.vhd----------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity FSM is
  port(Clk , Reset           : in  std_logic;
       ADC_Eocb         : in  std_logic; -- acquisition 
       ADC_Convstb       : out std_logic; -- acquisition 
       ADC_Rdb         : out std_logic; -- reading 
       ADC_csb          : out std_logic; -- chips 
       DAC_WRb          : out std_logic; -- writing in 
       DAC_csb           : out std_logic; -- chip 
       LDACb            : out std_logic; -- update of 
       CLRb              : out std_logic; -- clear of 
       Rom_Address        : out std_logic_vector(4 downto 0);
       Delay_Line_Address   : out std_logic_vector(4 downto 0);
       Delay_Line_sample_shift  : out std_logic; -- registering 
       Accu_ctrl                : out std_logic; -
       Buff_OE                  : out std_logic ; --
	   A,B			: in STD_LOGIC_VECTOR(7 downto 0) ;
	   comparateur			: out std_logic;
	   CMD			: in STD_LOGIC_VECTOR(3 downto 0) ;
	   ADC_Eocb_bar         : out  std_logic;
	   Filter_Out  : out std_logic_vector(7 downto 0));
end FSM;


architecture Behavior of FSM is
type STATE is (S0,S1,S2,S3,S4,S6,S8,S9,S10,S1delay,S1delay2,S9delay); 
type mot is (0 to 31) of std_logic ;
type hexa is (15 downto 0) of std_logic_vector(4 downto 0);

signal current_state : STATE;
signal next_state : STATE;
signal counter_I: unsigned (4 downto 0);
signal counter_J: unsigned (4 downto 0);
signal counter_I_temp: unsigned (4 downto 0);
signal counter_J_temp: unsigned (4 downto 0);

signal result: unsigned (8 downto 0); -- crer les signaux result, a_u et b_u
signal a_u: unsigned (7 downto 0);
signal b_u: unsigned (7 downto 0);


  component ACCU
    port(Accu_in          : in  std_logic_vector(7 downto 0);
                Accu_ctrl : in  std_logic;
                CLK       : in  std_logic;
                RESET     : in  std_logic;
                Accu_out  : out std_logic_vector(7 downto 0)) ;
  end component;
  


begin

 C1: accu PORT MAP (Accu_in=>"11110000",Accu_ctrl=>'1',clk=>'1',reset=>'1',Accu_out=>filter_out);

-- synchronous state
	a_u<= unsigned(a); --memorisation des valeur a,b dans leur signaux "tampon"
	b_u<= unsigned(b);

    P_STATE: process(Clk, reset)
    begin
    	if reset ='1' then current_state <= S0; -- Reset active when up
	counter_i <= "00000";
	counter_j <= "00000";
	elsif clk'event and clk='1' then
		current_state<=next_state;
		counter_I <= counter_I_temp;
		counter_J <= counter_J_temp;
	end if;
    end process P_STATE;

    P_FSM: process(current_state, ADC_Eocb, counter_I, counter_J)
	
	variable t : time; 
	
    begin
	case current_state is	when S0 => ADC_csb <= '0' ; --  CASE -> BONUS
					ADC_Convstb <= '1';
					t:= 5+(counter_i-counter_j)*2; -- Operation arithmetique
					

					case CMD is
						when "0000" => result <= ('0' & a_u)  ; 
						when "0001" => result <= ('0' & b_u) - ('0' & a_u );
						when "0010" => result <=  not ('0' & b_u );
						when "0011" => result <= ('0' & a_u) + ('0' & b_u );
						when "0100" => result <= ('0' & a_u) XOR ('0' & b_u );
						when "0101" => result <= ('0' & a_u) OR ('0' & b_u );
						when "0110" => result <= ('0' & a_u) AND ('0' & b_u ); 
						when "0111" => result <= ('0' & a_u) * "000000001";
						when "1000" => comparateur <= (a_u = b_u);
						when "1001" => comparateur <= (a_u \= b_u);
						when "1010" => comparateur <= (a_u < b_u);
						when "1011" => comparateur <= (a_u <= b_u);
						when "1100" => comparateur <= (a_u > b_u);
						when "1101" => comparateur <= (a_u >= b_u);
						when others => result <= "111111111";
					end case;


					Rom_Address <= "00000";
					Delay_Line_Address <= "00000";

					Delay_Line_sample_shift <= '0';
					Accu_ctrl <= '0';
					Buff_OE <= '0';
					
					next_state<=S1;

				when S1 => ADC_Convstb <= '0'; --request of conversion
					CLRb <= '1'; -- DAC ready

					if ADC_Eocb='0' then next_state <= S2; -- waiting for end of conversion
					else next_state<=S1;
					end if;

				when S2 => ADC_Convstb <= '1'; --end of conversion request
					ADC_Rdb <= '0'; -- sending data to data bus (their avaiability)

					next_state<=S3; 

				when S3 => Delay_Line_sample_shift <= '1'; -- inserting data into delay line

					if counter_I="11111" then next_state <= S4; -- 31 in binary
					else if t=5 then next_state <= S4 ;
						if counter_I="11111" then next_state <= S4; -- 31 in binary
						else if t=5 then next_state <= S4 ;
						else next_state<=S1delay;
						end if;
					else next_state<=S1delay;
						counter_I_temp <= counter_I+1; 
					end if;
					else next_state<=S1delay;
						counter_I_temp <= counter_I+1; 
					end if;

				when S1delay => ADC_Rdb <= '1';  -- disabling data avaiability
					Delay_Line_sample_shift <= '0';
					-- Wait for is not synthesisable

					next_state<=S1delay2;

				when S1delay2 => next_state<=S1;
					
				when others => next_state <= current_state;


	end case;
    end process P_FSM;
	
	ADC_Convstb <= ADC_Eocb when ADC_Eocb='1' else -- affectation concurrent -> BONUS
					'0' when current_state=S8 else
					'1';
					
	
end Behavior;
