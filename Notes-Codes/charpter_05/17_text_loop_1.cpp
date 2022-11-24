#include <iostream>

int main(void)
{
    using namespace std;

    char ch;       // 存储每次输入的字符
    int count = 0; // 记录输入字符数

    cout << "Enter characters, enter # to quit:" << endl;

    cin >> ch;
    while ((ch != '#'))
    {
        cout << ch;
        count++;
        cin >> ch; // 对于空白字符会跨过而不捕获
    }

    cout << endl;
    cout << count << " characters been input." << endl;

    return 0;
}