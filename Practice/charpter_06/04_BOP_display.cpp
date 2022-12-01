#include <iostream>

const int BopN = 5;
const int strsize = 30;

// Benevolent Order of Programmers name structure
struct bop
{
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

int main(void)
{
    using namespace std;
    char choice;

    bop bopmanbers[BopN] = {
        {"Wimp Macho", "Engnieer", "WM", 0},
        {"Raki Rhodes", "Junior Programmer", "RR", 1},
        {"Celia Laiter", "Data Engineer", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "HH", 1},
        {"Pat Hand", "Programmer", "LOOPY", 2}};

    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name\tb. display by title" << endl;
    cout << "c. display by bopname\td. display by preference" << endl;
    cout << "Enter your choice: ";

    while ((cin >> choice) && (choice != 'q'))
    {
        switch (choice)
        {
        case 'a':
            for (int i = 0; i < BopN; i++)
                cout << bopmanbers[i].fullname << endl;
            break;
        case 'b':
            for (int i = 0; i < BopN; i++)
                cout << bopmanbers[i].title << endl;
            break;
        case 'c':
            for (int i = 0; i < BopN; i++)
                cout << bopmanbers[i].bopname << endl;
            break;
        case 'd':
            for (int i = 0; i < BopN; i++)
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