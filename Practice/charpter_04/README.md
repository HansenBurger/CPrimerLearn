# Charpter 4 编程练习

## 4.1

题: 编写一个C++程序，如下述输出示例所示的那样请求并显示信息：

```cmd
What is your first name? Betty Sue
What is your last name? Yewe
What letter grad do you deserve? B
What is your age? 22
Name: Yewe, Betty Sue
Grade: C
Age: 22
```

注意，该程序应该接受的名字包含多个单词。另外，程序将向下调整成绩，即向上调一个字母。假设用户请求A、B或C，所以不必担心D和F之间的空档。

答:

```c++
#include <iostream>

const int Str_len = 20;

int main(void)
{
    using namespace std;

    int age;
    char grade, f_name[Str_len], l_name[Str_len];

    cout << "What is your first name? ";
    cin.getline(f_name, Str_len); // getline需要两个参数
    cout << "What is your last name? ";
    cin.getline(l_name, Str_len);
    cout << "What letter grad do you deserve? ";
    cin >> grade;
    // char本身也是整型，可以进行加法运算
    grade = (char)((int)grade + 1); // char (grade + 1)
    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << l_name << ", " << f_name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;

    return 0;
}
```

> char也是整型，可以加法运算，但是直接输出会改变类型，需要强制类型转换

## 4.2

题: 修改程序清单4.4，使用C++ string类而不是char数组

答:

```c++
#include <iostream>
#include <string>

int main(void)
{
    using namespace std;

    string name, dessert;

    cout << "Enter your name: " << endl;
    getline(cin, name); //  对于string类只需要指定捕获的方式和存放的对象
    cout << "Enter your favorite dessert: " << endl;
    getline(cin, dessert);

    cout << "I have some delicious " << dessert;
    cout << " for " << name << endl;
}
```

> **注意读题，4.4**，注意string类和char数组的区别: </br> 1) string类不需要指定长度 </br> 2) string用getline而不是cin.getline

## 4.3

题: 编写一个程序，它要求用户首先输入其名，然后输入其姓；然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。**请使用char数组和头文件cstring中的函数**。

下面是该程序运行时的情形：

```cmd
Enter your first name: Flip
Enter your last name: Fleming
Here's the information int a single string: Fleming, Flip
```

答:

```c++
#include <iostream>
#include <cstring>

const int Str_len = 20;

int main(void)
{
    using namespace std;
    char f_n[Str_len], l_n[Str_len];
    cout << "Enter your first name: ";
    cin.getline(f_n, Str_len);
    cout << "Enter your last name: ";
    cin.getline(l_n, Str_len);
    cout << "Here's the information int a single string: ";
    cout << strcat(strcat(l_n, ", "), f_n) << endl;

    return 0;
}
```

> 可以创建一个字符串对象full_name，用来**拷贝**last_name，并且在之后按需求拼接

参考:

```c++
strcpy(full_name, last_name);
strcat(full_name, ", ");
strcat(full_name, first_name);
```

## 4.4

题: 编写一个程序，它要求用户首先输入其名，再输入其姓；然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。**请使用string对象和头文件string中的函数**。

下面是该程序运行时的情形：

```cmd
Enter your first name: Flip
Enter your last name: Fleming
Here's the information int a single string: Fleming, Flip
```

答:

```c++
#include <iostream>
#include <string>

int main(void)
{
    using namespace std;
    string f_n, l_n;
    cout << "Enter your first name: ";
    getline(cin, f_n);
    cout << "Enter your last name: ";
    getline(cin, l_n);
    cout << "Here's the information int a single string: ";
    cout << l_n + ", " + f_n << endl;
    return 0;
}
```

## 4.5

题: 结构CandyBar包含3个成员。第一个成员存储了糖块的品牌；第二个成员存储糖块的重量（可以有小数）；第三个成员存储了糖块的卡路里含量（整数）。请编写一个程序，声明这个结构，创建一个名为snack的CandyBar变量，并将其成员分别初始化为“Mocha Munch”、2.3和350。初始化应在声明snack时进行。最后，程序显示snack变量的内容。

答:

```c++
#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    unsigned int kcal; // 卡路里没有负值
};

int main(void)
{
    using namespace std;
    CandyBar snack = {"Mocha Munch",
                      2.3,
                      350};
    cout << "Snack brand: " << snack.brand << endl;
    cout << "Snack weight: " << snack.weight << endl;
    cout << "Snack kcal: " << snack.kcal << endl;

    return 0;
}
```

## 4.6

题: 结构CandyBar包含3个成员，如编程练习5所示。请编写一个程序，创建一个包含3个元素的CandyBar数组，并将它们初始化为所选择的值，然后显示每个结构的内容。

答:

```c++
#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int kcal;
};

int main(void)
{
    using namespace std;
    CandyBar snacks[3] = {{"Mocha Munch", 2.3, 350},
                          {"Hershey", 1.8, 200},
                          {"M&M\'s", 5.5, 440}};

    cout << "Snack 1: " << endl;
    cout << "brand = " << snacks->brand << ", weight = " << snacks->weight << ", kcal = " << snacks->kcal << endl;
    cout << "Snack 2: " << endl;
    cout << "brand = " << (snacks + 1)->brand << ", weight = " << (snacks + 1)->weight << ", kcal = " << (snacks + 1)->kcal << endl;
    cout << "Snack 3: " << endl;
    cout << "brand = " << (snacks + 2)->brand << ", weight = " << (snacks + 2)->weight << ", kcal = " << (snacks + 2)->kcal << endl;

    return 0;
}
```

