#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node {
    int id;
    int pos;
    int st;
} Node;

int main()
{
    int n, l, t;
    cin >> n >> l >> t;
    Node *a = new Node[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].pos;
        a[i].id = i;
        if (a[i].pos == l)
            a[i].st = -1;
        else
            a[i].st = 1;
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j].pos > a[j + 1].pos) {
                swap(a[j], a[j + 1]);
            }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            a[j].pos += a[j].st;
            if (a[j].pos == 0 || a[j].pos == l) {
                a[j].st = -a[j].st;
            }
        }
        for (int j = 1; j < n; j++)
            if (a[j].pos == a[j - 1].pos) {
                a[j].st = -a[j].st;
                a[j - 1].st = -a[j - 1].st;
            }
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j].id > a[j + 1].id) {
                swap(a[j], a[j + 1]);
            }
    for (int i = 0; i < n; i++)
        cout << a[i].pos << " ";
}