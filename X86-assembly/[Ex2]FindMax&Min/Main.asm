INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data

minnum sdword ?
maxnum sdword ?

maxstr byte "Max : ",0
minstr byte "Min : ",0

nums sdword 200 dup(0)
datacount sdword ?


.code
main proc
	
	call readint
	mov datacount,eax
	mov ecx,eax
	mov esi,offset nums
	mov ebx,0
	mov bl,type nums

	;input arr
	makearr:
		call readint
		mov [esi],eax
		add esi,ebx
		loop makearr
	
	;set function regedit
	mov ecx,datacount
	mov esi,offset nums

	;find function
	call findmax
	call findmin

	;print result
	mov edx,offset minstr
	mov eax,minnum
	call writestring
	call writeint		
	call crlf
	mov edx,offset maxstr
	mov eax,maxnum
	call writestring
	call writeint
	call crlf

	invoke ExitProcess,0
main endp


findmax proc
	
	pushad
	
L1:
	mov eax,[esi]
	jmp returnL2
L2:
	add esi,ebx
	cmp [esi],eax
	jg L1
returnL2:
	loop L2

	mov maxnum,eax

	popad

	ret
findmax endp

findmin proc
	
	pushad
	
L1:
	mov eax,[esi]
	jmp returnL2
L2: 
	add esi,ebx
	cmp [esi],eax
	jl L1
returnL2:
	loop L2

	mov minnum,eax

	popad

	ret
findmin endp

end main
