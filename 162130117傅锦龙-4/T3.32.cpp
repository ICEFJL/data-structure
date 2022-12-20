#include <iostream>
using namespace std;

typedef struct {
    int *base;
    int front;
    int rear;
    int k;
    int size;
} Queue;

void InitQueue(Queue &Q, int k)
{
    Q.k = k;
    Q.base = new int[k];
    Q.front = Q.rear = 0;
    Q.size = 0;
}

void EnQueue(Queue &Q, int e)
{
    if (Q.size == Q.k) {
        return;
    } else {
        Q.base[Q.rear] = e;
        Q.rear = (Q.rear + 1) % Q.k;
        cout << e << " ";
        Q.size++;
    }
}

void DeQueue(Queue &Q, int &e)
{
    if (Q.size == 0) {
        return;
    } else {
        e = Q.base[Q.front];
        Q.front = (Q.front + 1) % Q.k;
        Q.size--;
    }
}

void Fibonacci(Queue &Q, int k, int max)
{
    int e = 1, num = 0;
    for (int i = 0; i < k; i++) {
        if (i == k - 1)
            EnQueue(Q, 1);
        else
            EnQueue(Q, 0);
    }
    while (1) {
        num = 2 * Q.base[(Q.rear + Q.k - 1) % Q.k] - e;
        if (num > max)
            break;
        DeQueue(Q, e);
        EnQueue(Q, num);
    }
}

int main()
{
    Queue Q;
    int k, max;
    cout << "ÊäÈëkºÍmax:";
    cin >> k >> max;
    InitQueue(Q, k);
    Fibonacci(Q, k, max);
}