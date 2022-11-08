#include <iostream>
#include <cstring>

int main(void)
{
    using namespace std;

    char animal[20] = "bear";
    const char *bird = "wren";
    char *ps;

    /*
    1. bird 是指向const char类型的指针,
    也就意味着 bird的内容是固定的，但其指针存的地址是不固定的
    用在函数时，func(const int * a)，表示a为只读

    2. bird 此时存的值为 "wren" 这个字符串数组的首地址

    3. "wren"本身是一个字符串常量，为了让赋值两边一致，必须
    使用const，不然编译报错(c++)
    */

    cout << animal << " and " << bird << endl;
    // cout << ps << endl; // ps 没有进行初始化，无所指向

    cout << "Enter a kind of animal: ";

    // cin >> ps;   // 缺少指向的地址不能用来接收值
    // cin >> bird; // 字符常量的指针，不能通过cin来改变指向的内容，只能改变地址

    cin >> animal;
    ps = animal; // 有地址指向(和animal相同)

    // 只有char类型的指针能输出字符，int类型的指针就会直接打印地址
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    cout << "After using strcpy\n";
    ps = new char[strlen(animal) + 1]; // 指向的地址空间改变
    strcpy(ps, animal);
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    cout << "After using strncpy\n";
    const char *arr = "a picnic basket filled with many goods";
    cout << "Origin info: " << arr << endl;

    // strcpy 在拷贝时会把多的字节一并拷贝
    int len_st_0 = 10;
    cout << "Strcpy results: (len:" << len_st_0 << ")" << endl;
    ps = new char[len_st_0];
    strcpy(ps, arr);
    cout << ps << " at " << (int *)ps << endl;
    delete[] ps;

    // strncpy 会拷贝限定大小
    int len_st_1 = 10;
    cout << "Strncpy results: (len:" << len_st_1 << ")" << endl;
    ps = new char[len_st_1];
    strncpy(ps, arr, 10);
    cout << ps << " at " << (int *)ps << endl;
    delete[] ps;

    return 0;
}