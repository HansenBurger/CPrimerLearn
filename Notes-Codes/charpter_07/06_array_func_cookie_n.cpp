#include <iostream>

using namespace std;

const int ArSize = 8;

int sum_arr(int arr[], int n);
int main(void)
{
    int sum = 0;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << "cookies address: " << cookies << endl;
    cout << "size of cookies: " << sizeof cookies << endl;
    cout << "size of cookie: " << sizeof cookies[0] << endl;
    sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, 3);
    cout << "First three eaten: " << sum << endl;

    sum = sum_arr(cookies + 4, 4);
    cout << "Last four eaten: " << sum << endl;

    return 0;
}

// 不提供元素的数量，是不能通过sizeof来获得数组的大小
int sum_arr(int arr[], int n)
{
    int total = 0;
    // 形参和实参的地址相同，函数传递的是地址
    cout << "arr address: " << arr << endl;
    // 实际计算的是整型指针的大小(即函数内还是对指针的操作)
    // cout << "size of arr: " << sizeof arr << endl;
    for (int i = 0; i < n; i++)
        total += arr[i];

    return total;
}