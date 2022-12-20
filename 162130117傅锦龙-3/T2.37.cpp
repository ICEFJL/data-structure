#include <iostream>
using namespace std;

struct LNode {
    int data;
    LNode *pre;
    LNode *next;
};

void ListTrave(LNode *head)
{
    LNode *temp = head->next;
    cout << "表中元素为： ";
    while (temp != head) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

void ChangeList(LNode *head)
{
    int i = 1;
    LNode *p, *q, *r;
    p = head->next;
    r = head->pre;
    while (p != r) {
        if (i % 2 == 0) {
            q = p;
            p = p->next;
            q->pre->next = q->next;
            q->next->pre = q->pre;
            q->pre = r;
            r->next->pre = q;
            q->next = r->next;
            r->next = q;
        } else
            p = p->next;
        i++;
    }
}

int main()
{
    LNode *head = new LNode, *p = head;
    p->next = p;
    p->pre = NULL;
    srand((unsigned int)time(0));

    for (int i = 0; i < rand() % 10 + 5; i++) {
        p->next = new LNode;
        p->next->pre = p;
        p = p->next;
        p->data = rand() % 100;
    }
    p->next = head;
    head->pre = p;
    ListTrave(head);
    ChangeList(head);
    ListTrave(head);
}