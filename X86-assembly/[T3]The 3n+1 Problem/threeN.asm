
INCLUDE libary.inc

.data
len DWORD 1
.code
threeN PROC,num:DWORD
	pushad
	mov len,1
	;while(n!=1)
	mov eax,num
w_head:
	cmp eax,1
	je w_end

	inc len												;len++

	TEST eax,1
	jne odd
	
	mov edx,0
	mov ebx,2
	div ebx
	jmp W_head
odd:
	mov ebx,3
	mul ebx
	inc eax
	jmp w_head
w_end:

	popad
	mov eax,len
	ret
	threeN ENDP
END
