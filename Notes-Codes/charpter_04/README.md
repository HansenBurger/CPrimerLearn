# 4. 复合类型

## 4.1 数组

数组(array)

1. 定义: 是一种数据格式，能够存储多个同类型的值
2. 特征: 每个值都存储在一个独立的数组元素中，计算机在内存中依次存储数组的各个元素。
3. 声明必要: 1.存储类型，2.数组名，3.元素个数

> 数组的元素之间连续排布，不存在空隙

数组声明示例:

```c++
typeName arrayName[arraySize];
```

arraySize可以写成多种形式，但必定是确定的大小(常量)

数组根据下标对数组中的元素进行访问:

![array_index](https://cdn.programiz.com/sites/tutorial2program/files/cpp-array-empty-members.png)

> 编译器不会检查下标有效，运行时会出现问题

如果将sizeof运算符用于数组名，得到的将是整个数组中的字节数

### 4.1.1 数组初始化规则

1. 只有**在定义数组时才能使用初始化**，即只能在定义时初始化，不能先定义再初始化。
2. 如果对数组的部分初始化，那会对后续的元素全部置0。
3. 声明长度为空，可以根据初始化的长度自动确定

### 4.1.2 数组初始化方法

1. 可以省略等号
2. 初始化 {} 为空，会全部置0
3. 无法缩窄(long数组存不了double变量)

## 4.2 字符串

两种类型:

1. C-style string
2. string 类库

字符数组和字符串:

1. 字符串的结尾要用 **空字符('\0')** 来表示，字符串和字符数组都可以用数组表示，区别就在于有无空字符。
2. 对于用字符数组表示的字符串，输出到'\0'停止，对于单纯的字符数组，一直输出全部字符，直到内存中遇到'\0'结束。
3. 声明可以直接用双引号括起字符串，这种字符串被称为字符串常量（string constant）或字符串字面值（string literal）
4. cin 输入字符串时，也是存入字符数组，**并补充空字符**。

> 在确定存储字符串所需的最短数组时，需将结尾的空字符计算在内。对于数组长度大于字符串长度时，会在字符后自动补空字节

**补充**：'' 和 ""不能混用，"S" = {'S', '\0'} = 字符串内存地址，不能给char类型变量。

### 4.2.1 拼接字符串

```c++
char s1[6] = {'H','e','l','l','o','\0'}
char s2[6] = {'W','o','r','l','d','\0'}
char s1s2[11] = {'H','e','l','l','o','W','o','r','l','d','\0'}
```

第一个字符串的空字符被第二个取代，不会添加空格，而是紧跟其后

### 4.2.2 数组中使用字符串

1. sizeof 计算的是字符数组的长度
2. \<cstring\> 库中的strlen只计算可见字符的长度(不包括'\0')

### 4.2.3 字符串输入

对于cin类，空白字符(space, enter)，对于"Alistair Dreeb":

1. "Alistair'\space'Dreeb'\Enter'"
2. 遇到'\space'，将"Alistair"存入字符数组，"Dreeb'\Enter'"放入缓冲区
3. 再次遇到输入，会接着从缓冲区读取

而面向行的类成员函数有: getline()和get()

#### (1) getline()

```c++
cin.getline(name, 20);
```

istream类的成员函数，\Enter作为输入的结尾，**但不保存到输入队列，将\Enter用'\0'替换**

1. param1: 存储行的数组名
2. param2: 读取的字符数

#### (2) get()

```c++
cin.get(name, ArSize);
cin.get(desert, ArSize); // error
```

istream类的成员函数，\Enter作为输入的结尾，**停止读取，将\Enter保留到输入队列**

1. param1: 存储行的数组名
2. param2: 读取的字符数

为了解决第二次get读取直接从换行符开始导致输入为空，可以连续调用来读取\Enter，具体实现有两种方法:

方法1:

```c++
cin.get(name, ArSize);
cin.get();
cin.get(desert, ArSize); // error
```

方法2:

基于cin.get返回的也是cin对象

```c++
cin.get(name, ArSize).get();
```

#### (3) 两者区别

1. 老式实现没有getline()
2. get能够确定是因为数组满了而停止读取还是遇到了换行符(直接输出最后一个字符)
3. getline简单，get便于检查

### 4.2.4 混合输入

cin本身也是将换行符保留在输入队列的，如果用getline和get则会导致字符串接收为空，需要用get()中的两种方法解决。

## 4.3 string 类

string类使用起来比数组简单，同时提供了将字符串作为一种数据类型的表示方法。**string类也位于命名空间std当中**。

参考程序: [7_string_class.cpp](Notes-Codes/charpter_04/7_string_class.cpp)

string和字符数组的区别:

1. 可以将string对象声明为**简单变量**，而不是数组
2. 程序能够自动处理string的大小
3. 使用string对象更方便，也更安全

### 4.3.1 赋值-拼接-附加

赋值: **数组不能赋值给数组**(数组名本身指代的是数组地址)，但string可以赋值给string。

拼接: string对象可以用加法运算符，还可以用"+="将string添加到末尾。

参考程序: [8_string_operation.cpp](Notes-Codes/charpter_04/8_string_operations.cpp)

### 4.3.2 string类其他操作

使用c-风格的字符串，可以使用cstring中的函数方法，有"strcpy"，"strcat"等方来实现前文所说的赋值，拼接和附加操作，但是**使用还是string类更方便简洁**

参考程序: [9_c_string_func.cpp](Notes-Codes/charpter_04/9_c_string_func.cpp)

### 4.3.3 string类I/O

1. 对于一个string对象，cout处理时和c风格字符串一致
2. 但读取一行时，句法不同

参考程序: [10_string_getline.cpp](Notes-Codes/charpter_04/10_string_getline.cpp)

#### (1) 初始化长度区别

```c++
char charr[20];
cout << strlen(charr) << endl;
```

此时输出结果不是20，因为字符数组声明且不初始化，只有一个内存空间，且内部字符是随机的，**此时的长度是由内存空间什么时候出现空字符决定**。

```c++
string str;
cout << str.size() << endl;
```

此时输出的结果是0，因为未初始化的string对象**长度自动为0**。

#### (2) getline

```c++
string str;
getline(cin, str)
```

string对象读取输入用的不是cin的成员函数，而是直接使用"getline"函数，从cin捕获输入并赋值给string对象，**string对象自动调整大小**。

> 本质原因还是istream缺少对处理string类的方法，cin >> str成立，是基于string类的友元函数

## 4.4 结构简介

数组可以存储多个元素，但不能存储多个数据类型。

结构(可以视作自己创建的数据类型)是一种比数组更灵活的数据格式，因为同一个结构可以存储多种类型的数据。

![struct_c++](https://i0.wp.com/coderhalt.com/wp-content/uploads/2021/08/word-image.png?resize=695%2C339&ssl=1)

### 4.4.1 使用结构体

定义结构体以后就可以创建结构体变量(c++中可以省略关键字struct):

```c++
struct coderHalt goose;
coderHalt goose;
```

对声明的结构体变量进行赋值，不需要用 ";" 做分隔符号

```c++
goose = {
    10,
    'H'
};
```

对于结构体内部的成员可以用 "." 来访问，"goose.ch" 就表示goose变量的ch成员，而ch的类型则是由结构体定义决定。

参考程序: [11_struct_init.cpp](Notes-Codes/charpter_04/11_struct_init.cpp)

> C++不提倡使用外部变量，但提倡使用外部结构声明。

### 4.4.2 结构初始化

c++11初始化方式(不推荐使用)

```c++
coderHalt dog {11, 'D'};
coderHalt cat {}; // 依据类型空初始化
```

### 4.4.3 结构体内的成员类型

参考程序: [12_struct_assign.cpp](Notes-Codes/charpter_04/12_struct_assign.cpp)

1. 可以支持string类(string类在std内，需要在定义结构体之前使用命名空间，或者std::string)

2. 结构体可以直接通过赋值操作赋值给另一个同类结构变量(不同于数组)

3. 创建结构体变量虽然可以跟在结构体之后，**但不能再创建同类的结构体变量**，因为没有声明结构体，不推荐。

### 4.4.4 结构体数组

可以声明结构体类型的数组，同样，可以用访问数组的方式访问结构体数组，也可以用访问结构体成员的方式访问结构体数组的元素的成员。

```c++
codeHalt duck[100];
```

初始化结构体数组需要两个花括号，外部是用来存数组中的每个元素，内部则是用来存元素的结构体成员

```c++
codeHalt duck[2] = {
    {0, 'A'},
    {1, 'B'}
};
```

参考程序: [13_struct_array.cpp](Notes-Codes/charpter_04/13_struct_array.cpp)

### 4.4.5 结构体中的位字段

创建硬件的**寄存器**的数据结构使用，确定位和字段

## 4.5 共用体(联合体)

共用体（union）是一种数据格式，它能够存储不同的数据类型，但只能同时存储其中的一种类型。

![differ_in_union_struct](https://static.studytonight.com/c/images/union-and-structure-storage-comparison.gif)

> union相当于抽屉，所有成员共用空间，每次只能存一个值(联合体的空间由支持最大空间的类型支持)，相当于对于同一个变量的不同形式。

共用体的用途之一是，当数据项使用两种或更多种格式（但不会同时使用）时，可节省空间。

参考程序: [14_union_init.cpp](Notes-Codes/charpter_04/14_union_init.cpp)

### 4.5.1 共用体在结构体中

union也可以用在结构体当中，有两种形式:

### (1) 有成员变量名

```c++
struct widget
{
    union id
    {
        long id_num;
        char id_char[20];
    }id_val;
}
```

可以通过连续调用访问结构体中共用体内的成员变量

```c++
widget prize;
cout << prize.id_val.id_num;
```

### (2) 无成员变量名

```c++
struct widget
{
    union id
    {
        long id_num;
        char id_char[20];
    };
}
```

可以直接调用结构体中共用体内的成员变量

```c++
widget prize;
cout << prize.id_num;
```

## 4.6 枚举

定义: enum代替const创建连续的符号常量，**默认用整数赋值**，从0开始。

赋值:

1. 枚举类型**只有赋值运算**，且只能同类赋值。
2. 枚举量是整型，可被提升为int类型，但类型不能自动转换为枚举。
3. 可以通过强制类型转换完成赋值(但如果超出枚举范围就会导致结果不确定)。

目的: **为了更方便的定义符号常量**(const 需要每个都写)。

### 4.6.1 设置枚举的值

指定枚举类型的值也是可以的，但必为整型，如果指定一个，则是通过位置关系给其他变量自动赋值:

```c++
enum bits{one = 1, two = 2, seven = 7, eight};
```

也可以在枚举类型中创建多个相同的枚举量。

### 4.6.2 枚举的范围

不是枚举值，但在枚举定义范围内的取值依然是有效的:

```c++
myflag = bits(6);
```

枚举变量的上下限:

1. 最大值的最小2的幂减1(max_bits = 8 - 1 = 7)
2. 由最小值决定，默认是0，如果小于0则依据最大值的方法确定(min_bits = 0)

## 4.7 指针和自由存储空间

存储数据时需要跟踪的三种基本属性: **地址，值，类型**。查看的地址的策略是指针，指针本身是**变量**，作用是存放值的地址。

参考程序: [15_var_address.cpp](Notes-Codes/charpter_04/15_var_address.cpp)

> 连续变量间的地址一般也是连续，但大小一般由变量类型决定，地址中差1代表1个字节

指针运算符-互反:

1. **&**: 取址运算符(取出值对应的地址)
2. **\***: 取值运算符(取出地址中的值)

参考程序: [16_pointer.cpp](Notes-Codes/charpter_04/16_pointer.cpp)

对于变量的指针在取值后操作，和对变量本身进行操作是等价的。

![relation_p_v](https://media.geeksforgeeks.org/wp-content/uploads/pointers-in-c.png)

### 4.7.1 声明和初始化指针

#### (1) 声明的表示

```c++
int * p_updates;
```

1. p_updates 本身是指针变量()
2. p_updates **指向int类型**
3. p_updates 是地址
4. *p_updates 是变量

#### (2) 声明的方法

强调 \*ptr 是int类型的变量

```c++
int *ptr;
```

强调ptr是指向int类的指针，int\*(指向int的指针)

```c++
int* ptr; 
```

空格的位置不影响变量的声明，不加也是合法的

```c++
int*ptr;
```

> int*是一种复合类型，是指向int的指针。

对于两个不同的指针变量:

```c++
double* tax_ptr;
char* str;
```

两个变量的值(存放指针的内存空间)一致，但是两者指向的对象大小不同，可以类比位数相同的门牌号和住房面积的关系。

### 4.7.2 指针的危险

声明了指针的地址，但是没有对地址进行初始化，而直接进行地址内值得赋值操作，可能此时**地址随机分配到了不能修改的地址**。

> 一定要在对指针应用解除引用运算符（*）之前，将指针初始化为一个确定的、适当的地址。

### 4.7.3 指针和数字

指针有，但本身加减运算没有实际意义，主要指针操作还是取值后运算。

指针的赋值必须要类型匹配，**强制类型转换**:

```c++
int * pt;
pt = (int *) 0xBB00000; // types now match
```

### 4.7.4 new 分配内存

C语言: 库函数malloc()

C++: new 运算符，new根据**指定类型(包括复合类型)**找到一个长度正确的内存块，并返回该内存块的地址

> new 为数据对象开辟指定大小空间

参考程序: [17_use_new.cpp](Notes-Codes/charpter_04/17_use_new.cpp)

> 必须声明指针所指向的类型的原因之一。**地址本身只指出了对象存储地址的开始，而没有指出其类型**（使用的字节数）。

补充: 开辟内存空间过多，也会导致内存耗尽。

### 4.7.5 delete 释放内存

1. delete要和new配套使用
2. delete不能去释放已经释放的内存
3. delete不能拿去释放指向同一内存块的指针

### 4.7.6 new 创建动态数组

静态数组(static binding): 需要数组长度，不管使用与否，内存都被占用(编译时加入到程序)

动态数组(dynamic binding): 程序运行时确定数组的长度，占用相应的内存空间

#### (1) new 创建动态数组

```c++
int * psome = new int[10];
```

此时psome指向数组中的**第一个地址**，释放数组内存块则是:

```c++
delete [] psome;
```

如果不带方括号，那就只会释放指针指向的元素。但delete的括号使用与否一定要和new的指针对象对应。

#### (2) 使用动态数组

相同:

有些情况下，指针和数组是等价的，**可以用下标来访问动态数组**，因为C/C++内部都是用指针处理数组。

不同:

指针(指向的位置的改变)本身可以进行加减运算，但是数组不行。

参考程序: [18_dynamic_array.cpp](Notes-Codes/charpter_04/18_dynamic_array.cpp)

## 4.8 指针、数组和指针算术

指针在内存中移动的位置是由变量的类型决定的:

![pointer_calculation](https://hackingcpp.com/cpp/slides/cpp_memory_pointer_arithmetic_07.svg)

### 4.8.1 指针加法

1. 数组名本身代表数组第1个元素地址
2. *(stacks + 1) 和 stacks\[1] 等价
3. 指针加法可以，数组加法不行

参考程序: [19_pointer_count.cpp](Notes-Codes/charpter_04/19_pointer_count.cpp)

### 补充: 数组的地址

> 数组名被解释为其第一个元素的地址，而对数组名应用地址运算符时，得到的是整个数组的地址

#### (1) 数组取地址

```c++
short tell[10];
std::cout << tell << std::endl;
std::cout << &tell << std::endl;
```

其中tell(\&tell\[0])的值为数组中第一个元素的地址，\&tell为整个数组的起始地址，**两者的值相同，但意义不同**。

```c++
std::cout << &tell[0] + 1 << std::endl;
std::cout << &tell + 1 << std::endl;
```

前者会输出第二个元素的地址，short类型(2字节)，则会在原有基础上加**1个内存块(2字节)**，而后者则要加上**10个内存块(20字节)**。

参考程序: [20_arrays_address.cpp](Notes-Codes/charpter_04/20_arrays_address.cpp)

#### (2) 指针数组结合律

```c++
short (*pas)[20] = &tell;
short *pas[20];
```

前者: pas指针，指向长度为20，存储元素为short的数组(数组的**指针**)

后者: pas\[20]数组，存的是short类型的指针(指针的**数组**)

### 4.8.2 指针小结

1. 指针声明
2. 指针赋值(\&，\*，new)
3. 解除引用(取值，数组表示法)
4. 指针，指针指向的值
5. 数组名(一般为第一个元素地址，sizeof array)
6. 指针运算(加1=原地址+指向对象占用的总字节数)
7. 动态联编(动态数组，程序运行分配)
8. 数组表示法，指针表示法

### 4.8.3 指针和字符串

对于cout输出字符串，有

```c++
char flower[10] = "rose";
std::cout << flower << "s are red\n";
```

输出结果为

```shell
roses are red
```

工作流程

1. flower为char数组的首地址
2. cout遇到char类型的地址不会直接输出地址，而是**输出字符**直到遇到空字符('\0')
3. "s are red\n"本身就是一个字符串的**首地址**，cout处理他的方式同2
4. 主要原因: 传递地址比所有字符相比减少工作量。

参考程序: [21_pointer_str.cpp](Notes-Codes/charpter_04/21_pointer_str.cpp)

strcpy 不会考虑字符串长度全复制，strncpy限定字符串长度的复制。

### 4.8.4 使用new创建动态结构

#### (1) 访问动态结构体内的成员变量

对于动态结构体变量:

```c++
struct things
{
    int good;
    int bad;
}
things grubnose = {3, 453};
things * pt = &grubnose;
```

访问pt内的成员变量可以用(->)运算符

```c++
pt->good = grubnose.good;
pt->bad = (*ps).bad;
```

参考程序: [22_new_struct.cpp](Notes-Codes/charpter_04/22_new_struct.cpp)

#### (2) 根据输入动态分配内存(new,delete)

1. new要和delete一一对应(最好在同一位置内)
2. 释放类型要匹配(delete[] a;)
3. 根据返回值类型决定函数类型(包括指针)

参考程序: [23_new_delete.cpp](Notes-Codes/charpter_04/23_new_delete.cpp)

### 4.8.5 自动存储、静态存储和动态存储

#### (1) 自动存储

1. 函数内部常规变量属于自动存储
2. 调用时创建，调用结束释放
3. 存在栈中，根据执行顺序加入，符合后进先出(LIFO)

#### (2) 静态存储

1. 全局变量输入静态存储
2. 和动态的区别就在于程序运行周期的寿命

#### (3) 动态存储

1. 人为的选择创建和释放的时机
2. 动态存储不随程序运行周期决定
3. 管理内存复杂，需要避免内存泄露(没有调用delete，占用的内存空间仍然保留)

## 4.9 类型组合

结构体声明和变量创建

```c++
struct years_end
{
    int year;
};
years_end s_0, s_1, s_2;
```

访问成员变量(运算符)

```c++
s_0.year = 1998;
```

访问成员变量(指针)

```c++
years_end * p_0 = &s_1; // 结构体指针p_0
p_0 -> year = 1999; // 间接成员运算符访问(用于指针)
```

创建结构体数组

```c++
years_end trio[3];
```

访问结构体数组内的成员变量

```c++
trio[0].year = 2003
(trio + 1) -> year = 2004; // trio为数组第一位地址
```

创建结构体指针数组(结合律):

```c++
const years_end * arp[3] = {&s_0, &s_1, &s_2}; // 是一个指针数组，指针的类型为结构体
std::cout << arp[1] -> year << std::end;
```

指向指针的指针:

```c++
const years_end ** ppa = arp;
```

参考程序: [24_mix_type.cpp](Notes-Codes/charpter_04/24_mix_type.cpp)

具体的映射流程可以参考下图:

![struct_ptr_map](https://pic1.imgdb.cn/item/636e557c16f2c2beb153c427.png)

## 4.10 数组替代品

### 4.10.1 模板类vector

1. 使用必须包含vector头文件
2. vector包含在命名空间std内
3. vector**长度可变**

```c++
#include<vector>
using namespace std;
vector<int> vi; // 长度可变
vector<double> vd(n); // 可以预设长度
```

模板:

vector\<typeName> vt (n_elem);

### 4.10.2 模板类array

1. 使用必须包含array头文件
2. array包含在命名空间std内
3. array对象**长度固定**

```c++
#include <array>
using namespace std;
array<int, 5> ai;
array<doubel, 4> ad = {1.2, 2.1, 3.43, 4.3};
```

模板:

array\<typeName, n_elem\> arr;

### 4.10.3 数组,vector,array

1. 三者都可以用"\[i]"查找第i个元素
2. 三者都不会检查索引**越界**
3. vector和array可以用arr.at()检查，但会增加运行时间
4. vector使用内存的堆，而数组和array使用时栈

参考程序: [25_choice.cpp](Notes-Codes/charpter_04/25_choice.cpp)
