#include <cstdio>
#include <cstring>

int n, t;
int matrix[1005][1005];

int lowbit(int x)
{
    return x & (-x);
}

int change(int x, int y, int delta)
{
    for (int i = x; i < 1005; i += lowbit(i)) {
        for (int j = y; j < 1005; j += lowbit(j)) {
            matrix[i][j] += delta;
        }
    }
}

long long getsum(int x, int y)
{
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ans += matrix[i][j];
        }
    }

    return ans;
}

int main()
{
    char ch;
    int cases;
    int a, b, c, d;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d%d%*c", &n, &t);
        memset(matrix, 0, sizeof(matrix));

        for (int i = 0; i < t; i++) {
            scanf("%c", &ch);

            if (ch == 'C') {
                scanf("%d%d", &a, &b);
                scanf("%d%d%*c", &c, &d);
                change(a, b, 1);
                change(c + 1, b, -1);
                change(a, d + 1, -1);
                change(c + 1, d + 1, 1);
            } else {
                scanf("%d%d%*c", &a, &b);
                long long ans = getsum(a, b);
                printf("%d\n", ans % 2);
            }
        }

        if (cases) {
            printf("\n");
        }

    }

}
