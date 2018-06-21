#include <cstdio>

int sequence[1001];
int lis[1001];

int main()
{
    int n;

    while (scanf("%d", &n) != EOF) {
        int max = -1;

        for (int i = 0; i < n; i++) {
            scanf("%d", sequence + i);
            lis[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            lis[i] = 1;
            for (int j = 0; j < i; j++) {
                if (sequence[j] < sequence[i] && lis[j] + 1> lis[i]) {
                    lis[i] = lis[j] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (max < lis[i]) {
                max = lis[i];
            }
        }

        printf("%d\n", max);

    }
    return 0;
}
