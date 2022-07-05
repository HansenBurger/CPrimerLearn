#include <iostream>
using namespace std;

int main(void)
{
    int carrots;
    carrots = 25; // 使用变量之前需要先声明(开辟对应类型的内存空间)
    cout << "I have ";
    cout << carrots;              // 此时carrots就是变量(存储于中的整形数)
    cout << " Binary: " << 11001; // 内存中值(二进制)
    cout << endl;

    carrots = carrots - 1;
    cout << "Crunch, Crunch, Now I have " << carrots << " carrots";
    cout << endl;
    return 0;
}