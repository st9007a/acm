#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int llink[1000], rlink[1000];
vector<int> edge[1000];
bool visited[1000];

int Bipartite(int n, int u, int v);
bool DFS(int now, int u, int v);

int main()
{
    int n;
    int cases = 1;
    int xMax[1000], xMin[1000], yMax[1000], yMin[1000];
    int x, y;

    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < 1000; i++) {
            edge[i].clear();
        }

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", xMin + i, xMax + i, yMin + i, yMax + i);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);

            for (int j = 0; j < n; j++) {
                if (xMin[j] <= x && x <= xMax[j] && yMin[j] <= y && y <= yMax[j]) {
                    edge[j].push_back(i);
                }
            }
        }

        int res = Bipartite(n, -1, -1);
        int ans[1000];

        for (int i = 0; i < n; i++) {
            ans[i] = llink[i];
        }

        printf("Heap %d\n", cases++);

        bool check = false;
        for (int i = 0; i < n; i++) {
            if (Bipartite(n, i, ans[i]) < res) {
                if (check) {
                    printf(" ");
                }
                printf("(%c,%d)", i + 'A', ans[i] + 1);
                check = true;
            }
        }

        if (!check) {
            printf("none");
        }

        printf("\n\n");


    }
}

int Bipartite(int n, int u, int v)
{
    fill(llink, llink + n, -1);
    fill(rlink, rlink + n, -1);

    int num = 0;

    for (int i = 0; i < n; i++) {
        fill(visited, visited + n, false);
        if (DFS(i, u, v)) {
            num++;
        }
    }

    return num;
}

bool DFS(int now, int u, int v)
{
    for (int next : edge[now]) {
        if (visited[next] || (now == u && next == v)) {
            continue;
        }

        visited[next] = true;

        if (rlink[next] == -1 || DFS(rlink[next], u, v)) {
            llink[now] = next;
            rlink[next] = now;
            return true;
        }
    }

    return false;
}
