# Charpter 5 编程练习

## 5.1

题: 编写一个要求用户输入两个整数的程序。该程序将计算并输出这两个整数之间（包括这两个整数）所有整数的和。这里假设先输入较小的整数。例如，如果用户输入的是2和9，则程序将指出2～9之间所有整数的和为44。

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    int i_start, i_end;

    cout << "Enter two integers and calculate the sum between them: " << endl;
    cout << "Integer 1: ";
    cin >> i_start;
    cout << "Integer 2: ";
    cin >> i_end;

    int sum = 0;
    for (int i = i_start; i <= i_end; i++)
        sum += i;

    cout << "Sum value: " << sum << endl;

    return 0;
}
```

## 5.2

题: 使用array对象（而不是数组）和long double（而不是long long），重新编写程序清单5.4，并计算100!的值。

答:

```c++
#include <array>
#include <iostream>

const int ArSize = 500;

int main(void)
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    int n;
    cout << "Enter an integer to calculate the factorial: ";
    cin >> n;

    array<long double, ArSize> factorials;

    factorials[0] = factorials[1] = 1;

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    std::cout << n << "! = " << factorials[n] << std::endl;

    return 0;
}
```

## 5.3

题: 编写一个要求用户输入数字的程序。每次输入后，程序都将报告到目前为止，所有输入的累计和。当用户输入0时，程序结束。

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;

    unsigned int v;
    unsigned long sum = 0;

    cout << "Enter the integer and calculate the sum value above all(0 to end):" << endl;

    cin >> v;
    while (v)
    {
        sum += v;
        cout << "Sum: " << sum << endl;
        cin >> v;
    }

    return 0;
}
```

## 5.4

题: Daphne以10%的单利投资了100美元。也就是说，每一年的利润都是投资额的10%，即每年10美元：利息 = 0.10×原始存款。而Cleo以5%的复利投资了100美元。也就是说，利息是当前存款（包括获得的利息）的5%，：利息 = 0.05×当前存款。Cleo在第一年投资100美元的盈利是5%—得到了105美元。下一年的盈利是105美元的5%—即5.25美元，依此类推。请编写一个程序，计算多少年后，Cleo的投资价值才能超过Daphne的投资价值，并显示此时两个人的投资价值。

答:

```c++
#include <iostream>

const double InitDeposit = 100.0;
const double SimInterest = 0.1;
const double ComInterest = 0.05;

int main(void)
{
    using namespace std;

    int years = 0;
    double cleos = InitDeposit;
    double daphnes = InitDeposit;

    do
    {
        years++;
        daphnes += SimInterest * InitDeposit;
        cleos += cleos * ComInterest;
    } while (cleos <= daphnes);

    cout << "When investing " << years << " yrs, Cleo's deposit exceed Daphne's: " << endl;
    cout << "Daphen:\t" << daphnes << " $" << endl;
    cout << "Cleo:\t" << cleos << " $" << endl;

    return 0;
}
```

## 5.5

题: 假设要销售《C++ For Fools》一书。请编写一个程序，输入全年中每个月的销售量（图书数量，而不是销售额）。程序通过循环，使用初始化为月份字符串的char *数组（或string对象数组）逐月进行提示，并将输入的数据储存在一个int数组中。然后，程序计算数组中各元素的总数，并报告这一年的销售情况

答:

```c++
#include <iostream>

const int ArSize = 12;

int main(void)
{
    using namespace std;

    const char *month_names[ArSize] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    int *sales = new int[ArSize];

    cout << "Enter monthly book sales: " << endl;
    for (int i = 0; i < ArSize; i++)
    {
        cout << *(month_names + i) << ": ";
        cin >> sales[i];
    }

    int sum = 0;
    for (int i = 0; i < ArSize; i++)
        sum += sales[i];
    cout << "Total sales for the year: " << sum << endl;

    delete[] sales;

    return 0;
}
```

## 5.6

题: 完成编程练习5，但这一次使用一个二维数组来存储输入3年中每个月的销售量。程序将报告每年销售量以及三年的总销售量。

答:

