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

    BiTNode *DestroyChildTree(BiTNode *root, char x)
    {
        if (root != NULL) {
            if (root->data == x) {
                DestroyBiTree(root);
                return NULL;
            } else {
                root->left = DestroyChildTree(root->left, x);
                root->right = DestroyChildTree(root->right, x);
            }
        }
        return root;
    }
};

int main(){
    BinaryTree biTree;
    const char *str1 = "A(B(D,E(G,)),C(,F))";
    cout << "构造二叉树 A(B(D,E(G,)),C(,F))" << endl;
    biTree.InitBiTree();
    biTree.CreateBiTree(str1);
    biTree.Traverse();

    char x;
	cout << "输入删除子树根的值：" ;
	cin >> x;

	biTree.DestroyChildTree(biTree.root, x);
	cout << endl;
    biTree.Traverse();
}