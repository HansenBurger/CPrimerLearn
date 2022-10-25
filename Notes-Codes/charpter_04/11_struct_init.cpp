#include <iostream>

// 不提倡外部变量，但是提倡外部结构体

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(void)
{
    using namespace std;

    inflatable guest = {
        "Glorious Gloria",
        1.88,
        29.99};

    inflatable pal = {
        "Audacious Arthur",
        3.12,
        32.99};

    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << endl;
    cout << "You can have both for $: ";
    cout << guest.price + pal.price << endl;

    return 0;
}