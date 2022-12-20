#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main()
{
    int m, a, b, s;
    int max = 0, res = 0;
    cin >> m;
    int *sum = new int[m + 1];
    PII *num = new PII[m];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        num[i] = make_pair(a, b);
    }

    sort(num, num + m);
    sum[0] = 0;

    for (int i = 1; i <= m; i++) {
        sum[i] = sum[i - 1] + num[i - 1].second;
    }

    for (int i = 0; i < m; i++) {
        a = num[i].first;
        if (i && a == b)
            continue;
        s = sum[m] + i - 2 * sum[i];
        if (s >= max) {
            max = s;
            res = a;
        }
        b = a;
    }
    cout << res;
    return 0;
}