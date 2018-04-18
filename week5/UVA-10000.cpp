#include <cstdio>

struct Edge {
    int a;
    int b;
};

int dis[102];
Edge path[10005];

void BellmanFord(int nodes, int numOfEdges);

int main()
{
    int nodes;
    int cases = 1;

    while (scanf("%d", &nodes) && nodes) {
        int start;
        int p, q, numOfEdges = 0;

        scanf("%d", &start);

        while (scanf("%d %d", &p, &q) && p && q) {
            path[numOfEdges].a = p;
            path[numOfEdges].b = q;
            numOfEdges++;
        }

        for (int i = 1; i <= nodes; i++) {
            dis[i] = -9999999;
        }

        dis[start] = 0;

        BellmanFord(nodes, numOfEdges);

        int maxDis = -1, maxIdx = -1;
        for(int i = 1; i <= nodes; i++) {
            if (maxDis < dis[i]) {
                maxDis = dis[i];
                maxIdx = i;
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cases++, start, maxDis, maxIdx);
    }
}

void BellmanFord(int nodes, int numOfEdges)
{
    for (int i = 0; i < nodes - 1; i++) {
        for (int j = 0; j < numOfEdges; j++) {
            if (dis[path[j].a] + 1 > dis[path[j].b]) {
                dis[path[j].b] = dis[path[j].a] + 1;
            }
        }
    }
}
