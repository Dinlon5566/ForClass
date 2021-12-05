;------------------------------------------------
;Exercise-4: GCD 
;Author : 408261292
;
;Calculates and print number's LCM & GCD by invoke ./gcd.asm
;------------------------------------------------

INCLUDE gcd.inc

.386
.model flat,stdcall
.stack 4096

.data
	;In fact, these are not needed, but it will be easier to read
	num1 DWORD ?
	num2 DWORD ?
	result DWORD ?
	
	blank BYTE " ",0					;String of blank

.code
main proc

procBegin:

	call ReadInt						;read num1

	;End if input==-1
	cmp eax,-1
	je progEnd

	;save num1 & read num2
	mov num1,eax
	call ReadInt
	mov num2,eax

	;call fuction
	INVOKE gcd,num1,num2				;gcd(num1,num2)
	mov result,eax
	call WriteDec						;output result (form eax)

	;output " "
	mov edx,OFFSET blank
	call WriteString

	;calution LCM
	mov eax,num1
	mul num2
	div result
	call WriteDec
	call Crlf

	jmp procBegin
progEnd:
	invoke ExitProcess,0
main endp
end main