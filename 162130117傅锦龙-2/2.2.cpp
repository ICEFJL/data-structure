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
        cout << "线性表长度为" << L->length << " 各元素为：  ";
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

    void RemoveDupSListInfo()
    {
        if (L->length == 0 || L->length == 1)
            return;
        LNode *p = L->head->next;
        int len = 0;
        while (p) {
            len++;
            LNode *pre = p;
            LNode *curr = p;
            int t = p->data;
            while (curr) {
                curr = curr->next;
                while (curr && curr->data == t) {
                    pre->next = curr->next;
                    delete curr;
                    curr = pre->next;
                }
                pre = curr;
            }
            p = p->next;
        }
        L->length = len;
    }

    void SortSListInfo()
    {
        if (L->length == 0 || L->length == 1)
            return;
        LNode *p = L->head->next;
        LNode *curr = p->next;
        while (curr != NULL) {
            if (p->data >= curr->data) {
                p = p->next;
            } else {
                LNode *prev = L->head;
                while (prev->next->data >= curr->data) {
                    prev = prev->next;
                }
                p->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = p->next;
        }
    }

    void MergeSListInfo(const ADT_SListInfo &L2)
    {
        LNode *p1 = L->head, *p2 = L2.L->head->next;
        int e1 = 0, e2 = 0;
        while (p1->next && p2) {
            e1 = p1->next->data;
            e2 = p2->data;
            if (e1 == e2)
                p2 = p2->next;
            else if (e1 > e2)
                p1 = p1->next;
            else if (e1 < e2) {
                LNode *p = new LNode;
                p->data = e2;
                p->next = p1->next;
                p1->next = p;
                p2 = p2->next;
                p1 = p1->next;
            }
        }
        while (p2) {
            LNode *p = new LNode;
            p->data = e2;
            p->next = p1->next;
            p1->next = p;
            p2 = p2->next;
            p1 = p1->next;
        }
    }
};

int main()
{
    ADT_SListInfo slistinfo[2];
    srand((unsigned int)time(0));
    for (int j = 0; j < 2; j++) {
        slistinfo[j].InitList();
        for (int i = 1; i < rand() % 10 + 5; i++) {
            slistinfo[j].InsertElem(i, rand() % 100);
        }
        slistinfo[j].SortSListInfo();
        slistinfo[j].ListTraverse();
    }
    slistinfo[0].MergeSListInfo(slistinfo[1]);
    slistinfo[0].RemoveDupSListInfo();
    slistinfo[0].ListTraverse();
    return 0;
}