#include <iostream>
#include <fstream>

using namespace std;

struct donor
{
    string name;
    double money;
};

int main(void)
{
    ifstream inFile;
    const char *file_loc = "./Practice/charpter_06/tmp/donors.txt";
    inFile.open(file_loc);
    if (!inFile.is_open())
    {
        cout << "Error in opening file!" << endl;
        exit(EXIT_FAILURE);
    }
    int n;
    inFile >> n;
    inFile.get();
    if (n <= 0) // 遇到n不满足，直接退出
        exit(EXIT_FAILURE);

    donor *donors = new donor[n];
    // 用while需要满足，不是eof且读取的i小于n
    for (int i = 0; i < n; i++)
    {

        getline(inFile, (donors + i)->name);
        cout << "Read name: " << donors[i].name << endl;
        inFile >> (donors + i)->money;
        cout << "Donation: " << donors[i].money << endl;
        inFile.get();
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