#include <iostream>

using namespace std;

void showmenu(void);
void report(void);
void comfort(void);

int main(void)
{
    int choice;
    showmenu();
    cin >> choice;
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            cout << "\a\n";
            break;
        case 2:
            report();
            break;
        case 3:
            cout << "The boss was in all day." << endl;
            break;
        case 4:
            comfort();
            break;

        default:
            cout << "That is not a choice" << endl;
            break; // default 在最后，break可以不加
        }
        showmenu();
        cin >> choice;
    }

    return 0;
}

void showmenu(void)
{
    cout << "Please enter 1, 2, 3, 4, 5 as your choise:" << endl;
    cout << "1) alarm\t2) report\n3) alibi\t4) comfort\n5)quit\n"
         << endl;
}

void report(void)
{
    cout << "Sales are up 120%. Expenses are down 35%." << endl;
}

void comfort(void)
{
    cout << "You are the best CEO" << endl;
}