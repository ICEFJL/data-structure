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
    cout << "ɾ��֮ǰ��Ԫ�طֱ�Ϊ��";
    for (int i = 1; i < 10; i++) {
        LNode *t = new LNode;
        t->data = i;
        cout << i << " ";
        p->next = t;
        p = p->next;
    }
    p->next=NULL;
    cout << endl;
    cout << "������mink��";
	cin >> mink;
	cout << "������maxk��";
	cin >> maxk;
    if (!ListDelete_L(L, mink, maxk))
        cout << "�����ڿ�ɾ��Ԫ��" << endl;
    cout << "ɾ��֮���Ԫ�طֱ�Ϊ��" << endl;
    p = L.head->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}