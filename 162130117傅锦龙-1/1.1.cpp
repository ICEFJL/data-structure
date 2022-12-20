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
            cout << "�����ɹ�" << endl;
            return;
        }
        cout << "����ʧ��" << endl;
    }

    void ClearList()
    {
        if (L) {
            L->length = 0;
            cout << "��ճɹ�" << endl;
            return;
        }
        cout << "���ʧ��" << endl;
    }

    bool ListEmpty()
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
        e = L->pData[i - 1];
        return 1;
    }

    int LocateElem(int e)
    {
        if (!L)
            return 0;
        for (int i = 0; i < L->length; i++) {
            if (L->pData[i] == e)
                return i + 1;
        }
        return 0;
    }

    int PriorElem(int cur_e, int &pre_e)
    {
        if (!L)
            return 0;
        for (int i = 0; i < L->length; i++) {
            if (L->pData[i] == cur_e && i != 0) {
                pre_e = L->pData[i - 1];
                return 1;
            }
        }
        return 0;
    }

    int NextElem(int cur_e, int &next_e)
    {
        if (!L)
            return 0;
        for (int i = 0; i < L->length; i++) {
            if (L->pData[i] == cur_e && i != L->length - 1) {
                next_e = L->pData[i + 1];
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
        for (int i = 0; i < L->length; i++) {
            cout << L->pData[i] << " ";
        }
        cout << endl;
    }

    int SetElem(int i, int &e)
    {
        if (!L || i < 1 || i > L->length)
            return 0;
        int t = e;
        e = L->pData[i - 1];
        L->pData[i - 1] = t;
        return 1;
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

    int DeleteElem(int i, int &e)
    {
        if (!L || i < 1 || i > L->length)
            return 0;
        e = L->pData[i - 1];
        for (int j = i; j < L->length; j++)
            L->pData[j - 1] = L->pData[j];
        L->length -= 1;
        return 1;
    }
};

int main()
{
    ADT_SeqList seqlist;
    int e;
    cout << "��ʼ����InitList()" << endl;
    seqlist.InitList();
    cout << "��ʼ����InsertElem()" << endl;
    for (int i = 1; i < 12; i++) {
        seqlist.InsertElem(i, i * i - 1);
    }
    seqlist.ListTraverse();
    cout << "��ʼ����ListEmpty()" << endl;
    if (seqlist.ListEmpty())
        cout << "���Ա�Ϊ��" << endl;
    else
        cout << "���Ա�Ϊ��" << endl;
    cout << "��ʼ����GetElem()" << endl;
    for (int i = 1; i < 12; i += 3) {
        if (seqlist.GetElem(i, e))
            cout << "���Ա��е� " << i << " ��Ԫ��Ϊ " << e << endl;
    }
    cout << "��ʼ����LocateElem()" << endl;
    for (int i = 1; i < 12; i += 4) {
        if (int x = seqlist.LocateElem(i * i - 1))
            cout << "���Ա��� " << i * i - 1 << " ��λ���� " << x << endl;
    }
    cout << "��ʼ����PriorElem()" << endl;
    for (int i = 1; i < 12; i += 5) {
        if (seqlist.PriorElem(i * i - 1, e))
            cout << "���Ա��� " << i * i - 1 << " ��ǰ��Ԫ���� " << e << endl;
    }
    cout << "��ʼ����NextElem()" << endl;
    for (int i = 1; i < 12; i += 5) {
        if (seqlist.NextElem(i * i - 1, e))
            cout << "���Ա��� " << i * i - 1 << " �ĺ���Ԫ���� " << e << endl;
    }
    cout << "��ʼ����SetElem()" << endl;
    for (int i = 1; i < 12; i += 3) {
        e = i + 1;
        if (seqlist.SetElem(i, e)) {
            cout << "���Ա��е� " << i << " ��Ԫ������Ϊ " << i + 1 << endl;
            cout << "ԭԪ��Ϊ " << e << endl;
            seqlist.ListTraverse();
        }
    }
    cout << "��ʼ����DeleteElem()" << endl;
    for (int i = 1; i < 12; i += 3) {
        if (seqlist.DeleteElem(i, e)) {
            cout << "���Ա��е� " << i << " ��Ԫ��ԭΪ " << e << " ��ɾ��" << endl;
        }
        seqlist.ListTraverse();
    }
    cout << "��ʼ����ClearList()" << endl;
    seqlist.ClearList();
    cout << "��ʼ����DestoryList()" << endl;
    seqlist.DestroyList();
}