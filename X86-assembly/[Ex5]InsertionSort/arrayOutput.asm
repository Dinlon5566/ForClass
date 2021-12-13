INCLUDE libary.inc

.code
arrayOutput PROC,
	ptrArray:PTR SDWORD,arraySize:DWORD,ptrBlank:PTR BYTE

	mov esi,ptrarray
	mov ecx,arraySize
	mov edx,ptrBlank
next_out:
	mov eax,[esi]
	cmp eax,0
	jl negative

postive:								;+
	call writeDec
	jmp numberOut_end

negative:								;-
	call writeInt

numberOut_end:

	call writeString
	add esi,4
	loop next_out

	call crlf
	
	mov esi,ptrArray
	mov eax,arraySize
	mov ebx,2
	mov edx,0
	div ebx
	mov ecx,eax
toCenter:
	add esi,4
	loop toCenter
	mov eax,[esi]

	cmp eax,0
	jl negative2

postive2:								;+
	call writeDec
	jmp numberOut_end2

negative2:								;-
	call writeInt
	
numberOut_end2:

	cmp edx,0
	jne center_end

	mov edx,ptrBlank
	call writeString

	sub esi,4
	mov eax,[esi]

	cmp eax,0
	jl negative3

postive3:								;+
	call writeDec
	jmp numberOut_end3

negative3:								;-
	call writeInt
	
numberOut_end3:

center_end:

	call crlf
	ret
	arrayOutput ENDP
END