;------------------------------------------------
;Assembly languageThe fourth computer test
;Author : 408261292
;
;------------------------------------------------

INCLUDE Irvine32.inc

ExitProcess proto,dwExitCode:DWORD

.data

arraySize	DWORD ?										;n
maxNum		REAL4 ?										;maxNum	
minNum		REAL4 ?										;minNum
sum			REAL4 ?										;sum of array
zero		DWORD 0
blank		BYTE " ",0
array		REAL4 300 DUP(?)							;float array

.code
main proc
	
proc_begin:

	;input n
	call readInt
	cmp eax,0
	je proc_end
	mov arraySize,eax

	;call    ShowFPUStack

	;init reg
	mov ecx,eax
	finit
	mov edi,OFFSET array

L1:
	call ReadFloat
	fstp REAL4 PTR[edi]
	add edi,4
	loop L1

	;init max/min val
	mov edi,OFFSET array
	fld REAL4 PTR[edi]
	fst maxNum
	fst minNum
	
	fstp sum

	;cont max/min
	mov ecx,arraySize
	dec ecx
	add edi,4
	
	mov edi,OFFSET array
	add edi,4
L2:
	;sum+=num
	fld REAL4 PTR[edi]
	fadd sum
	fstp sum

	;maxNum=max(maxNum,num)
	fld REAL4 PTR[edi]
	fcomp maxNum
	fnstsw ax
	sahf
	jna L3
	fld REAL4 PTR[edi]
	fstp maxNum
L3:
	fld REAL4 PTR[edi]
	fcomp minNum
	fnstsw ax
	sahf
	jnb L4
	fld REAL4 PTR[edi]
	fstp minNum
L4:

	add edi,4
	loop l2

	fld minNum
	call WriteFloat

	mov edx,OFFSET blank
	call WriteString

	fld maxNum
	call WriteFloat
	call crlf

	fld sum
	call WriteFloat
	call crlf

	fld minNum
	fmul maxNum
	call WriteFloat
	call crlf

	fld sum
	fild arraySize
	fdiv
	call WriteFloat
	call crlf

	fld sum
	fabs
	fsqrt
	call WriteFloat


proc_end:


	invoke ExitProcess,0
main endp

end main