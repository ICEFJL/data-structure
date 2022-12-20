#include <iostream>

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
    char name;

  public:
    void InitList(char t)
    {
        L = new SListInfo;
        L->head = new LNode;
        if (L->head == NULL)
            exit(0);
        L->head->next = NULL;
        L->length = 0;
        name =t;
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
        cout << name << "线性表长度为：" << L->length << "  线性表各元素为：  ";
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

    void HeadInsert(ADT_SListInfo &s, LNode *&p)
    {
        s.L->head->next = p->next;
        p->next = L->head->next;
        L->head->next = p;
        p = s.L->head->next;
        L->length++;
        s.L->length--;
    }

    void MergeSListInfo(ADT_SListInfo s[2])
    {
        LNode *p[2];
        int e[2];
        p[0] = s[0].L->head->next;
        p[1] = s[1].L->head->next;
        while (p[0] && p[1]) {
            e[0] = p[0]->data;
            e[1] = p[1]->data;
            if (e[0] > e[1]) {
                HeadInsert(s[1], p[1]);
            } else if (e[0] < e[1]) {
                HeadInsert(s[0], p[0]);
            } else {
                HeadInsert(s[0], p[0]);
                HeadInsert(s[1], p[1]);
            }
        }
        for (int i = 0; i < 2; i++) {
            while (p[i]) {
                HeadInsert(s[i], p[i]);
            }
        }
    }
};

int main()
{
    ADT_SListInfo slistinfo[2], s;
    srand((unsigned int)time(0));
    for (int j = 0; j < 2; j++) {
        slistinfo[j].InitList('A'+j);
        for (int i = 1; i < rand() % 10 + 5; i++) {
            slistinfo[j].InsertElem(i, rand() % 100);
        }
        slistinfo[j].SortSListInfo();
        slistinfo[j].ListTraverse();
    }
    s.InitList('C');
    s.MergeSListInfo(slistinfo);
    s.ListTraverse();
    s.DestroyList();
    for (int i = 0; i < 2; i++){
        slistinfo[i].DestroyList();
    }
    return 0;
}