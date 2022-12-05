#include <iostream>
#include <cctype>

int main(void)
{
    using namespace std;

    char ch;
    cout << "Please enter characters:" << endl;

    while ((cin.get(ch)) && (ch != '@'))
    {
        if (isdigit(ch))
            continue;
        else if (islower(ch))
            ch = toupper(ch);
        else
            ch = tolower(ch);
        cout << ch;
    }

    return 0;
}