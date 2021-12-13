;----------------------------------------------------
;Sort by insertion sort
;
;for(int i=0; i<arraySize; i++)
;    for(int j=i; j>0&&nums[j]<nums[j-1]; j--)
;        swap(nums[j],nums[j-1]);
;----------------------------------------------------

INCLUDE libary.inc

.code
insertionSort PROC,
	ptrArray:PTR SDWORD,arraySize:DWORD

	mov esi,ptrArray
	mov eax,0								;eax=i=0

for1_begin:
	;for1 title

	cmp eax,arraySize						;i<arraySize
	jnb for1_end;
	push eax
	;for1 body
	
	for2_begin:
		;for2 title
		;j>0 && nums[j]<nums[j-1]
		cmp eax,0
		jna for2_end

		push eax

		mov ebx,[esi+4*eax]
		dec eax
		cmp ebx,[esi+4*eax]
		jnl for2_end

		pop eax
		push eax

		;swap(nums[j],nums[j-1]);
		mov ebx,[esi+4*eax]
		dec eax
		xchg ebx,[esi+4*eax]
		inc eax
		mov [esi+4*eax],ebx

		;for2 tail
		pop eax
		dec eax
		jmp for2_begin
	for2_end:

	;for1 tail
	pop eax
	inc eax
	jmp for1_begin
for1_end:

	ret
	insertionSort ENDP
END
