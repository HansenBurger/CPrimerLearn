# 复习题

## 1. 为什么C++有多种整型

答(×): 为了存储多种变量，满足不同内存空间需要

> 不完整

参考答案:

> 根据数据运算的需要选择合适的数据类型和应用进行匹配。

## 2. 声明与下述相符变量

a. short整数，值为80
b. unsigned int整数，值为42110
c. 值为3000000000的整数

答(√):

```c++
short a = 80;
int b = 42110U;
long c = 3000000000;
```

参考答案:

> a)short a = 80; </br> b)unsigned int b = 42110; </br> c-1) unsigned int c = 3000000000; </br> c-2) long c = 3000000000; </br> c-3) long long c = 3000000000; </br> 可以发现INT_MAX虽然不满足，但是可以用unsigned替代。

## 3. C++提供了什么措施来防止超出整型范围

答(×): {}初始化，避免narrowing，出现就报错

> 这样做的前提还是要编译

参考答案:

> c++ 语言没有提供自动防止超出整数类型范围的功能，需要程序员自己预估数据大小并选择合适的数据类型，每种数据类型的宽度，c++并没有做规定，具体的值由开发平台和编译器决定。

## 4. 33L与33之间有什么区别

答(√): 前者作为常量为long类型，后者则为int类型

参考答案:

> 默认c++整数不超出int类型范围的应用下，默认优先使用int类型。</br> 33: int </br> 33L: long

## 5. 下面两条C++语句是否等价

```c++
char grade = 65;
char grade = 'A';
```

答(×): 等价，char在内存中存的都是整数，第一行是直接存入字符对应的整数，第二行则是先通过ASCII找到对应字符，再存入到内存

> 不完整，缺少对于常量到变量的类型转换，只解释了字符编码原理

参考答案:

> 在基于ASCII的平台下，两者是等价的。但是前者，先将65存成int，再进行类型转换；而后者直接存的是字符。

## 6. 如何使用C++来找出编码88表示的字符？指出至少两种方法

答(√):

```c++
// way 1
char ch = 88;
cout << 88 << " = " << ch << endl;
// way 2
int ch_i = 88;
cout << ch_i << " = " << (char)ch_i << endl;
```

参考答案:

> 1) char ch = 88; </br> cout << ch << endl;
> 2) cout << (char)88 << endl;

## 7. long->float会导致误差，将long->double呢？将long long->double呢？

答(√): long -> double，double的小数位数有52位，应该能满足long的基本要求；而long long至少64位，对比double的小数位数，还是会出现误差的。

> 还是要指出不同平台编译器的类型大小的区别

参考答案:

> 不同平台和编译器对应的long和long long类型的大小是不同的，如果long的长度为4字节，则再double中不会出现舍入误差，如果long long类型为8字节，会出现舍入误差。

## 8. 下列C++表达式的结果分别是多少？

a. 8 \* 9 + 2
b. 6 \* 3 / 4
c. 3 / 4 \* 6
d. 6.0 \* 3 / 4
e. 15 % 4

答(√): a. 74，b. 4，c. 0，d. 4.5，e. 3

参考答案:

> 74, 4, 0, 4.5, 3

## 9. 假设x1和x2是两个double变量

问: 假设x1和x2是两个double变量，您要将它们作为整数相加，再将结果赋给一个整型变量。请编写一条完成这项任务的C++语句。如果要将它们作为double值相加并转换为int呢？

答(√): 两者结果可能有区别

```c++
double x1, x2;
int result_0, result_1;
result_0 = (int)x1 + (int)x2;
result_1 = x1 + x2; 
```

> 注意拼写，计算结果会自动转换为变量类型，不写类型转换也是可以的

参考答案:

> int sum = (int)x1 + (int)x2; //int sum = int(x1) + int(x2);
> int sum = (int) (x1+x2); // int sum = int(x1+x2);

## 10. 下面每条语句声明的变量都是什么类型？

a. auto cars = 15;
b. auto iou = 150.34f;
c. auto level = 'B';
d. auto crat = U'/U00002155';
e. auto fract = 8.25f/2.5;

答(×): a. int，b. float，c. char，d. char，e. double

> 注意c++还有的char32_t和char16_t的类型

参考答案:

> int, float, char, char32_t, double
