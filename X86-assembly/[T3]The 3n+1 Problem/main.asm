;------------------------------------------------
;Exercise-6: 3n+1
;Author : 408261292
;
;------------------------------------------------

INCLUDE libary.inc

.data
	numi DWORD ?
	numj DWORD ?
	max3n DWORD ?
	blank BYTE " ",0
.code
main proc
	
proc_begin:
	call readInt
	cmp eax,0
	je proc_end
	mov numi,eax
	call readInt
	mov numj,eax

	;output
	mov eax,numi
	call writeDec
	mov edx,OFFSET blank
	call writeString
	mov eax,numj
	call writeDec
	call writeString

	;swap?
	mov eax,numi
	mov ebx,numj
	cmp eax,ebx
	jna noSwap
	;swap
	xchg eax,ebx
	mov numi,eax
	mov numj,ebx

noSwap:

	mov max3n,0
; for(int a=i;a<=j;a++)
	mov eax,numi
for1_head:
	cmp eax,numj
	ja for1_end
	push eax

	;for1 body

	INVOKE threeN,eax
	mov ebx,max3n
	cmp eax,ebx
	jna nothing
	mov max3n,eax
nothing:

	;for1_tail
	pop eax
	inc eax
	jmp for1_head
for1_end:

	;output max3n
	mov eax,max3n
	call writeDec
	call Crlf

	jmp proc_begin
proc_end:

	invoke ExitProcess,0
main endp
end main