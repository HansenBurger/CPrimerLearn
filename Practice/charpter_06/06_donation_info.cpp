#include <iostream>
#include <string>

using namespace std;

struct donor
{
    string name;
    double money;
};

int main(void)
{
    int n;
    cout << "Enter the number of donors: ";
    cin >> n;
    cin.get();

    donor *donors = new donor[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Donor's name: ";
        getline(cin, (donors + i)->name); // 字符和数字混合输入注意捕获队列中空白字符
        cout << "Donor's donation: ";
        cin >> (donors + i)->money;
        cin.get();
    }

    int n_gp = 0, n_p = 0;

    cout << "Grand Patrons" << endl;
    for (int i = 0; i < n; i++)
        if (donors[i].money > 10000)
        {
            cout << "Name: " << donors[i].name << "\tDonation: " << donors[i].money << endl;
            ++n_gp;
        }
    if (!n_gp)
        cout << "none" << endl;

    cout << "Patrons" << endl;
    for (int i = 0; i < n; i++)
        if (donors[i].money <= 10000)
        {
            cout << "Name: " << donors[i].name << "\tDonation: " << donors[i].money << endl;
            ++n_p;
        }
    if (!n_p)
        cout << "none" << endl;

    delete[] donors;

    return 0;
}
