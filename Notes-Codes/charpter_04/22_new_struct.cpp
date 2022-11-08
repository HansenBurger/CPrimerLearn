#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(void)
{
    using namespace std;
    inflatable *ps = new inflatable;
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20); // 存放到结构体内的name空间
    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;
    cout << "Enter price $: ";
    cin >> ps->price;

    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " << ps->volume << endl;
    cout << "Price: " << ps->price << endl;

    delete ps;
    return 0;
}