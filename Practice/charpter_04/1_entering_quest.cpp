#include <iostream>

const int Str_len = 20;

int main(void)
{
    using namespace std;

    int age;
    char grade, f_name[Str_len], l_name[Str_len];

    cout << "What is your first name? ";
    cin.getline(f_name, Str_len); // getline需要两个参数
    cout << "What is your last name? ";
    cin.getline(l_name, Str_len);
    cout << "What letter grad do you deserve? ";
    cin >> grade;
    // char本身也是整型，可以进行加法运算
    grade = (char)((int)grade + 1); // char (grade + 1)
    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << l_name << ", " << f_name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;

    return 0;
}