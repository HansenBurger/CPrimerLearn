#include <iostream>

int main(void)
{
    using namespace std;
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            cout << '.';
        for (int k = n - 1 - i; k < n; k++)
            cout << '*';
        cout << endl;
    }
    return 0;
}