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
        cout << "线性表长度为" << L->length << " 各元素为：  ";
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

    void RemoveDupSeqList()
    {
        int len = L->length;
        if (len == 0 || len == 1)
            return;
        int *nums = L->pData;
        int slow = 0, fast = 1;
        while (fast < len) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        L->length = slow + 1;
    }

    void SortSeqList()
    {
        int len = L->length;
        if (len == 0 || len == 1)
            return;
        int *nums = L->pData;
        for (int i = 0; i < len - 1; i++)
            for (int j = 0; j < len - 1 - i; j++)
                if (nums[j] < nums[j + 1])
                    swap(nums[j], nums[j + 1]);
    }

    void MergeSeqList(const ADT_SeqList &L2)
    {
        int i = 0, j = 0;
        int e1 = 0, e2 = 0;
        while (i < L->length && j < L2.L->length) {
            e1 = L->pData[i];
            e2 = L2.L->pData[j];
            if (e1 == e2)
                j++;
            else if (e1 > e2)
                i++;
            else if (e1 < e2) {
                InsertElem(++i, e2);
                j++;
            }
        }
        while (j < L2.L->length) {
            InsertElem(++i, L2.L->pData[j++]);
        }
    }
};

int main()
{
    ADT_SeqList seqlist[2];
    srand((unsigned int)time(0));
    for (int j = 0; j < 2; j++) {
        seqlist[j].InitList();
        for (int i = 1; i < rand() % 10 + 5; i++) {
            seqlist[j].InsertElem(i, rand() % 100);
        }
        seqlist[j].SortSeqList();
        seqlist[j].ListTraverse();
    }
    seqlist[0].MergeSeqList(seqlist[1]);
    seqlist[0].RemoveDupSeqList();
    seqlist[0].ListTraverse();
}