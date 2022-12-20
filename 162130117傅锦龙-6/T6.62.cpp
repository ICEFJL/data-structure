#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode *firstChild;
    TreeNode *nextbrother;
    TreeNode(char d) : data(d)
    {
        firstChild = nextbrother = NULL;
    }
};

struct Tree {
    TreeNode *root;
    void InitTree()
    {
        root = NULL;
    }

    void DestroyTree(TreeNode *root)
    {
        if (root == NULL)
            return;
        DestroyTree(root->firstChild);
        DestroyTree(root->nextbrother);
        delete root;
        root = NULL;
    }

    void CreateTree(const char *str)
    {
        stack<TreeNode *> s;
        TreeNode *p = NULL;
        if (str[0] == 0)
            return;
        p = new TreeNode(str[0]);
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
                    p = new TreeNode(str[i]);
                    if (k == 1)
                        s.top()->firstChild = p;
                    else
                        s.top()->nextbrother = p;
                    s.pop();
                    s.push(p);
            }
            ++i;
        }
    }

    int GetDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int d1 = 1 + GetDepth(root->firstChild);
        int d2 = GetDepth(root->nextbrother);
        return max(d1, d2);
    }
};

int main()
{
    Tree T;
    const char *str1 = "A(B(E),C(F,G(I,J),H),D)";
    cout << "开始构造树 A(B(E),C(F,G(I,J),H),D)" << endl << endl;
    T.CreateTree(str1);
    cout << "树的深度为：" << T.GetDepth(T.root);
    T.DestroyTree(T.root);
}