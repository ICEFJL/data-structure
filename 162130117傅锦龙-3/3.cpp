#include <iostream>
#include <stack>
using namespace std;

typedef struct Point {
    int row;
    int col;
} Point;

bool JudgeQueenConfiction(Point curQueen, stack<Point> StkQueen)
{
    int x, y;
    Point temp;

    while (StkQueen.size()) {
        temp = StkQueen.top();
        StkQueen.pop();
        x = temp.row;
        y = temp.col;
        if (abs(x - curQueen.row) == abs(y - curQueen.col))
            return false;
        if ((x == curQueen.row) || (y == curQueen.col))
            return false;
    }

    return true;
}

void OutputResult(stack<Point> StkQueen, int N)
{
    Point temp;

    for (int i = 1; i <= N; i++) {
        temp = StkQueen.top();
        StkQueen.pop();
        cout << "(" << temp.row << ", " << temp.col << ") " << endl;
    }
    cout << endl;
}

void PlaceQueen(int N)
{
    stack<Point> StkQueen;
    Point curQueen;
    bool ret;

    int resultCount = 0;
    curQueen.col = curQueen.row = 1;
    StkQueen.emplace(curQueen);

    curQueen.row = 2;
    curQueen.col = 1;

    while (curQueen.row <= N && curQueen.col <= N) {
        while (curQueen.col <= N) {
            ret = JudgeQueenConfiction(curQueen, StkQueen);
            if (ret) {
                break;
            }
            curQueen.col += 1;
        }

        if (ret) {
            StkQueen.emplace(curQueen);
            curQueen.row += 1;
            curQueen.col = 1;

            if (curQueen.row > N) {
                OutputResult(StkQueen, N);
                resultCount++;

                curQueen = StkQueen.top();
                StkQueen.pop();
                curQueen.col += 1;

                while (curQueen.col > N && !StkQueen.empty()) {
                    curQueen = StkQueen.top();
                    StkQueen.pop();
                    curQueen.col += 1;
                }
            }
        }

        else {
            curQueen = StkQueen.top();
            StkQueen.pop();
            curQueen.col += 1;

            while (curQueen.col > N && !StkQueen.empty()) {
                curQueen = StkQueen.top();
                StkQueen.pop();
                curQueen.col += 1;
            }
        }
    }
    cout << "符合条件的解的总个数：" << resultCount << endl;
}

int main()
{
    PlaceQueen(8);
    return 0;
}