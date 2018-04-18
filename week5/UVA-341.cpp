#include <cstdio>
#include <stack>

using namespace std;

struct Edge {
    int a;
    int b;
    int weight;
};

Edge paths[100];
int numOfEdge;
int dis[11];
int pre[11];

void BellmanFord(int nodes);
void Relax(Edge &e);

int main()
{
    int cases = 1;
    int nodes, conn;
    int start, end;

    while (scanf("%d", &nodes) && nodes) {
        numOfEdge = 0;

        for (int i = 1; i <= nodes; i++) {
            scanf("%d", &conn);
            for (int j = 0; j < conn; j++) {
                scanf("%d %d", &paths[numOfEdge].b, &paths[numOfEdge].weight);
                paths[numOfEdge++].a = i;
            }
        }

        scanf("%d %d", &start, &end);

        for (int i = 1; i <= nodes; i++) {
            dis[i] = 99999999;
        }

        dis[start] = 0;
        pre[start] = -1;

        BellmanFord(nodes);

        int curr = end;
        stack<int> p;

        do {
            p.push(pre[curr]);
            curr = pre[curr];
        } while (curr != start);

        printf("Case %d: Path =", cases++);

        while (!p.empty()) {
            printf(" %d", p.top());
            p.pop();
        }

        printf(" %d; %d second delay\n", end, dis[end]);
    }

}

void Relax(Edge &e)
{
    int x = e.a;
    int y = e.b;

    if (dis[x] + e.weight < dis[y]) {
        dis[y] = e.weight + dis[x];
        pre[y] = x;
    }
}

void BellmanFord(int nodes)
{
    for (int i = 0; i < nodes - 1; i++) {
        for (int j = 0; j < numOfEdge; j++) {
            Relax(paths[j]);
        }
    }
}
