# 7. 函数--C++编程模块

## 7.1 复习函数的基本知识

适用C++函数:

1. 提供函数定义
2. 提供函数原型
3. 调用函数

对于库函数而言，只要包含对应头文件即可(头文件内包含原型)，而自建函数需要满足这三个原则。

参考程序: [01_func_principle.cpp](Notes-Codes/charpter_07/01_func_principle.cpp)

### 7.1.1 定义函数

1. 没有返回值的函数称为void函数，可以不写return
2. 有返回值的函数必须**有return**，并且和**声明类型对应**
3. 函数**不能返回数组**，但可以是其他任何形式(因为数组是不支持赋值拷贝)
4. 在内存中，**返回函数**将内容存放到指定内存地址，**调用函数**到指定位置拷贝出值，需要类型匹配
5. 多个返回语句(ifelse中)，执行一个函数结束

参考程序: [02_func_return.cpp](Notes-Codes/charpter_07/02_func_return.cpp)

#### 1) 函数原型

1. 原型描述了函数到编译器的接口
2. 原型可以指出调用的错误
3. 函数定义在main之前，也可以不用原型(**不推荐**)

> 原型主要是由编译器的原理决定的，首先是效率，其次是方便多文件调用

#### 2) 原型的语句

1. 直接复制函数头
2. 不带参数名的函数头

```c++
int func(int a);    // 1
int func(int);      // 2
```

因为只要告诉编译器，函数名，返回类型，参数个数和类型，参数名不必须。

#### 3) 原型的用途

1. 编译器正确处理函数返回值
2. 编译器检查使用的参数数目是否正确
3. 编译器检查使用的参数类型是否正确。如果不正确(类型转换)。

## 7.2 函数参数和按值传递

> 函数适用的是参数的拷贝

### 7.2.1 函数调用规则

1. 会创建一个对应类型(参数类型)的变量，**并对输入值拷贝**，再处理初始化后的变量
2. 函数内部定义的变量是**私有的**，函数结束后会被释放
3. main函数内和函数内定义了相同名变量时(**二者地址完全不同，只在自己作用域工作**)

### 7.2.2 函数参数

1. 逗号分隔多个参数
2. 函数头中也用逗号来区分形参(**类型相同必须单独定义**)
3. 原型中形参的数量也要和定义中相同(**最好加上变量名，用来区分不同形参具体含义**)

参考程序: [03_func_param.cpp](Notes-Codes/charpter_07/03_func_param.cpp)

参考程序: [04_func_param_Rank.cpp](Notes-Codes/charpter_07/04_func_param_Rank.cpp)

## 7.3 函数和数组

函数可以用来处理更复杂的类型(数组，结构)，将形参声明为数组，方法如下:

```c++
int sum_arr(int arr[], int n);
```

注意，此时arr不是长度不定的数组，**而是指针**，但函数编写时可以视作数组。

参考程序: [05_array_func_cookie.cpp](Notes-Codes/charpter_07/05_array_func_cookie.cpp)

### 7.3.1 函数使用指针处理数组

> 一般来说，数组名等于数组首地址；sizeof数组名返回的是整个数组的大小(**个数\*元素字节数**)；对数组名取地址，返回的也是整个数组长度的地址

实际上的函数头:

```c++
int sum_arr(int *arr, int n);
```

两种方式都可以实现，**当且仅当在函数头和函数原型中**。有两个恒等式:

```c++
arr[i] == *(arr + i);
&arr[i] == arr + i;
```

### 7.3.2 数组作为参数的意义

使用数组名(地址)原因:

1. 将数组地址作为参数可以节省复制整个数组所需的时间和内存。
2. 数组本身不支持拷贝(**当数组量大的时候，只要处理地址，避免拷贝的系统时间**)
3. 降低破坏原始数组的风险(const)

传递数组长度进入函数的原因:

1. 传入函数的是数组的地址(**元素类型指针**)
2. size of 对**指针不能获得数组的大小**，只能得到指针的大小
3. 传递地址和大小，能更动态的索引数组内的内容

参考程序: [06_array_func_cookie_n.cpp](Notes-Codes/charpter_07/06_array_func_cookie_n.cpp)

### 7.3.3 更多数组函数示例

1. 对于输入无效的内容，需要重置标志位，并清空队列
2. 对于不希望通过指针修改内容的形参，可以添加const

输入无效内容的解决方式具体如下:

```c++
if (!cin)
{
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cout << "Bad input: input process terminated." << endl;
    break;
}
```

参考程序: [07_three_func_array.cpp](Notes-Codes/charpter_07/07_three_func_array.cpp)

### 7.3.4 使用数组区间的函数

1. 使用数组指针和长度，访问数组
2. 使用数组的区间，**指向开头的指针**，**指向结尾的指针**

> 指针elboud和elboud+20定义了区间。首先，数组名elboub指向第一个元素。表达式elboud+19指向最后一个元素（即elboud\[19\]），因此，elboud+20指向数组结尾后面的一个位置。

参考程序: [08_array_cookies_index.cpp](Notes-Codes/charpter_07/08_array_cookies_index.cpp)

### 7.3.5 指针和const

主要可以分为三类:

#### 1) const在指针标识之前

指针指向的对象(地址)**可以**修改，**不能**通过指针修改对象的内容，参考如下:

```c++
const int * pt; // a pointer to const int
int const * pt;
```

参考程序: [07_const_1_before.cpp](Notes-Codes/charpter_07/08_const_1_before.cpp)

#### 2) const在指针标识之后

指针指向的对象(地址)**不能**修改，**可以**通过指针修改对象的内容,参考如下

```c++
int * const pt; // a const pointer to int
```

也并不能将一个const的指针赋值给一个非const指针。

参考程序: [07_const_2_after.cpp](Notes-Codes/charpter_07/08_const_2_after.cpp)

#### 3) const在指针标识前后

指针指向的对象(地址)**不能**修改，**也不能**通过指针修改对象的内容,参考如下

```c++
const int * const pt;
```

#### 4) 补充

1. 对于const指针指向的对象本身来说，能否修改取决于他们自己的类型
2. const/no-const变量的地址**都可以赋值给const指针**，而对于非const指针则会报错
3. 不能将数组名作为参数传递给使用**非常量形参**的函数

> 尽可能地使用const，如果条件允许，应将指针**形参声明指向const的指针**，用于保护传递到函数内的数组

参考程序: [08_array_cookies_index_const.cpp](Notes-Codes/charpter_07/08_array_cookies_index_const.cpp)
