#include <iostream>

int main(void)
{
    using namespace std;

    const int ArSize = 20;

    char name[ArSize];
    char dessert[ArSize];

    // cin使用空白字符确定字符串切割的位置

    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Enter your favorite dessert: " << endl;
    cin >> dessert;

    cout << "I have some delicious " << dessert;
    cout << " for " << name << endl;
}