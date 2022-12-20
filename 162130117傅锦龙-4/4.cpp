#include <iostream>
using namespace std;
int main()
{
    int n, N;
    cin >> n >> N;
    int temp, v = 0, x = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += v * (temp - x);
        x = temp;
        v++;
    }
    sum += v * (N - x);
    cout << sum;
    return 0;
}