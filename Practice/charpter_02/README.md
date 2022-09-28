# Charpter 2 编程练习

## 2.1 

题: 编写一个C++程序，它显示您的姓名和地址。

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    cout << "My name: V" << endl;
    cout << "Where I live: Night City" << endl;
    return 0;
}
```

## 2.2

题: 编写一个C++程序，它要求用户输入一个以long为单位的距离，然后将它转换为码（一long等于220码）

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    long length;
    cout << "Enter the distance: ";
    cin >> length;
    int yard = 220 * length;
    cout << length << "long = ";
    cout << yard << " yard." << endl;
    return 0;
}
```

**注意:** 输出时两者单位

## 2.3 

题: 编写一个C++程序，它使用3个用户定义的函数（包括main()），并生成下面的输出

> Three blind mice </br> Three blind mice </br> see how they run </br> see how they run </br>

其中一个函数要调用两次，该函数生成前两行；另一个函数也被调用两次，并生成其余的输出。

```c++
#include <iostream>

void Cout_1(void);
void Cout_2(void);

int main(void)
{
    Cout_1();
    Cout_1();
    Cout_2();
    Cout_2();
}

void Cout_1(void)
{
    std::cout << "Three blind mice" << std::endl;
}

void Cout_2(void)
{
    std::cout << "See how they run" << std::endl;
}
```

## 2.4

题: 编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月，如下所示

> Enter your age: 29

```c++
#include <iostream>

int YearToMonth(int);

int main(void)
{
    using namespace std;
    int year;
    cout << "Enter your age: ";
    cin >> year;

    int month = YearToMonth(year);
    cout << year << " Yr = ";
    cout << month << " M." << endl;
    return 0;
}

int YearToMonth(int year)
{
    return 12 * year;
}
```

## 2.5

题: 编写一个程序，其中的main( )调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值）。该程序按下面的格式要 求用户输入摄氏温度值，并显示结果：

> Please enter a Celsius value: 20 </br> 20 degrees Celsius is 68 degrees Fahrenheit

```c++
#include <iostream>

double Convert(double);

int main(void)
{
    using namespace std;
    double c_degree;
    cout << "Please enter a Celsius value: ";
    cin >> c_degree;
    double f_degree = Convert(c_degree);
    cout << c_degree << " degrees Celsius is ";
    cout << f_degree << " degrees Fahrenheit." << endl;
    return 0;
}

double Convert(double c_degree)
{
    return 1.8 * c_degree + 32.0;
}
```

**注意:** 两者的数据类型应当为浮点型

## 2.6

题: 编写一个程序，其main( )调用一个用户定义的函数（以光年值为参数，并返回对应天文单位的值）。该程序按下面的格式要求用户输入光年值，并显示结果：

> Enter the number of light years: 4.2 </br> 4.2 light years = 265608 astronomical units.

```c++
#include <iostream>

double Convert(double);

int main(void)
{
    using namespace std;
    double light_yr;
    cout << "Enter the number of light years: ";
    cin >> light_yr;

    double astro_unit = Convert(light_yr);
    cout << light_yr << " light years = ";
    cout << astro_unit << " astronomical units. " << endl;
    return 0;
}

double Convert(double light_yr)
{
    return light_yr * 63240;
}
```

## 2.7

题: 编写一个程序，要求用户输入小时数和分钟数。在main( )函数中，将这两个值传递给一个void函数，后者以下面这样的格式显示这两个值：

> Enter the number of hours: 9 </br> Enter the number of minutes: 28 </br> Time: 9:28

```c++
#include <iostream>

void show_time(int, int);

int main(void)
{
    using namespace std;
    int hour, minutes;
    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    show_time(hour, minutes);
    return 0;
}

void show_time(int h, int m)
{
    std::cout << "Time: " << h << ":" << m << std::endl;
}
```

**注意:**读题，函数原型