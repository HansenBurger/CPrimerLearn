#include <iostream>

int main(void)
{
    using namespace std;

    short tell[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "tell = " << tell << endl;
    cout << "tell + 1 = " << tell + 1 << endl;
    cout << "&tell + 1 = " << &tell + 1 << endl;

    return 0;
}