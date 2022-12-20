#include <iostream>
#include <stack>
using namespace std;
struct pos {
    int x, y;
};

int dp[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void FillColor(int m[6][6], int x, int y, int color)
{
    stack<pos> s;
    int oldcolor = m[x][y];
    if (color == oldcolor)
        return;
    s.push({x, y});
    while (!s.empty()) {
        pos t = s.top();
        s.pop();
        m[t.x][t.y] = color;
        for (int i = 0; i < 4; i++) {
            int x = t.x + dp[i][0];
            int y = t.y + dp[i][1];
            if (x >= 0 && x < 6 && y >= 0 && y < 6 && m[x][y] == oldcolor)
                s.push({x, y});
        }
    }
}

void Traverse(int m[6][6])
{
    cout << "¾ØÕóÈçÏÂ£º" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int m[6][6];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            m[i][j] = rand()%5;
    Traverse(m);
    FillColor(m, 3, 2, 2);
    Traverse(m);
    return 0;
}