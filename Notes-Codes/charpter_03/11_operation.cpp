#include <iostream>

int main(void)
{
    using namespace std;

    float hats, heads;

    // 如果没有强制小数点，则四舍五入自动近似
    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Enter a number: ";
    cin >> hats;

    cout << "Enter another number: ";
    cin >> heads;

    cout << "hats = " << hats << ",heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    // 此时float的位数不足够表示结果，只是近似值
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;

    return 0;
}