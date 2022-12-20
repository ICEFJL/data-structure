#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct BiTNode {
    char data;
    BiTNode *left, *right;
    BiTNode(char d) : data(d)
    {
        left = right = NULL;
    }
};

struct BinaryTree {
    BiTNode *root;
    void InitBiTree()
    {
        root = NULL;
    }

    void DestroyBiTree(BiTNode *root)
    {
        if (root == NULL)
            return;
        DestroyBiTree(root->left);
        DestroyBiTree(root->right);
        delete root;
        root = NULL;
    }

    void CreateBiTree(const char *str)
    {
        stack<BiTNode *> s;
        BiTNode *p = NULL;
        if (str[0] == 0)
            return;
        p = new BiTNode(str[0]);
        root = p;
        int k = 0, i = 1;
        while (str[i]) {
            switch (str[i]) {
                case '(':
                    s.push(p);
                    k = 1;
                    break;
                case ')':
                    s.pop();
                    break;
                case ',':
                    k = 2;
                    break;
                default:
                    p = new BiTNode(str[i]);
                    if (k == 1)
                        s.top()->left = p;
                    else
                        s.top()->right = p;
            }
            ++i;
        };
    }

    int BiTreeDepth(BiTNode *root)
    {
        if (root == NULL)
            return 0;
        return max(BiTreeDepth(root->left), BiTreeDepth(root->right)) + 1;
    }

    void Traverse()
    {
        vector<vector<string>> res;
        int m = BiTreeDepth(root);
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

    void fill(BiTNode *root, int depth, int begin, int end, vector<vector<string>> &res)
    {
        if (!root)
            return;
        int mid = begin + (end - begin) / 2;
        res[depth][mid] = root->data;
        fill(root->left, depth + 1, begin, mid - 1, res);
        fill(root->right, depth + 1, mid + 1, end, res);
    }

    void PreOrderTraverse(BiTNode *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ' ';
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }

    void PreOrderTraverse()
    {
        if (root == NULL)
            return;
        BiTNode *p = root;
        stack<BiTNode *> s;
        while (!s.empty() || p) {
            if (p) {
                cout << p->data << " ";
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
    }

    void InOrderTraverse(BiTNode *root)
    {
        if (root == NULL)
            return;
        InOrderTraverse(root->left);
        cout << root->data << ' ';
        InOrderTraverse(root->right);
    }

    void InOrderTraverse()
    {
        if (root == NULL)
            return;
        BiTNode *p = root;
        stack<BiTNode *> s;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                cout << p->data << " ";
                p = p->right;
            }
        }
    }

    void PostOrderTraverse(BiTNode *root)
    {
        if (root == NULL)
            return;
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        cout << root->data << ' ';
    }

    void PostOrderTraverse()
    {
        if (root == NULL)
            return;
        stack<BiTNode *> s;
        BiTNode *pCur, *pLast;

        pCur = root;
        pLast = NULL;
        while (pCur) {
            s.push(pCur);
            pCur = pCur->left;
        }
        while (!s.empty()) {
            pCur = s.top();
            s.pop();
            if (pCur->right == NULL || pCur->right == pLast) {
                cout << pCur->data << " ";
                pLast = pCur;
            } else {
                s.push(pCur);
                pCur = pCur->right;
                while (pCur) {
                    s.push(pCur);
                    pCur = pCur->left;
                }
            }
        }
    }

    void LevelOrderTraverse()
    {
        queue<BiTNode *> que;
        int num = 1;
        que.emplace(root);
        BiTNode *t;

        while (que.size() != 0) {
            while (num--) {
                t = que.front();
                que.pop();
                cout << t->data << ' ';
                if (t->left != NULL)
                    que.emplace(t->left);
                if (t->right != NULL)
                    que.emplace(t->right);
            }
            num = que.size();
        }
    }
};

int main()
{
    BinaryTree biTree;
    const char *str1 = "A(B(D,E(G,)),C(,F))";
    cout << "构造二叉树 A(B(D,E(G,)),C(,F))" << endl;
    biTree.InitBiTree();
    biTree.CreateBiTree(str1);
    biTree.Traverse();

    cout << "先序遍历（递归）" << endl;
    biTree.PreOrderTraverse(biTree.root);
    cout << endl << endl;

    cout << "先序遍历（非递归）" << endl;
    biTree.PreOrderTraverse();
    cout << endl << endl;

    cout << "中序遍历（递归）" << endl;
    biTree.InOrderTraverse(biTree.root);
    cout << endl << endl;

    cout << "中序遍历（非递归）" << endl;
    biTree.InOrderTraverse();
    cout << endl << endl;

    cout << "后序遍历（递归）" << endl;
    biTree.PostOrderTraverse(biTree.root);
    cout << endl << endl;

    cout << "后序遍历（非递归）" << endl;
    biTree.PostOrderTraverse();
    cout << endl << endl;

    cout << "层次遍历" << endl;
    biTree.LevelOrderTraverse();
    cout << endl << endl;
}