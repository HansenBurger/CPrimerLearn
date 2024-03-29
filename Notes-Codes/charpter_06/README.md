# 6. 分支语句和逻辑运算符

## 6.1 if 语句

if语句的基本流程可以参考:

![if-condition](https://iowiki.com/static/cimg/scala/scala_decision_making.jpg)

参考程序: [01_if_count_blank.cpp](Notes-Codes/charpter_06/01_if_count_blank.cpp)

### 6.1.1 if else 语句

if-else语句则让程序决定执行两条语句或语句块中的哪一条，这种语句对于选择其中一种操作很有用。

参考程序: [02_str_encode.cpp](Notes-Codes/charpter_06/02_str_encode.cpp)

> ch + 1和ch++不等价，ch+1会提升类型为int

### 6.1.2 格式化 if else语句

由于C++不会自动将if和else之间的所有代码视为一个代码块，因此必须使用大括号将这些语句组合成一个语句块。

> 即if结构结束后再加else就会报错

```c++
if(ch == 'A')
    cout << ch;
cout << "process ends." << end;
else    // 编译错误
    cout << '\n';
```

所以对于多条语句**必须使用**大花括号。

### 6.1.3 多重条件

多个条件判断可以用if-else if-else结构，实际是if-else被包裹在另一个else内，但更清晰。

```c++
if(cond_0)
    state_0;
else
    if(cond_1)
        state_1;
    else(cond_2)
        state_2;
```

等价于

```c++
if(cond_0)
    state_0;
else if(cond_1)
    state_1;
else
    state_2;
```

参考程序: [03_if_elseif.cpp](Notes-Codes/charpter_06/03_if_elseif.cpp)

> 条件运算符中更推荐使用(**value == variable**)避免出现(variable=value)的错误。

## 6.2 逻辑表达式

### 6.2.1 逻辑OR运算符: ||

或运算: 左右有一个为真，即真；左右都假，即假

或运算优先级较低，可以不加括号，但加入括号可以避免优先级先后错误(提升代码阅读性)

表达式只要左侧为真，就不会判断右侧(**节省CPU性能**)

参考程序: [04_logic_or.cpp](Notes-Codes/charpter_06/04_logic_or.cpp)

### 6.2.2 逻辑AND运算符: \&\&

与运算: 左右都真，即真；有一为假，即假

与运算优先级**高于**逻辑或，建议加入括号

表达式只要左侧为假，就不会判断右侧

参考程序: [05_logic_and.cpp](Notes-Codes/charpter_06/05_logic_and.cpp)

### 6.2.3 用\&\&来设置取值范围

```c++
a >= 100 && b <= 150;
```

参考程序: [06_logic_and_setrange.cpp](Notes-Codes/charpter_06/06_logic_and_setrange.cpp)

注意不要写成数学符号：

```c++
17 < a < 35;
(17 < a ) < 35; // 此时真假都成立
```

### 6.2.4 逻辑NOT运算符

非运算: 遇到真，为假；遇到假，为真

对于返回true-false值或可以被解释为true-false值的函数来说很有用

参考程序: [07_not_climits.cpp](Notes-Codes/charpter_06/07_not_climits.cpp)

> 非运算符的优先级**高于**所有关系运算符和算数运算符，需要括号

### 6.2.5 逻辑运算符细节

最简单的方法还是用括号将测试进行分组，而不管是否需要括号。这样代码容易阅读，避免读者查看不常使用的优先级规则，并减少由于没有准确记住所使用的规则而出错的可能性。

## 6.3 字符函数库cctype

1. 判断是否字符: isalpha()
2. 判断是否数字: isdigit()
3. 判断标点符号: ispunct()

参考程序: [08_cctype.cpp](Notes-Codes/charpter_06/08_cctype.cpp)

## 6.4 条件运算符

通用格式: expression1 ? expression2 : expression3

输出结果: exp_1真，输出exp_2；exp_1假，输出exp_3

参考程序: [09_condition_choose.cpp](Notes-Codes/charpter_06/09_condition_choose.cpp)

使用建议: 简单关系，条件简单，用条件表达式；多种情况，判断复杂，用if/else。

## 6.5 switch语句

通用格式:

```c++
switch(integer-expression)
{
    case label1: statement(s)
    case label2: statement(s)
    case label4: statement(s)
    default: statement(s)
}
```

关键点:

1. 其中integer-exp必为整型表达式，label也是整型内
2. 对于任何都不满足的会转到default，**default非必要**；如果没有default，都不满足就结束switch。
3. 执行完指定的case不会跳出switch，**除非增加break**。

参考程序: [10_switch_report.cpp](Notes-Codes/charpter_06/10_switch_report.cpp)

### 6.5.1 将枚举量作为标签变量

case的label需要常量，枚举量也是等效的。

参考程序: [11_enum_switch.cpp](Notes-Codes/charpter_06/11_enum_switch.cpp)

### 6.5.2 switch和ifelse

1. ifelse更通用，适合取值范围的选择(浮点型，分类不多)
2. 对于选项超过两个，且选项都是整型的任务来说，switch**效率更高**

> 如果既可以使用if else if语句，也可以使用switch语句，则当选项不少于3个时，应使用switch语句

## 6.6 break和continue语句

break跳出循环，continue结束本次循环，具体参考:

![break_continue](https://i.ytimg.com/vi/UUaObrE-Ypw/maxresdefault.jpg)

> 注意: continue对于for循环会直接**跳到更新表达式**，对于while循环会直接**跳到测试表达式**。所以需要检查continue之前是否经过更新表达式。

参考程序: [12_break_continue.cpp](Notes-Codes/charpter_06/12_break_continue.cpp)

**禁用goto语句！**

## 6.7 读取数字循环

读取数字中输入字母，会出现类型不匹配，此时:

1. n值保持不变(没有初始化默认0?)
2. 不匹配的输入留在输入队列
3. cin对象中的一个错误标记被设置
4. 对cin方法的调用将返回false(转换bool型)

此时**cin的读取输入功能会被禁用**，解决步骤:

1. cin.clear()，重置当前cin的状态
2. while循环用cin.get()读取掉队列中错误的输入
3. 提示用户再次输入

用程序表示即:

```c++
cin.clear();
while(cin.get() != '\n');
```

参考程序: [13_cin_clear.cpp](Notes-Codes/charpter_06/13_cin_clear.cpp)

参考程序: [14_cin_count_fish.cpp](Notes-Codes/charpter_06/14_cin_count_fish.cpp)

参考程序: [15_cin_count_golf.cpp](Notes-Codes/charpter_06/15_cin_count_golf.cpp)

## 6.8 简单文件输入/输出

### 6.8.1 文本I/O和文本文件

使用cin进行输入时，程序将输入视为一系列的字节，其中**每个字节都被解释为字符编码**。

> 不管目标数据类型是什么，输入一开始都是字符数据——文本数据

char读取浮点数(38.5):

```c++
char ch;
cin >> ch;
```

此时ch内存储的时字符"3"，而使用int读取浮点数(38.5)，会读取到非数字字符为止:

```c++
int x;
cin >> x;
```

此时存储到x内的时38的二进制编码。同理如果读取char类型的数组，则是直到遇到空白字符为止，cin.get()则是直到遇到"\n"符号为止。

两者共通之处: **控制台输入的文件版本是文本文件**，即每个字节都存储了一个字符编码的文件。

### 6.8.2 写入文本文件

c++中写入文件可以参考标准输出流程:

1. 调用fstream头文件
2. 创建ofstream类型的对象
3. 关联对象和文本文件(open)
4. 同cout的操作
5. 关闭ofstream对象(close，非必要，程序运行完也会关闭)

程序表现:

```c++
#include <iostream>
#include <fstream>

ofstream outFile;
outFile.open("xxxx.txt");
outFile << "Something output." << endl;
outFile.close();
```

参考程序: [16_output_file.cpp](Notes-Codes/charpter_06/16_output_file.cpp)

open**注意**:

1. 对于不存在的文件，open会新建文件
2. 对于已存在的文件，**默认将它其长度截短为零，因此原来的内容将丢失**。

### 6.8.3 读取文本文件

c++中写入文件可以参考标准输入流程:

1. 调用fstream头文件
2. 创建ifstream类型的对象
3. 关联对象和文本文件(open)
4. 同cin的操作
5. 关闭ifstream对象(close，非必要，程序运行完也会关闭)

```c++
#include <fstream>

ifstream inFile;
inFile.open("xxxx.txt");
int value;
inFile >> value;
inFile.close();
```

参考程序: [17_read_a_file.cpp](Notes-Codes/charpter_06/17_read_a_file.cpp)

需要注意的是，和写入文本不同，读取文本需要注意**文件是否能够打开**和**读取值的有效性**

文件能否打开可以使用ifstream类的is_open()函数，不能打开退出程序可以写成如下形式:

```c++
#include <cstdlib>

if(!inFile.is_open())
    exit(EXIT_FAILURE);
```

对于读取值得有效性可以用ifstream类本身读取方法，fail()，eof()来判断(**对于老版本，也可以用good()**)。其中eof用来判断读写是否结束，fail用来判断读写是否成功(**类型匹配**)。

> c++在读取文件时，也需要通过**空白字符**(回车，换行)判断输入结束，对于文本最后的内容，如果没有自动的换行符补充，需要手动添加。
