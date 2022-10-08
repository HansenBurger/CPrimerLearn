#include <iostream>

int main(void)
{
    using namespace std;

    int cheat = 42;
    int waist = 0x42; // 16进制
    int inseam = 042; // 8进制

    //最终显示的都是上面值对应的10进制结果

    cout << "cheat = " << cheat << " (42 in dec)." << endl;

    cout << "waist = " << waist << " (0x42 in hex)." << endl;

    cout << "inseam = " << inseam << " (042 in oct)." << endl;

    return 0;
}