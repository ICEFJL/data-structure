#include <iostream>

using namespace std;

int main()
{
    int n, a[2005][2], b[2005][2];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i][0] >> b[i][1];
    }
    int i = 0, j = 0, res = 0, x = 0, y = 0;
    while (i < n && j < n) {
        if (a[i][1] <= b[j][0])
            i++;
        else if (a[i][0] >= b[j][1])
            j++;
        else {
            x = max(a[i][0], b[j][0]);
            y = min(a[i][1], b[j][1]);
            res += y - x;
            if (y == a[i][1])
                i++;
            else
                j++;
        }
    }
    cout << res;

    return 0;
}