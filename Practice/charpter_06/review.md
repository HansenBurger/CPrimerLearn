# 复习题

## 1. 比较两个计算空格和换行符数目的代码片段

```c++
// Version 1
while(cin.get(ch))  // quit on eof
{
    if(ch == ' ')
        spaces++;
    if(ch == '\n')
        newlines++;
}
// Version 2
while(cin.get(ch))  // quit on eof
{
    if(ch == ' ')
        spaces++;
    else if(ch == '\n')
        newlines++;
}
```

第二种格式比第一种好在哪里?

答(): else if和最近的if相对应，属于对于ch不同情况的判断，ch不是空格，再判断是不是回车。版本1则是单纯反复判断。

## 2. 在程序清单6.2中，用ch+1替换++ch将发生什么情况呢？

```c++
char ch;
cin.get(ch);
while (ch != '.')
{
    if (ch == '\n')
        cout << ch;
    else
        cout << ++ch;
    cin.get(ch);
}
```

答(): 替换"++ch"为"ch+1"，会导致类型提升，输出的不是字符而是数字。因为ch是char型，而1作为整型常量，默认是int型，所以整体会提升到int型，无法输出字符。

## 3. 请认真考虑下面的程序

```c++
#include <iostream>
using namespace std;
int main()
{
    char ch;
    int ct1, ct2;

    ct1 = ct2 = 0;
    while ((ch = cin.get()) != '$')
    {
        cout << ch;
        ct1++;
        if(ch = '$')
            ct2++
        cout << ch;
    }
    cout << "ct1 = " << ct1 << ", ct2 = " << ct2 << "\n";
    return 0;
}
```

假设输入如下(请在每行末尾按回车键):

```cmd
Hi!
Send $10 or $20 now!
```

则输出的将是什么(还记得吗，输入被缓冲)？

答():

```cmd
HHii!!
SSeenndd 1100 oorr 2200 nnooww!!
ct1 = 21, ct2 = 21
$system return$
```

## 4. 创建表示下述条件的逻辑表达式

a. weight大于或等于115，但小于125
b. ch为q或Q
c. x为偶数，但不是26
d. x为偶数，但不是26的倍数
e. donation为1000-2000或guest为1
f. ch是小写字母或大写字母（假设小写字母是依次编码的，大写字母也是依次编码的，但在大小写字母间编码不是连续的）

答():

```c++
// a
(weight >= 115) && (weight < 125);
// b
(ch == 'q') || (ch == 'Q');
// c
!(x%2) && !(x==26);
// d
!(x%2) && (x%26);
// e
((donation >= 1000) && (donation <= 2000>)) || (guest == 1);
// f
((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'));
```

## 5. 在C++中，!!x是否与x相同呢？

答(): 不同，根据结合律，!!x等价于!(!x)，最后只会是0或者1，而不是x。

## 6. 创建一个条件表达式，其值为变量的绝对值

也是说，如果变量x为正，则表达式的值为x；但如果x为负，则表达式的值为−x——这是一个正值。

答():

```c++
if(x>0)
    x = x;
else if(x<0)
    x = -1;
```

## 7．用switch改写下面的代码片段

```c++
if (ch == 'A')
    a_grade++;
else if (ch == 'B')
    b_grade++;
else if (ch == 'C')
    c_grade++;
else if (ch == 'D')
    d_grade++;
else
    f_grade++;
```

答():

```c++
switch(ch)
{
    case 'A': a_grade++;break;
    case 'B': b_grade++;break;
    case 'C': c_grade++;break;
    case 'D': d_grade++;break;
    default: f_grade++;
}
```

## 8. 使用字符表示菜单选项和case标签有何优点

对于程序清单6.10，与使用数字相比，使用字符（如a和c）表示菜单选项和case标签有何优点呢？（提示：想想用户输入q和输入5的情况。）

答(): 字符也是整型适用switch；更加直观；可以缩略的概括每种case的对应情况，能够包含更多信息

## 9. 请看下面的代码片段

```c++
int line = 0;
char ch;
while (cin.get(ch))
{
    if (ch == 'Q')
        break;
    if (ch != '\n')
        continue;
    line++;
}
```

请重写该代码片段，不要使用break和continue语句。

答():

```c++
int line = 0;
char ch;
while((ch.get(ch)) && (ch != 'Q'))
{
    if (ch == '\n')
        line++;
}
```
