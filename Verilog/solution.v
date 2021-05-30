//ODD Program verilog solution for QUIZ1 is as follows:
//MODULE 1 for input and output comes below.

/*
	本專案為以HEX0輸出16進位數字，來源SW[0~3]
	By Dinlon.
*/

//中文註解是我寫的，英文是教授的
//有跟改的下方都會[!!!]標記

module plus(
 // Clock Input (50 MHz)
 input CLOCK_50,
 // Push Buttons
 input [3:0] KEY,
// DPDT Switches 
 input [17:0] SW,
// 7-SEG Displays
 output [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7,
// LEDs
 output [8:0] LEDG, // LED Green[8:0]
 output [17:0] LEDR, // LED Red[17:0]
 
 output [3:0] result1,
 //[!!!]result數量為邀輸出燈號數量，本案為1個
 
 output f1,f2,f3,f4,
 //[!!!]改成接入HEX燈信號的output
 
// GPIO Connections
 inout [35:0] GPIO_0, GPIO_1
);

// set all inout ports to tri-state
assign GPIO_0 = 36'hzzzzzzzzz;
assign GPIO_1 = 36'hzzzzzzzzz;
// Connect dip switches to red LEDs
assign LEDR[17:0] = SW[17:0];
assign LEDR[17]= SW[17];
assign LEDR[16] = SW[16];
// turn off green LEDs
assign LEDG[8:0] = 0;
wire [15:0] A;
// The following line called the circuit module with the input and output

circuit(A[0],A[1],A[2],A[3],f1,f2,f3,f4);
//circuit為下面你的主函式名稱
//[!!!]為(A[0]...<--input,f1...<--output)跟C++差不多

assign result1[0] = f1;
assign result1[1] = f2;
assign result1[2] = f3;
assign result1[3] = f4;
//[!!!]result1[0~3]為燈的4個信號接口

//[!!!]只需要一個燈，把其他的改成blank

// map to 7-segment displays
hex_7seg(result1,HEX0); // We are calling a module called hex_7seg
//這裡設定result1為HEX0的來源


wire [6:0] blank = ~7'h00; 
// blank remaining digits
//設定blank，之後才能使用

assign HEX1 = blank;
assign HEX2 = blank;
//[!!!]HEX1,HEX2不需要用到，改成blank

assign HEX3 = blank;
assign HEX4 = blank;
assign HEX5 = blank;
assign HEX6 = blank;
assign HEX7 = blank;
// A <= SW[15:0];

assign A = SW[15:0];
endmodule
module hex_7seg(hex_digit,seg);
input [3:0] hex_digit;
output [6:0] seg;
reg [6:0] seg;
// 0 is on and 1 is off
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

module circuit(a,b,c,d,f1,f2,f3,f4);
input a,b,c,d;
output f1,f2,f3,f4;
wire s1,s2,s3;
and(f1,a);
and(f2,b);
and(f3,c);
and(f4,d);
endmodule