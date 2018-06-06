#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int s[1100][1100];
int n;

int lowbit(int i);
void change(int x, int y, int delta);
int sum(int x, int y);
int getsum(int x1, int y1, int x2, int y2);

int main()
{
    int op;

    while (scanf("%d %d", &op, &n) != EOF) {
        memset(s, 0, sizeof(s));

        int a, b, c, d;

        while (scanf("%d", &op)) {
            if (op == 3) {
                break;
            } else if (op == 1) {
                scanf("%d %d %d", &a, &b, &c);
                change(a + 1, b + 1, c);
            } else {
                scanf("%d %d %d %d", &a, &b, &c, &d);
                printf("%d\n", getsum(a + 1, b + 1, c + 1, d + 1));
            }
        }
    }
}

int lowbit(int i)
{
    return i & (-i);
}

void change(int x, int y, int delta)
{
    for (int i = x; i < 1100; i += lowbit(i)) {
        for (int j = y; j < 1100; j += lowbit(j)) {
            s[i][j] = max(s[i][j] + delta, 0);
        }
    }
}

int sum(int x, int y)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ans += s[i][j];
        }
    }

    return ans;
}

int getsum(int x1, int y1, int x2, int y2)
{
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 -1 );
}
