#include <iostream>
#include <algorithm>
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
    char name;

  public:
    void InitList(char t)
    {
        L = new SeqList;
        L->pData = new int[LISTINITSIZE];
        L->size = LISTINITSIZE;
        L->length = 0;
        name = t;
    }

    void ListTraverse()
    {
        if (!L || L->length == 0)
            return;
        cout <<name<< "线性表各元素为：  ";
        for (int i = 0; i < L->length; i++) {
            cout << L->pData[i] << " ";
        }
        cout << endl << endl;
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

    void SortSeqList()
    {
        int len = L->length;
        if (len == 0 || len == 1)
            return;
        int *nums = L->pData;
        for (int i = 0; i < len - 1; i++)
            for (int j = 0; j < len - 1 - i; j++)
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
    }

    void DeleteDup(ADT_SeqList s[3])
    {
        int *Lx[3], len[3], i = 0, j = 0, k = 0, e1, e2;
        for (int i = 0; i < 3; i++) {
            Lx[i] = s[i].L->pData;
            len[i] = s[i].L->length;
        }
        while (i < len[1] && j < len[2]) {
            e1 = Lx[1][i];
            e2 = Lx[2][j];
            if (e1 == e2) {
                while (k < len[0] && Lx[0][k]<=e1) {
                    if (Lx[0][k] == e1) {
                        for (int i = k; i < len[0] - 1; i++)
                            Lx[0][i] = Lx[0][i + 1];
                        L->length--;
                        len[0]--;
                    } else
                        k++;
                }
                i++, j++;
            } else if (e1 > e2)
                j++;
            else
                i++;
        }
    }
};

int main()
{
    ADT_SeqList seqlist[3];
    for (int j = 0; j < 3; j++) {
        seqlist[j].InitList('A'+ j);
        for (int i = 1; i < rand() % 10 + 5; i++)
            seqlist[j].InsertElem(i, rand() % 10);
        seqlist[j].SortSeqList();
        seqlist[j].ListTraverse();
    }
    seqlist[0].DeleteDup(seqlist);
    for (int j = 0; j < 3; j++)
        seqlist[j].ListTraverse();

    return 0;
}