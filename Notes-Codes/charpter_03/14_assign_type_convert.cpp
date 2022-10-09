#include <iostream>

int main(void)
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tree = 3;
    int guess(3.9832);
    // int debt = 7.2E12;

    cout << "tree = " << tree << endl;   // int(常量) -> float(变量)
    cout << "guess = " << guess << endl; // 浮点->整型，但未溢出
    // cout << "debt = " << debt << endl;   // 溢出后结果不可确定

    return 0;
}