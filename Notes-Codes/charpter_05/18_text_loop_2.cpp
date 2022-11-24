#include <iostream>

int main(void)
{
    using namespace std;

    char ch;       // 存储每次输入的字符
    int count = 0; // 记录输入字符数

    cout << "Enter characters, enter # to quit:" << endl;

    cin.get(ch);
    while ((ch != '#'))
    {
        cout << ch;
        count++;
        cin.get(ch); // 不跳过空白字符(包括空格和回车)
        /*
        修改函数的形参，直接修改只是改变拷贝，
        如果要修改，只能输入指针
        */
    }

    cout << endl;
    cout << count << " characters been input." << endl;

    return 0;
}