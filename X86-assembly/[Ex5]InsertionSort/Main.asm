;------------------------------------------------
;Exercise-5: Implementation of Sorting Algorithms(Insertion sort)
;Author : 408261292
;
; Implement a sorting algorithm to sort a set of integers in ascending order.
;------------------------------------------------

INCLUDE libary.inc

.data
	array SDWORD 200 DUP (0)
	arraySize DWORD 0			
	intFormat BYTE "%d",0
	blank BYTE " ",0
.code
main proc

proc_begin:

	;input arraySize and array data.

	invoke scanf,ADDR intFormat,ADDR arraySize
	mov ecx,arraySize
	mov eax,arraySize
	cmp eax,0
	je proc_end
	mov esi,OFFSET array										;set array offset

data_input:
	pushad
	invoke scanf,ADDR intFormat,ADDR [esi]
	popad
	add esi,TYPE Array											;next SDWORD space
	loop data_input

	;input data end

	;sort function by invoke 
	INVOKE insertionSort,ADDR array,arraySize

	;Output array by invoke 
	INVOKE arrayOutput,ADDR array,arraySize,ADDR blank

	jmp proc_begin
proc_end:
	invoke ExitProcess,0
main endp
end main