#include <iostream>
using namespace std;

int main()
{
    int n, i, x;
    cout << "���������ֵ x: ";
    cin >> x;
    cout << "�������ʽ�Ľ״� n: ";
    cin >> n;
    int *a = new int[n + 1];
    cout << "�������ʽ��ϵ��: ";
    for (i = 0; i <= n; i++)
        cin >> a[i];
    int sum = a[n];
    for (i = n - 1; i >= 0; i--) {
        sum *= x;
        sum += a[i];
    }
    cout << "����ʽ��ֵ��" << sum << endl;
    return 0;
}