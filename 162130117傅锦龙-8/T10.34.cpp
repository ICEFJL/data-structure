#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define N 10

void Display(int *Rand)
{
    for (int i = 0; i < N; i++) {
        cout << Rand[i] << ' ';
    }
    cout << endl << endl;
}

void CreateRandom(int *Rand)
{
    for (int i = 0; i < N; i++) {
        Rand[i] = rand() % 100;
    }
    Display(Rand);
}

void Build_Heap(int *Rand)
{
    for (int i = 1; i < N; i++) {
        int j = i;
        while (j) {
            int k = (j - 1) / 2;
            if (Rand[k] < Rand[j])
                swap(Rand[k], Rand[j]);
            j = k;
        }
    }
}

void fill(int *Rand, int depth, int begin, int end, int index, vector<vector<string>> &res)
{
    if (index >= N)
        return;
    int mid = begin + (end - begin) / 2;
    res[depth][mid] = to_string(Rand[index]);
    fill(Rand, depth + 1, begin, mid - 1, 2 * index + 1, res);
    fill(Rand, depth + 1, mid + 1, end, 2 * index + 2, res);
}

void Traverse(int *Rand)
{
    vector<vector<string>> res;
    int m = 1;
    int x = N;
    while (x != 0) {
        x /= 2;
        m++;
    }
    int n = pow(2, m) - 1;
    for (int i = 0; i < m; ++i) {
        vector<string> temp;
        for (int i = 0; i < n; ++i) {
            temp.push_back(" ");
        }
        res.push_back(temp);
    }
    fill(Rand, 0, 0, n - 1, 0, res);
    for (auto &t : res) {
        for (auto &s : t)
            cout << s;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int *Rand = new int[N];
    srand((int)time(0));
    cout << "¹¹½¨´ó¶¥¶Ñ" << endl;
    CreateRandom(Rand);
    Build_Heap(Rand);
    Traverse(Rand);
}