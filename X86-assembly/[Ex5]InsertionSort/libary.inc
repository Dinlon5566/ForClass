INCLUDE Irvine32.inc

;C library
includelib ucrt.lib							
includelib legacy_stdio_definitions.lib


scanf PROTO C,format:PTR BYTE, args:VARARG

insertionSort PROTO,
	ptrArray:PTR SDWORD,arraySize:DWORD

arrayOutput PROTO,
	ptrArray:PTR SDWORD,arraySize:DWORD,ptrBlank:PTR BYTE

ExitProcess PROTO,dwExitCode:DWORD

