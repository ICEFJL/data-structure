#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *left, *right;
    BSTNode(int k) : key(k)
    {
        left = right = NULL;
    }
};

struct BST {
    BSTNode *root;
    void InitBST()
    {
        root = NULL;
    }

    void DestroyBST(BSTNode *root)
    {
        if (root == NULL)
            return;
        DestroyBST(root->left);
        DestroyBST(root->right);
        delete root;
        root = NULL;
    }

    void BSTInsert(int key)
    {
        BSTNode *p = root, *pa = nullptr;
        if (!root) {
            root = new BSTNode(key);
            return;
        }
        while (p) {
            if (p->key == key)
                return;
            else if (p->key < key) {
                pa = p;
                p = p->right;
            } else {
                pa = p;
                p = p->left;
            }
        }
        p = new BSTNode(key);
        if (pa->key < key)
            pa->right = p;
        else
            pa->left = p;
    }

    BSTNode *BSTSearch(int key)
    {
        BSTNode *p = root;
        while (p) {
            if (p->key == key)
                return p;
            else if (p->key < key)
                p = p->right;
            else
                p = p->left;
        }
        return nullptr;
    }

    void BSTDelete(int key)
    {
        BSTNode *p = root, *pa = nullptr;
        while (p) {
            if (p->key == key)
                break;
            else if (p->key < key) {
                pa = p;
                p = p->right;
            } else {
                pa = p;
                p = p->left;
            }
        }
        if (!p) {
            cout << "节点不存在" << endl;
        } else
            DeleteNode(p, pa);
    }

    void DeleteNode(BSTNode *p, BSTNode *pa)
    {
        BSTNode *t = nullptr;
        if (p->left && p->right) {
            BSTNode *f = p, *q = p->left;
            while (q->right) {
                f = q;
                q = q->right;
            }
            if (f != p) {
                f->right = q->left;
                q->left = p->left;
            }
            q->right = p->right;
            t = q;
        } else
            t = p->left == nullptr ? p->right : p->left;
        if (pa) {
            if (pa->key < p->key)
                pa->right = t;
            else
                pa->left = t;
        } else
            root = t;
        delete p;
    }

    int BSTDepth(BSTNode *root)
    {
        if (root == NULL)
            return 0;
        return max(BSTDepth(root->left), BSTDepth(root->right)) + 1;
    }

    void Traverse()
    {
        vector<vector<string>> res;
        int m = BSTDepth(root);
        int n = pow(2, m) - 1;
        for (int i = 0; i < m; ++i) {
            vector<string> temp;
            for (int i = 0; i < n; ++i) {
                temp.push_back(" ");
            }
            res.push_back(temp);
        }
        fill(root, 0, 0, n - 1, res);
        for (auto &t : res) {
            for (auto &s : t)
                cout << s;
            cout << endl;
        }
        cout << endl;
    }

    void fill(BSTNode *root, int depth, int begin, int end, vector<vector<string>> &res)
    {
        if (!root)
            return;
        int mid = begin + (end - begin) / 2;
        res[depth][mid] = to_string(root->key);
        fill(root->left, depth + 1, begin, mid - 1, res);
        fill(root->right, depth + 1, mid + 1, end, res);
    }

    void MAX_MIN(int key)
    {
        int a = 0, b = 0;
        BSTNode *p = root;
        while (p) {
            if (p->key == key) {
                BSTNode *q = p->left;
                if (q) {
                    while (q->right) {
                        q = q->right;
                    }
                    a = q->key;
                }
                q = p->right;
                if (q) {
                    while (q->left) {
                        q = q->left;
                    }
                    b = q->key;
                }
                break;
            } else if (p->key < key) {
                a = p->key;
                p = p->right;
            } else {
                b = p->key;
                p = p->left;
            }
        }
        cout << "小于" << key << "且最靠近的值为" << a << endl;
        cout << "大于" << key << "且最靠近的值为" << b << endl;
    }
};

int main()
{
    BST T;
    T.InitBST();
    int a[6] = {10, 6, 3, 9, 7, 12};
    cout << "建立二叉排序树" << endl;
    for (int i = 0; i < 6; i++) {
        T.BSTInsert(a[i]);
    }
    T.Traverse();
    T.MAX_MIN(8);
    T.MAX_MIN(9);
}