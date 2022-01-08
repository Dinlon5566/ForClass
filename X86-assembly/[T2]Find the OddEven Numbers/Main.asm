;------------------------------------------------
;Author : 408261292
;
;------------------------------------------------

INCLUDE libary.inc

.data
	array SDWORD 255 DUP (0)
	arraySize DWORD 0
.code
main proc
	
	mov esi,OFFSET array
input_begin:
	call ReadInt
	cmp eax,0
	je input_end
	mov [esi],eax
	add esi,4
	inc arraySize
	jmp input_begin
input_end:
	INVOKE findNum,ADDR array,arraySize
	
proc_end:
	invoke ExitProcess,0
main endp
end main