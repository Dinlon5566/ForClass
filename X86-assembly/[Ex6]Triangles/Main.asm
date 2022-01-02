;------------------------------------------------
;Exercise-6: Compute the Area of Triangles
;Author : 408261292
;
; Compute the area of a triangle.
;------------------------------------------------
;note https://www.hgy413.com/hgydocs/IA32/

INCLUDE Irvine32.inc

includelib legacy_stdio_definitions.lib
includelib ucrt.lib

ExitProcess proto,dwExitCode:DWORD

scanf PROTO C, format:PTR BYTE,args:VARARG
printf PROTO C, pString:PTR BYTE, args:VARARG 

.data

;point2D define
point2D	STRUCT		
	x		DWORD	?											
	y		DWORD	?												
point2D	ENDS

;triangle define
triangle	STRUCT		
	line_a	REAL8	?												
	line_b	REAL8	?											
	line_c	REAL8	?													
	area	REAL8	?													
triangle	ENDS

num_x	REAL8 ?											;save x
num_y	REAL8 ?											;save y
num_s	REAL8 ?											;save (a+b+c)/2
divtwo		REAL8 0.5									;way to get num_s
area_v	REAL8 ?											;
input6num	BYTE	"%d%d%d%d%d%d",0					;scanf format
outputFloat	BYTE "%.3f",0								;printf format

input_points point2D 3 DUP(<>)							;three line
line_data	triangle 1 DUP(<>)							;one triangle

.code
main proc
	
proc_begin:

	finit
	call inputPoint
	;exit when EOF 
	cmp eax,-1
	je proc_end

	call getLine
	
	call getArea

	INVOKE printf,ADDR outputFloat,line_data[esi].area
	call crlf											;It cann't work at cmd pipe : (
	;call testFunc

jmp proc_begin

proc_end:

	invoke ExitProcess,0
main endp

inputPoint PROC
	
	mov esi,TYPE input_points.x
	INVOKE scanf,ADDR input6num,
						  ADDR input_points[esi].x,
						  ADDR input_points[esi].y,
						  ADDR input_points[esi+8].x,						
						  ADDR input_points[esi+8].y,
						  ADDR input_points[esi+16].x,
						  ADDR input_points[esi+16].y				
	
	ret
inputPoint ENDP

getLine PROC
	
	;LINE_A
	;(b.x-a.x)^2
	mov esi,TYPE input_points.x
	fild input_points[esi+8].x							;m32int input
	fild input_points[esi].x							;m32int input
	fsubp												;b-a
	fst num_x											;Store to the memory
	fmul num_x											;^2

	;(b.y-a.y)^2
	fild input_points[esi+8].y							;m32int input
	fild input_points[esi].y							;m32int input
	fsubp												;b-a
	fst num_y											;Store to the memory
	fmul num_y											;^2

	;sqrt( L1^2+L2^2 )
	fadd	
	fsqrt									
	mov esi,TYPE line_data.line_a
	fst		line_data[esi].line_a

	;LINE_B
	;(c.x-b.x)^2
	mov esi,TYPE input_points.x
	fild input_points[esi+16].x							;m32int input
	fild input_points[esi+8].x							;m32int input
	fsubp												;b-a
	fst num_x											;Store to the memory
	fmul num_x											;^2

	;(c.y-b.y)^2
	fild input_points[esi+16].y							;m32int input
	fild input_points[esi+8].y							;m32int input
	fsubp												;b-a
	fst num_y											;Store to the memory
	fmul num_y											;^2

	;sqrt( L1^2+L2^2 )
	fadd	
	fsqrt									
	mov esi,TYPE line_data.line_b
	fst		line_data[esi].line_b

	;LINE_C
	;(c.x-a.x)^2
	mov esi,TYPE input_points.x
	fild input_points[esi+16].x							;m32int input
	fild input_points[esi].x							;m32int input
	fsubp												;b-a
	fst num_x											;Store to the memory
	fmul num_x											;^2

	;(b.y-a.y)^2
	fild input_points[esi+16].y							;m32int input
	fild input_points[esi].y							;m32int input
	fsubp												;c-a
	fst num_y											;Store to the memory
	fmul num_y											;^2

	;sqrt( L1^2+L2^2 )
	fadd	
	fsqrt									
	mov esi,TYPE line_data.line_c
	fst		line_data[esi].line_c

	ret
getLine ENDP

getArea PROC

	mov esi,TYPE line_data.line_a
	;a+b+c
	fld line_data[esi].line_a
	fadd line_data[esi].line_b
	fadd line_data[esi].line_c
	fmul divtwo
	fld divtwo
	fst	 line_data[esi].area
	fst num_s
	fsub line_data[esi].line_a
	fld num_s											;(s-a)->ST(1)
	fsub line_data[esi].line_b				
	fld num_s											;(s-b)->ST(1)
	fsub line_data[esi].line_c

	fmul												;(s-c)(s-b)
	fmul												;(s-c)(s-b)(s-a)
	fmul num_s											;(s-c)(s-b)(s-a) * s	
	fsqrt
	
	;fst	 line_data[esi].area

	ret
getArea ENDP

testFunc PROC

	;for test
	mov esi,TYPE line_data.line_a
	INVOKE printf,ADDR outputFloat,line_data[esi].line_a
	mov esi,TYPE line_data.line_b
	INVOKE printf,ADDR outputFloat,line_data[esi].line_b
	mov esi,TYPE line_data.line_c
	INVOKE printf,ADDR outputFloat,line_data[esi].line_c
	INVOKE printf,ADDR outputFloat,line_data[esi].area

	ret
testFunc ENDP

end main