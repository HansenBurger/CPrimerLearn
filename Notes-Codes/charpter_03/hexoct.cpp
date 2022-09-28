#include <iostream>

int main(void)
{
    using namespace std;

    int cheat = 42;
    int waist = 0x42;
    int inseam = 042;

    cout << "cheat = " << cheat << " (42 in dec)." << endl;

    cout << hex; // 修改显示整数方式，对之后的输出有效
    cout << "waist = " << waist << " (0x42 in hex)." << endl;

    cout << oct;
    cout << "inseam = " << inseam << " (042 in oct)." << endl;

    return 0;
}