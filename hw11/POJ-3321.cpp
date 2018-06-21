#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > tree(100001);
int start[100001], e[100001];
int ori[100001], s[100001];
int n, m;
int step;

void dfs(int x);
void change(int x, int delta);
int lowbit(int i);
int getsum(int x);

int main()
{
    char c;
    int x;
    int u, v;

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
    }

    step = 1;
    dfs(1);

    for (int i = 1; i <= n; i++) {
        change(start[i], 1);
        ori[i] = 1;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf(" %c%d", &c, &x);

        if (c == 'C') {
            change(start[x], (ori[x] ^ 1) - ori[x]);
            ori[x] ^= 1;
        } else {
            printf("%d\n", getsum(e[x]) - getsum(start[x] - 1));
        }
    }
    return 0;
}

void dfs(int x)
{
    start[x] = step;
    for (int i = 0; i < tree[x].size(); i++) {
        step++;
        dfs(tree[x][i]);
    }
    e[x] = step;
}

int lowbit(int i)
{
    return i & (-i);
}

void change(int x, int delta)
{
    for (int i = x; i <= n; i += lowbit(i)) {
        s[i] += delta;
    }
}

int getsum(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ans += s[i];
    }

    return ans;
}
