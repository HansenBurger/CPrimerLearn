#include <iostream>
#include <cctype>

int main(void)
{
    using namespace std;

    char ch;
    while ((cin.get(ch)) && (ch != '@'))
    {
        if (islower(ch))
            ch = toupper(ch);
        else if (isupper(ch))
            ch = tolower(ch);
        cout << ch;
    }

    return 0;
}