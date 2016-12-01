LIBRARY IEEE; 
USE IEEE.STD_LOGIC_1164.ALL; 
USE IEEE.STD_LOGIC_UNSIGNED.ALL; --df s fs  s fsf fg vfcv
--df s fs  s fsf fg vfcv
ENTITY compteur IS 

    PORT ( 
          clk:IN  STD_LOGIC;          
          compt_sortie : OUT STD_LOGIC_VECTOR(4 DOWNTO 0); 
          horloge_sortie : OUT STD_LOGIC 
         ); 
END compteur; 
