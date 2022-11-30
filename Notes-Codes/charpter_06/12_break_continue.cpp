#include <iostream>

using namespace std;

const int ArSize = 80;

int main(void)
{
    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:" << endl;
    cin.get(line, ArSize);

    cout << "Complete line: " << line << endl;

    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];
        if (line[i] == '.')
            break;
        // if (line[i] == ' ')
        //     spaces++;
        if (line[i] != ' ')
            continue;
        spaces++;
    }
    cout << endl;
    cout << "Spaces = " << spaces << endl;

    return 0;
}