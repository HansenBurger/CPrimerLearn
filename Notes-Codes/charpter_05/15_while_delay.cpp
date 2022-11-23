#include <iostream>
#include <ctime>

int main(void)
{
    using namespace std;

    cout << "Enter the delay time, in seconds: ";

    float secs;
    cin >> secs;
    // clock_t相当于整型，就是时钟节拍的个数
    clock_t delay = secs * CLOCKS_PER_SEC;

    clock_t start = clock();

    // 只要时间差在delay内，就等待(执行空循环)
    while (clock() - start < delay)
        ;
    cout << "End while !" << endl;

    return 0;
}