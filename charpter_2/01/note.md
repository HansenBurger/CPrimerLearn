# 2.1 Enyering C++

## 2.1.1 程序框架

cpp编写

```c++
int main(void):{
    return 0;
}
```

shell下执行

```bash
g++ 1.cpp # generate .out file (compiling)
./1.out # run executable file
```

程序两部分:

1. 函数头(花括号外)

2. 函数体(花括号内)

函数体:

1. 函数体内的语句**必须**要有分号来表示语句结束

2. 函数体最后有一个返回语句(表示函数运行结束)

函数头:

1. 函数头类型表示返回类型("int"为整型, "return 0;"与其匹配)

2. 调用main函数的是**启动代码**(.out中包括cpp的代码和启动代码)

3. **启动代码**由操作系统调用

4. return 0 作为标识当前函数调用的状态

> main()为空, 表示不接受任何参数, void同理

补充:

1. 虽然 int main(), main(), int main(void), void main() 同理, 还是尽量使用标准的int main() 或 int main(void)

2. C++必须包含main()函数, 通常从main()函数开始执行

3. **编写动态链接库不需要main()函数**, 因为是被调用的库, 而非程序

4. 如单片机程序等硬件, 程序执行从**地址**开始, 不需要考虑函数名

注释:

1. 作用解释程序的一部分

2. 编译器不会去执行, 从注释符号开始之后的全部

3. 一行注释: "//", 一段注释: "/* xx */"

## 2.1.2 程序头文件

程序开头

```c++
#include <iostream>
using namespace std;
```

### 1. 预处理器

#include 会在预编译的时候将iostream内的内容添加到程序, 并将原始代码文件和iostream组合复合文件传递给编译器

### 2. 头文件名

对于C++的头文件需要相对于C**去掉.h**

### 3. 名称空间

using为**编译指令**, 名称空间是C++的特性, 目的是为了更好使用封装好的库, 避免不同库中同名的函数冲突

> 把产品封装在名称空间单元内

```c++
Microflop::wanda("go dancing");
Piscine::wanda("a fish named desire"); 
```

不想在函数前加入命名空间, 则需要在头部加入这个编译指令using

```c++
using std::cout;
using std::endl;
```

只开放命名空间中的几个函数, 用起来更好