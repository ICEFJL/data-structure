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
        name = t;
    }

    void ListTraverse()
    {
        if (!L || L->length == 0)
            return;
        cout << name << "线性表长度为：" << L->length << "  线性表各元素为：  ";
        for (LNode *p = L->head->next; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl << endl;
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

    void DeleteDup(ADT_SListInfo s[3])
    {
        LNode *p[3];
        for (int i = 1; i < 3; i++)
            p[i] = s[i].L->head->next;
        p[0] = L->head;
        while (p[1] && p[2]) {
            if (p[1]->data == p[2]->data) {
                while (p[0]->next && p[0]->next->data <= p[1]->data) {
                    if (p[0]->next->data == p[1]->data) {
                        LNode *t = p[0]->next;
                        p[0]->next = t->next;
                        delete t;
                        L->length--;
                    } else
                        p[0] = p[0]->next;
                }
                p[1] = p[1]->next;
                p[2] = p[2]->next;
            } else if (p[1]->data > p[2]->data)
                p[2] = p[2]->next;
            else
                p[1] = p[1]->next;
        }
    }
};
int main()
{
    ADT_SListInfo slistinfo[3];
    srand((unsigned int)time(0));
    for (int j = 0; j < 3; j++) {
        slistinfo[j].InitList('A' + j);
        for (int i = 1; i < rand() % 10 + 5; i++) {
            slistinfo[j].InsertElem(i, rand() % 10);
        }
        slistinfo[j].SortSListInfo();
        slistinfo[j].ListTraverse();
    }
    slistinfo[0].DeleteDup(slistinfo);
    for (int j = 0; j < 3; j++)
        slistinfo[j].ListTraverse();
    return 0;
}