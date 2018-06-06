#include <cstdio>
#include <cstring>

int s[32005], level[32005];

int lowbit(int n);
void change(int idx, int data);
int getsum(int x);

int main()
{
    int x, y;
    int n;

    while (~scanf("%d", &n)) {
        memset(s, 0, sizeof(s));
        memset(level, 0, sizeof(level));

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            x++;
            level[getsum(x)]++;
            change(x, 1);
        }

        for (int i = 0; i < n; i++) {
            printf("%d\n", level[i]);
        }
    }

    return 0;
}

int lowbit(int n)
{
    return n & (-n);
}

void change(int idx, int delta)
{
    for (int i = idx; i < 32005; i += lowbit(i)) {
        s[i] += delta;
    }
}

int getsum(int x)
{
    int ans = 0;
    while (x > 0) {
        ans += s[x];
        x -= lowbit(x);
    }
    return ans;
}
