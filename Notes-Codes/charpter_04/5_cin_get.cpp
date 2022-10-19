#include <iostream>

int main(void)
{
    using namespace std;

    const int ArSize = 20;

    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name: " << endl;
    cin.get(name, ArSize);

    cin.get(); // read enter
    // cin.get(name, ArSize).get();

    cout << "Enter your favorite dessert: " << endl;
    cin.get(dessert, ArSize);

    cout << "I have some delicious " << dessert;
    cout << " for " << name << endl;
}