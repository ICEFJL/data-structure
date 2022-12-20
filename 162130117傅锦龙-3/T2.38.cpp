#include <iostream>
using namespace std;

struct LNode {
    int data;
    int freq;
    LNode *pre;
    LNode *next;
};

void ListTrave(LNode *head)
{
    LNode *temp = head->next;
    cout << "表中元素及频率为： ";
    while (temp != head) {
        cout << "(" << temp->data << "," << temp->freq << ")  ";
        temp = temp->next;
    }
    cout << endl << endl;
}

void ListLocate(LNode *head, int e)
{
    LNode *p, *q;
    p = head->next;
    while (p != head && p->data != e)
        p = p->next;
    if (p == head) {
        cout << "不存在该数" << endl;
        return;
    } else {
        cout << "访问元素为" << e << "的节点" << endl;
        p->freq++;
        p->pre->next = p->next;
        p->next->pre = p->pre;
        q = head;
        while (q->next != head && q->next->freq > p->freq)
            q = q->next;
        p->next = q->next;
        p->pre = q;
        q->next->pre = p;
        q->next = p;
    }
}

int main()
{
    LNode *head = new LNode, *p = head;
    p->next = p;
    p->pre = NULL;
    int len = rand() % 10 + 5;

    for (int i = 0; i < len; i++) {
        p->next = new LNode;
        p->next->pre = p;
        p = p->next;
        p->data = i;
        p->freq = 0;
    }
    p->next = head;
    head->pre = p;

    ListTrave(head);
    for (int i = 0; i < len; i++) {
        ListLocate(head, rand() % len);
        ListTrave(head);
    }
}