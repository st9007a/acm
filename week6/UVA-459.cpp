#include <cstdio>

int p[27];
int r[27];
int ans;

int find(int x);
int joint(int x, int y);

int main()
{
    int n;
    char c[10];

    scanf("%d", &n);
    gets(c);
    gets(c);

    while (n--) {
        gets(c);

        int maxNum = c[0] - 'A';
        ans = maxNum + 1;

        while (maxNum >= 0) {
            p[maxNum] = maxNum;
            r[maxNum] = 1;
            maxNum--;
        }

        while (gets(c)) {
            if (c[0] == '\0') {
                break;
            }

            ans -= joint(c[0] - 'A', c[1] - 'A');
        }

        printf("%d\n", ans);

        if (n) {
            printf("\n");
        }
    }
}

int find(int x)
{
    if (p[x] == x) {
        return x;
    } else {
        return p[x] = find(p[x]);
    }
}

int joint(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x != y) {
        if (r[x] > r[y]) {
            r[x] += r[y];
            p[y] = x;
        } else {
            r[y] += r[x];
            p[x] = y;
        }

        return 1;
    }

    return 0;
}
