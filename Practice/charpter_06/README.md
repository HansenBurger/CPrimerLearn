# Charpter 6 编程练习

## 6.1

题: 编写一个程序，读取键盘输入，直到遇到@符号为止，并回显输入（数字除外），同时将大写字符转换为小写，将小写字符转换为大写（别忘了cctype函数系列）

答:

```c++
#include <iostream>
#include <cctype>

int main(void)
{
    using namespace std;

    char ch;
    while ((cin.get(ch)) && (ch != '@'))
    {
        if (islower(ch))
            ch = toupper(ch);
        else if (isupper(ch))
            ch = tolower(ch);
        cout << ch;
    }

    return 0;
}
```

## 6.2

题: 编写一个程序，最多将10个donation值读入到一个double数组中（如果您愿意，也可使用模板类array）。程序遇到非数字输入时将结束输入，并报告这些数字的平均值以及数组中有多少个数字大于平均值。

答():

```c++
#include <iostream>
#include <array>

const int ArrSize = 10;

int main(void)
{
    using namespace std;
    array<double, ArrSize> donations;
    double sum = 0.0, mean = 0.0;
    int ind = 0, over_mean = 0;

    cout << "Enter the donations(not more than " << ArrSize << "): " << endl;

    while (cin >> donations[ind])
        ++ind;

    for (int i = 0; i < ind; i++)
        sum += donations[i];

    mean = sum / ind;
    for (int i = 0; i < ind; i++)
        if (donations[i] > mean)
            ++over_mean;

    cout << "Sum:\t" << sum << endl;
    cout << "Average:\t" << mean << endl;
    cout << "Over average:\t" << over_mean << endl;

    return 0;
}
```

## 6.3

题: 编写一个菜单驱动程序的雏形。该程序显示一个提供4个选项的菜单——每个选项用一个字母标记。如果用户使用有效选项之外的字母进行响应，程序将提示用户输入一个有效的字母，直到用户这样做为止。然后，该程序使用一条switch语句，根据用户的选择执行一个简单操作。

该程序的运行情况如下：

```cmd
Please enter one of the following choices:
c) carnivore    p) pianist
t) tree         g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree
```

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    char ch;
    const char *prefix = "A maple is a ";
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore\t p) pianist" << endl;
    cout << "t) tree\t\tf g) game" << endl;

    while (cin >> ch)
    {
        switch (ch)
        {
        case 'c':
            cout << prefix << "carnivore" << endl;
            break;
        case 'p':
            cout << prefix << "pianist" << endl;
            break;
        case 't':
            cout << prefix << "tree" << endl;
            break;
        case 'g':
            cout << prefix << "game" << endl;
            break;

        default:
            cout << "Please enter a c, p, t, or g: ";
            break;
        }
    }

    return 0;
}
```

## 6.4

题: 加入Benevolent Order of Programmer后，在BOP大会上，人们便可以通过加入者的真实姓名、头衔或秘密BOP姓名来了解他（她）。请编写一个程序，可以使用真实姓名、头衔、秘密姓名或成员偏好来列出
成员。

编写该程序时，请使用下面的结构：

```c++
// Benevolent Order of Programmers name structure
struct bop{
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};
```

该程序创建一个由上述结构组成的小型数组，并将其初始化为适当的值。

另外，该程序使用一个循环，让用户在下面的选项中进行选择：

```cwd
a. display by name      b. display by title
c. display by bopname   d. display by preference
q. quit
```

注意，“display by preference”并不意味着显示成员的偏好，而是意味着根据成员的偏好来列出成员。例如，如果偏好号为1，则选择d将显示程序员的头衔。

该程序的运行情况如下：

```cmd
Benevolent Order of Programmers Report
a. display by name      b. display by title
c. display by bopname   d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!
```

答:

```c++
#include <iostream>

const int BopN = 5;
const int strsize = 30;

