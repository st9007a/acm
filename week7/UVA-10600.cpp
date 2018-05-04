#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct Edge {
    int a;
    int b;
    int w;
    bool used;
};

Edge conn[102 * 102];
int set[102];
int ans;

bool cmp(const Edge a, const Edge b);
int findRoot(int x);
bool Union(int i);

int main()
{
    int t, n, m;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);
        ans = 0;
        int ontree[102];

        for (int i = 0; i <= n; i++) {
            set[i] = i;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &conn[i].a, &conn[i].b, &conn[i].w);
            conn[i].used = false;
        }

        sort(conn, conn + m, cmp);

        int idx = 0;
        for (int i = 0; i < m; i++) {
            if (Union(i)) {
                ontree[idx++] = i;
            }
        }

        printf("%d ", ans);

        int minAns = 99999999;
        for (int i = 0; i < idx; i++) {
            ans = 0;
            conn[ontree[i]].used = true;

            for (int i = 0; i <= n; i++) {
                set[i] = i;
            }

            int cnt = 0;

            for (int j = 0; j < m; j++) {
                if (!conn[j].used && Union(j)) {
                    cnt++;
                }
            }

            conn[ontree[i]].used = false;

            if (minAns > ans && cnt == n - 1) {
                minAns = ans;
            }
        }
        printf("%d\n", minAns);
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

bool Union(int i)
{
    int x = findRoot(conn[i].a);
    int y = findRoot(conn[i].b);

    if (x != y) {
        set[x] = y;
        ans += conn[i].w;
        return true;
    }
    return false;
}
