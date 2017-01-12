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
       Buff_OE                  : out std_logic) ; --
end FSM;


architecture Behavior of FSM is
type STATE is (S0,S1,S2,S3,S4,S6,S8,S9,S10,S1delay,S1delay2,S9delay); 
signal current_state : STATE;
signal next_state : STATE;
signal counter_I: unsigned (4 downto 0);
signal counter_J: unsigned (4 downto 0);
signal counter_I_temp: unsigned (4 downto 0);
signal counter_J_temp: unsigned (4 downto 0);

begin
-- synchronous state

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
    begin
	case current_state is	when S0 => ADC_csb <= '0' ; -- initializing state
					ADC_Convstb <= '1';
					ADC_Rdb <= '1';
					DAC_csb <= '0';
					DAC_WRb <= '1';
					LDACb <= '1';
					CLRb <= '0'; -- reset dac output and register

					counter_i_temp <= "00000";
					counter_j_temp <= "00000";

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
					else next_state<=S1delay;
						counter_I_temp <= counter_I+1; 
					end if;

				when S1delay => ADC_Rdb <= '1';  -- disabling data avaiability
					Delay_Line_sample_shift <= '0';
					-- Wait for is not synthesisable

					next_state<=S1delay2;

				when S1delay2 => next_state<=S1;

				when S4 => ADC_Rdb <= '1'; -- disabling data avaiability
					Delay_Line_sample_shift <= '0';
					
					Delay_Line_Address <= "00000";
					Rom_Address <= "00000";

					Accu_ctrl <= '1';
					next_state<=S6;

--					next_state<=S5; -- i think it work with a state less

--				when S5 => Accu_ctrl <= '1';
--
--					next_state<=S6;

				when S6 => Accu_ctrl <= '0';

					if counter_J="11110" then next_state <= S8;  
						Buff_OE <= '1'; -- danger active buffer at the right clock !!!
						counter_J_temp <= "00000";
					else next_state<=S6;
						counter_J_temp <= counter_J_temp+1; 
						Delay_Line_Address <= std_logic_vector(counter_J);					
						Rom_Address <= std_logic_vector(counter_J);
					end if;

--				when S7 => Buff_OE <= '1'; -- danger active buffer at the right clock !!!
--					counter_J <= '0';
--					next_state<=S8;

				when S8 => Buff_OE <= '0';
					
					DAC_WRb <= '0'; --request of registering value in DAC
					ADC_Convstb <='0';  --request of conversion

					next_state<=S9delay;
					
				when S9delay => DAC_WRb <= '1';
					ADC_Convstb <='1'; 

					next_state<=S9; 

				when S9 => LDACb <= '0'; -- request of analogic output update

					next_state<=S10; 

				when S10 => LDACb <= '1';

					if ADC_Eocb='0' then next_state <= S2; -- waiting for end of conversion
					else next_state<=S10;
					end if;
					

				when others => next_state <= current_state;


	end case;
    end process P_FSM;
end Behavior;
