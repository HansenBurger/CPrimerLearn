#include <iostream>

using namespace std;

void simple(void)
{
    cout << "I'm but a simple function." << endl;
}

int main(void)
{
    cout << "main() will call the simple function: " << endl;
    simple();
    return 0;
}
