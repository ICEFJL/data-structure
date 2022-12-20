#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define MAX_V 100
#define INFINITY INT_MAX

enum { Undirected_graph, Directed_graph, Undirected_net, Directed_net } type;

struct Edge {
    char from;
    char to;
    int value;
    Edge *next;
    Edge(char f, char t, int v = 1) : from(f), to(t), value(v)
    {
        next = nullptr;
    };
};

struct VertexType {
    char code;
    int num;
    Edge *first;
    VertexType(char c, int n = 0) : code(c), num(n)
    {
        first = new Edge(c, 0);
    };
};

struct MGraph {
    int vexnum, arcnum;
    vector<VertexType> vexs;
    map<char, int> ser;
    int type;
    MGraph(int t) : type(t)
    {
        vexnum = arcnum = 0;
    }
};

class ADT_Graph
{
  private:
    MGraph *G;
    int visited[MAX_V] = {0};
    stack<char> path;

  public:
    void CreateGraph(int type, vector<VertexType> V, vector<Edge> E)
    {
        G = new MGraph(type);
        G->type = type;
        for (VertexType &a : V)
            InsertVex(a);
        for (Edge &b : E)
            InsertArc(b);
    }

    void DestroyGraph()
    {
        delete G;
        G = NULL;
    }
    void InsertVex(const VertexType &V)
    {
        if (G == NULL) {
            cout << "图不存在" << endl;
            return;
        }
        if (G->ser.find(V.code) == G->ser.end()) {
            G->vexs.push_back({V.code, V.num});
            G->ser.insert({V.code, G->vexnum});
            G->vexnum++;
        }
    }

    void InsertArc(Edge &E)
    {
        if (G == NULL) {
            cout << "图不存在" << endl;
            return;
        }
        if (G->ser.find(E.from) == G->ser.end() || G->ser.find(E.to) == G->ser.end()) {
            cout << "顶点不存在" << endl;
            return;
        }
        int from = G->ser.find(E.from)->second;
        int to = G->ser.find(E.to)->second;
        if (from != to) {
            Edge *p = G->vexs[from].first;
            while (p->next != nullptr) {
                p = p->next;
                if (p->to == E.to)
                    return;
            }
            G->arcnum++;
            p->next = new Edge(E);
        }
    }

    void Traverse()
    {
        if (G == nullptr) {
            cout << "图不存在" << endl;
            return;
        }
        cout << "顶点数和边数为：" << G->vexnum << " " << G->arcnum << endl;
        for (int i = 0; i < G->vexnum; i++) {
            cout << G->vexs[i].code << " ";
            for (Edge *p = G->vexs[i].first->next; p != nullptr; p = p->next)
                cout << "(" << p->to << "," << p->value << ") ";
            cout << endl;
        }
        cout << endl;
    }

    bool exist_path_len(char v, char w, int k)
    {
        if (v == w && !k) {
            return true;
        } else if (k > 0) {
            int e = G->ser.find(v)->second;
            visited[e] = true;
            for (Edge *p = G->vexs[e].first->next; p != nullptr; p = p->next) {
                int t = G->ser.find(p->to)->second;
                if (!visited[t] && exist_path_len(p->to, w, k - 1)) {
                    path.push(p->to);
                    return true;
                }
            }
            visited[e] = false;
        }
        return false;
    }

    void find_path(char v, char w, int k)
    {
        if (exist_path_len(v, w, k)) {
            cout << v << "到" << w << "存在长度为" << k << "的简单路径" << endl;
            cout << "路径为：" << v;
            while (!path.empty()) {
                cout << " " << path.top();
                path.pop();
            }
        } else
            cout << v << "到" << w << "不存在长度为" << k << "的简单路径" << endl;
        memset(visited, 0, sizeof(visited));
    }
};

int main()
{
    ADT_Graph graph;
    vector<VertexType> V;
    vector<Edge> E;
    int vex = rand() % 5 + 6;
    int arc = rand() % 10 + 20;
    char v, w, t;
    for (int i = 0; i < vex; i++) {
        v = 'A' + i;
        V.push_back({v, i + 1});
    }
    for (int i = 0; i < arc; i++) {
        v = 'A' + rand() % vex;
        w = 'A' + rand() % vex;
        E.push_back({v, w, rand() % 10});
    }

    cout << "开始构造有向网" << endl;
    graph.CreateGraph(Directed_net, V, E);
    graph.Traverse();

    graph.find_path('A', 'D', 4);
}