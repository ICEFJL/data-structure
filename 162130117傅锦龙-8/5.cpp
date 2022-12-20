#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e3 + 10;
typedef long long LL;
typedef pair<LL, LL> PLL;

int main()
{
    map<PLL, int> m;
    PLL g[N];
    int ans[5] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[i] = {x, y};
        m[g[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        LL F = g[i].first, S = g[i].second;
        if (m[{F, S + 1}] && m[{F, S - 1}] && m[{F + 1, S}] && m[{F - 1, S}]) {
            sum += m[{F + 1, S + 1}] + m[{F + 1, S - 1}] + m[{F - 1, S + 1}] + m[{F - 1, S - 1}];
            ans[sum]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << endl;
    }
}
