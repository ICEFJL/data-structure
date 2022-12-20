#include <iostream>
using namespace std;

int main()
{
    int c[30] = {1};
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] *= c[i - 1];
    }

    int last = 0;
    for (int i = 1; i <= n; i++) {
        int b = m % c[i];
        cout << (b - last) / c[i - 1] << " ";
        last = b;
    }
    return 0;
}