#include <iostream>

const int strsize = 30;
using namespace std;

// Benevolent Order of Programmers name structure
struct bop
{
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

void showmenu(void);

int main(void)
{

    char choice;
    showmenu();
    // 结构体数组不一定要和初始化长度相等
    bop bopmanbers[] = {
        {"Wimp Macho", "Engnieer", "WM", 0},
        {"Raki Rhodes", "Junior Programmer", "RR", 1},
        {"Celia Laiter", "Data Engineer", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "HH", 1},
        {"Pat Hand", "Programmer", "LOOPY", 2}};

    // 得到结构体数组地长度，通过先sizeof数组指针地长度，再除以每个元素地长度
    int bop_size = sizeof(bopmanbers) / sizeof(bopmanbers[0]);

    while ((cin >> choice) && (choice != 'q'))
    {
        switch (choice)
        {
        case 'a':
            for (int i = 0; i < bop_size; i++)
                cout << bopmanbers[i].fullname << endl;
            break;
        case 'b':
            for (int i = 0; i < bop_size; i++)
                cout << bopmanbers[i].title << endl;
            break;
        case 'c':
            for (int i = 0; i < bop_size; i++)
                cout << bopmanbers[i].bopname << endl;
            break;
        case 'd':
            for (int i = 0; i < bop_size; i++)
                switch (bopmanbers[i].preference)
                {
                case 0:
                    cout << bopmanbers[i].fullname << endl;
                    break;
                case 1:
                    cout << bopmanbers[i].title << endl;
                    break;
                case 2:
                    cout << bopmanbers[i].bopname << endl;
                    break;
                default:
                    break;
                }
            break;
        default:
            cout << "Please enter(a, b, c, d): ";
            continue;
        }
        cout << "Next choice: ";
    }

    cout << "Bye!" << endl;
    return 0;
}

void showmenu(void)
{
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name\tb. display by title" << endl;
    cout << "c. display by bopname\td. display by preference" << endl;
    cout << "Enter your choice: ";
}