#include <iostream>
#include <cstdlib>
using namespace std;

#define LISTINITSIZE 256
#define LISTINCREMENT 128

typedef struct SeqList {
    int *pData;
    int length;
    int size;
} SeqList;

class ADT_SeqList
{
  private:
    SeqList *L;

  public:
    void InitList()
    {
        L = new SeqList;
        L->pData = new int[LISTINITSIZE];
        L->size = LISTINITSIZE;
        L->length = 0;
    }

    void DestroyList()
    {
        if (L != NULL) {
            delete L->pData;
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
        for (int i = 0; i < L->length; i++) {
            cout << L->pData[i] << " ";
        }
        cout << endl;
    }

    int InsertElem(int i, int e)
    {
        if (!L || i < 1 || i > L->length + 1)
            return 0;
        if (L->length >= L->size) {
            int *newbase = new int[L->length + LISTINCREMENT];
            for (int j = 0; j < L->length; j++) {
                newbase[j] = L->pData[j];
            }
            delete L->pData;
            L->pData = newbase;
            L->size += LISTINCREMENT;
        }
        for (int j = L->length - 1; j >= i - 1; j--)
            L->pData[j + 1] = L->pData[j];
        L->pData[i - 1] = e;
        L->length += 1;
        return 1;
    }

    void ReverseSeqList()
    {
        for (int i = 0, j = L->length - 1; i < j; i++, j--) {
            int t = L->pData[i];
            L->pData[i] = L->pData[j];
            L->pData[j] = t;
        }
    }
};

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

    void ReverseSListInfo()
    {
        LNode *c;
        LNode *r = L->head->next;
        L->head->next = NULL;
        while (r) {
            c = r;
            r = r->next;
            c->next = L->head->next;
            L->head->next = c;
        }
    }
};

int main()
{
    ADT_SeqList seqlist;
    ADT_SListInfo slistinfo;
    seqlist.InitList();
    for (int i = 1; i < 12; i++) {
        seqlist.InsertElem(i, rand()%100);
    }
    seqlist.ListTraverse();
    seqlist.ReverseSeqList();
    seqlist.ListTraverse();
    seqlist.DestroyList();

    slistinfo.InitList();
    for (int i = 1; i < 12; i++) {
        slistinfo.InsertElem(i, rand()%100);
    }
    slistinfo.ListTraverse();
    slistinfo.ReverseSListInfo();
    slistinfo.ListTraverse();
    slistinfo.DestroyList();
    return 0;
}