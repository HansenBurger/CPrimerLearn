#include <iostream>

int main(void)
{
    using namespace std;

    int i = 100;

    for (int i = 0; i < 5; i++)
    {
        cout << "C++ knows loop!" << endl;
    }
    // 作用域内的i值只作用在作用域内
    cout << "C++ i = " << i << endl;

    return 0;
}