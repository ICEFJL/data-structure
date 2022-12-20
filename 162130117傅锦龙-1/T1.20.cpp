#include <iostream>
using namespace std;

int main()
{
    int n, i, x;
    cout << "输入变量的值 x: ";
    cin >> x;
    cout << "输入多项式的阶次 n: ";
    cin >> n;
    int *a = new int[n + 1];
    cout << "输入多项式的系数: ";
    for (i = 0; i <= n; i++)
        cin >> a[i];
    int sum = a[n];
    for (i = n - 1; i >= 0; i--) {
        sum *= x;
        sum += a[i];
    }
    cout << "多项式的值：" << sum << endl;
    return 0;
}