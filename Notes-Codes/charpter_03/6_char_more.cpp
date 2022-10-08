#include <iostream>

int main(void)
{
    using namespace std;

    char ch = 'M';
    int i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    ch += 1; // ASCII对应字符向后推
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);
    cout.put('!'); // 对于单个字符可以用cout.put方法

    cout << endl
         << "Done" << endl;

    return 0;
}