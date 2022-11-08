#include <iostream>
#include <cstring>
using namespace std;

char *getname(void);

int main()
{
    char *name;
    name = getname();
    cout << name << " at " << (int *)name << endl;
    // name 只是char数组的起始地址，但delete要释放整个数组
    delete[] name;
}

char *getname(void)
/*
getname:
功能: 使用cin将输入的单词放到temp数组中，然后使用new分配新内存
返回: 指向temp数组的指针
*/
{
    char tmp[80];
    cout << "Enter last name: ";
    cin >> tmp;

    char *pn = new char[strlen(tmp)];
    strcpy(pn, tmp);

    return pn;
}

// delete和new最好在同一函数内，避免遗忘