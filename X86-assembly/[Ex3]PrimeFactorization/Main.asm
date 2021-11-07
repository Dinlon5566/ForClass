INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
star byte " * ",0
powchar byte "^",0

firstout sdword 0
power sdword ?
diver sdword ?

.code
main proc
prostart:
	call readint
	js proend
	cmp eax,2
	jb prostart

	call PrimeFactorization
	call crlf

	;return porgram beging
	jmp prostart
proend:

	invoke ExitProcess,0
main endp

PrimeFactorization proc
	
	pushad

	
	;init val
	mov diver,2
	mov firstout,0

	;while eax>1
L1:
	cmp eax,1
	jna proend

	mov power,0

	;while num>1 & num%div==0
L2:
	cmp eax,1
	jna L2end
	push eax
	mov edx,0
	div diver
	cmp edx,0
	pop eax
	jne L2end

	mov edx,0
	div diver
	add power,1

	jmp L2
L2end:
	
	;output star

	cmp firstout,0
	je L3a
	cmp power,0
	je L3a

	mov edx,OFFSET star
	call writeString
	jmp L3end
L3a:
	cmp power,0
	je L3end
	mov firstout,1
L3end:

	;out result
	cmp power,1
	jne L4a
	push eax
	mov eax,diver
	call writeDec
	pop eax
	jmp L4end
L4a:
	cmp power,1
	jna L4end
	push eax
	mov eax,diver
	call writeDec
	mov edx,OFFSET powchar
	call writeString
	mov eax,power
	call writeDec
	pop eax
L4end:

	add diver,1

	jmp L1
proend:
	popad

	ret
PrimeFactorization endp
end main