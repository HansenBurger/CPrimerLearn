#include <iostream>

using namespace std;

const int Max = 5;

int main(void)
{
    double fish[Max]; //数组中最多5条鱼

    cout << "Enter the weight of your fish:" << endl;
    cout << "You may enter up to " << Max;
    cout << " fish <q> to terminate." << endl;

    cout << "fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i]) // cin本身具备返回值
    {
        if (++i < Max)
            cout << "fish #" << i + 1 << " : ";
    }
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];
    if (i == 0)
        cout << "No fish" << endl;
    else
        cout << "Average weight of " << i << " fish: " << total / i << endl;
}