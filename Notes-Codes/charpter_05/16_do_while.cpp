#include <iostream>

int main(void)
{
    using namespace std;

    cout << "Enter numbers in the range 1~10 to find my favorite number" << endl;
    int n;

    do
    {
        cin >> n;
    } while (n != 7);

    return 0;
}