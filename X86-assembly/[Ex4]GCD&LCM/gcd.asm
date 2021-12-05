INCLUDE gcd.inc


.code
gcd PROC,num1:DWORD,num2:DWORD

	;local variable
	LOCAL Rem:DWORD

	;load variable
	mov eax,num1
	mov ebx,num2

	;if num2==0 : num1=result
	cmp ebx,0
	je return_num1

	;if num2>num1 : swap by recursion
	cmp ebx,eax
	ja return_swap

	;Euclidean algorithm
	mov edx,0
	div ebx
	mov Rem,edx
	INVOKE gcd,Rem,ebx								;recursion gcd(Rem,ebx)

	jmp end_gcd

return_swap:
	INVOKE GCD,ebx,eax								;recursion gcd(max,min)
	jmp end_gcd

return_num1:										;save result in EAX
	mov eax,num1
	jmp end_gcd
	
end_gcd:											;leave subproc
	ret
	gcd ENDP
END