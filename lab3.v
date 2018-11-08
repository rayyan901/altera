module lab3 (CLOCK_50,SW,KEY,HEX0);

input CLOCK_50;
input [7:0] SW;
input [0:0] KEY;
output [6:0] HEX0;



nios_system u0
 (
        .clk_clk         (CLOCK_50),         //      clk.clk
        .reset_reset_n   (KEY),   //    reset.reset_n
        .switches_export (SW), // switches.export
        .se7segs_export  (HEX0)   //  se7segs.export
  );
  
  endmodule  