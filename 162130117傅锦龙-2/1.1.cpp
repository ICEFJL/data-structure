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
};

int main()
{
    ADT_SeqList seqlist;

    seqlist.InitList();
    for (int i = 1; i < 12; i++) {
        seqlist.InsertElem(i, rand() % 100);
    }
    seqlist.ListTraverse();
    seqlist.SortSeqList();
    seqlist.ListTraverse();
    seqlist.DestroyList();

    return 0;
}