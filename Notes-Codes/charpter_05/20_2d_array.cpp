#include <iostream>
#include <string>

const int Cities = 5;
const int Years = 4;

int main(void)
{
    using namespace std;

    /*
    这里的cities是一个字符指针的数组，
    指向的是字符串常量的首地址
    等价于 char[Cities][ArSize]
    对比前一种方法限定了字符串长度，可能不够也可能浪费(经济)
    也能使用string类的数组
    */

    const char *cities[Cities] = // 用string类可以不加const
        {
            "Gribble City",
            "Gribbletown",
            "New Gribble",
            "San Gribble",
            "Gribble Vista"

        };

    int maxtemps[Years][Cities] =
        {
            {96, 100, 27, 101, 105},
            {96, 98, 91, 107, 104},
            {97, 101, 93, 108, 107},
            {98, 103, 95, 109, 108}};

    cout << "City: Maximum temperature for 2008 - 2011" << endl;
    for (int city = 0; city < Cities; city++)
    {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; year++)
            cout << maxtemps[year][city] << "\t"; // \t可以自动对齐
        cout << endl;
    }

    return 0;
}