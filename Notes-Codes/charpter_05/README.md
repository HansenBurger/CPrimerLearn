# 5. 循环和关系表达式

## 5.1 for循环

参考程序: [01_for_loop.cpp](Notes-Codes/charpter_05/01_for_loop.cpp)

### 5.1.1 for循环的组成

步骤:

1. 设置初始值
2. 执行测试，看循环是否应当继续进行
3. 执行循环测试
4. 更新用于测试的值

> for(**1**init; **2**test; **4**update) </br> **3** body

test-expression本身可以是任何类型，但是执行时会被转换到bool类型

具体for循环的执行流程可以参考:

![forloop](https://www.algbly.com/Assets/img/content-image/For%20Loop.png)

参考程序: [02_test_expression.cpp](Notes-Codes/charpter_05/01_test_expression.cpp)

#### (1) 表达式和语句

> 任何值或任何有效的值和运算符的组合都是表达式

对于赋值运算符，考虑的是 **=** 左侧的值，对于连续的赋值，就是最左侧的值，如"x=y=z=0"，参考x的值。

cout输出布尔类型，都会强制转换为int，可以通过以下语句输出bool值:

```c++
cout.setf(ios_base::boolalpha);
```

参考程序: [03_expression.cpp](Notes-Codes/charpter_05/03_expression.cpp)

#### (2) 非表达式语句

典型的是不带赋值的声明语句，int toad，本身不能用于赋值或者循环(非boody)

#### (3) 修改规则

首先，循环内声明变量的作用域只作用在循环内，其次init-statement和condition之间可以不加分号

参考程序: [01_for_loop_initinside.cpp](Notes-Codes/charpter_05/01_for_loop_initinside.cpp)

### 5.1.2 循环完成工作

可以用循环来输出阶乘的结果:

1. const的作用域由其声明的位置决定
2. 不使用using namespace 依然可以用std::方法实现
3. 循环内初始化的变量作用域只在循环内

参考程序: [04_loop_for_more.cpp](Notes-Codes/charpter_05/04_loop_for_more.cpp)

### 5.1.3 修改步长

修改步长输出等差数列

参考程序: [05_steps_in_loop.cpp](Notes-Codes/charpter_05/05_steps_in_loop.cpp)

### 5.1.4 for访问字符串

for循环倒序输出字符串

参考程序: [06_for_in_string.cpp](Notes-Codes/charpter_05/06_for_in_string.cpp)

> string类的大小可以用成员函数.size()

### 5.1.5 递增和递减运算符

++x: 使用变量前先自加

x--: 使用变量后再自加

参考程序: [07_plus_one.cpp](Notes-Codes/charpter_05/07_plus_one.cpp)

### 5.1.6 副作用和顺序点(自加自减)

递增递减最好不要和其他表达式一起计算，结果会和预期不一致

```c++
y = (4 + x++) + (6 + x++);
```

自加可能完成在子表达式后，也可能完成在全部的表达式后

### 5.1.7 前缀和后缀的选择

1. 在循环的update使用中，两者没有区别
2. 除内置类型外，对用户定义的类型，**前缀效率更高**

### 5.1.8 递增递减指针

递增递减和指针的原则:

1. ++前缀和\*前缀优先级**相同**
2. ++后缀要优先于\*前缀(**优先结合，处理之后**)

参考程序: [08_incremental_ptr.cpp](Notes-Codes/charpter_05/08_incremental_ptr.cpp)

**面试常见**:

#### (1) cout << \*++pt

地址自加，再输出指向的对象

```c++
pt = pt + 1;
cout << *pt;
```

#### (2) cout << ++\*pt

指向的对象自加并输出

```c++
*pt = *pt + 1;
cout << *pt;
```

#### (3) cout << (\*pt)++

先取出指向对象，输出后，再自加

```c++
cout << *pt;
*pt = *pt + 1;
```

#### (4) cout << \*pt++

先取出指向对象，输出后，指针自加

```c++
cout << \*pt;
pt = pt + 1;
```

### 5.1.9 组合赋值运算符

1. +=等价于让被赋值的对象先加再赋值
2. 左右两边**都是常量无效**(常量不能被赋值)

### 5.1.10 复合语句块

1. 循环可以用大花括号存放更多的执行语句
2. c++不依赖于缩进关系，没有大花括号，只能执行循环后的一行
3. 语句块中声明的变量**作用域只在语句块**
4. 当语句块外部和内部有同名变量，语句块内会覆盖语句块外的变量，直到语句块结束(**就近原则**)

参考程序: [09_for_block.cpp](Notes-Codes/charpter_05/09_for_block.cpp)

### 5.1.11 逗号运算符

1. 逗号运算符是针对**语句(expression)**，如"i++, j--;"
2. 对于变量声明中的 "int i, j = 1;"，只是分隔，因为同时对二者进行了声明
3. 在所有运算符中逗号运算符**优先级最低**

> cats = 17, 240; 等价于先(cats = 17), 240

参考程序: [10_for_in_string_2.cpp](Notes-Codes/charpter_05/10_for_in_string_2.cpp)

### 5.1.12 关系运算符

1. 关系运算符优先级**低于**算数运算符
2. 关系运算比较出的结果会自动转换为**整型**

### 5.1.13 易错点(==, =)

1. "==" 与 "=" 混淆，一个是关系运算，一个是赋值(在循环中做condition也是有效的)
2. 赋值运算输出**永远为真**，可能在编译器中不报错

### 5.1.14 C风格字符串比较

1. "=="直接比较的是两个字符串的地址，对于变量和字符串常量的比较而言，肯定为假
2. 比较字符串可以用ctring中的方法strcmp，相同返回0，不同返回其他整型
3. 字符串1在字符串2前，返回负值
4. 字符串1在字符串2后，返回正值

参考程序: [12_comp_str_char.cpp](Notes-Codes/charpter_05/12_comp_str_char.cpp)

### 5.1.15 string字符串比较

1. string类之间可以"=="判断是否相等
2. string和字符串常量，string和c风格字符串也满足条件1
3. 比c风格的字符串比较更加简洁直观
4. 和之前循环不一样，不依赖于循环次数(while也能实现)
