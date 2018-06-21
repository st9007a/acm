#include <cstdio>

int set[100005];
int sum[100005];
int num[100005];

int findRoot(int x);
void unionSet(int p, int q);
void move(int p, int q);

int main()
{

    int n, m;
    int command;
    int p, q;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            set[i] = i + n;
            set[i + n] = i + n;
            sum[i + n] = i;
            num[i + n] = 1;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &command);

            if (command == 1) {
                scanf("%d %d", &p, &q);
                unionSet(p, q);
            } else if (command == 2) {
                scanf("%d %d", &p, &q);
                move(p, q);
            } else {
                scanf("%d", &p);
                p = findRoot(p);
                printf("%d %d\n", num[p], sum[p]);
            }
        }
    }
}

int findRoot(int x)
{
    if (x == set[x]) {
        return x;
    }

    return set[x] = findRoot(set[x]);
}

void unionSet(int p, int q)
{
    p = findRoot(p);
    q = findRoot(q);

    if (p != q) {
        set[p] = q;
        sum[q] += sum[p];
        num[q] += num[p];
    }
}

void move(int p, int q)
{
    int rp = findRoot(p);
    int rq = findRoot(q);

    if (rp != rq) {
        set[p] = rq;
        sum[rq] += p;
        sum[rp] -= p;
        num[rq]++;
        num[rp]--;
    }

}
