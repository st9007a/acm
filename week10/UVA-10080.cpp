#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x;
    double y;
};

bool edge[105][105];
bool visited[105];
int llink[105], rlink[105];
Point gopher[105];
Point hole[105];

bool DFS(int now, int m);

int main()
{
    int n, m, s, v;

    while (scanf("%d %d %d %d", &n, &m, &s, &v) == 4) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
        }
        for (int i = 0; i < m; i++) {
            scanf("%lf %lf", &hole[i].x, &hole[i].y);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                double distance = sqrt(pow(gopher[i].x - hole[j].x, 2) + pow(gopher[i].y - hole[j].y, 2));
                edge[i][j] = distance / v <= s;
            }
        }

        fill(llink, llink + n, -1);
        fill(rlink, rlink + m, -1);

        int ans = n;

        for (int i = 0; i < n; i++) {
            fill(visited, visited + m, false);
            if (DFS(i, m)) {
                ans--;
            }
        }

        printf("%d\n", ans);
    }
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
