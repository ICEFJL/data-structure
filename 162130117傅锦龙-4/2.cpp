#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int m, n;
    bool flag = false;
    cout << "请输入行数m和列数n:" << endl;
    cin >> m >> n;
    flag = false;
    int *min = new int[m]{0};
    int *max = new int[n]{0};
    int **a = new int *[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 6;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++) {
        min[i] = a[i][0];
        for (int j = 1; j < n; j++)
            if (min[i] > a[i][j])
                min[i] = a[i][j];
    }
    for (int j = 0; j < n; j++) {
        max[j] = a[0][j];
        for (int i = 1; i < m; i++)
            if (max[j] < a[i][j])
                max[j] = a[i][j];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (min[i] == max[j]) {
                cout << "第" << i + 1 << "行第" << j + 1 << "列的" << a[i][j] << "为马鞍点" << endl;
                flag = true;
            }
        }
    }
    if (flag == false) {
        cout << "没有马鞍点" << endl;
    }
}