#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef struct {
    int x, y;
} Point;

bool cmp(Point c, Point d)
{
    return c.x < d.x || (c.x == d.x && c.y < d.y);
}

int main()
{
    int b[51][51];
    int temp[51][51];
    int n, l, s;
    cin >> n >> l >> s;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    sort(a.begin(), a.end(), cmp);

    for (int i = s; i >= 0; i--)
        for (int j = 0; j <= s; j++)
            cin >> b[i][j];

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].x + s > l || a[i].y + s > l)
            continue;
        memset(temp, 0, sizeof(temp));

        for (int j = i; j < n; j++) {
            if (a[j].y - a[i].y < 0 || a[j].x - a[i].x > s || a[j].y - a[i].y > s)
                continue;
            temp[a[j].x - a[i].x][a[j].y - a[i].y] = 1;
        }
        bool flag = true;
        for (int k = 0; k <= s; k++)
            for (int j = 0; j <= s; j++)
                if (temp[k][j] != b[k][j]) {
                    flag = false;
                    break;
                }
        if (flag)
            count++;
    }
    cout << count;
    return 0;
}
