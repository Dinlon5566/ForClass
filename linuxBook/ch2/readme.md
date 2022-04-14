# 第二章 使用者模式可實現功能
### 呼叫 System call
###### 使用檔案 [hello.c | hello.py | hello.log | hello.py.log ]
用 strace 來看 hello.c
`$cc -o hello hello.c`
`strace -o hello.log ./hello`

用 strace 來看 hello.py
`strace -o hello.py.log python3 ./hello.py`

用 cat 查看文檔
`cat hello.log`

使用 sar 得知 CPU 歷程資訊 按下 ctrl-C 輸出平均值 
`sar -P ALL(全部CPU) 1 (每1秒記錄一次)`
> 檔案 SAR_1.log

使用 ldd 查看程式與函式庫
`$ ldd /bin/echo`
`$ ldd ppidloop`
> 檔案 ldd.log

##### todo