> 结构体数组的初始化，{{},{},{}}

## 4.7

题: William Wingate从事比萨饼分析服务。对于每个披萨饼，他都需要记录下列信息

1. 披萨饼公司的名称，可以有多个单词组成。
2. 披萨饼的直径。
3. 披萨饼的重量。

请设计一个能够存储这些信息的结构，并编写一个使用这种结构变量的程序。程序将请求用户输入上述信息，然后显示这些信息。请使用cin（或它的方法）和cout。

答:

```c++
#include <iostream>

const int Str_len = 20;

struct Pizza
{
    char *company = new char[Str_len];
    double *diameter = new double;
    double *weight = new double;
};

int main(void)
{
    using namespace std;
    Pizza pizza_;
    cout << "Enter the company of pizza: ";
    cin.getline(pizza_.company, Str_len);
    cout << "Enter the size(cm) of pizza: ";
    cin >> *pizza_.diameter;
    cout << "Enter the weight(g) of pizza: ";
    cin >> *pizza_.weight;
    cout << "Pizza's Brand: " << pizza_.company << endl;
    cout << "Pizza's Diameter: " << *pizza_.diameter << endl;
    cout << "Pizza's Weight: " << *pizza_.weight << endl;

    return 0;
}

```

## 4.8

题: 完成编程练习7，但使用new来为结构分配内存，而不是声明一个结构变量。另外，让程序在请求输入比萨饼公司名称之前输入比萨饼的直径。

答:

```c++
#include <iostream>

const int Str_len = 20;

struct Pizza
{
    char *company = new char[Str_len];
    double *diameter = new double;
    double *weight = new double;
};

int main(void)
{
    using namespace std;
    Pizza *pizza_ = new Pizza;
    cout << "Enter the size(cm) of pizza: ";
    cin >> *((*pizza_).diameter);
    cout << "Enter the company of pizza: ";
    cin.get(); // 捕获没放入队列的回车符号
    cin.getline(pizza_->company, Str_len);
    cout << "Enter the weight(g) of pizza: ";
    cin >> *((*pizza_).weight);
    cout << "Pizza's Brand: " << pizza_->company << endl;
    cout << "Pizza's Diameter: " << *(pizza_->diameter) << endl;
    cout << "Pizza's Weight: " << *(pizza_->weight) << endl;

    delete pizza_;

    return 0;
}
```

> new返回的永远是对应类型的地址(比如这里是结构体的地址)，*ptr就转为结构体变量。cin是**不保存空白字符的**，而getline则会直接从队列中读取没被保存的空白字符。</br> new 和 delete 一定要成对出现。

## 4.9

题: 完成编程练习6，但使用new来动态分配数组，而不是声明一个包含3个元素的CandyBar数组。

答:

```c++
#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int kcal;
};

int main(void)
{
    using namespace std;
    CandyBar s_1 = {"Mocha Munch", 2.3, 350};
    CandyBar s_2 = {"Hershey", 1.8, 200};
    CandyBar s_3 = {"M&M\'s", 5.5, 440};
    CandyBar *snacks = new CandyBar[3];
    snacks[0] = s_1;
    snacks[1] = s_2;
    snacks[2] = s_3;

    cout << "Snack 1: " << endl;
    cout << "brand = " << snacks->brand;       // snacks = &s_1
    cout << ", weight = " << (*snacks).weight; // *snakes = snakes[0] = s_1
    cout << ", kcal = " << snacks[0].kcal << endl;
    cout << "Snack 2: " << endl;
    cout << "brand = " << (snacks + 1)->brand << ", weight = " << (*(snacks + 1)).weight << ", kcal = " << snacks[1].kcal << endl;
    cout << "Snack 3: " << endl;
    cout << "brand = " << (snacks + 2)->brand << ", weight = " << (*(snacks + 2)).weight << ", kcal = " << snacks[2].kcal << endl;

    delete[] snacks;

    return 0;
}
```

> 数组名就是指针，加几代表跨过几个元素，得到的也是地址，提取结构体地址的成员可以用"->"

## 4.10

题: 编写一个程序，让用户输入三次40码跑的成绩（如果您愿意，也可让用户输入40米跑的成绩），并显示次数和平均成绩。请使用一个array对象来存储数据（如果编译器不支持array类，请使用数组）

答:

```c++
#include <iostream>
#include <array>

int main()
{
    using namespace std;
    array<double, 3> scores;
    cout << "Enter three 40m run scores" << endl;
    cout << "First: ";
    cin >> scores[0];
    cout << "Second: ";
    cin >> scores[1];
    cout << "Third: ";
    cin >> scores[2];

    cout << "The average of the three score is ";
    cout << (scores[0] + scores[1] + scores[2]) / 3.0 << endl;

    return 0;
}
```
