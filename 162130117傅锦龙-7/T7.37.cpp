#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define MAX_V 100
#define INFINITY INT_MAX

enum { Undirected_graph, Directed_graph, Undirected_net, Directed_net } type;

struct VertexType {
    char code;
    int num;
    VertexType(char c, int n = 0) : code(c), num(n){};
};

struct Edge {
    char from;
    char to;
    int value;
    Edge(char f, char t, int v = 1) : from(f), to(t), value(v){};
};

struct MGraph {
    int arcs[MAX_V][MAX_V] = {0};
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
    int maxlen, path[MAX_V] = {0}, visited[MAX_V] = {0};
    int mlp[MAX_V] = {0};
    int indegree[MAX_V] = {0}, outdegree[MAX_V] = {0};

  public:
    void CreateGraph(int type, vector<VertexType> V, vector<Edge> E)
    {
        G = new MGraph(type);
        G->type = type;
        if (type == Undirected_net || type == Directed_net)
            for (int i = 0; i < MAX_V; i++)
                for (int j = 0; j < MAX_V; j++) 
                    G->arcs[i][j] = INFINITY;
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

    bool GetVex(char v, int &e)
    {
        if (G == NULL || G->ser.find(v) == G->ser.end())
            return false;
        else {
            int x = G->ser.find(v)->second;
            e = G->vexs[x].num;
            return true;
        }
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

    void InsertArc(const Edge &E)
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
        if (from != to && !G->arcs[to][from]) {
            if (!G->arcs[from][to] || G->arcs[from][to] == INFINITY)
                G->arcnum++;
            G->arcs[from][to] = E.value;
            if (G->type == Undirected_graph || G->type == Undirected_net)
                G->arcs[to][from] = E.value;
        }
    }

    void Traverse()
    {
        if (G == nullptr) {
            cout << "图不存在" << endl;
            return;
        }
        cout << "顶点数和边数为：" << G->vexnum << " " << G->arcnum << endl;
        cout << "  ";
        for (int i = 0; i < G->vexnum; i++) {
            cout << G->vexs[i].code << " ";
        }
        cout << endl;
        for (int i = 0; i < G->vexnum; i++) {
            cout << G->vexs[i].code << " ";
            for (int j = 0; j < G->vexnum; j++) {
                if (G->arcs[i][j] == INFINITY)
                    cout << "x ";
                else
                    cout << G->arcs[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void find_longest_path()
    {
        maxlen = 0;
        for (int i = 0; i < G->vexnum; i++)
            for (int j = 0; j < G->vexnum; j++)
                if (G->arcs[i][j]) {
                    indegree[j]++;
                    outdegree[i]++;
                }
        for (int i = 0; i < G->vexnum; i++) {
            memset(visited, 0, sizeof(visited));
            if (!indegree[i])
                DFS(i, 0);
        }
        cout << "最长路径为：";
        for (int i = 0; i <= maxlen; i++)
            cout << G->vexs[mlp[i]].code << " ";
    }

    void DFS(int i, int len)
    {
        visited[i] = true;
        path[len] = i;
        if (len > maxlen && !outdegree[i]) {
            for (int j = 0; j <= len; j++)
                mlp[j] = path[j];
            maxlen = len;
        } else
            for (int j = 0; j < G->vexnum; j++)
                if (!visited[j] && G->arcs[i][j])
                    DFS(j, len + 1);
        path[len] = 0;
        visited[i] = false;
    }
};

int main()
{
    ADT_Graph graph;
    vector<VertexType> V;
    vector<Edge> E;
    int vex = rand() % 5 + 6;
    int arc = rand() % 10 + 6;
    char v, w, t;
    int e;
    for (int i = 0; i < vex; i++) {
        v = 'A' + i;
        V.push_back({v, i + 1});
    }
    for (int i = 0; i < arc; i++) {
        v = 'A' + rand() % vex;
        w = 'A' + rand() % vex;
        E.push_back({v, w});
    }
    E.push_back({'E', 'F'});
    E.push_back({'C', 'B'});

    cout << "开始构造有向无环图" << endl;
    graph.CreateGraph(Directed_graph, V, E);
    graph.Traverse();
    graph.find_longest_path();
}
