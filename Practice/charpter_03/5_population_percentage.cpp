#include <iostream>

int main(void)
{
    using namespace std;
    long long cn_p, tot_p;

    cout << "Enter the world's population: ";
    cin >> tot_p; // 7983321000
    cout << "Enter the population of the CN: ";
    cin >> cn_p; // 1412600000

    double cn_per_tot;
    cn_per_tot = 100.0 * cn_p / tot_p;
    // 需要注意，自动类型同样遵守运算顺序，如果最后乘100.0，前面的结果还是整数类型

    cout << "The population of US is ";
    cout << cn_per_tot << "\% of the world population." << endl;

    return 0;
}