#include <cstdio>

struct Edge {
    int a;
    int b;
    int weight;
};

Edge paths[2002];

bool BellmanFord(int n, int m);

int main()
{
    int cases;
    int n, m;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &paths[i].a, &paths[i].b, &paths[i].weight);
        }

        printf("%s\n", BellmanFord(n, m) ? "possible" : "not possible");
    }
}

bool BellmanFord(int n, int m)
{
    int dis[1002];

    for (int i = 0; i < n; i++) {
        dis[i] = 99999999;
    }

    dis[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dis[paths[j].a] != 99999999) {
                if (dis[paths[j].a] + paths[j].weight < dis[paths[j].b]) {
                    dis[paths[j].b] = dis[paths[j].a] + paths[j].weight;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (dis[paths[i].a] + paths[i].weight < dis[paths[i].b]) {
            return true;
        }
    }

    return false;
}
