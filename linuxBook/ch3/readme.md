# 第三章 行程管理
### fork() & execve()
#### fork()
`fork` 可以複製程式
```c
	pid_t ret;
    ret = fork();
	printf("hello");
	/*
	ret 回傳值 :
	0 : 該程式為子程序 
	n : 子程序PID
	*/
```
順序不一定
```c
Output:
hello //by parent
hello //by child
```
#### execve()
我看不懂，之後寫
### ELF
使用 readelf -h 查看開始位置
```
┌──(user01㉿kali)-[~/workspace/linuxBook/ch3]
└─$ readelf -h /bin/sleep
ELF 檔頭：
魔術位元組：7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  類別:                              ELF64
  資料:                              2 的補數，小尾序(little endian)
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI 版本:                          0
  類型:                              DYN (Position-Independent Executable file)
  系統架構:                          Advanced Micro Devices X86-64
  版本:                              0x1
  進入點位址：              0x25f0
  程式標頭起點：            64 (檔案內之位元組)
  區段標頭起點：                     37824 (檔案內之位元組)
  旗標：             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         11
  Size of section headers:           64 (bytes)
  Number of section headers:         30
  Section header string table index: 29
                                          
```
使用 readelf -S 查看偏移量、大小、開始位置

```
┌──(user01㉿kali)-[~/workspace/linuxBook/ch3]
└─$ readelf -S /bin/sleep                                                                                                                                                                                                              130 ⨯
There are 30 section headers, starting at offset 0x93c0:

區段標頭：
  [號] 名稱              類型             位址              偏移量
       大小              全體大小         旗標   連結  資訊  對齊
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .interp           PROGBITS         00000000000002a8  000002a8
       000000000000001c  0000000000000000   A       0     0     1
  [ 2] .note.gnu.bu[...] NOTE             00000000000002c4  000002c4
       0000000000000024  0000000000000000   A       0     0     4
  [ 3] .note.ABI-tag     NOTE             00000000000002e8  000002e8
       0000000000000020  0000000000000000   A       0     0     4
  [ 4] .gnu.hash         GNU_HASH         0000000000000308  00000308
       0000000000000048  0000000000000000   A       5     0     8
  [ 5] .dynsym           DYNSYM           0000000000000350  00000350
       00000000000005a0  0000000000000018   A       6     1     8
  [ 6] .dynstr           STRTAB           00000000000008f0  000008f0
       00000000000002bf  0000000000000000   A       0     0     1
  [ 7] .gnu.version      VERSYM           0000000000000bb0  00000bb0
       0000000000000078  0000000000000002   A       5     0     2
  [ 8] .gnu.version_r    VERNEED          0000000000000c28  00000c28
       0000000000000060  0000000000000000   A       6     1     8
  [ 9] .rela.dyn         RELA             0000000000000c88  00000c88
       00000000000002b8  0000000000000018   A       5     0     8
  [10] .rela.plt         RELA             0000000000000f40  00000f40
       0000000000000450  0000000000000018  AI       5    24     8
  [11] .init             PROGBITS         0000000000002000  00002000
       0000000000000017  0000000000000000  AX       0     0     4
  [12] .plt              PROGBITS         0000000000002020  00002020
       00000000000002f0  0000000000000010  AX       0     0     16
  [13] .plt.got          PROGBITS         0000000000002310  00002310
       0000000000000008  0000000000000008  AX       0     0     8
  [14] .text             PROGBITS         0000000000002320  00002320
       0000000000003fce  0000000000000000  AX       0     0     16
  [15] .fini             PROGBITS         00000000000062f0  000062f0
       0000000000000009  0000000000000000  AX       0     0     4
  [16] .rodata           PROGBITS         0000000000007000  00007000
       0000000000000b94  0000000000000000   A       0     0     32
  [17] .eh_frame_hdr     PROGBITS         0000000000007b94  00007b94
       00000000000002ec  0000000000000000   A       0     0     4
  [18] .eh_frame         PROGBITS         0000000000007e80  00007e80
       0000000000000e40  0000000000000000   A       0     0     8
  [19] .init_array       INIT_ARRAY       0000000000009d30  00008d30
       0000000000000008  0000000000000008  WA       0     0     8
  [20] .fini_array       FINI_ARRAY       0000000000009d38  00008d38
       0000000000000008  0000000000000008  WA       0     0     8
  [21] .data.rel.ro      PROGBITS         0000000000009d40  00008d40
       00000000000000b8  0000000000000000  WA       0     0     32
  [22] .dynamic          DYNAMIC          0000000000009df8  00008df8
       00000000000001e0  0000000000000010  WA       6     0     8
  [23] .got              PROGBITS         0000000000009fd8  00008fd8
       0000000000000028  0000000000000008  WA       0     0     8
  [24] .got.plt          PROGBITS         000000000000a000  00009000
       0000000000000188  0000000000000008  WA       0     0     8
  [25] .data             PROGBITS         000000000000a1a0  000091a0
       0000000000000080  0000000000000000  WA       0     0     32
  [26] .bss              NOBITS           000000000000a220  00009220
       00000000000001c0  0000000000000000  WA       0     0     32
  [27] .gnu_debugaltlink PROGBITS         0000000000000000  00009220
       0000000000000049  0000000000000000           0     0     1
  [28] .gnu_debuglink    PROGBITS         0000000000000000  0000926c
       0000000000000034  0000000000000000           0     0     4
  [29] .shstrtab         STRTAB           0000000000000000  000092a0
       000000000000011c  0000000000000000           0     0     1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), l (large), p (processor specific)
                                                    
```