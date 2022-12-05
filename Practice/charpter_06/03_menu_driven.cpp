#include <iostream>

int main(void)
{
    using namespace std;
    char ch;
    const char *prefix = "A maple is a ";
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore\t p) pianist" << endl;
    cout << "t) tree\t\t g) game" << endl;

    while (cin >> ch)
    {
        switch (ch)
        {
        case 'c':
            cout << prefix << "carnivore" << endl;
            break;
        case 'p':
            cout << prefix << "pianist" << endl;
            break;
        case 't':
            cout << prefix << "tree" << endl;
            break;
        case 'g':
            cout << prefix << "game" << endl;
            break;

        default:
            cout << "Please enter a c, p, t, or g: ";
            break;
        }
    }

    return 0;
}