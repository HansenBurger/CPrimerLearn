#include <iostream>

int main(void)
{
    using namespace std;

    int auks, bats, coots;

    auks = 19.99 + 11.99;           // doubel + doubel 后只保留整数部分
    bats = (int)19.99 + (int)11.99; // 先转换再相加
    coots = int(19.99) + int(11.99);

    cout << "auks = " << auks << endl;
    cout << "bats = " << bats << endl;
    cout << "coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is " << (int)ch << endl;
    cout << static_cast<int>(ch) << endl;

    return 0;
}