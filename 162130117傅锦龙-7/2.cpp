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
    int visited[MAX_V];

  public:
    void CreateGraph(int type, vector<VertexType> V, vector<Edge> E)
    {
        G = new MGraph(type);
        G->type = type;
        if (type == Undirected_net || type == Directed_net)
            for (int i = 0; i < MAX_V; i++)
                for (int j = 0; j < MAX_V; j++) {
                    if (i == j)
                        continue;
                    G->arcs[i][j] = INFINITY;
                }
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
                if (G->arcs[i][j] == INFINITY)
                    cout << "x ";
                else
                    cout << G->arcs[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void Dijkstra(char v)
    {
        if (G == NULL) {
            cout << "图不存在" << endl;
            return;
        }
        if (G->ser.find(v) == G->ser.end()) {
            cout << "顶点不存在" << endl;
            return;
        }
        int s = G->ser.find(v)->second;
        int dist[MAX_V], path[MAX_V];
        bool flag[MAX_V];
        for (int i = 0; i < G->vexnum; i++) {
            dist[i] = G->arcs[s][i];
            flag[i] = false;
            if (dist[i] < INFINITY)
                path[i] = s;
            else
                path[i] = -1;
        }
        flag[s] = true;
        for (int i = 0; i < G->vexnum - 1; i++) {
            int k = 0;
            int mindist = INFINITY;
            for (int i = 0; i < G->vexnum; i++)
                if (!flag[i] && dist[i] < mindist) {
                    k = i;
                    mindist = dist[i];
                }
            flag[k] = true;
            if (mindist < INFINITY)
                for (int i = 0; i < G->vexnum; i++)
                    if (!flag[i] && G->arcs[k][i] < INFINITY && dist[i] > mindist + G->arcs[k][i]) {
                        dist[i] = mindist + G->arcs[k][i];
                        path[i] = k;
                    }
        }

        stack<int> p;
        for (int i = 0; i < G->vexnum; i++) {
            if (i == s)
                continue;
            int temp = i;
            cout << "顶点" << v << "到顶点" << G->vexs[i].code;
            if (path[temp] == -1) {
                cout << "无最短路径" << endl;
                continue;
            } else
                cout << "的最短距离为：" << dist[i] << endl;
            do {
                p.push(temp);
                temp = path[temp];
            } while (temp != s);
            p.push(s);
            cout << "最短路径为：";
            while (!p.empty()) {
                cout << G->vexs[p.top()].code << " ";
                p.pop();
            }
            cout << endl;
        }
    }
};

int main()
{
    ADT_Graph graph;
    vector<VertexType> V;
    vector<Edge> E;
    int vex = rand() % 5 + 6;
    int arc = rand() % 10 + 12;
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

    graph.Dijkstra('A');
}