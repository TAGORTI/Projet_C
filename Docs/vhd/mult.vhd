------------------------------MULT.vhd-----------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity MULT is
  port(Mult_in_A  : in  std_logic_vector(7 downto 0);
        Mult_in_B : in  std_logic_vector(7 downto 0);
        Mult_out  : out std_logic_vector(15 downto 0)) ;-- output of 16 bit because we multiply 8bit by 8bit
end MULT;


architecture A of MULT is
begin
  P_MULT : process(Mult_in_A, Mult_in_B)
  begin
 --convert Mult_in_B and  Mult_in_A to unsigned(to multiply). then  convert the result to std_logic_vector.
    Mult_out <= std_logic_vector((unsigned(Mult_in_A) * unsigned(Mult_in_B)));
  end process P_MULT;
end A;
