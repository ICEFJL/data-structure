#include <iostream>
using namespace std;

typedef struct QNode {
    int data;
    QNode *next;
} QNode;

typedef struct {
    QNode *rear;
    int size;
} Queue;

void InitQueue(Queue &q)
{
    q.rear = NULL;
    q.size = 0;
}

void Traverse(Queue q)
{
    if (!q.rear) {
        cout << "队列为空" << endl;
    } else {
        cout << "队列如下：" << endl;
        QNode *p = q.rear->next;
        while (p != q.rear) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data << endl << endl;
    }
}

void EnQueue(Queue &q, int e)
{
    QNode *p;
    p = new QNode;
    p->data = e;
    if (!q.rear) {
        q.rear = p;
        p->next = q.rear;
    } else {
        p->next = q.rear->next;
        q.rear->next = p;
        q.rear = p;
    }
    q.size++;
}

void DeQueue(Queue &q, int &e)
{
    QNode *p;
    if (q.size == 0) {
        cout << "队列为空，出队失败" << endl;
        return;
    }
    if (q.size == 1) {
        p = q.rear;
        e = p->data;
        q.rear = NULL;
        delete p;
    } else {
        p = q.rear->next;
        e = p->data;
        q.rear->next = p->next;
        delete p;
    }
    q.size--;
}

int main()
{
    Queue q;
    InitQueue(q);
    int e;
    for (int i = 0; i < rand() % 10 + 5; i++) {
        e = rand() % 10;
        EnQueue(q, e);
        cout << "入队" << e << endl;
    }
    Traverse(q);
    for (int i = 0; i < rand() % 10 + 2; i++) {
        DeQueue(q, e);
        cout << "出队" << e << endl;
    }
    Traverse(q);
}