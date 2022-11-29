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
