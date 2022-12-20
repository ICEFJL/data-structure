#include <iostream>
using namespace std;
int map[16][10], box[4][4];

int Judge(int r, int c)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (box[i][j] == 1 && map[i + r][j + c] == 1)
                return 1;
    return 0;
}
int main()
{
    for (int j = 0; j < 10; j++)
        map[15][j] = 1;

    int n, m = 0;

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 10; j++)
            cin >> map[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> box[i][j];

    cin >> n;

    for (int i = 0; i < 15; i++) {
        if (Judge(i, n - 1))
            break;
        m = i;
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (box[i][j] == 1)
                map[m + i][n - 1 + j] = 1;
    cout << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}