```c++
#include <iostream>

const int MtSize = 12;
const int YrSize = 3;

int main(void)
{
    using namespace std;

    const char *month_names[MtSize] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    int sales[YrSize][MtSize];

    for (int y = 0; y < YrSize; y++)
    {
        cout << "Enter " << y + 1 << "'s monthly book sales: " << endl;
        for (int m = 0; m < MtSize; m++)
        {
            cout << *(month_names + m) << ": ";
            cin >> sales[y][m];
        }
    }

    int sum = 0;
    for (int y = 0; y < YrSize; y++)
        for (int m = 0; m < MtSize; m++)
            sum += sales[y][m];

    cout << "Total sales for" << YrSize << " year: " << sum << endl;

    return 0;
}
```

## 5.7

题: 设计一个名为car的结构，用它存储下述有关汽车的信息：生产商（存储在字符数组或string对象中的字符串）、生产年份（整数）。编写一个程序，向用户询问有多少辆汽车。随后，程序使用new来创建一个由相应数量的car结构组成的动态数组。接下来，程序提示用户输入每辆车的生产商（可能由多个单词组成）和年份信息。请注意，这需要特别小心，因为它将交替读取数值和字符串（参见第4章）。最后，程序将显示每个结构的内容。该程序的运行情况如下：

```cmd
How many cars do you wish to catalog? 2
Car #1 :
Please enter the make: Hudson Hornet
Please enter the year made: 1952
Car #2 :
Please enter the make: Hudson Kaiser
Please enter the year made: 1951
Here is your collection:
1952 Hudson Hornet
1951 Kaiser
```

答:

```c++
#include <iostream>
#include <string>

using namespace std;

struct car
{
    string make;
    int year;
};

int main(void)
{
    int cat_size;
    cout << "How many cars do you wish to catalog? ";
    cin >> cat_size;
    cin.get(); // 空白字符仍然存在在队列中

    car *cars = new car[cat_size];
    for (int i = 0; i < cat_size; i++)
    {
        cout << "Car #" << i + 1 << " :" << endl;
        cout << "Please enter the make: ";
        getline(cin, (cars + i)->make);
        cout << "Please enter the year made: ";
        cin >> (cars + i)->year;
        cin.get();
    }

    cout << "Here is your collection: " << endl;
    for (int i = 0; i < cat_size; i++)
        cout << cars[i].year << " " << cars[i].make << endl;

    return 0;
}
```

## 5.8

题: 编写一个程序，它使用一个char数组和循环来每次读取一个单词，直到用户输入done为止。随后，该程序指出用户输入了多少个单词（不包括done在内）。

下面是该程序的运行情况：

```cmd
Enter words(to stop, type the word done):
anteater birthday category dumpster
envy finagle geometry done for sure
your entered a total of 7 words.
```

您应在程序中包含头文件cstring，并使用函数strcmp( )来进行比较测试。

答:

```c++
#include <iostream>
#include <cstring>

const int ArSize = 20;

int main(void)
{
    using namespace std;

    char word[ArSize]; //如果用char指针，完成初始化(指向对象)才能使用
    int sum = 0;
    cout << "Enter words(to stop, type the word done): " << endl;
    cin >> word;
    while (strcmp(word, "done"))
    {
        sum++;
        cin >> word;
    }
    cout << "your entered a total of " << sum << " words" << endl;

    return 0;
}
```

## 5.9

题: 编写一个满足前一个练习中描述的程序，但使用string对象而不是字符数组。请在程序中包含头文件string，并使用关系运算符来进行比较测试。

答:

```c++
#include <iostream>
#include <string>

int main(void)
{
    using namespace std;

    string word;
    int sum = 0;
    cout << "Enter words(to stop, type the word done): " << endl;
    cin >> word;
    while (word != "done")
    {
        sum++;
        cin >> word;
    }
    cout << "your entered a total of " << sum << " words" << endl;

    return 0;
}
```

## 5.10

题: 编写一个使用嵌套循环的程序，要求用户输入一个值，指出要显示多少行。然后，程序将显示相应行数的星号，其中第一行包括一个星号，第二行包括两个星号，依此类推。每一行包含的字符数等于用户指定的行数，在星号不够的情况下，在星号前面加上句点。

该程序的运行情况如下：

```cmd
Enter number of rows: 5
....*
...**
..***
.****
*****
```

答:

```c++
```
