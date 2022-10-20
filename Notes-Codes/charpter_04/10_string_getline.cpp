#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
    using namespace std;

    char charr[20];
    string str;

    cout << "Length of string of charr before assgin: ";
    cout << strlen(charr) << endl;

    cout << "Length of string of str before assgin: ";
    cout << str.size() << endl;

    cout << "Enter a line of text: " << endl;
    cin.getline(charr, 20);
    cout << "You entered: " << charr << endl;

    cout << "Enter another line of text: " << endl;
    getline(cin, str);
    cout << "You entered: " << str << endl;

    cout << "Length of string of charr after input: ";
    cout << strlen(charr) << endl;

    cout << "Length of string of str after input: ";
    cout << str.size() << endl;

    return 0;
}