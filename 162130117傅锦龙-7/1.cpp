#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
    int visited[MAX_V];

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

    void DFSTraverse()
    {
        if (G == NULL)
            return;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < G->vexnum; i++)
            if (!visited[i]) {
                DFS(i);
                cout << endl;
            }
    }

    void DFS(int i)
    {
        visited[i] = true;
        cout << G->vexs[i].code << " ";
        for (int j = 0; j < G->vexnum; j++)
            if (G->arcs[i][j] && !visited[j])
                DFS(j);
    }

    void BFSTraverse()
    {
        if (G == NULL)
            return;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < G->vexnum; i++)
            if (!visited[i])
                BFS(i);
    }

    void BFS(int i)
    {
        visited[i] = true;
        queue<int> que;
        cout << G->vexs[i].code << endl;
        que.push(i);
        int n = 1;
        while (!que.empty()) {
            while (n--) {
                int x = que.front();
                que.pop();
                for (int i = 0; i < G->vexnum; i++)
                    if (G->arcs[x][i] && !visited[i]) {
                        que.push(i);
                        visited[i] = true;
                        cout << G->vexs[i].code << " ";
                    }
            }
            n = que.size();
            cout << endl;
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
        if (from != to) {
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
                cout << G->arcs[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    ADT_Graph graph;
    vector<VertexType> V;
    vector<Edge> E;
    int vex = rand() % 5 + 4;
    int arc = rand() % 10 + 6;
    char v, w, t;
    for (int i = 0; i < vex; i++) {
        v = 'A' + i;
        V.push_back({v, i + 1});
    }
    for (int i = 0; i < arc; i++) {
        v = 'A' + rand() % vex;
        w = 'A' + rand() % vex;
        E.push_back({v, w});
    }
    cout << "开始构造无向图" << endl;
    graph.CreateGraph(0, V, E);
    graph.Traverse();

    cout << "DFSTraverse()" << endl;
    graph.DFSTraverse();
    cout << endl;

    cout << "BFSTraverse()" << endl;
    graph.BFSTraverse();
    cout << endl;
}