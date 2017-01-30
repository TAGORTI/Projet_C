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
	   A,B			: in STD_LOGIC_VECTOR(7 downto 0) ;
	   comparateur			: out std_logic;
	   CMD			: in STD_LOGIC_VECTOR(3 downto 0) ;
	   ADC_Eocb_bar         : out  std_logic;
	   Filter_Out  : out std_logic_vector(7 downto 0));
end FSM;


architecture Behavior of FSM is



begin

    P_FSM: process(current_state, ADC_Eocb, counter_I, counter_J)
	
	variable t : time;
	variable HEIGHT : integer := 8;
	variable COND : boolean := true;
	variable IN_STRING : string(1 to 80);
	variable M,N : bit := '1';
	variable I : integer range 0 to 3; 
	
    begin

    end process P_FSM;

end Behavior;
