#include <iostream>

using namespace std;

void n_chars(char ch, int n);

int main(void)
{
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    while (ch != 'q')
    {
        cout << "Enter a integer: ";
        cin >> times;
        n_chars(ch, times);
        // cout << "times = " << times; 实参传递给形参的是拷贝，自身不发生变化
        cout << endl;
        cout << "Enter another character or press q_key to quit: ";
        cin >> ch;
    }
    cout << "Bye" << endl;

    return 0;
}

void n_chars(char ch, int n)
{
    while (n--)
    {
        cout << ch;
    }
}