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

## 3. 声明一个包含5个元素的int数组，并将它初始化为前5个正奇数

答():

```c++
int arr[5] = {1, 3, 5, 7, 9};
```

## 4.编写一条语句，将问题3中数组第一个元素和最后一个元素的和赋给变量even

答():

```c++
int even = arr[1] + arr[4];
```

## 5. 编写一条语句，显示float数组ideas中的第2个元素的值

答():

```c++
std::cout << ideas[1] << endl;
```

## 6. 声明一个char的数组，并将其初始化为字符串“cheeseburger”

答():

```c++
char arr[30] = "cheeseburger";
```

## 7. 声明一个string对象，并将其初始化为字符串“Waldorf Salad”

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

```
