# 复习题

## 1.C++程序的模块叫什么？

答: 函数 √

> 参考答案: 函数

## 2.下面的预处理器编译指令是做什么用的？

```c++
#include <iostream>
```

答: 调用库函数 ×

> 参考答案: 包含iostream头文件，将头文件内容添加到源代码

## 3.下面语句是做什么用的？

```c++
using namespace std;
```

答: 使用命名空间, 可以调用对应类下的函数 ×

> 参考答案: using是预编译器指令，使用std命名空间

## 4.什么语句可以用来打印短语“Hello，world”，然后开始新的一行？

答: 标准输出语句 √

```c++
std::cout << "Hello, world" << std::endl;
```

> 参考答案: cout << "Hello world" << endl;

## 5.什么语句可以用来创建名为cheeses的整数变量？

答: 变量声明语句 √

```c++
int cheeses;
```

> 参考答案: int cheeses;

## 6.什么语句可以用来将值32赋给变量cheeses？

答: 赋值语句 √

```c++
cheeses = 32;
```

> 参考答案: cheeses = 32;

## 7.什么语句可以用来将从键盘输入的值读入变量cheeses中？

答: 标准输入语句 √

```c++
std::cin >> cheeses;
```

> 参考答案: cin >> cheeses;

## 8.什么语句可以用来打印“We have X varieties of cheese.”，其中X为变量cheeses的当前值

答: 标准输出语句 √

```c++
std::cout << "We have " << cheeses << "varieties of cheese.";
```

## 9.下面的函数原型指出了关于函数的哪些信息？

```c++
int froop(double t);
void rattle(int n);
int prune(void);
```

答:

1. 函数froop输入类型double， 返回int。√
2. 函数rattle输入类型int，无返回值。√
3. 函数prune无输入值，返回int。√

> 参考答案: </br>函数名: froop，带有参数t，参数类型double，返回一个整型 </br> 函数名：ratttle，带有参数n，参数类型int，无返回值 </br> 函数名：prune，无参数，返回一个整型

## 10.定义函数时，在什么情况下不必使用关键字return？

答: 函数类型为void时 √

> 参考答案: 当函数没有返回值时，void rattle(int n)

## 11.假设您编写的main( )函数包含如下代码

```c++
    cout << "Please enter your PIN: ";
```

而编译器指出cout是一个未知标识符。导致这种问题的原因很可能是什么？指出3种修复这种问题的方法。

答: 很可能的原因是缺少使用命名空间 √

1. 在全局使用 using namespace std;
2. 在main函数内使用 using namespace std;
3. 将cout改为 std::cout

× 不完整

> 参考答案: </br> 1) using namespace std; </br> 2) using std::cout; </br> 3) std::cout
