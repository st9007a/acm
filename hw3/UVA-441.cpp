#include <cstdio>

int cand[13];
int sol[6];

void bt(int dim, int size);

int main()
{
    int k;

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", cand + i);
    }

    bt(0, k);

    while (scanf("%d", &k)) {
        if (k == 0) {
            break;
        } else {
            printf("\n");
        }

        for (int i = 0; i < k; i++) {
            scanf("%d", cand + i);
        }

        bt(0, k);
    }
}

void bt(int dim, int size)
{
    if (dim == 6) {
        printf("%d %d %d %d %d %d\n", sol[0], sol[1], sol[2], sol[3], sol[4], sol[5]);
        return;
    }
    else {
        for (int i = 0; i <= size - 6 + dim; i++) {
            if (cand[i] > sol[dim - 1]) {
                sol[dim] = cand[i];
                bt(dim + 1, size);
            }
        }
    }
}
