#include <iostream>

using namespace std;

int main(void)
{
    cout << "This program mayreformat your hard disk, and destroy all your data." << endl;
    cout << "Do you wish to continue ? <y/n>" << endl;

    char ch;
    cin >> ch;

    if (ch == 'y' || ch == 'Y')
        cout << "You were warned!" << endl;
    else if (ch == 'n' || ch == 'N')
        cout << "A wise choise ..." << endl;
    else
        cout << "That's wasn't a y or n !" << endl;
}