#include <iostream>
using namespace std;

#define STACKINITSIZE 256
#define STACKINCREMENT 128

typedef struct SeqStack {
    int *pBase;
    int *pTop;
    int stacksize;
} SeqStack;

class ADT_Stack
{
  private:
    SeqStack *S;

  public:
    void InitStack()
    {
        S = new SeqStack;
        S->pBase = new int[STACKINITSIZE];
        S->pTop = S->pBase;
        S->stacksize = STACKINITSIZE;
    }

    void DestroyStack()
    {
        if (S != NULL) {
            delete S->pBase;
            delete S;
        }
        S = NULL;
    }

    void ClearStack()
    {
        if (S != NULL) {
            S->pTop = S->pBase;
        }
        cout << "��ճɹ�" << endl;
    }

    bool StackEmpty()
    {
        if (S != NULL) {
            return S->pTop == S->pBase;
        }
        return true;
    }

    int StackLength()
    {
        if (S != NULL) {
            return S->pTop - S->pBase;
        }
        cout << "ջ������" << endl;
        return 0;
    }

    bool GetTop(int &e)
    {
        if (S != NULL && S->pBase != S->pTop) {
            e = *(S->pTop - 1);
            return true;
        }
        return false;
    }

    void StackTraverse()
    {
        if (S != NULL) {
            cout << "��ջ�׵�ջ��������Ԫ�أ�";
            for (int *p = S->pBase; p != S->pTop; p++)
                cout << *p << "  ";
            cout << endl;
            return;
        }
        cout << "ջ������" << endl;
    }

    void Push(int e)
    {
        if (S != NULL) {
            if (S->pTop - S->pBase >= S->stacksize) {
                S->pBase = (int *)realloc(S->pBase, (S->stacksize + STACKINCREMENT) * sizeof(int));
                S->pTop = S->pBase + S->stacksize;
                S->stacksize += STACKINCREMENT;
            }
            *S->pTop = e;
            S->pTop++;
            cout << "Ԫ�� " << e << " ѹջ�ɹ�" << endl;
            return;
        }
        cout << "ѹջʧ��" << endl;
    }

    void Pop(int &e)
    {
        if (S != NULL && S->pBase != S->pTop) {
            e = *(S->pTop - 1);
            S->pTop--;
            cout << "��ջ�ɹ�" << endl;
            return;
        }
        cout << "��ջʧ��" << endl;
    }
};

int main()
{
    ADT_Stack seqstack;
    int e;
    cout << "��ʼ����InitStack()��" << endl;
    seqstack.InitStack();
    seqstack.StackTraverse();
    cout << endl;

    cout << "��ʼ����Push()" << endl;
    for (int i = 0; i < rand() % 10 + 5; i++) {
        seqstack.Push(rand() % 100);
    }
    seqstack.StackTraverse();
    cout << endl;

    cout << "��ʼ����StackLength()" << endl;
    cout << "˳��ջ�ĳ��ȣ�" << seqstack.StackLength() << endl << endl;

    cout << "��ʼ����GetTop()" << endl;
    if (seqstack.GetTop(e))
        cout << "ջ��Ԫ�أ�" << e << endl << endl;

    cout << "��ʼ����Pop()" << endl;
    seqstack.Pop(e);
    seqstack.StackTraverse();
    seqstack.Pop(e);
    seqstack.StackTraverse();
    cout << endl;

    cout << "��ʼ����StackEmpty()" << endl;
    if (seqstack.StackEmpty())
        cout << "ջΪ��" << endl << endl;
    else
        cout << "ջ��Ϊ��" << endl << endl;

    cout << "��ʼ����ClearStack()" << endl;
    seqstack.ClearStack();
    seqstack.StackTraverse();
    cout << endl;

    cout << "��ʼ����DestroyStack()" << endl;
    seqstack.DestroyStack();
    seqstack.StackTraverse();
}