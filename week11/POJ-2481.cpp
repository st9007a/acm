#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    int s, e;
    int no;
};

node tree[100005];
int n;
int ans[100005], cnt[100005];

bool cmp(node a, node b)
{
    if (a.e == b.e)
        return a.s < b.s;
    return a.e > b.e;
}

int lowbit(int x)
{
    return x & (-x);
}

void change(int x)
{
    while (x <= n) {
        ans[x]++;
        x = x + lowbit(x);
    }
}

int getsum(int x)
{
    int res = 0;
    while (x > 0) {
        res += ans[x];
        x = x - lowbit(x);
    }

    return res;
}

int main()
{
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &tree[i].s, &tree[i].e);
            tree[i].no = i;
        }

        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));

        sort(tree + 1, tree + n + 1, cmp);

        for (int i = 1; i <= n; ++i) {
            if (tree[i].e == tree[i - 1].e && tree[i].s == tree[i - 1].s) {
                cnt[tree[i].no] = cnt[tree[i - 1].no];
            } else {
                cnt[tree[i].no] = getsum(tree[i].s + 1);
            }

            change(tree[i].s + 1);
        }

        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                printf("%d", cnt[1]);
            } else {
                printf(" %d", cnt[i]);
            }
        }
        printf("\n");

    }
    return 0;
}
