#include <iostream>

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter an integer: ";
    int by;
    cin >> by;

    cout << "Counting by " << by << endl;

    for (int i = 0; i < 100; i += by)
        cout << i << endl;

    return 0;
}