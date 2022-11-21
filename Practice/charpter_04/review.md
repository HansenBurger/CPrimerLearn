# 复习题

## 1. 如何声明下述数据?

a. actor是由30个char组成的数组。
b. betsie是由100个short组成的数组。
c. chuck是由13个float组成的数组。
d. dipsea是由64个long double组成的数组。

答(√):

```c++
char actor[30];
short betsie[100];
float chuck[13];
long double dipsea[64];
```

参考答案:

> a) char actor[30]; </br> b) short betsie[100]; </br> c) float chuck[13]; </br> d) long double dipsea[64];

## 2. 使用模板类array而不是数组来完成问题1

答(√):

```c++
#include <array>

std::array<char, 30> actor;
std::array<short, 100> betsie;
std::array<float, 13> chuck;
std::array<long double, 64> dipsea; 
```

参考答案:

>#include \<array> </br> a) array<char, 30> actor; </br> b) array<short, 100> betsie; </br> c) array<float, 13> chuck; </br> d) array\<long double, 64> dipsea;

## 3. 声明一个包含5个元素的int数组，将它初始化为前5个正奇数

答(√):

```c++
int arr[5] = {1, 3, 5, 7, 9};
```

参考答案:

> int arr[5] = {1, 3, 5, 7, 9};

## 4. 将问题3中数组第一个元素和最后一个元素的和赋给变量even

答(√):

```c++
int even = arr[1] + arr[4];
```

参考答案:

> int even = arr[1] + arr[4];

## 5. 显示float数组ideas中的第2个元素的值

答(√):

```c++
std::cout << ideas[1] << endl;
```

> **注意**先定义数组

参考答案:

> float ideas[10]; </br> cout << ideas[1] << endl;

## 6. 声明一个char的数组，将其初始化为字符串“cheeseburger”

答(×):

```c++
char arr[30] = "cheeseburger";
```

> 用字符串常量初始化数组可以不用声明长度，**自动计算**

参考答案:

> char str[] = "cheeseburger";

## 7. 声明一个string对象，将其初始化为字符串“Waldorf Salad”

答(√):

```c++
#include <string>
std::string arr = "Waldorf Salad";
```

参考答案:

> string str = "Waldorf Salad";

## 8. 设计一个描述鱼的结构声明

结构中应当包括品种、重量（整数，单位为盎司）和长度（英寸，包括小数）。

答(√):

```c++
struct fish_des
{
    char cate[20];
    int weight;
    float height;
};
```

参考答案:

```c++
struct fish
{
    char kind[30];
    int weight;
    float height;
};
```

## 9. 声明一个问题8中定义的结构的变量，并对它进行初始化

答(√):

```c++
fish_des fish_a = {
    "blackfish", 100, 16.5
};
```

参考答案:

```c++
struct fish
{
    char kind[30];
    int weight;
    float length;
};
fish ff = {"BigFish", 12, 4.2};
```

## 10. 用enum定义一个名为Response的类型

它包含Yes、No和Maybe等枚举量，其中Yes的值为1，No为0，Maybe为2。

答(√):

```c++
enum Response = {Yes=1, No=0, Maybe=2};
```

> enum 可以**根据位置关系**自动赋值

参考答案:

> enum Response = {No, Yes, Maybe};

## 11. 声明一个指向ted(double变量)的指针，用该指针来显示ted的值

答(√):

```c++
double *ptr = &ted;
std::cout << *ptr << std::endl;
```

> 使用前先声明变量

参考答案:

```c++
double ted =1.8;
double *pt = &ted;
cout << "ted = " << *pt << endl;
```

## 12. treacle是一个包含10个元素的float数组

请声明一个指向treacle的第一个元素的指针，并使用该指针来显示数组的第一个元素和最后一个元素。

答(√):

```c++
float *ptr = treacle;
std::cout << "First: " << *ptr << "Last: "<< *(ptr + 9) <<std::endl;
```

> 使用前先声明

参考答案:

```c++
float treacle[10];
float *ptr = &treacle[0]; // float *ptr = treacle;
cout << pt[0] << " " << pt[9] << endl;
```

## 13. 编写一段代码

要求用户输入一个正整数，然后创建一个动态的int数组，其中包含的元素数目等于用户输入的值。首先使用new来完成这项任务，再使用vector对象来完成这项任务。

答(√):

```c++
#include<iostream>
#include<vector>

int n;
std::cout << "Enter a positive integer: " << std::endl;
std::cin >> n;

int * arr_0 = new int[n];
delete[] arr_0;

std::vector<int> arr_1(n);
```

参考答案:

```c++
int size;
cout << "Enter a number:" << endl;
cin >> size;

int *pt = new int[size]; // 先写右边再写左边
vector<int> arr(size);
```

## 14. 下面的代码是否有效？如果有效，它将打印出什么结果？

```c++
cout << (int *) "Home of the jolly bytesa";
```

答(√): 有效，输出的是"Home of the jolly bytesa"这个字符串数组中第一个元素的地址。因为对于对于一个字符串常量而言，传递给cout的是字符串数组的首地址，即指向char类型的指针，cout会一直输出内容直到遇到终止符。转成int类的指针，才能输出地址值。

> 强制类型转换会把**字符地址**转为整型地址

参考答案:

> valiable, print string's address. won't print string "Home of the jolly bytesa"

## 15. 编写一段代码

给问题8中描述的结构动态分配内存，再读取该结构的成员的值

答(√):

```c++
struct fish_des
{
    char cate[20];
    int weight;
    float height;
};

fish_des *fish_0 = new fish_des;
std::cout << (*fish_0).cate << std::endl;
std::cout << fish_0->weight << std::endl;
std::cout << fish_0->height << std::endl;
```

参考答案:

```c++
struct fish
{
    char kind[30];
    int weight;
    float length;
};
fish *pt = new fish;
cout << pt->kind << ", " << pt->weight << ", " << pt->length << endl;
```

## 16. 程序清单4.6指出了混合输入数字和一行字符串时存储的问题

如果将下面的代码：

```c++
cin.getline(address, 80);
```

替换为:

```c++
cin >> address;
```

会对程序运行带来什么影响?

答(√):可能会导致address接收的用户输入不完整，因为cin在遇到空格和回车都会转成终止符存入字符串数组。而getline则是到回车为止，作为终止符。

> 对于 cin >> address;没有**字符长度限制**(没有遇到空白字符前)

参考答案:

> getline捕获输入一直到回车位置，存放的是输入内容+"\0"，但address遇到**空白字符**都会结束，但是字符长度没限制

## 17. 声明一个vector对象和一个array对象

它们都包含10个string对象。指出所需的头文件，但不要使用using。使用const来指定要包含的
string对象数。

答(√):

```c++
#include<iostream>
#include<string>
#include<array>
#include<vector>

const int Str_n = 10;

std::vector<std::string> arr_0(Str_n);
std::array<std::string, Str_n> arr_1;
```

参考答案:

```c++
#include<string>
#include<array>
#include<vector>

const int size = 10;
std::vector<std::string> arr(size);
std::array<std::string, size> array;
```
