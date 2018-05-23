#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int graph[105][105];
bool visited[105];
int nodes;

int maxFlow(int s, int t);
int dfs(int u, int v, int c);

int main()
{
    int s, t, c;
    int id = 1;

    while (scanf("%d", &nodes) && nodes != 0) {
        scanf("%d %d %d", &s, &t, &c);
        memset(graph, 0, sizeof(graph));

        int from, to, weight;

        for (int i = 0; i < c; i++) {
            scanf("%d %d %d", &from, &to, &weight);

            graph[from][to] += weight;
            graph[to][from] += weight;
        }

        printf("Network %d\nThe bandwidth is %d.\n\n", id++, maxFlow(s, t));
    }
}

int dfs(int u, int v, int c)
{
    visited[u] = 1;

    if (u == v) {
        return c;
    }

    for (int i = 1; i <= nodes; i++) {
        if (graph[u][i] > 0 && visited[i] == 0) {
            int res = 0;
            if ((res = dfs(i, v, min(c, graph[u][i]))) > 0) {
                graph[u][i] -= res;
                graph[i][u] += res;
                return res;
            }
        }
    }

    return 0;
}

int maxFlow(int s, int t)
{
    int ret = 0, tmp = 0;
    memset(visited, 0, sizeof(visited));

    while ((tmp = dfs(s, t, 1e9)) > 0) {
        ret += tmp;
        memset(visited, 0, sizeof(visited));
    }

    return ret;
}
