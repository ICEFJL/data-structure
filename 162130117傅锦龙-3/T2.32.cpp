#include <iostream>
using namespace std;

struct LNode {
    LNode *pre;
    LNode *next;
    int data;
};

void ChangeList(LNode *head)
{
    LNode *p = head, *q = head->next;
    while (q != head) {
        q->pre = p;
        p = q;
        q = q->next;
    }
    q->pre = p;
}

int main()
{
    LNode *head = new LNode, *p;
    head->next = head;
    head->data = rand() % 100;
    cout << "ÕıĞò±éÀú: "<< head->data << " ";

    for (int i = 0; i < rand() % 10 + 5; i++) {
        p = new LNode;
        p->data = rand() % 100;
        p->next = head->next;
        head->next = p;
    }
    p = head->next;
    while (p != head) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;

    ChangeList(head);

    cout << "µ¹Ğò±éÀú: ";
    p = head->pre;
    while (p != head) {
        cout << p->data << ' ';
        p = p->pre;
    }
    cout << p->data << endl;

    return 0;
}