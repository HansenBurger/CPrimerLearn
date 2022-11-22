#include <iostream>

int main(void)
{
    using namespace std;

    cout << "Enter the starting countdown value: ";
    int limit;

    cin >> limit;

    int i;

    for (i = limit; i; i--) // 只要i为非0值就能输出
        cout << "i = " << i << endl;

    cout << "Done, now that i = " << i << endl;

    return 0;
}