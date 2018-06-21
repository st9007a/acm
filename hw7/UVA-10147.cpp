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
    float w;
};

Point cities[752];
Edge path[752 * 752];
int set[752];

bool cmp(const Edge a, const Edge b);
int findRoot(int x);
bool Union(Edge p);

int main()
{
    int cases;
    int n, m;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &cities[i].x, &cities[i].y);
            set[i] = i;
        }

        scanf("%d", &m);
        Edge tmp;
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &tmp.a, &tmp.b);
            Union(tmp);
        }

        int idx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                path[idx].a = i;
                path[idx].b = j;
                path[idx].w = sqrt(pow(cities[i].x - cities[j].x, 2) + pow(cities[i].y - cities[j].y, 2));

                ++idx;
            }
        }

        sort(path, path + idx, cmp);

        bool flag = false;

        for (int i = 0; i < idx; i++) {
            if (Union(path[i])) {
                flag = true;
                printf("%d %d\n", path[i].a, path[i].b);
            }
        }

        if (!flag) {
            printf("No new highways need\n");
        }

        if (cases) {
            printf("\n");
        }

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

bool Union(Edge p)
{
    int x = findRoot(p.a);
    int y = findRoot(p.b);

    if (x != y) {
        set[x] = y;
        return true;
    }

    return false;
}
