#include <iostream>
#include <string>

int main(void)
{
    using namespace std;
    string f_n, l_n;
    cout << "Enter your first name: ";
    getline(cin, f_n);
    cout << "Enter your last name: ";
    getline(cin, l_n);
    cout << "Here's the information int a single string: ";
    cout << l_n + ", " + f_n << endl;
    return 0;
}