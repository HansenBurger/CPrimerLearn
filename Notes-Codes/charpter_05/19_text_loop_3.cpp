#include <iostream>

int main(void)
{
    using namespace std;

    char ch;       // 存储每次输入的字符
    int count = 0; // 记录输入字符数

    cout << "Enter characters, enter # to quit:" << endl;

    cin.get(ch);
    while (cin.fail() == false) // 直到EOF停止
    {
        cout << ch;
        count++;
        cin.get(ch);
    }

    cout << endl;
    cout << count << " characters been input." << endl;

    return 0;
}