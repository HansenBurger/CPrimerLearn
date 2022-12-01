#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(void)
{

    ifstream inFile;
    const char *file_loc = "./Practice/charpter_06/tmp/test.txt";
    inFile.open(file_loc);
    if (!inFile.is_open())
    {
        cout << "Error in opening file!" << endl;
        exit(EXIT_FAILURE);
    }
    int n = 0;
    char ch;
    while ((inFile >> ch) && !inFile.fail())
    {
        ++n;
    }
    cout << "This file totally have " << n << " characters." << endl;
    inFile.close();

    return 0;
}