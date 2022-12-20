#include <iostream>
#include <algorithm>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

int main()
{
    int n = 0, m = 0;
    cout << "请输入人数n:" << endl;
    cin >> n;
    cout << "请输入m:" << endl;
    cin >> m;
    LNode *head = new LNode, *p = head, *prev;
    head->next = head;
    for (int i = 1; i <= n; i++) {
        p = p->next;
        p->data = i;
        p->next = new LNode;
    }
    delete p->next;
    p->next = head;
    prev = p;
    p = head;

    while (p->next != p) {
        for (int i = 1; i < m; i++) {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        cout << p->data << " ";
        delete p;
        p = prev->next;
    }
    cout << p->data << " ";
    delete p;

    return 0;
}