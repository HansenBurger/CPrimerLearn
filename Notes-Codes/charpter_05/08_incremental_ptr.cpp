#include <iostream>

/*
1) *++pt
2) ++*pt
3) (*pt)++
4) *pt++
*/

int main(void)
{
    using namespace std;

    double arr[5] = {21.1, 32.8, 23.4, 45.2, 37.4};
    double *pt = arr;

    cout << "*pt: " << *pt << endl;
    cout << "*++pt: " << *++pt << endl;
    // 等价于*(pt+1)，前缀递增递减与取值优先级相同，从右到做顺序，此时指针+1

    cout << "++*pt: " << ++*pt << endl; // 等价 *pt + 1
    cout << "*pt: " << *pt << endl;

    cout << "(*pt)++: " << (*pt)++ << endl; // 等价 *pt + 1，此时pt指向的值改变了
    cout << "*pt: " << *pt << endl;
    // 后缀的优先级要优于前缀

    cout << "*pt++: " << *pt++ << endl;
    // pt = pt+1，但要后处理，所以先取出*pt
    cout << "*pt: " << *pt << endl;

    return 0;
}