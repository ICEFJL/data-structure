#include <iostream>
using namespace std;

int main()
{
    int n, k, x, y, cnt = 0;
    cin >> n >> k;

    int *flag = new int[n + 1]{0};
    flag[0] = 1;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        if (flag[y] == 0)
            cnt++;
        flag[x] = 1;
    }

    cout << cnt;

    return 0;
}