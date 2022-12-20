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
        cout << "清空成功" << endl;
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
        cout << "栈不存在" << endl;
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
            cout << "从栈底到栈顶的所有元素：";
            for (int *p = S->pBase; p != S->pTop; p++)
                cout << *p << "  ";
            cout << endl;
            return;
        }
        cout << "栈不存在" << endl;
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
            cout << "元素 " << e << " 压栈成功" << endl;
            return;
        }
        cout << "压栈失败" << endl;
    }

    void Pop(int &e)
    {
        if (S != NULL && S->pBase != S->pTop) {
            e = *(S->pTop - 1);
            S->pTop--;
            cout << "弹栈成功" << endl;
            return;
        }
        cout << "弹栈失败" << endl;
    }
};

int main()
{
    ADT_Stack seqstack;
    int e;
    cout << "开始测试InitStack()：" << endl;
    seqstack.InitStack();
    seqstack.StackTraverse();
    cout << endl;

    cout << "开始测试Push()" << endl;
    for (int i = 0; i < rand() % 10 + 5; i++) {
        seqstack.Push(rand() % 100);
    }
    seqstack.StackTraverse();
    cout << endl;

    cout << "开始测试StackLength()" << endl;
    cout << "顺序栈的长度：" << seqstack.StackLength() << endl << endl;

    cout << "开始测试GetTop()" << endl;
    if (seqstack.GetTop(e))
        cout << "栈顶元素：" << e << endl << endl;

    cout << "开始测试Pop()" << endl;
    seqstack.Pop(e);
    seqstack.StackTraverse();
    seqstack.Pop(e);
    seqstack.StackTraverse();
    cout << endl;

    cout << "开始测试StackEmpty()" << endl;
    if (seqstack.StackEmpty())
        cout << "栈为空" << endl << endl;
    else
        cout << "栈不为空" << endl << endl;

    cout << "开始测试ClearStack()" << endl;
    seqstack.ClearStack();
    seqstack.StackTraverse();
    cout << endl;

    cout << "开始测试DestroyStack()" << endl;
    seqstack.DestroyStack();
    seqstack.StackTraverse();
}