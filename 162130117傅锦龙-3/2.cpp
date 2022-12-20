#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;
typedef struct LinkQueue {
    LNode *front;
    LNode *rear;
    int len;
} LinkQueue;

class ADT_Queue
{
  private:
    LinkQueue *L;

  public:
    void InitQueue()
    {
        L = new LinkQueue;
        L->front = L->rear = new LNode;
        L->front->next = NULL;
        L->len = 0;
    }

    void DestroyQueue()
    {
        if (L != NULL) {
            while (L->front != NULL) {
                LNode *temp = L->front;
                L->front = L->front->next;
                delete temp;
            }
            delete L;
            L = NULL;
        }
    }

    void ClearQueue()
    {
        if (L != NULL) {
            LNode *p = L->front;
            while (p != L->rear) {
                LNode *temp = p;
                p = p->next;
                delete temp;
            }
            L->front = L->rear;
            L->len = 0;
        }
    }

    bool QueueEmpty()
    {
        if (L != NULL) {
            return L->len == 0;
        }
        return true;
    }

    int QueueLength()
    {
        if (L != NULL) {
            return L->len;
        }
        return 0;
    }

    bool GetHead(int &e)
    {
        if (L != NULL && L->len != 0) {
            e = L->front->data;
            return true;
        }
        return false;
    }

    void QueueTraverse()
    {
        if (L != NULL) {
            if (L->len == 0) {
                cout << "队列为空" << endl;
                return;
            }
            cout << "队列元素为：" << endl;
            for (LNode *p = L->front; p != L->rear; p = p->next)
                cout << p->data << "  ";
            cout << endl;
            return;
        }
        cout << "队列不存在" << endl;
    }

    void EnQueue(int e)
    {
        if (L != NULL) {
            L->rear->data = e;
            L->rear->next = new LNode;
            L->rear = L->rear->next;
            L->rear->next = NULL;
            cout << "元素 " << e << " 入队成功" << endl;
            L->len++;
            return;
        }
        cout << "入队失败" << endl;
    }

    void DeQueue(int &e)
    {
        if (L != NULL && L->len != 0) {
            LNode *p = L->front;
            e = p->data;
            L->front = p->next;
            delete p;
            cout << "出队成功" << endl;
            L->len--;
            return;
        }
        cout << "出队失败" << endl;
    }
};

int main()
{
    ADT_Queue linkque;
    int e;

    cout << "开始测试InitQueue()" << endl;
    linkque.InitQueue();
    linkque.QueueTraverse();
    cout << endl;

    cout << endl << "开始测试EnQueue()" << endl;
    for (int i = 0; i < rand() % 10 + 5; i++) {
        linkque.EnQueue(rand() % 100);
    }
    linkque.QueueTraverse();
    cout << endl << endl;

    cout << "开始测试QueueEmpty()" << endl;
    if (linkque.QueueEmpty())
        cout << "队列为空" << endl << endl;
    else
        cout << "队列不为空" << endl << endl;

    cout << "开始测试QueueLength()" << endl;
    cout << "队列长度：" << linkque.QueueLength() << endl << endl;

    cout << "开始测试GetHead()" << endl;
    if (linkque.GetHead(e))
        cout << "队列头部元素：" << e << endl << endl;

    cout << "开始测试DeQueue()" << endl;
    linkque.DeQueue(e);
    linkque.QueueTraverse();
    cout << endl;

    cout << "开始测试ClearQueue()" << endl;
    linkque.ClearQueue();
    linkque.QueueTraverse();
    cout << endl;

    cout << "开始测试DestroyQueue()" << endl;
    linkque.DestroyQueue();
    linkque.QueueTraverse();
}