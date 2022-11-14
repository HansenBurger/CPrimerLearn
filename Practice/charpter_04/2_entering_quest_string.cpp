#include <iostream>
#include <string>

int main(void)
{
    using namespace std;
    int age;
    char grade;
    string f_name, l_name;

    cout << "What is your first name? ";
    getline(cin, f_name);
    cout << "What is your last name? ";
    getline(cin, l_name);
    cout << "What letter grad do you deserve? ";
    cin >> grade;
    grade = (char)((int)grade + 1);
    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << l_name << ", " << f_name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;

    return 0;
}