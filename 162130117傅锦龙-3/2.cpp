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
                cout << "����Ϊ��" << endl;
                return;
            }
            cout << "����Ԫ��Ϊ��" << endl;
            for (LNode *p = L->front; p != L->rear; p = p->next)
                cout << p->data << "  ";
            cout << endl;
            return;
        }
        cout << "���в�����" << endl;
    }

    void EnQueue(int e)
    {
        if (L != NULL) {
            L->rear->data = e;
            L->rear->next = new LNode;
            L->rear = L->rear->next;
            L->rear->next = NULL;
            cout << "Ԫ�� " << e << " ��ӳɹ�" << endl;
            L->len++;
            return;
        }
        cout << "���ʧ��" << endl;
    }

    void DeQueue(int &e)
    {
        if (L != NULL && L->len != 0) {
            LNode *p = L->front;
            e = p->data;
            L->front = p->next;
            delete p;
            cout << "���ӳɹ�" << endl;
            L->len--;
            return;
        }
        cout << "����ʧ��" << endl;
    }
};

int main()
{
    ADT_Queue linkque;
    int e;

    cout << "��ʼ����InitQueue()" << endl;
    linkque.InitQueue();
    linkque.QueueTraverse();
    cout << endl;

    cout << endl << "��ʼ����EnQueue()" << endl;
    for (int i = 0; i < rand() % 10 + 5; i++) {
        linkque.EnQueue(rand() % 100);
    }
    linkque.QueueTraverse();
    cout << endl << endl;

    cout << "��ʼ����QueueEmpty()" << endl;
    if (linkque.QueueEmpty())
        cout << "����Ϊ��" << endl << endl;
    else
        cout << "���в�Ϊ��" << endl << endl;

    cout << "��ʼ����QueueLength()" << endl;
    cout << "���г��ȣ�" << linkque.QueueLength() << endl << endl;

    cout << "��ʼ����GetHead()" << endl;
    if (linkque.GetHead(e))
        cout << "����ͷ��Ԫ�أ�" << e << endl << endl;

    cout << "��ʼ����DeQueue()" << endl;
    linkque.DeQueue(e);
    linkque.QueueTraverse();
    cout << endl;

    cout << "��ʼ����ClearQueue()" << endl;
    linkque.ClearQueue();
    linkque.QueueTraverse();
    cout << endl;

    cout << "��ʼ����DestroyQueue()" << endl;
    linkque.DestroyQueue();
    linkque.QueueTraverse();
}