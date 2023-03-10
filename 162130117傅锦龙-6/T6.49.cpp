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

    bool isCompleteTree(BiTNode *root)
    {
        if (!root)
            return true;
        queue<BiTNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front();
                q.pop();
                if (!cur) {
                    flag = true;
                } else {
                    if (flag)
                        return false;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};

int main()
{
    BinaryTree biTree;
    const char *str1 = "A(B(D,E),C(,F))";
    cout << "?????????? A(B(D,E),C(,F))" << endl;
    biTree.InitBiTree();
    biTree.CreateBiTree(str1);
    biTree.Traverse();

    if (biTree.isCompleteTree(biTree.root))
        cout << "??????????????????" << endl;
    else
        cout << "????????????????????" << endl;

    return 0;
}