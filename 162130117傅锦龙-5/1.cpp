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
        }
    }

    bool BiTreeEmpty()
    {
        if (root == NULL)
            return true;
        return false;
    }

    int BiTreeDepth(BiTNode *root)
    {
        if (root == NULL)
            return 0;
        return max(BiTreeDepth(root->left), BiTreeDepth(root->right)) + 1;
    }

    bool Root(char &e)
    {
        if (root != NULL) {
            e = root->data;
            return true;
        }
        return false;
    }

    bool Value(BiTNode *p, char &e)
    {
        if (p != NULL) {
            e = p->data;
            return true;
        }
        return false;
    }

    BiTNode *Parent(BiTNode *p, BiTNode *root)
    {
        if (root == NULL || p == root)
            return NULL;
        if (p == root->left || p == root->right)
            return root;
        BiTNode *p1 = Parent(p, root->left);
        BiTNode *p2 = Parent(p, root->right);

        return p1 == NULL ? p2 : p1;
    }

    bool LeftChild(BiTNode *p, BiTNode *&e)
    {
        if (p != NULL) {
            e = p->left;
            return true;
        }
        return false;
    }

    bool RightChild(BiTNode *p, BiTNode *&e)
    {
        if (p != NULL) {
            e = p->right;
            return true;
        }
        return false;
    }

    bool LeftBrother(BiTNode *p, BiTNode *&e)
    {
        if (p != NULL) {
            BiTNode *parent = Parent(p, root);
            if (parent->left == p)
                e = NULL;
            else
                e = parent->left;
            return true;
        }
        return false;
    }

    bool RightBrother(BiTNode *p, BiTNode *&e)
    {
        if (p != NULL) {
            BiTNode *parent = Parent(p, root);
            if (parent->right == p)
                e = NULL;
            else
                e = parent->right;
            return true;
        }
        return false;
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

    void InOrderTraverse(BiTNode *root)
    {
        if (root == NULL)
            return;
        InOrderTraverse(root->left);
        cout << root->data << ' ';
        InOrderTraverse(root->right);
    }

    void PostOrderTraverse(BiTNode *root)
    {
        if (root == NULL)
            return;
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        cout << root->data << ' ';
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

    void Assign(BiTNode *p, char value)
    {
        if (p != NULL) {
            p->data = value;
        }
    }

    void InsertChild(BiTNode *p, char LR, BiTNode *c)
    {
        if (p == NULL) {
            cout << "节点不存在！" << endl;
            return;
        }
        
        if (c == NULL || c->right != NULL) {
            cout << "插入树错误！" << endl;
            return;
        }

        if (LR == 0) {
            if (p->left != NULL)
                c->right = p->left;
            p->left = c;
        } else {
            if (p->right != NULL)
                c->right = p->right;
            p->right = c;
        }
    }

    void DeleteChild(BiTNode *p, char LR)
    {
        if (p == NULL) {
            cout << "节点不存在！" << endl;
            return;
        }
        if (LR == 0) {
            DestroyBiTree(p->left);
            p->left = NULL;
        } else {
            DestroyBiTree(p->right);
            p->right = NULL;
        }
    }
};

int main()
{
    BinaryTree biTree, cbiTree;
    const char *str1 = "A(B(D,E(G,)),C(,F))";
    const char *str2 = "H(I(J,K),)";
    char e;
    BiTNode *t, *p;

    biTree.InitBiTree();
    cout << "开始构造二叉树 A(B(D,E(G,)),C(,F))" << endl;
    biTree.CreateBiTree(str1);
    biTree.Traverse();

    cout << "开始测试先序遍历" << endl;
    biTree.PreOrderTraverse(biTree.root);
    cout << endl << endl;

    cout << "开始测试中序遍历" << endl;
    biTree.InOrderTraverse(biTree.root);
    cout << endl << endl;

    cout << "开始测试后序遍历" << endl;
    biTree.PostOrderTraverse(biTree.root);
    cout << endl << endl;

    cout << "开始测试层次遍历" << endl;
    biTree.LevelOrderTraverse();
    cout << endl << endl;

    cout << "树的深度：";
    cout << biTree.BiTreeDepth(biTree.root) << endl << endl;

    cout << "树的根节点的值：";
    if (biTree.Root(e))
        cout << e << endl << endl;

    p = biTree.root->left->right;

    cout << "查找节点E的值:";
    if (biTree.Value(p, e))
        cout << e << endl << endl;
    else
        cout << "无" << endl << endl;

    cout << "查找节点E的双亲:";
    t = biTree.Parent(p, biTree.root);
    if (t != NULL)
        cout << t->data << endl << endl;
    else
        cout << "无" << endl << endl;

    cout << "查找节点E的左child:";
    if (biTree.LeftChild(p, t) && t != NULL)
        cout << t->data << endl << endl;
    else
        cout << "无" << endl << endl;

    cout << "查找节点E的右child:";
    if (biTree.RightChild(p, t) && t != NULL)
        cout << t->data << endl << endl;
    else
        cout << "无" << endl << endl;

    cout << "查找节点E的左brother:";
    if (biTree.LeftBrother(p, t) && t != NULL)
        cout << t->data << endl << endl;
    else
        cout << "无" << endl << endl;

    cout << "查找节点E的右brother:";
    if (biTree.RightBrother(p, t) && t != NULL)
        cout << t->data << endl << endl;
    else
        cout << "无" << endl << endl;

    cout << "开始测试更改节点的值" << endl;
    biTree.Assign(p, 'X');
    biTree.Traverse();

    cbiTree.CreateBiTree(str2);
    cout << "开始测试添加子树 H(I(J,K),)" << endl;
    biTree.InsertChild(p, 0, cbiTree.root);
    cout << endl;
    biTree.Traverse();

    cout << "开始测试删除子树" << endl;
    biTree.DeleteChild(p, 0);
    biTree.Traverse();
}