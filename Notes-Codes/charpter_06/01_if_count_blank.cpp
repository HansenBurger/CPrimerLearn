#include <iostream>

using namespace std;

int main(void)
{
    char ch;
    int spaces = 0, total = 0;

    cin.get(ch);
    while (ch != '.')
    {
        if (ch == ' ')
            spaces++;
        total++;
        cin.get(ch);
    }

    cout << "spaces = " << spaces << endl;
    cout << "total characters = " << total << endl;

    return 0;
}