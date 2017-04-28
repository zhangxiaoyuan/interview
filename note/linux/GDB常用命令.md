* __首先确保安装了gdb__
* 编译文件：g++ -g xxx.cpp -o xxx / g++ -g -o xxx xxx.cpp
* 输入gdb xxx(上一步编译生成的科执行文件xxx)
* 这时候就进入了gdb，输入list查看源代码

####GDB:
>
 GNU debugger 安装GDB之后，在生成执行文件时加上-g   如：gcc -g -o hello hello.c
  list / info / break / file / continue / run / step / display / run / quit


> list/l：查看源代码  
break/b 行号/函数名：对应位置打断点  
delete 断点编号：删除对应断点，断点编号可以用i b查询  
info break/i b:查看断点信息  
run:开始运行程序  
next:单步执行，不进入函数  
step:单步执行，进入函数  
until:执行到比当前行号大一行为止  
jump 行号:跳转到对应行  
continue/c:执行到程序结束  
display 变量名xx：每次gdb执行命令的时候都会打印变量xx的值  
print 变量名xx：打印变量xx的值  
info stack/i s:查看当前线程的堆栈情况  
backtrace:栈回溯  
info frame:查看当前函数帧的信息  
up:往调用链上游移动，看看caller是谁  
down:往调用链下游移动，看看callee是谁  
return:从选定栈执行返回到caller  


[GDB调试命令详解](http://blog.csdn.net/haoel/article/details/2879)
