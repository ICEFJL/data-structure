#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int q[200020] = {0};
    int n, m, k, t, c, qi;
    cin >> n >> m >> k;
    while (n--) {
        cin >> t >> c;
        if (k < t) {
            int l = max(1, t - c - k + 1);
            int r = t - k;
            q[l]++, q[r + 1]--;
        }
    }
    for (int i = 1; i < 200020; i++)
        q[i] += q[i - 1];
    while (m--) {
        cin >> qi;
        cout << "  "<< q[qi] << endl;
    }
}