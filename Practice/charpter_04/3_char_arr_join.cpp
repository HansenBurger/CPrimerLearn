#include <iostream>
#include <cstring>

const int Str_len = 20;

int main(void)
{
    using namespace std;
    char f_n[Str_len], l_n[Str_len];
    cout << "Enter your first name: ";
    cin.getline(f_n, Str_len);
    cout << "Enter your last name: ";
    cin.getline(l_n, Str_len);
    cout << "Here's the information int a single string: ";
    cout << strcat(strcat(l_n, ", "), f_n) << endl;

    return 0;
}