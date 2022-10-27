#include <iostream>

int main(void)
{
    using namespace std;

    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    // 取数组第一个地址的两种方法
    double *pw = wages;     // 数组名数组首地址
    short *ps = &stacks[0]; // 提取第一个元素的地址

    cout << "pw = " << pw << " , *pw = " << *pw << endl;
    pw = pw + 1; // 地址加1(具体地址值的变动还是元素类型决定)
    cout << "add 1 to the pw pointer." << endl;
    cout << "now pw = " << pw << " , *pw = " << *pw << endl;

    cout << "ps = " << ps << " , *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer." << endl;
    cout << "now ps = " << ps << " , *ps = " << *ps << endl;

    cout << "stack[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    cout << "*stacks = " << *stacks << ", stacks + 1 = " << *(stacks + 1) << endl;

    // 虽然数组名和数组的首地址等价，但使用sizeof不会将他解释成地址
    cout << "size of wages array = " << sizeof wages << endl;
    cout << "size of pw pointer = " << sizeof pw << endl;

    return 0;
}