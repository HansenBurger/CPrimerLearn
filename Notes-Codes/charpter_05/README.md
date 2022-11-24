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

参考程序: [13_comp_str_string.cpp](Notes-Codes/charpter_05/13_comp_str_string.cpp)

## 5.2 while循环

while循环没有初始化和更新部分，只有测试条件和循环体

参考程序: [14_while_print_char.cpp](Notes-Codes/charpter_05/14_while_print_char.cpp)

> **注意:** 字符数组中每个元素本身就可以做判断条件，出现'\0'就等于False，但是string类不用'\0'标记字符串结尾

### 5.2.1 for与while

相同点:

1. for循环和while循环之间可以互相转换，把for循环的init-state放在while外，update-state放在body内。(for循环也可以省略初始化和update-state)
2. for循环和while循环对于多行body都需要放入花括号，**不由缩进决定**

差异点:

1. while(1) 等价于 for( ; ; )
2. for可以初始化局部变量但while不行
3. for通常用于可计数循环，**while通常用于无记数循环**
4. continue在for中执行会转到update-state，而while循环中则根据continue在body中的位置决定

设计循环的原则:

1. 指定循环终止的条件
2. 在首次测试之前初始化条件
3. 在条件被再次测试前更新条件

> 循环后加入分号";"代表循环体为**空**

### 5.2.2 编写延时循环

可以用while让系统等待，程序如下:

```c++
long wait = 0;
while (wait < 10000)
    wait++;
```

但等待的时间主要取决于计算机处理器的运算速度，可以用clock()返回**系统时间**来控制延迟，即

```c++
clock_t = sec * CLOCK_PER_SEC
```

其中CLOCK_PER_SEC是计算机**每秒包含的系统时间单位**，而clock_t是**int**的别名，为了更直观的表示变量，可以用typedef定义别名(建议不用define，**作为别名定义的唯一方法**)，即

```c++
typedef typeName aliaName;
```

也可以用来声明指针的别名，即

```c++
typedef char * bytte_pointer;
```

别名的优势:

1. 更直观的表示变量
2. 益于代码的移植

参考程序: [15_while_delay.cpp](Notes-Codes/charpter_05/14_while_delay.cpp)

## 5.3 do while循环

多数时候用for和while循环，即在执行前先判断，但对于**需要用户输入的**，需要有输入为先，推荐用do while。

参考程序: [16_do_while.cpp](Notes-Codes/charpter_05/16_do_while.cpp)

> 编写清晰、容易理解的代码比使用语言的晦涩特性来显示自己的能力更为有用

## 5.4 基于范围的for循环(c++11)

这个特性主要用于16章中的**容器类**，其中只遍历数组中的元素可以用:

```c++
double prices[5] = {4.99, 10.99, 6.87, 6.87, 7.99, 8.49}
for (double x:prices)
    cout << x << endl;
```

修改数组中的元素可以用:

```c++
for (double &x : prices)
    x = x * 0.80;
```

其中"\&"表示x为引用变量，此为运算符重载的一种方法，还可以基于初始化列表:

```c++
for (int x:{3,5,2,8,6})
    cout << x << " ";
cout << '\n';
```

## 5.5 循环和文本输入

### 5.5.1 原始cin进行输入

循环读取键盘输入，用**哨兵字符**作为停止标记，cin读取字符时会跳过**空白字符**。

参考程序: [17_text_loop_1.cpp](Notes-Codes/charpter_05/17_text_loop_1.cpp)

> 需要注意，这里循环输入是指从用户的**输入队列**中循环读取，也就是说直到按下回车，队列中的字符才会发给程序

### 5.5.2 cin.get(char)

cin.get可以用来捕获被跳过的空白字符(包括空格和回车)。

参考程序: [18_text_loop_2.cpp](Notes-Codes/charpter_05/18_text_loop_2.cpp)

> 需要注意，c中传递到函数中的变量不会修改他的值本身，而是修改拷贝，但cin.get()中参数被声明为**引用类型**，可以修改参数值

### 5.5.3 使用哪一个cin.get()(函数重载)

存在这样的情况:

```c++
cin.get(name, ArSize).get();
cin.get(ch);
```

对于可以同一个函数可以接收多种参数的情况，是**运算符重载**，即多个同名函数，但其输入参数不同，**就可以有多种版本**。

### 5.5.4 文件尾条件

EOF: 检测文本和文件，可以用ctrl+z模拟EOF

当检测到EOF，cin会将(**eofbit,failbit**)设置为1，可以用cin.eof和fail函数来检测(eof为true，反之false)。

win中的EOF为ctrl+z，而linux环境中为ctrl+d。

参考程序: [19_text_loop_3.cpp](Notes-Codes/charpter_05/19_text_loop_3.cpp)

要点:

1. EOF检测对于文本读取来说没问题，但对于键盘输入而言，可能会**结束循环**，可以用cin.clear()清楚EOF标记
2. cin.get()返回的也是cin对象
3. 程序可以对cin对象进行true/false判断，因此cin.get(ch)本身可以作为循环的test-statement

```c++
while(cin.get(ch));
```

## 5.6 嵌套循环和二维数组

使用下标访问二维数组可以参考:

![2D_Array](https://media.geeksforgeeks.org/wp-content/uploads/two-d.png)

```c++
for(int row = 0; row < 4; row++)
{
    for(int col = 0; col < 5; ++col)
        cout << maxtemps[row][col] << "\t";
    cout << endl;
}
```

### 5.6.1 初始化二维数组

初始化二维数组可以参考一维数组的方法:

```c++
int maxtemps[2][3] = 
{
    {0, 1, 0},
    {1, 0, 1}
};
```

### 5.6.2 使用二维数组(字符串数组)

初始化字符串数组的三种方法

1.声明字符指针数组(此时指针可以指向字符串的首地址)

```c++
const char * arr[3] = {
    "AAA",
    "BBB",
    "CCC"
}
```

初始化中如果都是字符串常量，不修改，需要增加const，避免编译报错

2.声明二维字符数组

```c++
const char arr[3][20] = {
    "AAA",
    "BBB",
    "CCC"
}
```

这种方法需要指定字符串的长度，可能会浪费，可能会不够，不推荐用

3.声明string类数组

```c++
std::string arr[3] = {
    "AAA",
    "BBB",
    "CCC"
}
```

string类，可以不添加const用字符串常量初始化，也不会报错。

参考程序: [20_2d_array.cpp](Notes-Codes/charpter_05/20_2d_array.cpp)
