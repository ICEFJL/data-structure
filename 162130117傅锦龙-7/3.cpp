#include <iostream>
using namespace std;

int main()
{
    int n, num, D = 0, E = 0;
    long long T = 0;
    int Drop[1001] = {0}, A[1001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> A[j];

        int temp = A[0];
        for (int j = 1; j < num; j++) {
            if (A[j] <= 0) {
                temp = temp + A[j];
            } else if (temp > A[j]) {
                Drop[i] = 1;
                temp = A[j];
            }
        }
        T += temp;
    }
    for (int i = 0; i < n; i++) {
        if (Drop[i] == 1)
            D++;
        if (Drop[i % n] == 1 && Drop[(i + 1) % n] == 1 && Drop[(i + 2) % n] == 1)
            E++;
    }
    cout << T << " " << D << " " << E << endl;

    return 0;
}
