#include <iostream>

using namespace std;

int main()
{
    int n, m, sum = 0;
    cin >> n >> m;
    int *v = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int *f = new int[sum + 1]{};
    f[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = sum; j >= v[i]; j--)
            f[j] |= f[j - v[i]];
    for (int i = m; i <= sum; i++)
        if (f[i]) {
            cout << i << endl;
            break;
        }
    return 0;
}