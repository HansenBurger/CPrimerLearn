# 复习题

## 1. 为什么C++有多种整型

答: 为了存储多种变量，满足不同内存空间需要

## 2. 声明与下述相符变量

a. short整数，值为80
b. unsigned int整数，值为42110
c. 值为3000000000的整数

答:

```c++
short a = 80;
int b = 42110U;
long c = 3000000000;
```

## 3. C++提供了什么措施来防止超出整型范围

答: {}初始化，避免narrowing，出现就报错

## 4. 33L与33之间有什么区别

答: 前者作为常量为long类型，后者则为int类型

## 5. 下面两条C++语句是否等价

```c++
char grade = 65;
char grade = 'A';
```

答: 等价，char在内存中存的都是整数，第一行是直接存入字符对应的整数，第二行则是先通过ASCII找到对应字符，再存入到内存

## 6. 如何使用C++来找出编码88表示的字符？指出至少两种方法

答:

```c++
// way 1
char ch = 88;
cout << 88 << " = " << ch << endl;
// way 2
int ch_i = 88;
cout << ch_i << " = " << (char)ch_i << endl;
```

## 7. long->float会导致误差，将long->double呢？将long long->double呢？

答: long -> double，double的小数位数有52位，应该能满足long的基本要求；而long long至少64位，对比double的小数位数，还是会出现误差的。

## 8. 下列C++表达式的结果分别是多少？

a. 8 \* 9 + 2
b. 6 \* 3 / 4
c. 3 / 4 \* 6
d. 6.0 \* 3 / 4
e. 15 % 4

答: a. 74，b. 4，c. 0，d. 0.5，e. 3

## 9. 假设x1和x2是两个double变量

问: 假设x1和x2是两个double变量，您要将它们作为整数相加，再将结果赋给一个整型变量。请编写一条完成这项任务的C++语句。如果要将它们作为double值相加并转换为int呢？

答: 两者结果可能有区别

```c++
double x1, x2;
int reuslt_0, result_1;
result_0 = (int)x1 + (int)x2;
result_1 = x1 + x2; 
```

## 10. 下面每条语句声明的变量都是什么类型？

a. auto cars = 15;
b. auto iou = 150.34f;
c. auto level = 'B';
d. auto crat = U'/U00002155';
e. auto fract = 8.25f/2.5;

答: a. int，b. float，c. char，d. char，e. double
