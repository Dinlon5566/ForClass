INCLUDE libary.inc

.data
	oddArr SDWORD 255 DUP (0)
	evenArr SDWORD 255 DUP (0)
	oddSum SDWORD 0
	evenSum SDWORD 0
	oddSize DWORD 0
	evenSize DWORD 0
	oddMax SDWORD ?
	evenMin SDWORD ?
	
	blank BYTE " ",0

.code
findNum PROC,
	ptrArray:PTR SDWORD,arraySize:DWORD

	mov esi,ptrArray

	; for(int i=0;i<arrSize;i++){
	mov eax,0
for1_head:
	cmp eax,arraySize
	jnb for1_end
	push eax
	;for1_body
		;if(nums[i]&1)
		mov esi,ptrArray
		mov eax,[esi+4*eax]
		;if(nums[i]&1)
		and eax,1
		cmp eax,1
		jne evenInput
		
		;odd[oddSize]=nums[i]
		mov esi,ptrArray
		pop eax
		push eax
		mov ecx,[esi+4*eax]
		mov ebx,oddSize
		mov esi,OFFSET oddArr
		mov [esi+4*ebx],ecx
		inc oddSize
		jmp inputEnd
		evenInput:
		;even[evenSize]=nums[i];
		mov esi,ptrArray
		pop eax
		push eax
		mov ecx,[esi+4*eax]
		mov ebx,evenSize
		mov esi,OFFSET evenArr
		mov [esi+4*ebx],ecx
		inc evenSize
		inputEnd:
		
	;for1_tail
	pop eax
	inc eax
	jmp for1_head
for1_end:

	; int oddMax=odd[0]
    ; int evenMin=even[0]
	mov esi,OFFSET oddArr
	mov eax,[esi]
	mov oddMax,eax
	mov esi,OFFSET evenArr
	mov eax,[esi]
	mov evenMin,eax

	;cout<<oddSize;
	mov eax,oddSize
	call writeDec

	;for(int i=0;i<oddSize;i++)
	mov eax,0
for2_head:
	cmp eax,oddSize
	jnb for2_end
	push eax
	;for2_body
		;cout<<" "<<odd[i];
		mov edx,OFFSET blank
		call writeString
		mov esi,OFFSET oddArr
		mov ebx,[esi+4*eax]
		xchg eax,ebx						;eax=i,ebx=odd[i]
		call writeInt
		xchg eax,ebx
		add oddSum,ebx
		cmp ebx,oddMax
		jng not_oddMax
		mov oddMax,ebx
		not_oddMax:
	;for2_tail
	pop eax
	inc eax
	jmp for2_head
for2_end:

	call crlf

	;even
	mov eax,evenSize
	call writeDec 
	
	;copy begin(even)
	mov eax,0
for3_head:
	cmp eax,evenSize
	jnb for3_end
	push eax
	;for3_body
		;cout<<" "<<even[i];
		mov edx,OFFSET blank
		call writeString
		mov esi,OFFSET evenArr
		mov ebx,[esi+4*eax]
		xchg eax,ebx						;eax=i,ebx=odd[i]
		call writeInt
		xchg eax,ebx
		add evenSum,ebx
		cmp ebx,evenMin
		jnl not_evenMin
		mov evenMin,ebx
		not_evenMin:
	;for3_tail
	pop eax
	inc eax
	jmp for3_head
for3_end:
	call crlf
	;copy end(even)

	;output max&min
	mov eax,oddMax
	call writeInt
	mov edx,OFFSET blank
	call writeString
	mov eax,evenMin
	call writeInt
	call crlf

	;output sum
	mov eax,oddSum
	call writeInt
	mov edx,OFFSET blank
	call writeString
	mov eax,evenSum
	call writeInt
	call crlf

	ret
	findNum ENDP
END
