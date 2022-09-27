# 复习题

1. C++程序的模块叫什么？

答: 函数

2. 下面的预处理器编译指令是做什么用的？

```c++
    #include <iostream>
```

答: 调用库函数

3. 下面语句是做什么用的？

```c++
    using namespace std;
```

答: 使用命名空间, 可以调用对应类下的函数

4. 什么语句可以用来打印短语“Hello，world”，然后开始新的一行？

答: 标准输出语句
```c++
    std::cout << "Hello, world" << std::endl;
```

5. 什么语句可以用来创建名为cheeses的整数变量？

答: 变量声明语句
```c++
    int cheeses;
```

6. 什么语句可以用来将值32赋给变量cheeses？

答: 赋值语句
```c++
    cheeses = 32;
```

7. 什么语句可以用来将从键盘输入的值读入变量cheeses中？

答: 标准输入语句
```c++
    std::cin >> cheeses;
```

8. 什么语句可以用来打印“We have X varieties of cheese.”，其中X为变量cheeses的当前值。

答: 标准输出语句
```c++
    std::cout << "We have " << cheeses << "varieties of cheese.";
```

9. 下面的函数原型指出了关于函数的哪些信息？

```c++
    int froop(double t);
    void rattle(int n);
    int prune(void);
```

答:

1.函数froop输入类型double， 返回int。
2.函数rattle输入类型int，无返回值。
3.函数prune无输入值，返回int。

10. 定义函数时，在什么情况下不必使用关键字return？

答: 函数类型为void时

11. 假设您编写的main( )函数包含如下代码：

```c++
    cout << "Please enter your PIN: ";
```

而编译器指出cout是一个未知标识符。导致这种问题的原因很可能是什么？指出3种修复这种问题的方法。

答: 很可能的原因是缺少使用命名空间

方法1: 在全局使用 using namespace std;

方法2: 在main函数内使用 using namespace std;

方法3: 将cout改为 std::cout
