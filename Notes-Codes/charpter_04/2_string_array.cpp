#include <iostream>
#include <cstring>

int main(void)
{
    using namespace std;

    const int Size = 15;

    char name1[Size];
    char name2[Size] = "C++owboy";

    cout << "Howdy! I'm " << name2 << ". What is your name?" << endl;
    cin >> name1;
    cout << "Well, " << name1 << ", your name has " << strlen(name1) << " letters." << endl;
    cout << "And your name is stored in an array of " << sizeof name1 << " bytes." << endl;

    // sizeof 计算数组长度, strlen 计算数组中字符串长度(不包括空字符)

    return 0;
}