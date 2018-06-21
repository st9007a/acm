#include <cstdio>

int set[200002];
int num[100002];
long long sum[100002];

int FindRoot(int x);
void Union(int p, int q);
void Move(int p, int q);

int main()
{
    int n, m, cmd;
    int p, q;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            set[i] = i + n;
            set[i + n] = i + n;
            sum[i + n] = i;

            num[i + n] = 1;
        }

        while (m--) {

            scanf("%d", &cmd);

            if (cmd == 3) {
                scanf("%d", &p);
                int r = FindRoot(p);
                printf("%d %lld\n", num[r], sum[r]);
            } else {
                scanf("%d %d", &p, &q);

                if (cmd == 1) {
                    Union(p, q);
                } else {
                    Move(p, q);
                }
            }
        }

    }
}

int FindRoot(int x)
{
    if (set[x] == x) {
        return x;
    }

    set[x] = FindRoot(set[x]);

    return set[x];
}

void Union(int p, int q)
{
    int x = FindRoot(p);
    int y = FindRoot(q);

    if (x != y) {
        set[x] = y;
        num[y] += num[x];
        sum[y] += sum[x];
    }
}

void Move(int p, int q)
{
    int x = FindRoot(p);
    int y = FindRoot(q);

    if (x != y) {
        set[p] = y;
        num[x] -= 1;
        num[y] += 1;
        sum[x] -= p;
        sum[y] += p;
    }
}
