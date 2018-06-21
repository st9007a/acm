#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n;
int flow[250][250];
int pre[250];

int bfs(int u, int v);
int maxFlow(int u, int v);

int main()
{
    while (scanf("%d", &n) != EOF) {
        n += 2;

        memset(flow, 0, sizeof(flow));
        flow[0][n] = 1e9;
        flow[n - 1][2 * n - 1] = 1e9;

        for (int i = 1; i < n - 1; i++) {
            scanf("%d", &flow[i][i + n]);
        }

        int m;
        scanf("%d", &m);

        while (m-- > 0) {
            int i, j, cost;
            scanf("%d %d %d", &i, &j, &cost);

            flow[i + n][j] += cost;
        }

        int b, d;

        scanf("%d %d", &b, &d);
        while (b-- > 0) {
            int node;
            scanf("%d", &node);

            flow[n][node] = 1e9;
        }

        while (d-- > 0) {
            int node;
            scanf("%d", &node);

            flow[node + n][n - 1] = 1e9;
        }

        printf("%d\n", maxFlow(0, 2 * n- 1));
    }
}

int bfs(int u, int v)
{
    queue<int> q;
    for (int i = 0; i < 2 * n; i++) {
        pre[i] = -2;
    }

    q.push(u);
    pre[u] = -1;

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        if (from == v) {
            int c = 1e9;
            for (int i = v; pre[i] != -1; i = pre[i]) {
                c = min(c, flow[pre[i]][i]);
            }

            return c;
        }

        for (int i = 0; i < 2 * n; i++) {
            if (pre[i] == -2 && flow[from][i] > 0) {
                q.push(i);
                pre[i] = from;
            }
        }
    }

    return 0;
}

int maxFlow(int u, int v)
{
    int tmp, ret = 0;

    while ((tmp = bfs(u, v))) {
        ret += tmp;

        for (int i = v; pre[i] != -1; i = pre[i]) {
            flow[pre[i]][i] -= tmp;
            flow[i][pre[i]] += tmp;
        }
    }

    return ret;
}
