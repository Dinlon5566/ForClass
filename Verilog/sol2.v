
module qu1(

 input CLOCK_50,
 input [3:0] KEY,
 input [17:0] SW,
 output [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7,

 output [8:0] LEDG, 
 output [17:0] LEDR,
 
 output [3:0] result1,result2,
 
 output f1,f2,f3,f4,f5,f6,f7,f8,
 
 inout [35:0] GPIO_0, GPIO_1
);

assign GPIO_0 = 36'hzzzzzzzzz;
assign GPIO_1 = 36'hzzzzzzzzz;
assign LEDR[17:0] = SW[17:0];
assign LEDR[17]= SW[17];
assign LEDR[16] = SW[16];
assign LEDG[8:0] = 0;
wire [15:0] A;

circuit(A[0],A[1],A[2],A[3],f1,f2,f3,f4,f5,f6,f7,f8);

assign result1[0] = f1;
assign result1[1] = f2;
assign result1[2] = f3;
assign result1[3] = f4;

assign result2[0] = f5;
assign result2[1] = f6;
assign result2[2] = f7;
assign result2[3] = f8;

hex_7seg(result1,HEX0); 
hex_7seg(result2,HEX1);

wire [6:0] blank = ~7'h00; 

assign HEX2 = blank;
assign HEX3 = blank;
assign HEX4 = blank;
assign HEX5 = blank;
assign HEX6 = blank;
assign HEX7 = blank;

assign A = SW[15:0];
endmodule
module hex_7seg(hex_digit,seg);
input [3:0] hex_digit;
output [6:0] seg;
reg [6:0] seg;

always @ (hex_digit)
case (hex_digit)
 4'h0: seg = ~7'h3F;
 4'h1: seg = ~7'h06; // ---a----
 4'h2: seg = ~7'h5B; // | |
 4'h3: seg = ~7'h4F; // f b
 4'h4: seg = ~7'h66; // | |
 4'h5: seg = ~7'h6D; // ---g----
 4'h6: seg = ~7'h7D; // | |
 4'h7: seg = ~7'h07; // e c
 4'h8: seg = ~7'h7F; // | |
 4'h9: seg = ~7'h67; // ---d----
 4'hA: seg = ~7'h77;
 4'hC: seg = ~7'h39;
 4'hE: seg = ~7'h79;
 4'hF: seg = ~7'h71;
 endcase
endmodule

module circuit(a,b,c,d,f1,f2,f3,f4,f5,f6,f7,f8);
input a,b,c,d;
output f1,f2,f3,f4,f5,f6,f7,f8;
wire s1,s2,s3;
and(f1,a);
and(f2,b);
and(f3,c);
and(f4,d);
and(f5,a);
and(f6,b);
and(f7,c);
and(f8,d);
endmodule
