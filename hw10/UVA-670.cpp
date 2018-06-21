#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

int llink[105], rlink[105];
bool visited[105];
bool edge[105][105];
Point point[105], interest[105];

int Bipartite(int nL, int nR);
bool DFS(int now, int m);

int main()
{
    int cases;
    int n, m;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &point[i].x, &point[i].y);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &interest[i].x, &interest[i].y);
        }

        memset(edge, 0, sizeof(edge));

        for (int i = 0; i < n - 1; i++) {
            double p1 = sqrt(pow(point[i].x - point[i + 1].x, 2) + pow(point[i].y - point[i + 1].y, 2));
            for (int j = 0; j < m; j++) {
                double p2 = sqrt(pow(point[i].x - interest[j].x, 2) + pow(point[i].y - interest[j].y, 2));
                double p3 = sqrt(pow(point[i + 1].x - interest[j].x, 2) + pow(point[i + 1].y - interest[j].y, 2));

                if (p2 + p3 < 2.0 * p1 + 1e-8) {
                    edge[i][j] = true;
                }
            }
        }

        int ans = Bipartite(n, m);
        int ptr = 0;

        printf("%d\n", ans + n);

        while (ptr < n - 1) {
            int curr = llink[ptr];

            if (ptr != 0) {
                printf(" ");
            }

            printf("%d %d", point[ptr].x, point[ptr].y);

            if (curr != -1) {
                printf(" %d %d", interest[curr].x, interest[curr].y);
            }

            ptr++;
        }
        printf(" %d %d", point[ptr].x, point[ptr].y);

        printf("\n");

        if (cases != 0) {
            printf("\n");
        }
    }
}

int Bipartite(int nL, int nR)
{
    fill(llink, llink + nL, -1);
    fill(rlink, rlink + nR, -1);

    int num = 0;

    for (int i = 0; i < nL - 1; i++) {
        fill(visited, visited + nR, 0);
        num += DFS(i, nR);
    }

    return num;
}

bool DFS(int now, int m)
{
    for (int i = 0; i < m; i++) {
        if (!edge[now][i] || visited[i]) {
            continue;
        }

        visited[i] = true;

        if (rlink[i] == -1 || DFS(rlink[i], m)) {
            llink[now] = i;
            rlink[i] = now;
            return true;
        }
    }

    return false;
}
