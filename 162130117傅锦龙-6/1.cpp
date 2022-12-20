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

    bool FirstAdjVex(char v, char &t)
    {
        if (G == NULL || G->ser.find(v) == G->ser.end())
            return false;
        int x = G->ser.find(v)->second;
        int i = 0;
        for (; i < G->vexnum; i++)
            if (G->arcs[x][i])
                break;
        if (i == G->vexnum)
            return false;
        else {
            t = G->vexs[i].code;
            return true;
        }
    }

    bool NextAdjVex(char v, char w, char &t)
    {
        if (G == NULL || G->ser.find(v) == G->ser.end() || G->ser.find(w) == G->ser.end())
            return false;
        int x = G->ser.find(v)->second;
        int y = G->ser.find(w)->second;
        int i = y + 1;
        for (; i < G->vexnum; i++)
            if (G->arcs[x][i])
                break;
        if (i == G->vexnum)
            return false;
        else {
            t = G->vexs[i].code;
            return true;
        }
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
            cout << "ͼ������" << endl;
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
            cout << "ͼ������" << endl;
            return;
        }
        if (G->ser.find(E.from) == G->ser.end() || G->ser.find(E.to) == G->ser.end()) {
            cout << "���㲻����" << endl;
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

    void DeleteVex(char v)
    {
        if (G == NULL) {
            cout << "ͼ������" << endl;
            return;
        }
        if (G->ser.find(v) == G->ser.end()) {
            cout << "���㲻����" << endl;
            return;
        }
        int x = G->ser.find(v)->second;
        G->vexs.erase(G->vexs.begin() + x);
        G->vexnum--;
        int t = 0;
        for (int i = 0; i <= G->vexnum; i++)
            if (G->arcs[x][i] || G->arcs[i][x])
                t++;
        G->arcnum -= t;
        G->ser.erase(v);
        for (; x < G->vexnum; x++) {
            char t = G->vexs[x].code;
            G->ser.find(t)->second--;
            for (int i = G->vexnum; i >= 0; i--) {
                G->arcs[x][i] = G->arcs[x + 1][i];
                G->arcs[i][x] = G->arcs[i][x + 1];
            }
        }
    }

    void DeleteArc(char v, char w)
    {
        if (G == NULL) {
            cout << "ͼ������" << endl;
            return;
        }
        if (G->ser.find(v) == G->ser.end() || G->ser.find(w) == G->ser.end()) {
            cout << "���㲻����" << endl;
            return;
        }
        int from = G->ser.find(v)->second;
        int to = G->ser.find(w)->second;
        if (G->arcs[from][to]) {
            G->arcs[from][to] = 0;
            if (G->type == 0)
                G->arcs[to][from] = 0;
            G->arcnum--;
        }
    }

    void Traverse()
    {
        if (G == nullptr) {
            cout << "ͼ������" << endl;
            return;
        }
        cout << "�������ͱ���Ϊ��" << G->vexnum << " " << G->arcnum << endl;
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
    int e;
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
    cout << "��ʼ��������ͼ" << endl;
    graph.CreateGraph(0, V, E);
    graph.Traverse();

    cout << "��ʼ����GetVex()" << endl;
    for (int i = 0; i < vex; i += 2) {
        v = 'A' + i;
        if (graph.GetVex(v, e))
            cout << v << "�����Ԫ��ֵΪ��" << e << endl;
        else
            cout << "��ȡʧ��" << endl;
    }
    cout << endl;
    cout << "��ʼ����FirstAdjVex()��NextAdjVex()" << endl;
    for (int i = 0; i < vex; i += 2) {
        v = 'A' + i;
        if (graph.FirstAdjVex(v, t)) {
            cout << v << "�ĵ�һ���ڽӵ�Ϊ��" << t << endl;
            w = t;
            if (graph.NextAdjVex(v, w, t))
                cout << v << "�����" << w << "����һ���ڽӵ�Ϊ��" << t << endl;
            else
                cout << "��ȡʧ��" << endl;
        } else
            cout << "��ȡʧ��" << endl;
    }
    cout << endl;

    cout << "��ʼ����DFSTraverse()" << endl;
    graph.DFSTraverse();
    cout << endl;

    cout << "��ʼ����BFSTraverse()" << endl;
    graph.BFSTraverse();
    cout << endl;

    cout << "��ʼ����InsertVex()��InsertArc()" << endl;
    cout << "��ӵ�X��Z" << endl;
    graph.InsertVex({'X', rand() % 10});
    graph.InsertVex({'Z', rand() % 10});
    cout << "��ӱ�(X,A)��(C,Z)" << endl << endl;
    graph.InsertArc({'X', 'A'});
    graph.InsertArc({'C', 'Z'});
    graph.Traverse();

    cout << "��ʼ����DeleteVex()��DeleteArc()" << endl;
    cout << "ɾ����C��Z" << endl;
    graph.DeleteVex('C');
    graph.DeleteVex('Z');
    cout << "ɾ����(X,A)" << endl << endl;
    graph.DeleteArc('X', 'A');
    graph.Traverse();
}
