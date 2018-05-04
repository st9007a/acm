#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Edge {
    int a;
    int b;
    double w;
};

Point buildings[752];
Edge path[752 * 752];
int set[752];
double ans;

bool cmp(const Edge a, const Edge b);
int findRoot(int x);
void Union(Edge p);

int main()
{
    int n, m;

    while (scanf("%d", &n) != EOF) {
        ans = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &buildings[i].x, &buildings[i].y);
            set[i] = i;
        }

        scanf("%d", &m);
        Edge tmp = { 0, 0, 0 };

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &tmp.a, &tmp.b);
            Union(tmp);
        }

        int idx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                path[idx].a = i;
                path[idx].b = j;
                path[idx].w = sqrt(pow(buildings[i].x - buildings[j].x, 2) + pow(buildings[i].y - buildings[j].y, 2));

                ++idx;
            }
        }

        sort(path, path + idx, cmp);

        for (int i = 0; i < idx; i++) {
            Union(path[i]);
        }

        printf("%.2lf\n", ans);
    }
}

bool cmp(const Edge a, const Edge b)
{
    return a.w < b.w;
}

int findRoot(int x)
{
    if (x != set[x]) {
        return set[x] = findRoot(set[x]);
    }

    return x;

}

void Union(Edge p)
{
    int x = findRoot(p.a);
    int y = findRoot(p.b);

    if (x != y) {
        set[x] = y;
        ans += p.w;
    }
}
