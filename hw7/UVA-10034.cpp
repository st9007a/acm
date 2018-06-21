#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point {
    float x;
    float y;
};

struct Edge {
    int a;
    int b;
    float w;
};

Edge path[102 * 102];
Point p[102];
int set[102];
float ans;

bool cmp(const Edge a, const Edge b);
int findRoot(int x);
int Union(Edge a);

int main()
{
    int cases;
    int n;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &n);

        ans = 0;
        for (int i = 0; i <= n; i++) {
            set[i] = i;
        }

        for (int i = 0; i < n; i++) {
            scanf("%f %f", &p[i].x, &p[i].y);
        }

        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                float length = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
                path[idx++] = {i, j, length};
            }
        }

        sort(path, path + idx, cmp);

        int count = 0;
        int pIdx = 0;

        while (count < n - 1) {
            count += Union(path[pIdx++]);
        }

        printf("%.2f\n", ans);

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

int Union(Edge a)
{
    int x = findRoot(a.a);
    int y = findRoot(a.b);

    if (x != y) {
        set[x] = y;
        ans += a.w;
        return 1;
    }

    return 0;
}
