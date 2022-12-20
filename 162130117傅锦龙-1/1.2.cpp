#include <iostream>
#include <cstdlib>
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
                LNode* p = L->head->next;
                L->head->next = p->next;
                delete p;
            }
            delete L->head;
            L = NULL;
            cout << "�����ɹ�" << endl;
            return;
        }
        cout << "����ʧ��" << endl;
    }

    void ClearList()
    {
        if (L) {
            while (L->head->next != NULL) {
                LNode *p = L->head->next;
                L->head->next = p->next;
                delete p;
            }
            L->length = 0;
            cout << "��ճɹ�" << endl;
            return;
        }
        cout << "���ʧ��" << endl;
    }

    int ListEmpty()
    {
        if (L != NULL) {
            if (L->length == 0)
                return true;
        }
        return false;
    }

    int ListLength()
    {
        if (L != NULL) {
            return L->length;
        }
        return 0;
    }

    int GetElem(int i, int &e)
    {
        if (!L || i < 1 || i > L->length)
            return 0;
        LNode *p = L->head;
        for (int j = 0; j < i; j++)
            p = p->next;
        e = p->data;
        return 1;
    }

    int LocateElem(int e)
    {
        if (!L)
            return 0;
        int i = 1;
        for (LNode *p = L->head->next; p; p = p->next, i++) {
            if (p->data == e)
                return i;
        }
        return 0;
    }

    int PriorElem(int cur_e, int &pre_e)
    {
        if (!L)
            return 0;
        LNode *pre = L->head->next;
        if (pre->data == cur_e)
            return 0;
        for (LNode *p = pre->next; p != NULL; p = p->next, pre = pre->next) {
            if (p->data == cur_e) {
                pre_e = pre->data;
                return 1;
            }
        }
        return 0;
    }

    int NextElem(int cur_e, int &next_e)
    {
        if (!L)
            return 0;
        for (LNode *p = L->head->next; p != NULL; p = p->next) {
            if (p->data == cur_e && p->next != NULL) {
                next_e = p->next->data;
                return 1;
            }
        }
        return 0;
    }

    void ListTraverse()
    {
        if (!L || L->length == 0)
            return;
        cout << "���Ա���Ϊ" << ListLength() << " ��Ԫ��Ϊ��  ";
        for (LNode *p = L->head->next; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }

    int SetElem(int i, int &e)
    {
        if (!L || i < 1 || i > L->length)
            return 0;
        for (LNode *p = L->head->next; p != NULL; p = p->next) {
            if (--i == 0) {
                int t = e;
                e = p->data;
                p->data = t;
                return 1;
            }
        }
        return 0;
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

    int DeleteElem(int i, int &e)
    {
        if (!L || i < 1 || i > L->length)
            return 0;
        LNode *pre = L->head;
        while (--i > 0) {
            pre = pre->next;
        }
        LNode *p = pre->next;
        e = p->data;
        pre->next = p->next;
        delete p;
        L->length -= 1;
        return 1;
    }
};

int main()
{
    ADT_SListInfo slistinfo;
    int e;
    cout << "��ʼ����InitList()" << endl;
    slistinfo.InitList();
    cout << "��ʼ����InsertElem()" << endl;
    for (int i = 1; i < 12; i++) {
        slistinfo.InsertElem(i, i * i - 1);
    }
    slistinfo.ListTraverse();
    cout << "��ʼ����ListEmpty()" << endl;
    if (slistinfo.ListEmpty())
        cout << "���Ա�Ϊ��" << endl;
    else
        cout << "���Ա�Ϊ��" << endl;
    cout << "��ʼ����GetElem()" << endl;
    for (int i = 1; i < 12; i += 3) {
        if (slistinfo.GetElem(i, e))
            cout << "���Ա��е� " << i << " ��Ԫ��Ϊ " << e << endl;
    }
    cout << "��ʼ����LocateElem()" << endl;
    for (int i = 1; i < 12; i += 4) {
        if (int x = slistinfo.LocateElem(i * i - 1))
            cout << "���Ա��� " << i * i - 1 << " ��λ���� " << x << endl;
    }
    cout << "��ʼ����PriorElem()" << endl;
    for (int i = 1; i < 12; i += 5) {
        if (slistinfo.PriorElem(i * i - 1, e))
            cout << "���Ա��� " << i * i - 1 << " ��ǰ��Ԫ���� " << e << endl;
    }
    cout << "��ʼ����NextElem()" << endl;
    for (int i = 1; i < 12; i += 5) {
        if (slistinfo.NextElem(i * i - 1, e))
            cout << "���Ա��� " << i * i - 1 << " �ĺ���Ԫ���� " << e << endl;
    }
    cout << "��ʼ����SetElem()" << endl;
    for (int i = 1; i < 12; i += 3) {
        e = i + 1;
        if (slistinfo.SetElem(i, e)) {
            cout << "���Ա��е� " << i << " ��Ԫ������Ϊ " << i + 1 << endl;
            cout << "ԭԪ��Ϊ " << e << endl;
            slistinfo.ListTraverse();
        }
    }
    cout << "��ʼ����DeleteElem()" << endl;
    for (int i = 1; i < 12; i += 3) {
        if (slistinfo.DeleteElem(i, e)) {
            cout << "���Ա��е� " << i << " ��Ԫ��ԭΪ " << e << " ��ɾ��" << endl;
        }
        slistinfo.ListTraverse();
    }
    cout << "��ʼ����ClearList()" << endl;
    slistinfo.ClearList();
    cout << "��ʼ����DestoryList()" << endl;
    slistinfo.DestroyList();
}