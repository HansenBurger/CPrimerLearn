#include <iostream>

int main(void)
{
    using namespace std;

    int yams[3];

    // 方式 1: 逐个赋值
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    // 方式2: 声明同时赋值

    int yamscosts[3] = {20, 30, 5};

    cout << "The total yams ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamscosts[1] << " cents per yams." << endl;
    cout << "The total yams cost: ";
    cout << yams[0] * yamscosts[0] + yams[1] * yamscosts[1] + yams[2] * yamscosts[2];
    cout << " cents." << endl;

    cout << "Size of yams array = " << sizeof yams << " bytes." << endl;
    cout << "Size of one element = " << sizeof yams[0] << " bytes." << endl;

    return 0;
}