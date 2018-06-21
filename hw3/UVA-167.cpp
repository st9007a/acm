#include <cstdio>

int set[8][8];
int ans;

void bt(int sum, int x, int y[], int slash1[], int slash2[]);

int main()
{
    int num;

    scanf("%d", &num);

    while (num--) {
        int sum = 0;
        int y[8] = {0}, slash1[15] = {0}, slash2[15] = {0};

        ans = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                scanf("%d", &set[i][j]);
            }
        }

        bt(0, 0, y, slash1, slash2);
        printf("%5d\n", ans);
    }
}

void bt(int sum, int x, int y[], int slash1[], int slash2[])
{

    if (x == 8) {
        if (sum > ans) {
            ans = sum;
        }
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (!y[i] && !slash1[(i + x) % 15] && !slash2[(i - x + 15) % 15]) {
            y[i] = 1;
            slash1[(i + x) % 15] = 1;
            slash2[(i - x + 15) % 15] = 1;

            bt(sum + set[x][i], x + 1, y, slash1, slash2);

            y[i] = 0;
            slash1[(i + x) % 15] = 0;
            slash2[(i - x + 15) % 15] = 0;
        }
    }
}

