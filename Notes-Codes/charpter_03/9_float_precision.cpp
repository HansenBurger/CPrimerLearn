#include <iostream>

int main(void)
{
    using namespace std;

    // 为了避免程序使用E表示，并使程序显示到小数点后6位

    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;
    const float million = 1.0E6;

    cout << "tub = " << tub << endl;
    cout << "A million tubs = " << million * tub << endl; // 输出后会发现精度有误
    cout << "Ten million tubs = " << 10 * million * tub << endl;

    double mint = 10.0 / 3.0;

    cout << "mint = " << mint << endl;
    cout << "A million mints = " << million * mint << endl;        // 输出后会发现精度无误
    cout << "Ten million mints = " << 10 * million * mint << endl; // 精度依然无误

    return 0;
}