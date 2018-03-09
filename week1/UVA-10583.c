#include <stdio.h>

int set[50001];
int count;

int find_root(int x);
void union_set(int x, int y);

int main ()
{

    int pairs;
    int x, y;
    int cases = 1;

    while (scanf("%d %d", &count, &pairs)) {
        if (count == 0 && pairs == 0) {
            break;
        }

        for (int i = 1; i <= count; i++) {
            set[i] = i;
        }

        while (pairs--) {
            scanf("%d %d", &x, &y);
            union_set(x, y);
        }
        printf("Case %d: %d\n", cases++, count);
    }

    return 0;
}

int find_root(int x)
{
    if (x == set[x]) {
        return x;
    }

    return set[x] = find_root(set[x]);
}

void union_set(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if (x != y) {
        set[x] = y;
        count--;
    }
}
