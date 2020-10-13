
includelib legacy_stdio_definitions.lib			

.386
.model flat,C

;PROTO
scanf PROTO C, format:PTR BYTE, args:VARARG
printf PROTO C,pString:PTR BYTE, args:VARARG
AllPrimeFactors PROTO C,arg1:DWORD

.data
Num DWORD 0
format BYTE "%d",0

.code
mainasm PROC										;start
	INVOKE scanf,ADDR format,ADDR Num
	INVOKE AllPrimeFactors,Num
	INVOKE printf,ADDR format,EAX
	RET
mainasm ENDP
END