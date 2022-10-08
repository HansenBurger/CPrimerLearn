#include <iostream>

int main(void)
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Integer division: 9/5 = " << 9 / 5 << endl; // 存在取整操作
    cout << "Float division: 9.0/5.0 = " << 9.0 / 5.0 << endl;
    cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << endl;          // 自动提升数据类型，转换同一类型计算
    cout << "Double division: 1e7/9.0 = " << 1e7 / 9.0 << endl;     // 自动变换为double计算
    cout << "Float constance: 1e7f/9.0f = " << 1e7f / 9.0f << endl; // 由于数据类型问题，和前者结果不同
    return 0;
}