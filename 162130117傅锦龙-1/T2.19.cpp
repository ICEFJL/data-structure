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

bool ListDelete_L(SListInfo &L, int mink, int maxk)
{
    LNode *p, *temp, *prev;
    if (mink > maxk)
        return false;
    prev = L.head;
    p = prev->next;
    while (p && p->data < maxk) {
        if (p->data <= mink) {
            prev = p;
        } else {
            prev->next = p->next;
            temp = p;
            free(temp);
        }
        p = prev->next;
    }
    return true;
}

int main()
{
    SListInfo L;
    int mink,maxk;
    L.head = new LNode;
    L.length = 9;
    LNode *p = L.head;
    cout << "删除之前的元素分别为：";
    for (int i = 1; i < 10; i++) {
        LNode *t = new LNode;
        t->data = i;
        cout << i << " ";
        p->next = t;
        p = p->next;
    }
    p->next=NULL;
    cout << endl;
    cout << "请输入mink：";
	cin >> mink;
	cout << "请输入maxk：";
	cin >> maxk;
    if (!ListDelete_L(L, mink, maxk))
        cout << "不存在可删除元素" << endl;
    cout << "删除之后的元素分别为：" << endl;
    p = L.head->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}