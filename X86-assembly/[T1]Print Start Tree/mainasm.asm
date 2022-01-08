;FJU CSIE-10-27
;408261292
;TING PO-WEI
;P1
INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
space byte " ",0
star byte "*",0
starcount dword 1
.code
main proc
	
	;read num
start:
	call readDec

	cmp eax,0		;if eax==0->endp
	je endpro
	js start	;eax is <0

	call subpro

	jmp start	;loop again
endpro:

invoke ExitProcess,0

main endp

subpro proc
	pushad

	
	mov starcount,1;
	mov ecx,eax
L1:

	push ecx

	;print space for ecx time
	mov edx,OFFSET space
	sub ecx,1;
	cmp ecx,0
	je L2END
	
L2:
	call writestring
	loop L2
L2END:
	

	;print star for starcount time
	mov ecx,starcount
	mov edx,OFFSET star
L3:
	call writestring
	loop L3

	add starcount,2
	call crlf
	pop ecx
	loop L1

	popad
	ret
subpro endp
end main