#include <iostream>

int main(void)
{
    using namespace std;

    int cheat = 42;
    int waist = 0x42; // 16进制
    int inseam = 042; // 8进制

    cout << dec;
    cout << "cheat = " << cheat << " (42 in dec)." << endl;

    cout << hex;
    cout << "waist = " << waist << " (0x42 in hex)." << endl;

    cout << oct; // 显示的数据类型依据最近一次的切换
    cout << "inseam = " << inseam << " (042 in oct)." << endl;

    return 0;
}