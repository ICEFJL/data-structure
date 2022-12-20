#include <iostream>
#include <algorithm>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct SListInfo {
    LNode *head;
    int length;
} SListInfo;

class ADT_SListInfo
{
  private:
    SListInfo *L;

  public:
    void InitList()
    {
        L = new SListInfo;
        L->head = new LNode;
        if (L->head == NULL)
            exit(0);
        L->head->next = NULL;
        L->length = 0;
    }

    void DestroyList()
    {
        if (L) {
            while (L->head->next != NULL) {
                LNode *p = L->head->next;
                L->head->next = p->next;
                delete p;
            }
            delete L->head;
            L = NULL;
            cout << "消除成功" << endl;
            return;
        }
        cout << "消除失败" << endl;
    }

    void ListTraverse()
    {
        if (!L || L->length == 0)
            return;
        cout << "线性表各元素为：  ";
        for (LNode *p = L->head->next; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }

    int InsertElem(int i, int e)
    {
        if (!L || i < 1 || i > L->length + 1)
            return 0;
        LNode *pre = L->head;
        while (--i > 0) {
            pre = pre->next;
        }
        LNode *s = new LNode;
        if (s == NULL)
            exit(0);
        s->data = e;
        s->next = pre->next;
        pre->next = s;
        L->length += 1;
        return 1;
    }

    void SortSListInfo()
    {
        if (L->length == 0 || L->length == 1)
            return;
        LNode *p = L->head->next;
        LNode *curr = p->next;
        while (curr != NULL) {
            if (p->data <= curr->data) {
                p = p->next;
            } else {
                LNode *prev = L->head;
                while (prev->next->data <= curr->data) {
                    prev = prev->next;
                }
                p->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = p->next;
        }
    }
};

int main()
{
    ADT_SListInfo slistinfo;

    slistinfo.InitList();
    for (int i = 1; i < 12; i++) {
        slistinfo.InsertElem(i, rand() % 100);
    }
    slistinfo.ListTraverse();
    slistinfo.SortSListInfo();
    slistinfo.ListTraverse();
    slistinfo.DestroyList();
    
    return 0;
}