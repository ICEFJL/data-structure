#include <iostream>
using namespace std;

#define MAXINT 90000
#define ArrSize 10

int main()
{
    int n;
    int a[ArrSize];
    cout << "���� n:";
    cin >> n;
    if (n > ArrSize) {
        cout << "n�ķ�Χ�������鷶Χ" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0)
            a[i] = 2;
        else {
            if (2 * (i + 1) * a[i - 1] > MAXINT) {
                cout << "��ֵ�����޷��洢" << endl;
                break;
            } else
                a[i] = 2 * (i + 1) * a[i - 1];
        }
        cout << a[i] << " ";
    }
    return 0;
}