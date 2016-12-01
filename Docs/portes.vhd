library portes;
use portes.all;



package cell is

  entity and_2 is
    port (
      a : in  bit;
      b : in  bit;
      c : out bit);
  end and_2;

  entity or_2 is
    port (
      a : in  bit;
      b : in  bit;
      c : out bit);    
  end or_2;
  
  entity not_1 is
    port (
      a : in  bit;
      c : out bit);    
  end not_1;
  
  entity xor_2 is
    port (
      a : in  bit;
      b : in  bit;
      c : out bit);    
  end xor_2;

  entity eq is
    port (
      a : in  bit;
      b : in  bit;
      c : out bit);    
  end eq;

  entity mux_2 is    
    port (
      a,b   : in  bit;
      enable: in  bit;
      c     : out bit);
  end mux_2;

  entity mux_4 is    
    port (
      a1,a2,a3,a4 : in  bit;
      enable   : in  bit_vector(1 downto 0);
      c     : out bit);
  end mux_4;

  entity mux_8 is    
    port (
      a1,a2,a3,a4,a5,a6,a7,a8     : in  bit;
      enable   : in  bit_vector(2 downto 0);
      c     : out bit);
  end mux_8;

  entity and_2_vec is
    generic (
      S : integer);
    port (
      a : in  bit_vector (S-1 downto 0);
      b : in  bit_vector (S-1 downto 0);
      c : out bit_vector (S-1 downto 0));
  end and_2_vec;

  entity or_2_vec is
    generic (
      S : integer);
    port (
      a : in  bit_vector (S-1 downto 0);
      b : in  bit_vector (S-1 downto 0);
      c : out bit_vector (S-1 downto 0));    
  end or_2_vec;
  
  entity not_1_vec is
    generic (
      S : integer);
    port (
      a : in  bit_vector (S-1 downto 0);
      c : out bit_vector (S-1 downto 0));    
  end not_1_vec;
  
  entity xor_2_vec is
    generic (
      S : integer);
    port (
      a : in  bit_vector (S-1 downto 0);
      b : in  bit_vector (S-1 downto 0);
      c : out bit_vector (S-1 downto 0));    
  end xor_2_vec;

  entity eq_vec is
    generic (
      S : integer);  
    port (
      a : in  bit_vector (S-1 downto 0);
      b : in  bit_vector (S-1 downto 0);
      c : out bit);    
  end eq_vec;

  entity mux_2_vec is
    generic (
      S : integer);  
    port (
      a,b     : in  bit_vector (S-1 downto 0);
      enable   : in  bit;
      c     : out bit_vector (S-1 downto 0));
  end mux_2_vec;

  entity mux_4_vec is
    generic (
      S : integer);
    port (
      a1,a2,a3,a4     : in  bit_vector (S-1 downto 0);
      enable   : in  bit_vector(1 downto 0);
      c     : out bit_vector (S-1 downto 0));
  end mux_4_vec;

  entity mux_8_vec is
    generic (
      S : integer);
    port (
      a1,a2,a3,a4,a5,a6,a7,a8     : in  bit_vector (S-1 downto 0);
      enable   : in  bit_vector(2 downto 0);
      c     : out bit_vector (S-1 downto 0));
  end mux_8_vec;
  
  entity latch is
    port (
      D     : in  bit;
      clk   : in  bit;
      reset : in  bit;
      Q     : out bit);
  end latch;
  
  entity flip_flop is
    port (
      D     : in  bit;
      clk   : in  bit;
      reset : in  bit;
      Q     : out bit);
  end flip_flop;

  entity registre is
    generic (
      S : integer);
    port (
      D          : in  bit_vector (S-1 downto 0);
      clk, reset : in  bit;
      Q          : out bit_vector (S-1 downto 0));
  end registre;

  entity registre_e is   
    generic (
      S : integer);
    port (
      D          : in  bit_vector (S-1 downto 0);
      e          : in  bit;
      clk, reset : in  bit;
      Q          : out bit_vector (S-1 downto 0));
  end registre_e;

  entity add is    
    generic (
      S : integer);
    port (
      A, B  : in  bit_vector (S-1 downto 0);
      R     : out bit_vector (S-1 downto 0);
      c_out : out bit);
  end add;

  entity sub is  
    generic (
      S : integer);
    port (
      A, B  : in  bit_vector (S-1 downto 0);
      R     : out bit_vector (S-1 downto 0);
      c_out : out bit);
  end sub;

  entity mult is   
    generic (
      S : integer);
    port (
      A, B  : in  bit_vector (S-1 downto 0);
      R     : out bit_vector (S-1 downto 0);
      c_out : out bit);
  end mult;
  end cell;


  package body cell is

    

  end cell;
