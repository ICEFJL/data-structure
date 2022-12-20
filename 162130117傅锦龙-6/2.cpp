#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct HFNode {
    string code;
    int weight;
    HFNode *left, *right;
    HFNode(int w = 0) : weight(w)
    {
        left = right = nullptr;
    }
};

class HufTree
{
  private:
    HFNode *root;

  public:
    HFNode *CreateHufTree(vector<HFNode *> L)
    {
        HFNode *temp = new HFNode();
        sort(L.begin(), L.end(), [](HFNode *a, HFNode *b) { return a->weight > b->weight; });
        int num = L.size();

        temp->weight = L[num - 1]->weight + L[num - 2]->weight;
        temp->left = L[num - 1];
        temp->right = L[num - 2];

        if (num == 2) {
            return temp;
        }

        L.pop_back();
        L.pop_back();
        L.emplace_back(temp);

        return CreateHufTree(L);
    }

    void HufCode(HFNode *L)
    {
        root = L;
        queue<HFNode *> que;
        que.push(root);
        int n = 1;
        while (!que.empty()) {
            while (n--) {
                HFNode *temp = que.front();
                que.pop();
                if (temp->left != nullptr) {
                    que.push(temp->left);
                    temp->left->code = temp->code + "0";
                }
                if (temp->right != nullptr) {
                    que.push(temp->right);
                    temp->right->code = temp->code + "1";
                }
            }
            n = que.size();
        }
    }

    int HufTreeDepth(HFNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(HufTreeDepth(root->left), HufTreeDepth(root->right)) + 1;
    }

    void Traverse()
    {
        vector<vector<string>> res;
        int m = HufTreeDepth(root);
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

    void fill(HFNode *root, int depth, int begin, int end, vector<vector<string>> &res)
    {
        if (!root)
            return;
        int mid = begin + (end - begin) / 2;
        res[depth][mid] = to_string(root->weight);
        fill(root->left, depth + 1, begin, mid - 1, res);
        fill(root->right, depth + 1, mid + 1, end, res);
    }
};

int main()
{
    HufTree HF;
    int num = rand() % 10 + 5;
    vector<HFNode *> L;
    for (int i = 0; i < num; i++) {
        HFNode *temp = new HFNode(rand() % 100 + 1);
        L.push_back(temp);
    }
    HF.HufCode(HF.CreateHufTree(L));
    HF.Traverse();
    for (auto t : L) {
        cout << t->weight << "µÄ±àÂëÎª£º" << t->code << endl;
    }
}
