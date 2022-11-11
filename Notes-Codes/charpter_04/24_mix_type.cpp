#include <iostream>
using namespace std;

struct antarctica_years_end
{
    int year;
};

int main(void)
{
    // 结构体变量
    antarctica_years_end s_1, s_2, s_3;
    s_1.year = 1998;

    // 结构体指针
    antarctica_years_end *pa = &s_2;
    pa->year = 1999;

    // 结构体数组
    antarctica_years_end trio[3] = {s_1, s_2, s_3};
    cout << trio << endl;
    cout << trio + 1 << endl;
    cout << trio + 2 << endl;

    trio[0].year = 2003;

    // 数组名本身代表地址
    cout << trio->year << endl;

    // 结构体指针数组(指向对象为常量，不能修改)，数组中存的也是地址
    const antarctica_years_end *arp[3] = {&s_1, &s_2, &s_3};

    // 数组中存的是指向结构体的地址，->访问成员变量
    cout << (**(arp + 1)).year << endl;

    // arp是结构体指针数组的首地址，ppa为指向结构体指针(arp[0])的指针
    const antarctica_years_end **ppa = arp;

    cout << "&s_1: " << &s_1 << endl;
    cout << "*ppa: " << *ppa << endl;
    cout << "(*ppa)->year: " << (*ppa)->year << endl;

    // auto声明，ppb自动为结构体指针数组

    auto ppb = arp;
    cout << (*(ppb + 1))->year << endl; // (*(ppb+1)) = &s_2

    return 0;
}