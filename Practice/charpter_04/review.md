# 复习题

## 1. 如何声明下述数据?

a. actor是由30个char组成的数组。
b. betsie是由100个short组成的数组。
c. chuck是由13个float组成的数组。
d. dipsea是由64个long double组成的数组。

答():

```c++
char actor[30];
short betsie[100];
float chuck[13];
long double dipsea[64];
```

## 2. 使用模板类array而不是数组来完成问题1

答():

```c++
#include <array>

std::array<char, 30> actor;
std::array<short, 100> betsie;
std::array<float, 13> chuck;
std::array<long double, 64> dispsea; 
```

## 3. 声明一个包含5个元素的int数组，将它初始化为前5个正奇数

答():

```c++
int arr[5] = {1, 3, 5, 7, 9};
```

## 4. 将问题3中数组第一个元素和最后一个元素的和赋给变量even

答():

```c++
int even = arr[1] + arr[4];
```

## 5. 显示float数组ideas中的第2个元素的值

答():

```c++
std::cout << ideas[1] << endl;
```

## 6. 声明一个char的数组，将其初始化为字符串“cheeseburger”

答():

```c++
char arr[30] = "cheeseburger";
```

## 7. 声明一个string对象，将其初始化为字符串“Waldorf Salad”

答():

```c++
#include <string>
std::string arr = "Waldorf Salad";
```

## 8. 设计一个描述鱼的结构声明

结构中应当包括品种、重量（整数，单位为盎司）和长度（英寸，包括小数）。

答():

```c++
struct fish_des
{
    char cate[20];
    int weight;
    float height;
};
```

## 9. 声明一个问题8中定义的结构的变量，并对它进行初始化

答():

```c++
fish_des fish_a = {
    "blackfish", 100, 16.5
};
```

## 10. 用enum定义一个名为Response的类型

它包含Yes、No和Maybe等枚举量，其中Yes的值为1，No为0，Maybe为2。

答():

```c++
enum Response = {Yes=1, No=0, Maybe=2};
```

## 11. 声明一个指向ted(double变量)的指针，用该指针来显示ted的值

答():

```c++
double *ptr = &ted;
std::cout << *ptr << std::endl;
```

## 12. treacle是一个包含10个元素的float数组

请声明一个指向treacle的第一个元素的指针，并使用该指针来显示数组的第一个元素和最后一个元素。

答():

```c++
float *ptr = treacle;
std::cout << "First: " << *ptr << "Last: "<< *(ptr + 9) <<std::endl;
```

## 13. 编写一段代码

要求用户输入一个正整数，然后创建一个动态的int数组，其中包含的元素数目等于用户输入的值。首先使用new来完成这项任务，再使用vector对象来完成这项任务。

答():

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

## 14. 下面的代码是否有效？如果有效，它将打印出什么结果？

```c++
cout << (int *) "Home of the jolly bytesa";
```

答(): 有效，输出的是"Home of the jolly bytesa"这个字符串数组中第一个元素的地址。因为对于对于一个字符串常量而言，传递给cout的是字符串数组的首地址，即指向char类型的指针，cout会一直输出内容直到遇到终止符。转成int类的指针，才能输出地址值。

## 15. 编写一段代码

给问题8中描述的结构动态分配内存，再读取该结构的成员的值

答():

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

答():可能会导致address接收的用户输入不完整，因为cin在遇到空格和回车都会转成终止符存入字符串数组。而getline则是到回车为止，作为终止符。

## 17. 声明一个vector对象和一个array对象

它们都包含10个string对象。指出所需的头文件，但不要使用using。使用const来指定要包含的
string对象数。

答():

```c++
#include<iostream>
#include<string>
#include<array>
#include<vector>

const int Str_n = 10;

std::vector<std::string> arr_0(Str_n);
std::array<std::string, Str_n> arr_1;
```