// Benevolent Order of Programmers name structure
struct bop
{
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

int main(void)
{
    using namespace std;
    char choice;

    bop bopmanbers[BopN] = {
        {"Wimp Macho", "Engnieer", "WM", 0},
        {"Raki Rhodes", "Junior Programmer", "RR", 1},
        {"Celia Laiter", "Data Engineer", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "HH", 1},
        {"Pat Hand", "Programmer", "LOOPY", 2}};

    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name\tb. display by title" << endl;
    cout << "c. display by bopname\td. display by preference" << endl;
    cout << "Enter your choice: ";

    while ((cin >> choice) && (choice != 'q'))
    {
        switch (choice)
        {
        case 'a':
            for (int i = 0; i < BopN; i++)
                cout << bopmanbers[i].fullname << endl;
            break;
        case 'b':
            for (int i = 0; i < BopN; i++)
                cout << bopmanbers[i].title << endl;
            break;
        case 'c':
            for (int i = 0; i < BopN; i++)
                cout << bopmanbers[i].bopname << endl;
            break;
        case 'd':
            for (int i = 0; i < BopN; i++)
                switch (bopmanbers[i].preference)
                {
                case 0:
                    cout << bopmanbers[i].fullname << endl;
                    break;
                case 1:
                    cout << bopmanbers[i].title << endl;
                    break;
                case 2:
                    cout << bopmanbers[i].bopname << endl;
                    break;
                default:
                    break;
                }
            break;
        default:
            cout << "Please enter(a, b, c, d): ";
            continue;
        }
        cout << "Next choice: ";
    }

    cout << "Bye!" << endl;
    return 0;
}
```

## 6.5

在Neutronia王国，货币单位是tvarp，收入所得税的计算方式如下：

1. 5000 tvarps：不收税
2. 5001～15000 tvarps：10%
3. 15001～35000 tvarps：15%
4. 35000 tvarps以上：20%

例如，收入为38000 tvarps时，所得税为5000 0.00 + 10000 0.10 +20000 0.15 + 3000 0.20，即4600 tvarps。请编写一个程序，使用循环来要求用户输入收入，并报告所得税。当用户输入负数或非数字时，循环将结束。

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    const double tex_st[4] = {0.0, 0.1, 0.15, 0.20};
    cout << "Calculate the tax you need to pay in Neutronia Kingdom" << endl;
    cout << "Income(tvarps):\t";
    int income;
    double tex = 0;

    while ((cin >> income) && income >= 0)
    {
        if (income <= 5000)
            tex = 0.0;
        else if ((income > 5000) && (income <= 15000))
            tex = (income - 5000) * tex_st[1];
        else if ((income > 15000) && (income <= 35000))
            tex = 10000 * tex_st[1] + (income - 15000) * tex_st[2];
        else
            tex = 10000 * tex_st[1] + 20000 * tex_st[2] + (income - 35000) * tex_st[3];

        cout << "Tex(tvarps):\t" << tex << endl;
        cout << "Income(tvarps):\t";
    }
    cout << "Bye!" << endl;

    return 0;
}
```

## 6.6

题: 编写一个程序，记录捐助给“维护合法权利团体”的资金。该程序要求用户输入捐献者数目，然后要求用户输入每一个捐献者的姓名和款项。这些信息被储存在一个动态分配的结构数组中。每个结构有两个成员：用来储存姓名的字符数组（或string对象）和用来存储款项的double成员。读取所有的数据后，程序将显示所有捐款超过10000的捐款者的姓名及其捐款数额。该列表前应包含一个标题，指出下面的捐款者是重要捐款人（Grand Patrons）。然后，程序将列出其他的捐款者，该列表要以Patrons开头。如果某种类别没有捐款者，则程序将打印单词“none”。该程序只显示这两种类别，而不进行排序。

答:

```c++
#include <iostream>
#include <string>

using namespace std;

struct donor
{
    string name;
    double money;
};

int main(void)
{
    int n;
    cout << "Enter the number of donors: ";
    cin >> n;
    cin.get();

    donor *donors = new donor[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Donor's name: ";
        getline(cin, (donors + i)->name); // 字符和数字混合输入注意捕获队列中空白字符
        cout << "Donor's donation: ";
        cin >> (donors + i)->money;
        cin.get();
    }

    int n_gp = 0, n_p = 0;

    cout << "Grand Patrons" << endl;
    for (int i = 0; i < n; i++)
        if (donors[i].money > 10000)
        {
            cout << "Name: " << donors[i].name << "\tDonation: " << donors[i].money << endl;
            ++n_gp;
        }
    if (!n_gp)
        cout << "none" << endl;

    cout << "Patrons" << endl;
    for (int i = 0; i < n; i++)
        if (donors[i].money <= 10000)
        {
            cout << "Name: " << donors[i].name << "\tDonation: " << donors[i].money << endl;
            ++n_p;
        }
    if (!n_p)
        cout << "none" << endl;

    delete[] donors;

    return 0;
}
```

## 6.7

题: 编写一个程序，它每次读取一个单词，直到用户只输入q。然后，该程序指出有多少个单词以元音打头，有多少个单词以辅音打头，还有多少个单词不属于这两类。为此，方法之一是，使用isalpha( )来区分以字母和其他字符打头的单词，然后对于通过了isalpha( )测试的单词，使用if或switch语句来确定哪些以元音打头。

该程序的运行情况如下：

```cmd
Enter words (q to quit):
The 12 awesome oxen ambled
quiet across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 otherss
```

答:

```c++
#include <iostream>
#include <cstring>
#include <cctype>

const int ArSize = 20;

int main(void)
{
    using namespace std;
    char ch[ArSize];
    int vowels = 0, consonants = 0, others = 0;

    cout << "Enter words (q to quit):" << endl;
    while ((cin >> ch) && strcmp(ch, "q"))
    {
        if (!isalpha(ch[0]))
        {
            ++others;
            continue;
        }
        else
        {
            if (isupper(ch[0]))
                ch[0] = tolower(ch[0]);
            switch (ch[0])
            {
            case 'a':
                ++vowels;
                break;
            case 'e':
                ++vowels;
                break;
            case 'i':
                ++vowels;
                break;
            case 'o':
                ++vowels;
                break;
            case 'u':
                ++vowels;
                break;

            default:
                ++consonants;
                break;
            }
        }
    }
    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;
}
```

## 6.8

题: 编写一个程序，它打开一个文件文件，逐个字符地读取该文件，直到到达文件末尾，然后指出该文件中包含多少个字符。

答:

```c++
#include <iostream>
#include <fstream>

using namespace std;

struct donor
{
    string name;
    double money;
};

int main(void)
{
    ifstream inFile;
    const char *file_loc = "./Practice/charpter_06/tmp/donors.txt";
    inFile.open(file_loc);
    if (!inFile.is_open())
    {
        cout << "Error in opening file!" << endl;
        exit(EXIT_FAILURE);
    }
    int n;
    inFile >> n;
    inFile.get();

    donor *donors = new donor[n];
    for (int i = 0; i < n; i++)
    {

        getline(inFile, (donors + i)->name);
        inFile >> (donors + i)->money;
        inFile.get();
    }

    int n_gp = 0, n_p = 0;

    cout << "Grand Patrons" << endl;
    for (int i = 0; i < n; i++)
        if (donors[i].money > 10000)
        {
            cout << "Name: " << donors[i].name << "\tDonation: " << donors[i].money << endl;
            ++n_gp;
        }
    if (!n_gp)
        cout << "none" << endl;

    cout << "Patrons" << endl;
    for (int i = 0; i < n; i++)
        if (donors[i].money <= 10000)
        {
            cout << "Name: " << donors[i].name << "\tDonation: " << donors[i].money << endl;
            ++n_p;
        }
    if (!n_p)
        cout << "none" << endl;

    delete[] donors;

    return 0;
}
```
