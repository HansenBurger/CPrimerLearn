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