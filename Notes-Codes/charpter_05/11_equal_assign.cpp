#include <iostream>

int main(void)
{
    using namespace std;

    int arr[10] = {20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

    cout << "Doing it right: " << endl;
    int i;
    for (i = 0; arr[i] == 20; i++)
        cout << "arr[" << i << "] is " << arr[i] << endl;

    // cout << "Doing it danerous: " << endl;
    // for (i = 0; arr[i] = 20; i++)
    //     cout << "arr[" << i << "] is " << arr[i] << endl;
    // 陷入死循环

    return 0;
}