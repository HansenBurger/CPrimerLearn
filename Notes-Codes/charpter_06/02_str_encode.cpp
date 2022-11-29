#include <iostream>

int main(void)
{
    using namespace std;

    char ch;

    cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            cout << ch;
        else
            // cout << ch + 1; 这样会导致类型提升，输出不是字符而是数字
            cout << ++ch;
        cin.get(ch);
    }

    cout << "\nPlease excuse the slight confusion.\n";

    return 0;
}