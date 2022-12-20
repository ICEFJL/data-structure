#include <iostream>
using namespace std;
int main()
{
    long long r, y, g, n, k, t, time = 0, sum, v;
    cin >> r >> y >> g;
    sum = r + y + g;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k >> t;
        if (k == 0)
            time += t;
        else {
            if (k == 1)
                v = (r - t + time) % sum;
            else if (k == 2)
                v = (sum - t + time) % sum;
            else
                v = (r + g - t + time) % sum;
            if (v >= 0 && v < r)
                time += r - v ;
            if (v >= r + g)
                time += r + sum - v;
        }
    }
    cout << time;
}