#include <iostream>
#include <array>

const int ArrSize = 10;

int main(void)
{
    using namespace std;
    array<double, ArrSize> donations;
    double sum = 0.0, mean = 0.0;
    int ind = 0, over_mean = 0;

    cout << "Enter the donations(not more than " << ArrSize << "): " << endl;

    // 需要同时满足输入有效和长度有效
    while ((cin >> donations[ind++]) && (ind < ArrSize))
        ;

    for (int i = 0; i < ind; i++)
        sum += donations[i];

    mean = sum / ind;
    for (int i = 0; i < ind; i++)
        if (donations[i] > mean)
            ++over_mean;

    cout << "Sum:\t" << sum << endl;
    cout << "Average:\t" << mean << endl;
    cout << "Over average:\t" << over_mean << endl;

    return 0;
}