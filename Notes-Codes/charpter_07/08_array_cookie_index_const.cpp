#include <iostream>

using namespace std;

const int ArSize = 8;

int sum_arr(const int *begin, const int *end);
int main(void)
{
    int sum = 0;
    const int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    sum = sum_arr(cookies, cookies + 8); // 加到最后一个位置，等于末尾之后的位置
    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, cookies + 3);
    cout << "First three eaten: " << sum << endl;

    sum = sum_arr(cookies + 4, cookies + 8);
    cout << "Last four eaten: " << sum << endl;

    return 0;
}

int sum_arr(const int *begin, const int *end)
{
    /*
    1. 形参增加const对于const和非const变量都适用
    2. 除非要修改实参的内容，不建议增加const
    */
    int total = 0;
    const int *pt;
    for (pt = begin; pt != end; pt++)
        total += *pt;

    return total;
}