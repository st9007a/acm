#include <stdio.h>

int main()
{
    int num[10001] = {0};
    int total = 0;
    int tmp;

    while (scanf("%d", num + (total++)) != EOF) {

        for (int i = 0; i < total; i++) {
            if (num[i] < num[total - 1]) {
                tmp = num[total - 1];
                for (int j = total - 1; j > i; j--) {
                    num[j] = num[j - 1];
                }
                num[i] = tmp;
                break;
            }
        }

        if (total % 2) {
            printf("%d\n", num[total / 2]);
        }
        else {
            printf("%d\n", (num[total / 2] + num[total / 2 - 1]) / 2);
        }
    }

    return 0;
}
