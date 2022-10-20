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
