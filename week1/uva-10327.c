#include <stdio.h>

int main()
{
    int size;

    int series[1001];

    while(scanf("%d", &size) != EOF) {
        int count = 0;

        for (int i = 0; i < size; i++) {
            scanf("%d", series + i);
        }

        for (int i = size - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (series[j + 1] < series[j]) {
                    series[j] ^= series[j + 1] ^= series[j] ^= series[j + 1];
                    count++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", count);
    }

    return 0;
}
