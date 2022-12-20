#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 256

typedef struct {
    int i, j;
    int v;
} Triple;

typedef struct {
    Triple arr[MAXSIZE];
    int Rows, Cols, Nums;
} SqSMatrix;

void CreateSqSMatrix(SqSMatrix &m, int r, int c, int n)
{
    m.Rows = r;
    m.Cols = c;
    m.Nums = n;
}

void Traverse(SqSMatrix m)
{
    int count = 0;
    for (int i = 0; i < m.Rows; i++) {
        for (int j = 0; j < m.Cols; j++) {
            if (m.arr[count].i == i && m.arr[count].j == j) {
                cout << m.arr[count].v << ' ';
                count++;
            } else
                cout << 0 << ' ';
        }
        cout << endl;
    }
}

void TransposeSMatrix(SqSMatrix A, SqSMatrix &B)
{
    B.Rows = A.Cols;
    B.Cols = A.Rows;
    B.Nums = A.Nums;
    if (A.Nums > 0) {
        int q = 0;
        for (int k = 0; k < A.Cols; k++)
            for (int p = 0; p < A.Nums; p++)
                if (A.arr[p].j == k) {
                    B.arr[q].i = A.arr[p].j;
                    B.arr[q].j = A.arr[p].i;
                    B.arr[q].v = A.arr[p].v;
                    q++;
                }
    }
}

void FastTransposeSMatrix(SqSMatrix A, SqSMatrix &B)
{
    B.Rows = A.Cols;
    B.Cols = A.Rows;
    B.Nums = A.Nums;
    if (A.Nums > 0) {
        int *rowNum = new int[A.Cols]{0};
        int *rowStart = new int[A.Cols]{0};
        for (int p = 0; p < A.Nums; p++)
            rowNum[A.arr[p].j]++;
        for (int k = 1; k < A.Cols; k++)
            rowStart[k] = rowStart[k - 1] + rowNum[k - 1];
        for (int p = 0; p < A.Nums; p++) {
            int q = rowStart[A.arr[p].j];
            B.arr[q].i = A.arr[p].j;
            B.arr[q].j = A.arr[p].i;
            B.arr[q].v = A.arr[p].v;
            rowStart[A.arr[p].j]++;
        }
    }
}

int main()
{
    SqSMatrix A, B, C;

    int n = rand() % 10 + 5;
    CreateSqSMatrix(A, 5, 6, n);
    for (int i = 0; i < n; i++) {
        A.arr[i].i = rand() % 5;
        A.arr[i].j = rand() % 6;
        A.arr[i].v = rand() % 10;
    }
    sort(A.arr, A.arr + n, [](Triple a, Triple b) { return a.i < b.i || (a.i == b.i && a.j < b.j); });
    Traverse(A);

    cout << endl << "列序遍历转置法" << endl;
    TransposeSMatrix(A, B);
    cout << "矩阵如下：" << endl;
    Traverse(B);

    cout << endl << "快速转置法" << endl;
    FastTransposeSMatrix(A, C);
    cout << "矩阵如下：" << endl;
    Traverse(C);
}